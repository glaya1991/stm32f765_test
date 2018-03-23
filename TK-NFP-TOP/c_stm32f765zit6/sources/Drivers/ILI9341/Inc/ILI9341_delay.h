#ifndef DELAY_H
#define DELAY_H

#define DELAY_TEST for(uint16_t i=0;i<10000;i++);

#include "stm32f7xx_hal.h"
//#include "stm32f7xx_hal_dma.h"
//include "ILI9341_config.h"

void delay_us(uint32_t time);
void delay_ms(uint32_t time);

#endif	/* DELAY_H */
