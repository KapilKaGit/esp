#include "all.h"

//==================================================
// Internal Variables
//==================================================

static bool bootDone = false;

static unsigned long bootStartTime = 0;

static const unsigned long BOOT_DURATION = 3000;
static bool bootFrameDrawn = false;
static uint8_t lastBootPercent = 255;

bool bootBegin()
{
    bootDone = false;
    bootStartTime = millis();
    bootFrameDrawn = false;
    lastBootPercent = 255;

    animationStart(BOOT_DURATION);

    return true;
}

bool bootFinished()
{
    return bootDone;
}
void bootUpdate()
{
    animationUpdate();

    if (millis() - bootStartTime >= BOOT_DURATION)
    {
        bootDone = true;
    }
}
void bootDraw()
{
    uint8_t percent = (uint8_t)(animationProgress() * 100.0f);

    if (percent > 100)
    {
        percent = 100;
    }

    if (!bootFrameDrawn)
    {
        displayClear();

        const Bitmap *logo = bitmapGetBootLogo();

        if (logo != nullptr)
        {
            widgetDrawBitmap(
                (SCREEN_WIDTH - logo->width) / 2,
                40,
                logo
            );
        }

        displaySetTextSize(2);
        widgetDrawCenteredText(130, "CYBERKEY");

        displaySetTextSize(1);
        widgetDrawCenteredText(155, FIRMWARE_VERSION);

        bootFrameDrawn = true;
    }

    if (percent != lastBootPercent)
    {
        displayFillRect(40, 220, 200, 16, COLOR_BLACK);
        widgetDrawProgressBar(40, 220, 160, 12, percent);
        lastBootPercent = percent;
    }
}
