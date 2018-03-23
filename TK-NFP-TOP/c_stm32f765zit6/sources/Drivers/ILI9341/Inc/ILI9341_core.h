#ifndef TEST1_ILI9341_CORE_H
#define TEST1_ILI9341_CORE_H

#include <stdint.h>
#include "stm32f7xx_hal.h"
//#include <stm32f7xx_hal_dma.h>
//#include <stm32f7xx_hal_spi.h>
#include "ILI9341_delay.h"
#include "ILI9341_commands.h"
#include "ILI9341_dma.h"

#define LCD_setAddressWindowToWrite(x1,y1,x2,y2) \
    LCD_setAddressWindow(x1, y1, x2, y2); \
    dmaSendCmd(LCD_GRAM)

#define LCD_setAddressWindowToRead(x1,y1,x2,y2) \
    LCD_setAddressWindow(x1, y1, x2, y2); \
    dmaSendCmd(LCD_RAMRD)

uint16_t LCD_getWidth();
uint16_t LCD_getHeight();

void LCD_init();

void LCD_setSpi8(void);
void LCD_setSpi16(void);

void LCD_setOrientation(uint8_t o);
void LCD_setAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

#endif //TEST1_ILI9341_CORE_H
