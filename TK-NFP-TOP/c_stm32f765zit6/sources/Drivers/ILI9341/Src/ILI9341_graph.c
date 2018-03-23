#include "ILI9341_graph.h"

void LCD_readPixels(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t *buf) {
    uint8_t  red, green, blue;
    uint32_t count = (uint32_t) ((x2 - x1 + 1) * (y2 - y1 + 1));

    LCD_setAddressWindowToRead(x1, y1, x2, y2);

    TFT_CS_RESET;
    TFT_DC_SET;

    dmaReceiveDataCont8(&red);

    for (uint32_t i = 0; i < count; ++i) {
        dmaReceiveDataCont8(&red);
        dmaReceiveDataCont8(&green);
        dmaReceiveDataCont8(&blue);

        buf[i] = (uint16_t) ILI9341_COLOR(red, green, blue);
    }

    TFT_CS_SET;
}

inline void LCD_fillRect(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t color) {
    uint32_t count = w * h;
    LCD_setSpi8();
    LCD_setAddressWindowToWrite(x1, y1, (uint16_t) (x1 + w - 1), (uint16_t) (y1 + h - 1));
    LCD_setSpi16();
    dmaFill16(color, count);
    LCD_setSpi8();
}

void LCD_fillScreen(uint16_t color) {  
    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), color);
    //LCD_fillRect(0, 0, 100, 100, color);
}

inline void LCD_drawFastHLine(uint16_t x0, uint16_t y0, uint16_t w, uint16_t color) {
    if (w == 1) {
        LCD_putPixel(x0, y0, color);
        return;
    }
    LCD_fillRect(x0, y0, w, 1, color);
}

inline void LCD_putPixel(uint16_t x, uint16_t y, uint16_t color) {
    LCD_setSpi8();
    LCD_setAddressWindowToWrite(x, y, x, y);
    LCD_setSpi16();
    dmaFill16(color, 1);
    LCD_setSpi8();
}

inline static void LCD_putPixelCont(uint16_t x, uint16_t y, uint16_t color) {
    LCD_setSpi8();
    LCD_setAddressWindowToWrite(x, y, x, y);
    LCD_setSpi16();
    dmaFill16(color, 1);
}

inline void LCD_drawFastVLine(uint16_t x0, uint16_t y0, uint16_t h, uint16_t color) {
    if (h == 1) {
        LCD_putPixel(x0, y0, color);
        return;
    }
    LCD_fillRect(x0, y0, 1, h, color);
}

void LCD_drawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color) {
    if (r == 0) {
        LCD_putPixel(x0, y0, color);
        return;
    }

    int16_t f  = (int16_t) (1 - r),
        dx = 1,
        dy = (int16_t) (-2 * r),
        x  = 0;

    uint16_t y = r;

    //LCD_setSpi16();
    
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
void LCD_fillCircleHelper(uint16_t x0, uint16_t y0, uint16_t r, uint8_t cornername, int16_t delta, uint16_t color) {
    if (r == 0)
        return;
    if (r == 1) {
        LCD_putPixel(x0, y0, color);
        return;
    }
    int16_t f  = (int16_t) (1 - r),
        dx = 1,
        dy = (int16_t) (-2 * r),
        x  = 0;

    uint16_t y = r;

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
            LCD_drawFastVLine(x0 + x, y0 - y, (uint16_t) (2 * y + 1 + delta), color);
            LCD_drawFastVLine(x0 + y, y0 - x, (uint16_t) (2 * x + 1 + delta), color);
        }
        if (cornername & 0x2) {
            LCD_drawFastVLine(x0 - x, y0 - y, (uint16_t) (2 * y + 1 + delta), color);
            LCD_drawFastVLine(x0 - y, y0 - x, (uint16_t) (2 * x + 1 + delta), color);
        }
    }
}

void LCD_fillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color) {
    LCD_drawFastVLine(x0, y0 - r, (uint16_t) (2 * r + 1), color);
    LCD_fillCircleHelper(x0, y0, r, 3, 0, color);
}

void LCD_drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color) {
    int16_t Dx = (int16_t) abs(x1 - x0),
        Dy = (int16_t) abs(y1 - y0);

    if (Dx == 0 && Dy == 0) {
        LCD_putPixel(x0, y0, color);
        return;
    }

    int16_t steep = Dy > Dx;
    int16_t dx, dy, err, yStep;

    if (steep) {
        _int16_swap(x0, y0);
        _int16_swap(x1, y1);
    }

    if (x0 > x1) {
        _int16_swap(x0, x1);
        _int16_swap(y0, y1);
    }

    dx = x1 - x0;
    dy = (int16_t) abs(y1 - y0);

    err = (int16_t) (dx / 2);

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

void LCD_drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) {
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
    LCD_drawFastHLine(x, (uint16_t) (y + h - 1), w, color);
    LCD_drawFastVLine(x, y, h, color);
    LCD_drawFastVLine((uint16_t) (x + w - 1), y, h, color);
}

void LCD_setVerticalScrolling(uint16_t startY, uint16_t endY) {
    dmaSendCmd(LCD_VSCRDEF);
    uint16_t d[] = {
            startY,
            (uint16_t) (LCD_PIXEL_HEIGHT - startY - endY),
            endY
    };
    LCD_setSpi16();
    dmaSendData16(d, 3);
    LCD_setSpi8();
}

void LCD_scroll(uint16_t v) {
    dmaSendCmd(LCD_VSCRSADD);
    LCD_setSpi16();
    dmaSendData16(&v, 1);
    LCD_setSpi8();
}

