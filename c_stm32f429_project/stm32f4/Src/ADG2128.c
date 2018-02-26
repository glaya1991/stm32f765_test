#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "ADG2128.h"

#include "stdio.h"
#include <string.h>

#define	AFE_HPF_EMG	((uint16_t)0x0003)
#define	AFE_HPF_ECG	((uint16_t)0x000C)
#define	AFE_RLD		((uint16_t)0x00F0)
#define	AFE_GAIN	((uint16_t)0x0F00)
#define	AFE_LPF_ECG	((uint16_t)0x3000)
#define	AFE_LPF_EMG	((uint16_t)0xC000)

#define ADG2128_I2C_ADDRESS     0xEE

/*#define Reserved7				128
#define Reserved6				64
#define Reserved5				32
#define Reserved4   			16
#define Reserved3				8
#define Reserved2				4*/
#define MUX_STATE_REQUESTED		2
#define MUX_SWITCH_REQUESTED	1

static uint8_t MUX_action_flags = 0;

static uint8_t MUX_A = 0;
static uint8_t MUX_B = 0;
static uint8_t MUX_A_old = 0;
static uint8_t MUX_B_old = 0;
static uint8_t AFE_MUX_State = 0;

typedef enum
{
	MUX_CLEAR1 = 0,
	MUX_CLEAR2,
	MUX_WRITE1,
	MUX_WRITE2,
	MUX_DONE
} TMUXStateMachine;

static TMUXStateMachine MUX_state;

#define CheckMUXSwitchRequested	(MUX_action_flags & MUX_SWITCH_REQUESTED)
#define SetMUXSwitchRequested	{MUX_action_flags |= MUX_SWITCH_REQUESTED; MUX_state = MUX_CLEAR1;}
#define ClrMUXSwitchRequested	{MUX_action_flags &= ~MUX_SWITCH_REQUESTED;}

#define CheckMUXStateRequested	(MUX_action_flags & MUX_STATE_REQUESTED)
#define SetMUXStateRequested	{MUX_action_flags |= MUX_STATE_REQUESTED;}
#define ClrMUXStateRequested	{MUX_action_flags &= ~MUX_STATE_REQUESTED;}

extern uint8_t I2C2_TRANSMIT_STARTED;
extern uint8_t I2C2_TRANSMIT_ENDED;

MUX_State_TypeDef MUX_process(void)
{
	static uint8_t tempi2ctx[4];
	static uint8_t tempi2crx[4];

	if(CheckMUXSwitchRequested)
	{
		switch (MUX_state)
		{
//=========================================================================================================================================
		case MUX_CLEAR1:
			if(I2C2_TRANSMIT_STARTED == 1)
			{
				if(I2C2_TRANSMIT_ENDED == 1)
				{
					I2C2_TRANSMIT_STARTED = 0;
					I2C2_TRANSMIT_ENDED = 0;
#if  MUX_UART_DEBUG
					printf("MUX switch clear1 done: %02X %02X\n\r", tempi2ctx[0], tempi2ctx[1]);
#endif
					MUX_state = MUX_CLEAR2;
				}
			}
			else if (HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY)
			{
				I2C2_TRANSMIT_STARTED = 1;
				I2C2_TRANSMIT_ENDED = 0;
				tempi2ctx[0] = MUX_A_old & 0x7F;
				tempi2ctx[1] = 0x0;
#if  MUX_UART_DEBUG
				printf("MUX switch clear1 attempt: %02X %02X\n\r", tempi2ctx[0], tempi2ctx[1]);
#endif
				if (HAL_I2C_Master_Transmit_DMA(&hi2c2, ADG2128_I2C_ADDRESS,  tempi2ctx, 2) != HAL_OK)
				{
#if  MUX_UART_DEBUG
					printf("MUX_process HAL fail\n\r");
#endif
				}
			}
			return MUX_STATE_BUSY; //
			break;
//=========================================================================================================================================
		case MUX_CLEAR2:
			if(I2C2_TRANSMIT_STARTED == 1)
			{
				if(I2C2_TRANSMIT_ENDED == 1)
				{
					I2C2_TRANSMIT_STARTED = 0;
					I2C2_TRANSMIT_ENDED = 0;
#if  MUX_UART_DEBUG
					printf("MUX switch clear2 done: %02X %02X\n\r", tempi2ctx[0], tempi2ctx[1]);
#endif
					MUX_state = MUX_WRITE1;
				}
			}
			else if (HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY)
			{
				I2C2_TRANSMIT_STARTED = 1;
				I2C2_TRANSMIT_ENDED = 0;
				tempi2ctx[0] = MUX_B_old & 0x7F;
				tempi2ctx[1] = 0x0;
#if  MUX_UART_DEBUG
				printf("MUX switch clear2 attempt: %02X %02X\n\r", tempi2ctx[0], tempi2ctx[1]);
#endif
				if (HAL_I2C_Master_Transmit_DMA(&hi2c2, ADG2128_I2C_ADDRESS,  tempi2ctx, 2) != HAL_OK)
				{
#if  MUX_UART_DEBUG
					printf("MUX_process HAL fail\n\r");
#endif
				}
			}
			return MUX_STATE_BUSY; //
			break;
//=========================================================================================================================================
		case MUX_WRITE1:
			if(I2C2_TRANSMIT_STARTED == 1)
			{
				if(I2C2_TRANSMIT_ENDED == 1)
				{
					I2C2_TRANSMIT_STARTED = 0;
					I2C2_TRANSMIT_ENDED = 0;
#if  MUX_UART_DEBUG
					printf("MUX switch write1 done: %02X %02X\n\r", tempi2ctx[0], tempi2ctx[1]);
#endif
					MUX_state = MUX_WRITE2;
				}
			}
			else if (HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY)
			{
				I2C2_TRANSMIT_STARTED = 1;
				I2C2_TRANSMIT_ENDED = 0;
				tempi2ctx[0] = MUX_A;
				tempi2ctx[1] = 0x0;
#if  MUX_UART_DEBUG
				printf("MUX switch write1 attempt: %02X %02X\n\r", tempi2ctx[0], tempi2ctx[1]);
#endif
				if (HAL_I2C_Master_Transmit_DMA(&hi2c2, ADG2128_I2C_ADDRESS,  tempi2ctx, 2) != HAL_OK)
				{
#if  MUX_UART_DEBUG
					printf("MUX_process HAL fail\n\r");
#endif
				}
			}
			return MUX_STATE_BUSY; //
			break;
//=========================================================================================================================================
		case MUX_WRITE2:
						if(I2C2_TRANSMIT_STARTED == 1)
						{
							if(I2C2_TRANSMIT_ENDED == 1)
							{
								I2C2_TRANSMIT_STARTED = 0;
								I2C2_TRANSMIT_ENDED = 0;
			#ifdef  MUX_UART_DEBUG
								printf("MUX switch write2 done: %02X %02X\n\r", tempi2ctx[0], tempi2ctx[1]);
			#endif
								MUX_state = MUX_DONE;
							}
						}
						else if (HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY)
						{
							I2C2_TRANSMIT_STARTED = 1;
							I2C2_TRANSMIT_ENDED = 0;
							tempi2ctx[0] = MUX_B;
							tempi2ctx[1] = 0x1;
			#ifdef  MUX_UART_DEBUG
							printf("MUX switch write2 attempt: %02X %02X\n\r", tempi2ctx[0], tempi2ctx[1]);
			#endif
							if (HAL_I2C_Master_Transmit_DMA(&hi2c2, ADG2128_I2C_ADDRESS,  tempi2ctx, 2) != HAL_OK)
							{
			#ifdef  MUX_UART_DEBUG
								printf("MUX_process HAL fail\n\r");
			#endif
							}
						}
						return MUX_STATE_BUSY; //
						break;

//=========================================================================================================================================
		case MUX_DONE:
			ClrMUXSwitchRequested;
#if  MUX_UART_DEBUG
			printf("MUX switch done\n\r");
#endif
			return MUX_STATE_OK; //
			break;
		default:
#if  MUX_UART_DEBUG
			printf("MUX switch error\n\r");
#endif
	return MUX_STATE_ERROR; // should never get here
			break;
		} // switch AFE_switch_state
	} // CheckAFESwitchRequested

	if(CheckMUXStateRequested)
	{
		return MUX_STATE_OK; //
		ClrMUXStateRequested;
	} // CheckAFESwitchRequested

	return MUX_STATE_OK; //
}

MUX_Mode_TypeDef MUX_get(void)
{
	return AFE_MUX_State;
}

MUX_State_TypeDef MUX_set(MUX_Mode_TypeDef mode)
{
	SetMUXSwitchRequested;
	MUX_A_old = MUX_A;
	MUX_B_old = MUX_B;
	switch(mode)
	{
	case	MUX_Strap1_IMP:
		MUX_A = 0x82;
		MUX_B = 0x8B;
		AFE_MUX_State = MUX_Strap1_IMP;
		break;
	case	MUX_Strap2_IMP:
		MUX_A = 0x92;
		MUX_B = 0x9B;
		AFE_MUX_State = MUX_Strap2_IMP;
		break;
	case	MUX_ECG_IMP:
		MUX_A = 0xD2;
		MUX_B = 0xDB;
		AFE_MUX_State = MUX_ECG_IMP;
		break;
	case	MUX_EMG_IMP:
		MUX_A = 0xE2;
		MUX_B = 0xEB;
		AFE_MUX_State = MUX_EMG_IMP;
		break;
	case	MUX_Strap1_ECG12:
		MUX_A = 0x80;
		MUX_B = 0x89;
		AFE_MUX_State = MUX_Strap1_ECG12;
		break;
	case	MUX_Strap2_ECG12:
		MUX_A = 0x90;
		MUX_B = 0x99;
		AFE_MUX_State = MUX_Strap2_ECG12;
		break;
	case	MUX_ExtECG_ECG12:
		MUX_A = 0xD0;
		MUX_B = 0xD9;
		AFE_MUX_State = MUX_ExtECG_ECG12;
		break;
	case	MUX_Strap1_EMG1:
		MUX_A = 0x84;
		MUX_B = 0x8D;
		AFE_MUX_State = MUX_Strap1_EMG1;
		break;
	case	MUX_Strap2_EMG2:
		MUX_A = 0x96;
		MUX_B = 0x9F;
		AFE_MUX_State = MUX_Strap2_EMG2;
		break;
	case	MUX_ExtEMG_EMG12:
		MUX_A = 0xE4;
		MUX_B = 0xED;
		AFE_MUX_State = MUX_ExtEMG_EMG12;
		break;
	case	MUX_Strap1_ECG12_ExtEMG_EMG12:
		MUX_A = 0xE6;
		MUX_B = 0xEF;
		AFE_MUX_State = MUX_Strap1_ECG12_ExtEMG_EMG12;
		break;
	case	MUX_Strap2_ECG12_ExtEMG_EMG12:
		MUX_A = 0x0;
		MUX_B = 0x0;
		AFE_MUX_State = MUX_Strap2_ECG12_ExtEMG_EMG12;
		break;
	case	MUX_Strap1_EMG1_ExtECG_ECG12:
		MUX_A = 0x0;
		MUX_B = 0x0;
		AFE_MUX_State = MUX_Strap1_EMG1_ExtECG_ECG12;
		break;
	case	MUX_Strap2_EMG2_ExtECG_ECG12:
		MUX_A = 0x0;
		MUX_B = 0x0;
		AFE_MUX_State = MUX_Strap2_EMG2_ExtECG_ECG12;
		break;
	case	MUX_ExtECG_ECG12_ExtEMG_EMG12:
		MUX_A = 0x0;
		MUX_B = 0x0;
		AFE_MUX_State = MUX_ExtECG_ECG12_ExtEMG_EMG12;
		break;
	case	MUX_Zero_ECG12:
		MUX_A = 0x0;
		MUX_B = 0x0;
		AFE_MUX_State = MUX_Zero_ECG12;
		break;
	case	MUX_Zero_EMG1:
		MUX_A = 0x0;
		MUX_B = 0x0;
		AFE_MUX_State = MUX_Zero_EMG1;
		break;
	case	MUX_Zero_EMG2:
		MUX_A = 0x0;
		MUX_B = 0x0;
		AFE_MUX_State = MUX_Zero_EMG2;
		break;
	default:		// should never get here
#if  MUX_UART_DEBUG
			printf("MUX mode error\n\r");
#endif
		return MUX_STATE_ERROR;
		break;
	}
	return MUX_STATE_OK;
}

uint8_t MUX_get_AF(void)
{
	return MUX_action_flags;
}
