#include "all.h"

//==================================================
// About Functions
//==================================================

bool aboutBegin()
{
    topBarSetTitle("About");

    return true;
}

void aboutUpdate()
{
    if (buttonWasPressed())
    {
        uiNextScreen();
    }

    animationUpdate();

    popupUpdate();

    topBarUpdate();
}

void aboutDraw()
{
    displayClear();

    topBarDraw();

    widgetDrawTitle("About");

    widgetDrawCenteredText(
        60,
        "ESP32-S3 Keychain"
    );

    widgetDrawCenteredText(
        90,
        FIRMWARE_VERSION
    );

    widgetDrawCenteredText(
        120,
        "Developed by"
    );

    widgetDrawCenteredText(
        145,
        "Kapil"
    );

    widgetDrawCenteredText(
        190,
        "2026"
    );

    popupDraw();
}