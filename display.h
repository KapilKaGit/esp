#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "config.h"

bool displayBegin();
void displayClear(uint16_t color = COLOR_BLACK);
void displayFillScreen(uint16_t color = COLOR_BLACK);
void displayUpdate();

void displayPrint(int16_t x, int16_t y, const char *text);
void displayPrintInt(int16_t x, int16_t y, int32_t value);
void displayPrintNumber(int16_t x, int16_t y, float value, uint8_t decimals);
void displaySetCursor(int16_t x, int16_t y);
void displaySetTextSize(uint8_t size);
void displaySetTextColor(uint16_t color = COLOR_WHITE);
void displaySetBackground(uint16_t color = COLOR_BLACK);

void displayDrawPixel(int16_t x, int16_t y, uint16_t color = COLOR_WHITE);
void displayDrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color = COLOR_WHITE);
void displayDrawFastHLine(int16_t x, int16_t y, int16_t width, uint16_t color = COLOR_WHITE);
void displayDrawFastVLine(int16_t x, int16_t y, int16_t height, uint16_t color = COLOR_WHITE);
void displayDrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color = COLOR_WHITE);
void displayFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color = COLOR_WHITE);
void displayDrawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t radius, uint16_t color = COLOR_WHITE);
void displayFillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t radius, uint16_t color = COLOR_WHITE);
void displayDrawCircle(int16_t x, int16_t y, int16_t radius, uint16_t color = COLOR_WHITE);
void displayFillCircle(int16_t x, int16_t y, int16_t radius, uint16_t color = COLOR_WHITE);
void displayDrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color = COLOR_WHITE);
void displayFillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color = COLOR_WHITE);

int16_t displayWidth();
int16_t displayHeight();
void displaySetRotation(uint8_t rotation);
void displayDrawBitmap(int16_t x, int16_t y, int16_t width, int16_t height, const uint16_t *bitmap);
void displayDrawMonoBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t width, int16_t height, uint16_t color = COLOR_WHITE);
void displaySleep();
void displayWake();

#endif
