#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"

#include "AFE_MUX_IMP.h"
#include "MCP23017.h"	// AFE mode selector
#include "ADG2128.h"	// AFE MUX

#include "stdio.h"
#include <string.h>
#include "Handler.h"

typedef enum
{
	AFEMUX_RST_DOWN = 0,
	AFEMUX_RST_UP,
	AFEMUX_RST_DONE
} TAFEMUXRSTtStateMachine;

TAFEMUXRSTtStateMachine AFEMUX_RST_state = 0;

#define AFEMUX_TIMER_OVER		2
#define AFEMUX_RESET_REQUESTED	1

uint8_t AFEMUX_action_flags = 0;

#define CheckAFEMUXTimerOver	(AFEMUX_action_flags & AFEMUX_TIMER_OVER)
#define SetAFEMUXTimerOver	{AFEMUX_action_flags |= AFEMUX_TIMER_OVER;}
#define ClrAFEMUXTimerOver	{AFEMUX_action_flags &= ~AFEMUX_TIMER_OVER;}

#define CheckAFEMUXResetRequested	(AFEMUX_action_flags & AFEMUX_RESET_REQUESTED)
#define SetAFEMUXResetRequested	{AFEMUX_action_flags |= AFEMUX_RESET_REQUESTED; AFEMUX_RST_state = AFEMUX_RST_DOWN;}
#define ClrAFEMUXResetRequested	{AFEMUX_action_flags &= ~AFEMUX_RESET_REQUESTED;}

void AFEMUX_RST_process(void);
void AFEMUX_SetTimer (uint16_t ms);
void AFEMUX_StartTimer(void);

void AFE_MUX_IMP_init (void)
{
    //    ReadMem(REG_AFE_MUX_STATE);
    //    ReadMem(REG_AFE_GPIO_STATE);
    
//	MUX_set((MUX_Mode_TypeDef)(REG_AFE_MUX_STATE & 0xFF));
    //    AFE_write((uint16_t)(REG_AFE_GPIO_STATE & 0xFFFF ));
    
    //AFE_set(AFE_REG_LPF_ECG, AFE_LPF_ECG_150Hz);
    AFE_write(0xF000);

#ifdef  AFE_UART_DEBUG
	printf("AFE set: %02X\n\r", AFE_read());
#endif

#ifdef  MUX_UART_DEBUG
	printf("MUX set: %02X\n\r", MUX_get());
#endif

	AFEMUX_reset();
#ifdef  AFEMUX_UART_DEBUG
	printf("AFE&MUX reset requested\n\r");
#endif

	AFEMUX_SetTimer(200);
	AFEMUX_StartTimer();
}

AFE_MUX_IMP_State_TypeDef AFE_MUX_IMP_process(void)
{
	if (CheckAFEMUXResetRequested)
	{
		AFEMUX_RST_process();
	}
	else
	{
		if (AFE_get_AF() != 0)
		{
			AFE_process();
		}
		else
		{
			MUX_process();
		}
	}

	if (CheckAFEMUXTimerOver)
	{
#ifdef  AFEMUX_UART_DEBUG
		printf("AFE&MUX timer!\n\r");
#endif

		//readmem here
               /* if (ReadMem(REG_AFE_MODE) !=0)
                {
                    ReadMem(REG_AFE_MUX_STATE);
                    ReadMem(REG_AFE_GPIO_STATE);
                    MUX_set((MUX_Mode_TypeDef)(REG_AFE_MUX_STATE & 0xFF));
                    AFE_write((uint16_t)(REG_AFE_GPIO_STATE & 0xFFFF));
                    WriteMem(REG_AFE_MODE, 0x0);
                }*/
                

		AFEMUX_StartTimer();
		ClrAFEMUXTimerOver;
	}
	return AFE_MUX_IMP_STATE_OK; //
}

void AFEMUX_RST_process(void)
{
	switch (AFEMUX_RST_state)
	{
//=========================================================================================================================================
	case AFEMUX_RST_DOWN:
//		HAL_GPIO_WritePin(AFE_SW_RESET_GPIO_Port, AFE_SW_RESET_Pin,GPIO_PIN_RESET);
		AFEMUX_RST_state = AFEMUX_RST_UP;
#ifdef  AFEMUX_UART_DEBUG
		printf("AFE&MUX RST down\n\r");
#endif
		break;
//=========================================================================================================================================
	case AFEMUX_RST_UP:
//		HAL_GPIO_WritePin(AFE_SW_RESET_GPIO_Port, AFE_SW_RESET_Pin,GPIO_PIN_SET);
		AFEMUX_RST_state = AFEMUX_RST_DONE;
#ifdef  AFEMUX_UART_DEBUG
		printf("AFE&MUX RST up\n\r");
#endif
		ClrAFEMUXResetRequested
		break;
	}	//switch AFE_MUX_RST_state
}

void AFEMUX_reset(void)
{
	SetAFEMUXResetRequested;
}

void AFEMUX_SetTimer (uint16_t ms)
{
	  htim13.Instance = TIM13;
	  htim13.Init.Prescaler = (uint32_t) ((SystemCoreClock /2) / 10000) - 1;
	  htim13.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim13.Init.Period = ms*10;
	  htim13.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  if (HAL_TIM_Base_Init(&htim13) != HAL_OK)
	  {
#ifdef  AFEMUX_UART_DEBUG
		printf("AFE&MUX timer init error\n\r");
#endif
	  }
	  __HAL_TIM_CLEAR_FLAG(&htim13, TIM_SR_UIF);  //
}

void AFEMUX_timer_callback(void)
{
	SetAFEMUXTimerOver;

#ifdef  AFEMUX_MODES_DEBUG
	static uint8_t testmode;

	MUX_set (testmode);
	testmode++;
	if (testmode == 10)
	{
		testmode = 1;
	}
#endif
}

void AFEMUX_StartTimer(void)
{
	if (HAL_TIM_Base_Start_IT(&htim13) != HAL_OK)
	{
#ifdef  AFEMUX_UART_DEBUG
		printf("AFE&MUX timer start error\n\r\n\r");
#endif
	};
}
