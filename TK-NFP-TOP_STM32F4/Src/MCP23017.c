#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "MCP23017.h"

#include "stdio.h"
#include <string.h>

#define	AFE_HPF_EMG		((uint16_t)0x0003)
#define	AFE_HPF_ECG		((uint16_t)0x000C)
#define	AFE_RLD_EMG2	((uint16_t)0x0010)
#define	AFE_RLD_EMG1	((uint16_t)0x0020)
#define	AFE_RLD_ECG1	((uint16_t)0x0040)
#define	AFE_RLD_ECG2	((uint16_t)0x0080)
#define	AFE_GAIN_EMG1	((uint16_t)0x0100)
#define	AFE_GAIN_EMG2	((uint16_t)0x0200)
#define	AFE_GAIN_ECG1	((uint16_t)0x0400)
#define	AFE_GAIN_ECG2	((uint16_t)0x0800)
#define	AFE_LPF_ECG		((uint16_t)0x3000)
#define	AFE_LPF_EMG		((uint16_t)0xC000)

#define MCP23017_I2C_ADDRESS     0x40

/*#define Reserved7				128
#define Reserved6				64
#define Reserved5				32
#define Reserved4   			16
#define Reserved3				8
#define Reserved2				4*/
#define AFE_STATE_REQUESTED		2
#define AFE_SWITCH_REQUESTED	1

uint8_t AFE_action_flags = 0;
static uint16_t AFE_GPIO_State = 0;
static uint16_t AFE_GPIO_State_Read = 0;

typedef enum
{
	AFE_SWITCH_STATE_REINIT = 0,
	AFE_SWITCH_STATE_SWITCH,
	AFE_SWITCH_STATE_READBACK,
	AFE_SWITCH_STATE_DONE
} TAFESwitchtStateMachine;

static TAFESwitchtStateMachine AFE_switch_state;

#define CheckAFESwitchRequested	(AFE_action_flags & AFE_SWITCH_REQUESTED)
#define SetAFESwitchRequested	{AFE_action_flags |= AFE_SWITCH_REQUESTED; AFE_switch_state = AFE_SWITCH_STATE_REINIT;}
#define ClrAFESwitchRequested	{AFE_action_flags &= ~AFE_SWITCH_REQUESTED;}

#define CheckAFEStateRequested	(AFE_action_flags & AFE_STATE_REQUESTED)
#define SetAFEAFEStateRequested	{AFE_action_flags |= AFE_STATE_REQUESTED;}
#define ClrAFEAFEStateRequested	{AFE_action_flags &= ~AFE_STATE_REQUESTED;}

extern uint8_t I2C2_TRANSMIT_STARTED;
extern uint8_t I2C2_TRANSMIT_ENDED;

AFE_State_TypeDef AFE_process(void)
{
	static uint8_t tempi2ctx[4];
	static uint8_t tempi2crx[4];

	if(CheckAFESwitchRequested)
	{
		switch (AFE_switch_state)
		{
//=========================================================================================================================================
		case AFE_SWITCH_STATE_REINIT:
			if(I2C2_TRANSMIT_STARTED == 1)
			{
				if(I2C2_TRANSMIT_ENDED == 1)
				{
					I2C2_TRANSMIT_STARTED = 0;
					I2C2_TRANSMIT_ENDED = 0;
#ifdef  AFE_UART_DEBUG
					printf("AFE switch reinit done: %02X%02X\n\r", tempi2ctx[1], tempi2ctx[0]);
#endif
					AFE_switch_state = AFE_SWITCH_STATE_SWITCH;
				}
			}
			else if (HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY)
			{
				I2C2_TRANSMIT_STARTED = 1;
				I2C2_TRANSMIT_ENDED = 0;
#ifdef  AFE_UART_DEBUG
				printf("AFE switch reinit attempt\n\r");
#endif
				tempi2ctx[0] = 0x0;
				tempi2ctx[1] = 0x0;
				if (HAL_I2C_Mem_Write_DMA(&hi2c2, MCP23017_I2C_ADDRESS, 0x0, I2C_MEMADD_SIZE_8BIT, tempi2ctx, 2) != HAL_OK)
				{
#ifdef  AFE_UART_DEBUG
					printf("MCP23017_config HAL fail\n\r");
#endif
				}
			}
			return AFE_STATE_BUSY; //
			break;
//=========================================================================================================================================
		case AFE_SWITCH_STATE_SWITCH:
			if(I2C2_TRANSMIT_STARTED == 1)
			{
				if(I2C2_TRANSMIT_ENDED == 1)
				{
					I2C2_TRANSMIT_STARTED = 0;
					I2C2_TRANSMIT_ENDED = 0;
#ifdef  AFE_UART_DEBUG
					printf("AFE switch write done: %02X%02X\n\r", tempi2ctx[1], tempi2ctx[0]);
#endif
					AFE_switch_state = AFE_SWITCH_STATE_READBACK;
				}
			}
			else if (HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY)
			{
				I2C2_TRANSMIT_STARTED = 1;
				I2C2_TRANSMIT_ENDED = 0;
#ifdef  AFE_UART_DEBUG
				printf("AFE switch write attempt: %04X\n\r", AFE_GPIO_State);
#endif
				tempi2ctx[0] = (uint8_t)(AFE_GPIO_State & (0xFF));//GPA
			    tempi2ctx[1] = (uint8_t)((AFE_GPIO_State>>8) & (0xFF));//GPB - first!
				tempi2ctx[2] = (uint8_t)(AFE_GPIO_State & (0xFF));//GPA
			    tempi2ctx[3] = (uint8_t)((AFE_GPIO_State>>8) & (0xFF));//GPB - first!
				if (HAL_I2C_Mem_Write_DMA(&hi2c2, MCP23017_I2C_ADDRESS, 0x12, I2C_MEMADD_SIZE_8BIT, tempi2ctx, 4) != HAL_OK)
				{
#ifdef  AFE_UART_DEBUG
					printf("AFE_process HAL fail\n\r");
#endif
				}
			}
			return AFE_STATE_BUSY; //
			break;
//=========================================================================================================================================
		case AFE_SWITCH_STATE_READBACK:
			if(I2C2_TRANSMIT_STARTED == 1)
			{
				if(I2C2_TRANSMIT_ENDED == 1)
				{
					I2C2_TRANSMIT_STARTED = 0;
					I2C2_TRANSMIT_ENDED = 0;

					AFE_GPIO_State_Read = ((uint16_t)(tempi2crx[1]) << 8) + tempi2crx[0];
					AFE_switch_state = AFE_SWITCH_STATE_DONE;
#ifdef  AFE_UART_DEBUG
					printf("AFE switch read done: %04X %02X%02X\n\r", AFE_GPIO_State_Read, tempi2crx[1], tempi2crx[0]);
#endif
				}
			}
			else if (HAL_I2C_GetState(&hi2c2) == HAL_I2C_STATE_READY)
			{
				I2C2_TRANSMIT_STARTED = 1;
				I2C2_TRANSMIT_ENDED = 0;
#ifdef  AFE_UART_DEBUG
				printf("AFE switch read attempt\n\r");
#endif
				if (HAL_I2C_Mem_Read_DMA(&hi2c2, MCP23017_I2C_ADDRESS, 0x14, I2C_MEMADD_SIZE_8BIT, tempi2crx, 2) != HAL_OK)
				{
#ifdef  AFE_UART_DEBUG
					printf("AFE_process HAL fail\n\r");
#endif
				}
			}
			return AFE_STATE_BUSY; //
			break;
//=========================================================================================================================================
		case AFE_SWITCH_STATE_DONE:
			ClrAFESwitchRequested;
#ifdef  AFE_UART_DEBUG
			printf("AFE switch done\n\r");
#endif
			return AFE_STATE_OK; //
			break;
		default:
#ifdef  AFE_UART_DEBUG
			printf("AFE switch error\n\r");
#endif
	return AFE_STATE_ERROR; // should never get here
			break;
		} // switch AFE_switch_state
	} // CheckAFESwitchRequested

	if(CheckAFEStateRequested)
	{
		return AFE_STATE_OK; //
		ClrAFEAFEStateRequested;
	} // CheckAFESwitchRequested

	return AFE_STATE_OK; //
}

AFE_Data_TypeDef AFE_get(AFE_Reg_TypeDef AFE_reg)
{
//	SetAFEAFEStateRequested;
	switch (AFE_reg)
	{
	case	AFE_REG_HPF_EMG:
		switch(AFE_GPIO_State&AFE_HPF_EMG)
		{
		case 0:
			return AFE_HPF_EMG_10kHz;
			break;
		case 1:
			return AFE_HPF_EMG_70kHz;
			break;
		case 2:
			return AFE_HPF_EMG_30kHz;
			break;
		case 3:
			return AFE_HPF_EMG_100kHz;
			break;
		}
		break;
	case	AFE_REG_HPF_ECG:
		switch((AFE_GPIO_State&AFE_HPF_EMG)>>4)
		{
		case 0:
			return AFE_HPF_ECG_0d1Hz;
			break;
		case 1:
			return AFE_HPF_ECG_1d0Hz;
			break;
		case 2:
			return AFE_HPF_ECG_0d3Hz;
			break;
		case 3:
			return AFE_HPF_ECG_3d0Hz;
			break;
		}
		break;
	case	AFE_REG_RLD_EMG2:
		if(AFE_GPIO_State&AFE_RLD_EMG2)
			return AFE_RLD_EMG2_ON;
		else
			return AFE_RLD_EMG2_OFF;
		break;
	case	AFE_REG_RLD_EMG1:
		if(AFE_GPIO_State&AFE_RLD_EMG1)
			return AFE_RLD_EMG1_ON;
		else
			return AFE_RLD_EMG1_OFF;
		break;
	case	AFE_REG_RLD_ECG1:
		if(AFE_GPIO_State&AFE_RLD_ECG1)
			return AFE_RLD_ECG1_ON;
		else
			return AFE_RLD_ECG1_OFF;
	case	AFE_REG_RLD_ECG2:
		if(AFE_GPIO_State&AFE_RLD_ECG2)
			return AFE_RLD_ECG2_ON;
		else
			return AFE_RLD_ECG2_OFF;
		break;
	case	AFE_REG_GAIN_EMG1:
		if(AFE_GPIO_State&AFE_GAIN_EMG1)
			return AFE_GAIN_EMG1_100;
		else
			return AFE_GAIN_EMG1_1000;
		break;

	case	AFE_REG_GAIN_EMG2:
		if(AFE_GPIO_State&AFE_GAIN_EMG2)
			return AFE_GAIN_EMG2_100;
		else
			return AFE_GAIN_EMG2_1000;
		break;
	case	AFE_REG_GAIN_ECG1:
		if(AFE_GPIO_State&AFE_GAIN_ECG1)
			return AFE_GAIN_ECG1_100;
		else
			return AFE_GAIN_ECG1_1000;
		break;
	case	AFE_REG_GAIN_ECG2:
		if(AFE_GPIO_State&AFE_GAIN_ECG2)
			return AFE_GAIN_ECG2_100;
		else
			return AFE_GAIN_ECG2_1000;
		break;
	case	AFE_REG_LPF_ECG:
		switch((AFE_GPIO_State&AFE_LPF_ECG)>>12)
		{
		case 0:
			return AFE_LPF_ECG_40Hz;
			break;
		case 1:
			return AFE_LPF_ECG_100Hz;
			break;
		case 2:
			return AFE_LPF_ECG_70Hz;
			break;
		case 3:
			return AFE_LPF_ECG_150Hz;
			break;
		}
		break;
	case	AFE_REG_LPF_EMG:
		switch((AFE_GPIO_State&AFE_LPF_EMG)>>14)
		{
		case 0:
			return AFE_LPF_EMG_30Hz;
			break;
		case 1:
			return AFE_LPF_EMG_1000Hz;
			break;
		case 2:
			return AFE_LPF_EMG_400Hz;
			break;
		case 3:
			return AFE_LPF_EMG_3000Hz;
			break;
		}
		break;
	}//switch AFE_reg
	return AFE_DATA_ERROR; // should never get here
} // AFE_process

AFE_State_TypeDef AFE_set(AFE_Reg_TypeDef AFE_reg, AFE_Data_TypeDef AFE_data)
{
	static uint16_t temp16u;

/*	if (CheckAFESwitchRequested)
	{
		return AFE_STATE_BUSY;
	}*/

	SetAFESwitchRequested;

	switch (AFE_reg)
	{
	case	AFE_REG_HPF_EMG:
		temp16u = AFE_GPIO_State & 0xFFFC;
		switch(AFE_data)
		{
		case	AFE_HPF_EMG_10kHz:
			AFE_GPIO_State = (0x00 | temp16u);
			break;
		case	AFE_HPF_EMG_70kHz:
			AFE_GPIO_State = (0x01 | temp16u);
			break;
		case	AFE_HPF_EMG_30kHz:
			AFE_GPIO_State = (0x02 | temp16u);
			break;
		case	AFE_HPF_EMG_100kHz:
			AFE_GPIO_State = (0x03 | temp16u);
			break;
		}// switch data AFE_REG_HPF_EMG
		break;

	case	AFE_REG_HPF_ECG:
		temp16u = AFE_GPIO_State & 0xFFF3;
		switch(AFE_data)
		{
		case	AFE_HPF_ECG_0d1Hz:
			AFE_GPIO_State = ((0x00<<2) | temp16u);
			break;
		case	AFE_HPF_ECG_1d0Hz:
			AFE_GPIO_State = ((0x01<<2) | temp16u);
			break;
		case	AFE_HPF_ECG_0d3Hz:
			AFE_GPIO_State = ((0x02<<2) | temp16u);
			break;
		case	AFE_HPF_ECG_3d0Hz:
			AFE_GPIO_State = ((0x03<<2) | temp16u);
			break;
		}// switch data AFE_REG_HPF_ECG
		break;

	case	AFE_REG_RLD_EMG2:
		switch(AFE_data)
		{
		case	AFE_RLD_EMG2_OFF:
			AFE_GPIO_State &= 0xFFEF;
			break;
		case	AFE_RLD_EMG2_ON:
			AFE_GPIO_State |= 0x0010;
			break;
		}
		break;

	case	AFE_REG_RLD_EMG1:
		switch(AFE_data)
		{
		case	AFE_RLD_EMG1_OFF:
			AFE_GPIO_State &= 0xFFDF;
			break;
		case	AFE_RLD_EMG1_ON:
			AFE_GPIO_State |= 0x0020;
			break;
		}
		break;

	case	AFE_REG_RLD_ECG1:
		switch(AFE_data)
		{
		case	AFE_RLD_ECG1_OFF:
			AFE_GPIO_State &= 0xFFBF;
			break;
		case	AFE_RLD_ECG1_ON:
			AFE_GPIO_State |= 0x0040;
			break;
		}
		break;

	case	AFE_REG_RLD_ECG2:
		switch(AFE_data)
		{
		case	AFE_RLD_ECG2_OFF:
			AFE_GPIO_State &= 0xFF7F;
			break;
		case	AFE_RLD_ECG2_ON:
			AFE_GPIO_State |= 0x0080;
			break;
		}// switch data AFE_REG_RLD
		break;

	case	AFE_REG_GAIN_EMG1:
		switch(AFE_data)
		{
		case	AFE_GAIN_EMG1_1000:
			AFE_GPIO_State &= 0xF4FF;
			break;
		case	AFE_GAIN_EMG1_100:
			AFE_GPIO_State |= 0x0100;
			break;
		}
		break;

	case	AFE_REG_GAIN_EMG2:
		switch(AFE_data)
		{
		case	AFE_GAIN_EMG2_1000:
			AFE_GPIO_State &= 0xFDFF;
			break;
		case	AFE_GAIN_EMG2_100:
			AFE_GPIO_State |= 0x0200;
			break;
		}
		break;

	case	AFE_REG_GAIN_ECG1:
		switch(AFE_data)
		{
		case	AFE_GAIN_ECG1_1000:
			AFE_GPIO_State &= 0xFBFF;
			break;
		case	AFE_GAIN_ECG1_100:
			AFE_GPIO_State |= 0x0400;
			break;
		}
		break;

	case	AFE_REG_GAIN_ECG2:
		switch(AFE_data)
		{
		case	AFE_GAIN_ECG2_1000:
			AFE_GPIO_State &= 0xF7FF;
			break;
		case	AFE_GAIN_ECG2_100:
			AFE_GPIO_State |= 0x0800;
			break;
		}
		break;

	case	AFE_REG_LPF_ECG:
		temp16u = AFE_GPIO_State & 0xCFFF;
		switch(AFE_data)
		{
		case	AFE_LPF_ECG_40Hz:
			AFE_GPIO_State = ((0x00<<12) | temp16u);
			break;
		case	AFE_LPF_ECG_100Hz:
			AFE_GPIO_State = ((0x01<<12) | temp16u);
			break;
		case	AFE_LPF_ECG_70Hz:
			AFE_GPIO_State = ((0x02<<12) | temp16u);
			break;
		case	AFE_LPF_ECG_150Hz:
			AFE_GPIO_State = ((0x03<<12) | temp16u);
			break;
		}// switch data
		break;

	case	AFE_REG_LPF_EMG:
		temp16u = AFE_GPIO_State & 0x3FFF;
		switch(AFE_data)
		{
		case	AFE_LPF_EMG_30Hz:
			AFE_GPIO_State = ((0x00<<14) | temp16u);
			break;
		case	AFE_LPF_EMG_1000Hz:
			AFE_GPIO_State = ((0x01<<14) | temp16u);
			break;
		case	AFE_LPF_EMG_400Hz:
			AFE_GPIO_State = ((0x02<<14) | temp16u);
			break;
		case	AFE_LPF_EMG_3000Hz:
			AFE_GPIO_State = ((0x03<<14) | temp16u);
			break;
		}// switch data
		break;

	default:
		break;
	}// switch reg
	return AFE_STATE_OK;
}

uint16_t AFE_read(void)
{
	return AFE_GPIO_State;
}

void AFE_write(uint16_t data)
{
	AFE_GPIO_State = data;
	SetAFESwitchRequested;
}

uint8_t AFE_get_AF(void)
{
	return AFE_action_flags;
}