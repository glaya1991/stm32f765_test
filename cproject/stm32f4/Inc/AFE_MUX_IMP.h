#include "stm32f4xx_hal.h"

#define AFE_UART_DEBUG 0
#define MUX_UART_DEBUG 0
#define AFEMUX_UART_DEBUG 0
#define AFEMUX_MODES_DEBUG 0

typedef enum
{
	AFE_MUX_IMP_STATE_OK = 0,
	AFE_MUX_IMP_STATE_BUSY = 1,
	AFE_MUX_IMP_STATE_ERROR = 2
} AFE_MUX_IMP_State_TypeDef;


void AFE_MUX_IMP_init (void);
AFE_MUX_IMP_State_TypeDef AFE_MUX_IMP_process(void);
void AFEMUX_reset(void);
void AFEMUX_timer_callback(void);

