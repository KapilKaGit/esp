#include "all.h"
void widgetDrawFrame(int16_t x, int16_t y, int16_t w, int16_t h)
{
    displayDrawRect(x, y, w, h);
}

void widgetDrawText(int16_t x, int16_t y, const char *text)
{
    displayPrint(x, y, text);
}

void widgetDrawCenteredText(int16_t y, const char *text)
{
    int16_t x = (SCREEN_WIDTH - (strlen(text) * 12)) / 2;
    displayPrint(x, y, text);
}

void widgetDrawTitle(const char *title)
{
    displaySetTextSize(2);
    widgetDrawCenteredText(10, title);
    displaySetTextSize(1);
}

void widgetDrawCard(int16_t x, int16_t y, int16_t w, int16_t h)
{
    displayFillRoundRect(x, y, w, h, 6);
    displayDrawRoundRect(x, y, w, h, 6);
}

void widgetDrawStatusBox(int16_t x,
                         int16_t y,
                         int16_t w,
                         int16_t h,
                         const char *text)
{
    widgetDrawCard(x, y, w, h);
    widgetDrawCenteredText(y + (h / 2) - 4, text);
}

void widgetDrawBitmap(int16_t x,
                      int16_t y,
                      const Bitmap *bitmap)
{
    if (bitmap == nullptr)
    {
        return;
    }

    displayDrawBitmap(x,
                      y,
                      bitmap->width,
                      bitmap->height,
                      bitmap->data);
}

void widgetDrawIcon(int16_t x,
                    int16_t y,
                    const uint16_t *icon,
                    uint16_t width,
                    uint16_t height)
{
    displayDrawBitmap(x, y, width, height, icon);
}

void widgetDrawPopup(const char *title,
                     const char *message)
{
    widgetDrawCard(20, 80, 200, 120);

    widgetDrawCenteredText(95, title);
    widgetDrawCenteredText(125, message);
}

void widgetDrawNotification(const char *message)
{
    widgetDrawCard(10, 280, 220, 30);
    widgetDrawCenteredText(290, message);
}
void widgetDrawValueBox(int16_t x,
                        int16_t y,
                        int16_t w,
                        int16_t h,
                        const char *title,
                        const char *value)
{
    widgetDrawCard(x, y, w, h);

    displaySetTextSize(1);
    displayPrint(x + 8, y + 8, title);

    displaySetTextSize(2);
    displayPrint(x + 8, y + 28, value);

    displaySetTextSize(1);
}

void widgetDrawProgressBar(int16_t x,
                           int16_t y,
                           int16_t w,
                           int16_t h,
                           uint8_t percent)
{
    if (percent > 100)
    {
        percent = 100;
    }

    displayDrawRect(x, y, w, h);

    int16_t fillWidth = (w * percent) / 100;

    if (fillWidth > 0)
    {
        displayFillRect(x + 1,
                        y + 1,
                        fillWidth - 2,
                        h - 2);
    }

    displaySetTextSize(1);

    char text[5];
    snprintf(text, sizeof(text), "%u%%", percent);

    displayPrint(x + w + 5,
                 y + (h / 2) - 4,
                 text);
}
void widgetDrawMenuItem(int16_t x,
                        int16_t y,
                        int16_t w,
                        int16_t h,
                        const char *text,
                        bool selected)
{
    if (selected)
    {
        displayFillRoundRect(x, y, w, h, 6);
    }
    else
    {
        displayDrawRoundRect(x, y, w, h, 6);
    }

    displaySetTextSize(2);

    if (selected)
    {
        displaySetTextColor(COLOR_BLACK);
    }
    else
    {
        displaySetTextColor(COLOR_WHITE);
    }

    displayPrint(x + 10,
                 y + (h / 2) - 8,
                 text);

    displaySetTextSize(1);
    displaySetTextColor(COLOR_WHITE);
}
