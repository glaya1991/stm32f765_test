#include "graph.h"

void LCD_readPixels(short x1, short y1, short x2, short y2, short *buf) {
    char  red, green, blue;
    int count = (int) ((x2 - x1 + 1) * (y2 - y1 + 1));

    LCD_setAddressWindowToRead(x1, y1, x2, y2);

    TFT_CS_RESET;
    TFT_DC_SET;

    dmaReceiveDataCont8(&red);

    for (int i = 0; i < count; ++i) {
        dmaReceiveDataCont8(&red);
        dmaReceiveDataCont8(&green);
        dmaReceiveDataCont8(&blue);

        buf[i] = (short) ILI9341_COLOR(red, green, blue);
    }

    TFT_CS_SET;
}

inline void LCD_fillRect(short x1, short y1, short w, short h, short color) {
    int count = w * h;
    LCD_setAddressWindowToWrite(x1, y1, (short) (x1 + w - 1), (short) (y1 + h - 1));
    LCD_setSpi16();
    dmaFill16(color, count);
    LCD_setSpi8();
}

void LCD_fillScreen(short color) {
    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), color);
}

inline void LCD_drawFastHLine(short x0, short y0, short w, short color) {
    if (w == 1) {
        LCD_putPixel(x0, y0, color);
        return;
    }
    LCD_fillRect(x0, y0, w, 1, color);
}

inline void LCD_putPixel(short x, short y, short color) {
    LCD_setAddressWindowToWrite(x, y, x, y);
    LCD_setSpi16();
    dmaFill16(color, 1);
    LCD_setSpi8();
}

inline static void LCD_putPixelCont(short x, short y, short color) {
    LCD_setAddressWindowToWrite(x, y, x, y);
    dmaFill16(color, 1);
}

inline void LCD_drawFastVLine(short x0, short y0, short h, short color) {
    if (h == 1) {
        LCD_putPixel(x0, y0, color);
        return;
    }
    LCD_fillRect(x0, y0, 1, h, color);
}

void LCD_drawCircle(short x0, short y0, short r, short color) {
    if (r == 0) {
        LCD_putPixel(x0, y0, color);
        return;
    }

    short f  = (short) (1 - r),
        dx = 1,
        dy = (short) (-2 * r),
        x  = 0;

    short y = r;

    LCD_setSpi16();
    
    LCD_putPixelCont(x0, y0 + r, color);
    LCD_putPixelCont(x0, y0 - r, color);
    LCD_putPixelCont(x0 + r, y0, color);
    LCD_putPixelCont(x0 - r, y0, color);

    while (x < y) {
        if (f >= 0) {
            y--;
            dy += 2;
            f += dy;
        }
        x++;
        dx += 2;
        f += dx;

        LCD_putPixelCont(x0 + x, y0 + y, color);
        LCD_putPixelCont(x0 - x, y0 + y, color);
        LCD_putPixelCont(x0 + x, y0 - y, color);
        LCD_putPixelCont(x0 - x, y0 - y, color);
        LCD_putPixelCont(x0 + y, y0 + x, color);
        LCD_putPixelCont(x0 - y, y0 + x, color);
        LCD_putPixelCont(x0 + y, y0 - x, color);
        LCD_putPixelCont(x0 - y, y0 - x, color);
    }

    LCD_setSpi8();
}

// Used to do circles and roundrects
void LCD_fillCircleHelper(short x0, short y0, short r, char cornername, short delta, short color) {
    if (r == 0)
        return;
    if (r == 1) {
        LCD_putPixel(x0, y0, color);
        return;
    }
    short f  = (short) (1 - r),
        dx = 1,
        dy = (short) (-2 * r),
        x  = 0;

    short y = r;

    while (x < y) {
        if (f >= 0) {
            y--;
            dy += 2;
            f += dy;
        }
        x++;
        dx += 2;
        f += dx;

        if (cornername & 0x1) {
            LCD_drawFastVLine(x0 + x, y0 - y, (short) (2 * y + 1 + delta), color);
            LCD_drawFastVLine(x0 + y, y0 - x, (short) (2 * x + 1 + delta), color);
        }
        if (cornername & 0x2) {
            LCD_drawFastVLine(x0 - x, y0 - y, (short) (2 * y + 1 + delta), color);
            LCD_drawFastVLine(x0 - y, y0 - x, (short) (2 * x + 1 + delta), color);
        }
    }
}

void LCD_fillCircle(short x0, short y0, short r, short color) {
    LCD_drawFastVLine(x0, y0 - r, (short) (2 * r + 1), color);
    LCD_fillCircleHelper(x0, y0, r, 3, 0, color);
}

void LCD_drawLine(short x0, short y0, short x1, short y1, short color) {
    short Dx = (short) abs(x1 - x0),
        Dy = (short) abs(y1 - y0);

    if (Dx == 0 && Dy == 0) {
        LCD_putPixel(x0, y0, color);
        return;
    }

    short steep = Dy > Dx;
    short dx, dy, err, yStep;

    if (steep) {
        _int16_swap(x0, y0);
        _int16_swap(x1, y1);
    }

    if (x0 > x1) {
        _int16_swap(x0, x1);
        _int16_swap(y0, y1);
    }

    dx = x1 - x0;
    dy = (short) abs(y1 - y0);

    err = (short) (dx / 2);

    if (y0 < y1) {
        yStep = 1;
    } else {
        yStep = -1;
    }

    for (; x0 <= x1; x0++) {
        if (steep) {
            LCD_putPixel(y0, x0, color);
        } else {
            LCD_putPixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += yStep;
            err += dx;
        }
    }
}

void LCD_drawRect(short x, short y, short w, short h, short color) {
    if (w == 0 || h == 0) return;
    if (w == 1) {
        LCD_drawFastVLine(x, y, h, color);
        return;
    }
    if (h == 1) {
        LCD_drawFastHLine(x, y, w, color);
        return;
    }
    LCD_drawFastHLine(x, y, w, color);
    LCD_drawFastHLine(x, (short) (y + h - 1), w, color);
    LCD_drawFastVLine(x, y, h, color);
    LCD_drawFastVLine((short) (x + w - 1), y, h, color);
}

void LCD_setVerticalScrolling(short startY, short endY) {
    dmaSendCmd(LCD_VSCRDEF);
    short d[] = {
            startY,
            (short) (LCD_PIXEL_HEIGHT - startY - endY),
            endY
    };
    LCD_setSpi16();
    dmaSendData16(d, 3);
    LCD_setSpi8();
}

void LCD_scroll(short v) {
    dmaSendCmd(LCD_VSCRSADD);
    LCD_setSpi16();
    dmaSendData16(&v, 1);
    LCD_setSpi8();
}

