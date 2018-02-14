#include "stm32f4xx_hal.h"

typedef enum
{
	Switch_STATE_OK = 0,
	Switch_STATE_BUSY = 1,
	Switch_STATE_ERROR = 2
} Switch_State_TypeDef;


typedef enum
{
    SW_RESET		= 0,
	SW_Strap1_IMP	= 1,
	SW_Strap2_IMP	= 2,
	SW_ECG_IMP		= 3,
	SW_EMG_IMP		= 4,
	SW_Strap1_ECG12	= 5,
	SW_Strap2_ECG12	= 6,
	SW_ExtECG_ECG12	= 7,
	SW_Strap1_EMG1	= 8,
	SW_Strap2_EMG2	= 9,
	SW_ExtEMG_EMG12	= 10,
	SW_Strap1_ECG12_ExtEMG_EMG12	= 11,
	SW_Strap2_ECG12_ExtEMG_EMG12	= 12,
	SW_Strap1_EMG1_ExtECG_ECG12		= 13,
	SW_Strap2_EMG2_ExtECG_ECG12		= 14,
	SW_ExtECG_ECG12_ExtEMG_EMG12	= 15,
    SW_Zero_ECG12	= 16,
	SW_Zero_EMG1	= 17,
	SW_Zero_EMG2	= 18,
} Switch_Mode_TypeDef;

void Switch_process(void);
Switch_Mode_TypeDef Switch_get(void);
Switch_State_TypeDef Switch_set(Switch_Mode_TypeDef mode);

