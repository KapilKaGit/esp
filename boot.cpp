#include "all.h"

//==================================================
// Internal Variables
//==================================================

static bool bootDone = false;

static unsigned long bootStartTime = 0;

static const unsigned long BOOT_DURATION = 3000;
bool bootBegin()
{
    bootDone = false;
    bootStartTime = millis();

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

    widgetDrawCenteredText(130, "CYBERKEY");

    displaySetTextSize(1);
    widgetDrawCenteredText(155, FIRMWARE_VERSION);

    widgetDrawProgressBar(
        40,
        220,
        160,
        12,
        (uint8_t)(animationProgress() * 100.0f)
    );
}
