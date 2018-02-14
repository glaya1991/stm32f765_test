#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "ADG2128.h"

#define	AFE_HPF_EMG	((uint16_t)0x0003)
#define	AFE_HPF_ECG	((uint16_t)0x000C)
#define	AFE_RLD		((uint16_t)0x00F0)
#define	AFE_Ku		((uint16_t)0x0F00)
#define	AFE_LPF_ECG	((uint16_t)0x3000)
#define	AFE_LPF_EMG	((uint16_t)0xC000)


void Switch_process(void)
{
	;
}

Switch_Mode_TypeDef Switch_get(void)
{
	;
}

Switch_State_TypeDef Switch_set(Switch_Mode_TypeDef mode)
{
	;
}
