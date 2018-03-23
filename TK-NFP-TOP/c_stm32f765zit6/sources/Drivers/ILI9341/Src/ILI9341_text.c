#include "ILI9341_text.h"

uint8_t _cp437 = 0;

uint16_t cursorX = 0,
    cursorY = 0;

uint8_t textSize = 1;

uint8_t wrap = 1;

uint16_t textColor   = RED,
    textBgColor = TRANSPARENT_COLOR;

inline static void LCD_drawChar(uint16_t x0, uint16_t y0, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) {
    uint16_t scaledWidth       = (uint16_t) (size * 6),
        doubleScaledWidth = scaledWidth * size;

    uint16_t x1 = (uint16_t) (x0 + scaledWidth - 1),
        y1 = (uint16_t) (y0 + 8 * size - 1);

    uint16_t doubleSize = size * size;
    uint16_t count      = (uint16_t) (48 * doubleSize);

    uint16_t charPixels[count];

    uint16_t mx, my;
    int8_t  i, j, sx, sy;
    uint8_t  line;
    uint16_t pixelColor;

    if (x0 >= LCD_getWidth() || y0 >= LCD_getHeight() || x1 < 0 || y1 < 0) return;

    if (!_cp437 && (c >= 176)) c++; // Handle 'classic' charset behavior

    uint16_t characterNumber = (uint16_t) (c * 5);

    if (bg == TRANSPARENT_COLOR) {
        LCD_readPixels(x0, y0, x1, y1, charPixels);
    }

    LCD_setAddressWindowToWrite(x0, y0, x1, y1);

    for (i = 0; i < 6; i++) {
        line = (uint8_t) (i < 5 ? pgm_read_byte(font + characterNumber + i) : 0x0);
        my   = (uint16_t) (i * size);


        for (j = 0; j < 8; j++, line >>= 1) {
            mx = (uint16_t) (j * doubleScaledWidth);

            pixelColor = line & 0x1 ? color : bg;

            if (pixelColor == TRANSPARENT_COLOR) continue;

            for (sx = 0; sx < size; ++sx) {
                for (sy = 0; sy < size; ++sy) {
                    charPixels[mx + my + sy * scaledWidth + sx] = pixelColor;
                }
            }
        }
    }

    LCD_setSpi16();
    dmaSendData16(charPixels, count);
    LCD_setSpi8();
}

inline void LCD_write(unsigned char c) {
    if (c == '\n') {
        cursorY += textSize * 8;
        cursorX = 0;
    } else if (c == '\r') {
        cursorX = 0;
    } else {
        if (wrap && ((cursorX + textSize * 6) >= LCD_getWidth())) { // Heading off edge?
            cursorX = 0;            // Reset x to zero
            cursorY += textSize * 8; // Advance y one line
        }
        LCD_drawChar(cursorX, cursorY, c, textColor, textBgColor, textSize);
        cursorX += textSize * 6;
    }
}

void LCD_writeString(unsigned char *s) {
    while (*(s)) LCD_write(*s++);
}

void LCD_setCursor(uint16_t x, uint16_t y) {
    cursorX = x;
    cursorY = y;
}

void LCD_setTextSize(uint8_t size) {
    textSize = size;
}

void LCD_setTextColor(uint16_t color) {
    textColor = color;
}

void LCD_setTextBgColor(uint16_t color) {
    textBgColor = color;
}

uint16_t LCD_getCursorX() {
    return cursorX;
}

uint16_t LCD_getCursorY() {
    return cursorY;
}
