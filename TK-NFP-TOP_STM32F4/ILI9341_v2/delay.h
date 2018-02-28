#ifndef DELAY_H
#define DELAY_H

#include "stm32f4xx_hal_dma.h"

void delay_us(uint32_t time);
void delay_ms(uint32_t time);

#endif	/* DELAY_H */
