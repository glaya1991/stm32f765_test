#include "text.h"

char _cp437 = 0;

short cursorX = 0,
    cursorY = 0;

char textSize = 1;

char wrap = 1;

short textColor   = RED,
    textBgColor = TRANSPARENT_COLOR;

inline static void LCD_drawChar(short x0, short y0, unsigned char c, short color, short bg, uint8_t size) {
    short scaledWidth       = (short) (size * 6),
        doubleScaledWidth = scaledWidth * size;

    short x1 = (short) (x0 + scaledWidth - 1),
        y1 = (short) (y0 + 8 * size - 1);

    short doubleSize = size * size;
    short count      = (short) (48 * doubleSize);

    short charPixels[count];

    short mx, my;
    char  i, j, sx, sy;
    char  line;
    short pixelColor;

    if (x0 >= LCD_getWidth() || y0 >= LCD_getHeight() || x1 < 0 || y1 < 0) return;

    if (!_cp437 && (c >= 176)) c++; // Handle 'classic' charset behavior

    short characterNumber = (short) (c * 5);

    if (bg == TRANSPARENT_COLOR) {
        LCD_readPixels(x0, y0, x1, y1, charPixels);
    }

    LCD_setAddressWindowToWrite(x0, y0, x1, y1);

    for (i = 0; i < 6; i++) {
        line = (char) (i < 5 ? pgm_read_byte(font + characterNumber + i) : 0x0);
        my   = (short) (i * size);


        for (j = 0; j < 8; j++, line >>= 1) {
            mx = (short) (j * doubleScaledWidth);

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

void LCD_setCursor(short x, short y) {
    cursorX = x;
    cursorY = y;
}

void LCD_setTextSize(char size) {
    textSize = size;
}

void LCD_setTextColor(short color) {
    textColor = color;
}

void LCD_setTextBgColor(short color) {
    textBgColor = color;
}

short LCD_getCursorX() {
    return cursorX;
}

short LCD_getCursorY() {
    return cursorY;
}
