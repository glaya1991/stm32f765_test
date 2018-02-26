#include "stm32f4xx_hal.h"

typedef enum
{
	MUX_STATE_OK = 0,
	MUX_STATE_BUSY = 1,
	MUX_STATE_ERROR = 2
} MUX_State_TypeDef;


typedef enum
{
	MUX_RESET_ALL	= 0,
	MUX_Strap1_IMP	= 1,
	MUX_Strap2_IMP	= 2,
	MUX_ECG_IMP		= 3,
	MUX_EMG_IMP		= 4,
	MUX_Strap1_ECG12	= 5,
	MUX_Strap2_ECG12	= 6,
	MUX_ExtECG_ECG12	= 7,
	MUX_Strap1_EMG1		= 8,
	MUX_Strap2_EMG2		= 9,
	MUX_ExtEMG_EMG12	= 10,
	MUX_Strap1_ECG12_ExtEMG_EMG12	= 11,
	MUX_Strap2_ECG12_ExtEMG_EMG12	= 12,
	MUX_Strap1_EMG1_ExtECG_ECG12	= 13,
	MUX_Strap2_EMG2_ExtECG_ECG12	= 14,
	MUX_ExtECG_ECG12_ExtEMG_EMG12	= 15,
	MUX_Zero_ECG12	= 16,
	MUX_Zero_EMG1	= 17,
	MUX_Zero_EMG2	= 18,
} MUX_Mode_TypeDef;

MUX_State_TypeDef MUX_process(void);
MUX_Mode_TypeDef MUX_get(void);
MUX_State_TypeDef MUX_set(MUX_Mode_TypeDef mode);
uint8_t MUX_get_AF(void);
