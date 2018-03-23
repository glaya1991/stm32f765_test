#ifndef TEST1_TEXT_H
#define TEST1_TEXT_H

#include "ILI9341_graph.h"
#include "../fonts/glcdfont.h"

#define TRANSPARENT_COLOR CYAN

#define pgm_read_word(addr) (*(const unsigned short *)(addr))
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define pgm_read_pointer(addr) ((void *)pgm_read_word(addr))

void LCD_write(unsigned char c);
void LCD_writeString(unsigned char *s);
void LCD_writeString2(unsigned char *string);

void LCD_setCursor(uint16_t x, uint16_t y);
void LCD_setTextSize(uint8_t size);
void LCD_setTextColor(uint16_t color);
void LCD_setTextBgColor(uint16_t color);

uint16_t LCD_getCursorX();
uint16_t LCD_getCursorY();

#endif //TEST1_TEXT_H
