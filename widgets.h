#ifndef WIDGETS_H
#define WIDGETS_H

#include "all.h"

void widgetDrawFrame(int16_t x,
                     int16_t y,
                     int16_t w,
                     int16_t h);

void widgetDrawTitle(const char *title);

void widgetDrawText(int16_t x,
                    int16_t y,
                    const char *text);

void widgetDrawCenteredText(int16_t y,
                            const char *text);

void widgetDrawCard(int16_t x,
                    int16_t y,
                    int16_t w,
                    int16_t h);

void widgetDrawValueBox(int16_t x,
                        int16_t y,
                        int16_t w,
                        int16_t h,
                        const char *title,
                        const char *value);

void widgetDrawStatusBox(int16_t x,
                         int16_t y,
                         int16_t w,
                         int16_t h,
                         const char *text);

void widgetDrawProgressBar(int16_t x,
                           int16_t y,
                           int16_t w,
                           int16_t h,
                           uint8_t percent);

void widgetDrawMenuItem(int16_t x,
                        int16_t y,
                        int16_t w,
                        int16_t h,
                        const char *text,
                        bool selected);

void widgetDrawBitmap(int16_t x,
                      int16_t y,
                      const Bitmap *bitmap);

void widgetDrawIcon(int16_t x,
                    int16_t y,
                    const uint16_t *icon,
                    uint16_t width,
                    uint16_t height);

void widgetDrawPopup(const char *title,
                     const char *message);

void widgetDrawNotification(const char *message);

#endif