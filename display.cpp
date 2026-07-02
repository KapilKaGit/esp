#include "display.h"
#include "pins.h"

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// Global display object
static Adafruit_ST7789 tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
static uint16_t currentTextColor = ST77XX_WHITE;

bool displayBegin()
{
    // Match the verified worked_display.ino startup timing before
    // the ST7789 receives any commands.
    delay(500);

    // Initialize display using the same constructor-provided SPI pins,
    // dimensions, rotation, and no explicit inversion command as the
    // verified sketch.
    tft.init(240, 320);
    tft.setRotation(0);

    currentTextColor = ST77XX_WHITE;

    return true;
}
void displayClear(uint16_t color)
{
    tft.fillScreen(color);

    // Reset cursor and default text settings
    tft.setCursor(0, 0);
    currentTextColor = ST77XX_WHITE;
    tft.setTextColor(currentTextColor);
    tft.setTextSize(1);
}
void displayFillScreen(uint16_t color)
{
    tft.fillScreen(color);
}
void displayDrawPixel(int16_t x, int16_t y, uint16_t color)
{
    tft.drawPixel(x, y, color);
}

void displayDrawLine(int16_t x0, int16_t y0,
                     int16_t x1, int16_t y1,
                     uint16_t color)
{
    tft.drawLine(x0, y0, x1, y1, color);
}

void displayDrawFastHLine(int16_t x,
                          int16_t y,
                          int16_t width,
                          uint16_t color)
{
    tft.drawFastHLine(x, y, width, color);
}

void displayDrawFastVLine(int16_t x,
                          int16_t y,
                          int16_t height,
                          uint16_t color)
{
    tft.drawFastVLine(x, y, height, color);
}

//====================================================
// Rectangles
//====================================================

void displayDrawRect(int16_t x,
                     int16_t y,
                     int16_t width,
                     int16_t height,
                     uint16_t color)
{
    tft.drawRect(x, y, width, height, color);
}

void displayFillRect(int16_t x,
                     int16_t y,
                     int16_t width,
                     int16_t height,
                     uint16_t color)
{
    tft.fillRect(x, y, width, height, color);
}

void displayDrawRoundRect(int16_t x,
                          int16_t y,
                          int16_t width,
                          int16_t height,
                          int16_t radius,
                          uint16_t color)
{
    tft.drawRoundRect(x, y, width, height, radius, color);
}

void displayFillRoundRect(int16_t x,
                          int16_t y,
                          int16_t width,
                          int16_t height,
                          int16_t radius,
                          uint16_t color)
{
    tft.fillRoundRect(x, y, width, height, radius, color);
}

//====================================================
// Circles
//====================================================

void displayDrawCircle(int16_t x,
                       int16_t y,
                       int16_t radius,
                       uint16_t color)
{
    tft.drawCircle(x, y, radius, color);
}

void displayFillCircle(int16_t x,
                       int16_t y,
                       int16_t radius,
                       uint16_t color)
{
    tft.fillCircle(x, y, radius, color);
}

//====================================================
// Triangles
//====================================================

void displayDrawTriangle(int16_t x0,
                         int16_t y0,
                         int16_t x1,
                         int16_t y1,
                         int16_t x2,
                         int16_t y2,
                         uint16_t color)
{
    tft.drawTriangle(x0, y0, x1, y1, x2, y2, color);
}

void displayFillTriangle(int16_t x0,
                         int16_t y0,
                         int16_t x1,
                         int16_t y1,
                         int16_t x2,
                         int16_t y2,
                         uint16_t color)
{
    tft.fillTriangle(x0, y0, x1, y1, x2, y2, color);
}

//====================================================
// Text
//====================================================

void displaySetCursor(int16_t x, int16_t y)
{
    tft.setCursor(x, y);
}

void displaySetTextSize(uint8_t size)
{
    tft.setTextSize(size);
}

void displaySetTextColor(uint16_t color)
{
    currentTextColor = color;
    tft.setTextColor(currentTextColor);
}

void displaySetBackground(uint16_t color)
{
    tft.setTextColor(currentTextColor, color);
}

//====================================================
// Display Info
//====================================================

int16_t displayWidth()
{
    return tft.width();
}

int16_t displayHeight()
{
    return tft.height();
}

void displaySetRotation(uint8_t rotation)
{
    tft.setRotation(rotation);
}
void displayDrawBitmap(
    int16_t x,
    int16_t y,
    int16_t width,
    int16_t height,
    const uint16_t *bitmap
)
{
    tft.drawRGBBitmap(x, y, bitmap, width, height);
}
void displayDrawMonoBitmap(
    int16_t x,
    int16_t y,
    const uint8_t *bitmap,
    int16_t width,
    int16_t height,
    uint16_t color
)
{
    tft.drawBitmap(x, y, bitmap, width, height, color);
}
void displayPrint(
    int16_t x,
    int16_t y,
    const char *text
)
{
    tft.setCursor(x, y);
    tft.print(text);
}

void displayPrintInt(
    int16_t x,
    int16_t y,
    int32_t value
)
{
    tft.setCursor(x, y);
    tft.print(value);
}

void displayPrintNumber(
    int16_t x,
    int16_t y,
    float value,
    uint8_t decimals
)
{
    tft.setCursor(x, y);
    tft.print(value, decimals);
}
void displaySleep()
{
    tft.enableDisplay(false);
}

void displayWake()
{
    tft.enableDisplay(true);
}

void displayUpdate()
{
    // Nothing to do.
    // Adafruit ST7789 draws directly to the display,
    // so no buffer needs to be flushed.
}