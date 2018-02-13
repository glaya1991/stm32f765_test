#include "stm32f4xx_hal.h"

typedef enum
{
    AFE_STATE_OK = 0,
    AFE_STATE_BUSY = 1,
    AFE_STATE_ERROR = 2
} AFE_StateTypeDef;


typedef enum
{
    AFE_HPF_EMG = 0,
    AFE_HPF_ECG = 1,
    AFE_RLD		= 2,
    AFE_GAIN	= 3,
    AFE_LPF_ECG	= 4,
    AFE_LPF_EMG = 5,
} AFE_Reg_TypeDef;

typedef enum
{
    AFE_HPF_EMG_10kHz	= 0,
    AFE_HPF_EMG_70kHz	= 1,
    AFE_HPF_EMG_30kHz	= 2,
    AFE_HPF_EMG_100kHz	= 3,
    AFE_HPF_ECG_0d1Hz	= 4,
    AFE_HPF_ECG_1d0Hz	= 5,
    AFE_HPF_ECG_0d3Hz	= 6,
    AFE_HPF_ECG_3d0Hz	= 7,
    AFE_RLD_EMG2_OFF	= 8,
    AFE_RLD_EMG2_ON		= 9,
    AFE_RLD_EMG1_OFF	= 10,
    AFE_RLD_EMG1_ON		= 11,
    AFE_RLD_ECG1_OFF	= 12,
    AFE_RLD_ECG1_ON		= 13,
    AFE_RLD_ECG2_OFF	= 14,
    AFE_RLD_ECG2_ON		= 15,
    AFE_Ku_EMG1_1000	= 16,
    AFE_Ku_EMG1_100		= 17,
    AFE_Ku_EMG2_1000	= 18,
    AFE_Ku_EMG2_100		= 19,
    AFE_Ku_ECG1_1000	= 20,
    AFE_Ku_ECG1_100		= 21,
    AFE_Ku_ECG2_1000	= 22,
    AFE_Ku_ECG2_100		= 23,
    AFE_LPF_ECG_40Hz	= 24,
    AFE_LPF_ECG_100Hz	= 25,
    AFE_LPF_ECG_70Hz	= 26,
    AFE_LPF_ECG_150Hz	= 27,
    AFE_LPF_EMG_30Hz	= 28,
    AFE_LPF_EMG_1000Hz	= 29,
    AFE_LPF_EMG_400Hz	= 30,
    AFE_LPF_EMG_3000Hz	= 31,
} AFE_Data_TypeDef;

void AFE_process(void);

AFE_Data_TypeDef AFE_get(AFE_Reg_TypeDef AFE_reg);
AFE_StateTypeDef AFE_set(AFE_Reg_TypeDef reg, AFE_Data_TypeDef data);

