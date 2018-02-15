#include "stm32f4xx_hal.h"

typedef enum
{
    AFE_STATE_OK = 0,
    AFE_STATE_BUSY = 1,
    AFE_STATE_ERROR = 2
} AFE_State_TypeDef;


typedef enum
{
    AFE_REG_HPF_EMG 	= 0,
    AFE_REG_HPF_ECG 	= 1,
    AFE_REG_RLD_EMG2	= 2,
    AFE_REG_RLD_EMG1	= 3,
    AFE_REG_RLD_ECG1	= 4,
    AFE_REG_RLD_ECG2	= 5,
    AFE_REG_GAIN_EMG1	= 6,
    AFE_REG_GAIN_EMG2	= 7,
    AFE_REG_GAIN_ECG1	= 8,
    AFE_REG_GAIN_ECG2	= 9,
    AFE_REG_LPF_ECG		= 10,
    AFE_REG_LPF_EMG 	= 11
} AFE_Reg_TypeDef;

typedef enum
{
	AFE_DATA_ERROR		= 0,
    AFE_HPF_EMG_10kHz	= 1,
    AFE_HPF_EMG_70kHz	= 2,
    AFE_HPF_EMG_30kHz	= 3,
    AFE_HPF_EMG_100kHz	= 4,
    AFE_HPF_ECG_0d1Hz	= 5,
    AFE_HPF_ECG_1d0Hz	= 6,
    AFE_HPF_ECG_0d3Hz	= 7,
    AFE_HPF_ECG_3d0Hz	= 8,
    AFE_RLD_EMG2_OFF	= 9,
    AFE_RLD_EMG2_ON		= 10,
    AFE_RLD_EMG1_OFF	= 11,
    AFE_RLD_EMG1_ON		= 12,
    AFE_RLD_ECG1_OFF	= 13,
    AFE_RLD_ECG1_ON		= 14,
    AFE_RLD_ECG2_OFF	= 15,
    AFE_RLD_ECG2_ON		= 16,
    AFE_GAIN_EMG1_1000	= 17,
    AFE_GAIN_EMG1_100	= 18,
    AFE_GAIN_EMG2_1000	= 19,
    AFE_GAIN_EMG2_100	= 20,
    AFE_GAIN_ECG1_1000	= 21,
    AFE_GAIN_ECG1_100	= 22,
    AFE_GAIN_ECG2_1000	= 23,
    AFE_GAIN_ECG2_100	= 24,
    AFE_LPF_ECG_40Hz	= 25,
    AFE_LPF_ECG_100Hz	= 26,
    AFE_LPF_ECG_70Hz	= 27,
    AFE_LPF_ECG_150Hz	= 28,
    AFE_LPF_EMG_30Hz	= 29,
    AFE_LPF_EMG_1000Hz	= 30,
    AFE_LPF_EMG_400Hz	= 31,
    AFE_LPF_EMG_3000Hz	= 32
} AFE_Data_TypeDef;

AFE_State_TypeDef AFE_process(void);

uint16_t AFE_read(void);
AFE_Data_TypeDef AFE_get(AFE_Reg_TypeDef AFE_reg);
AFE_State_TypeDef AFE_set(AFE_Reg_TypeDef reg, AFE_Data_TypeDef data);
void MCP23017_config(void);
