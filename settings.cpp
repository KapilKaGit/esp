#include "all.h"

//==================================================
// Internal Variables
//==================================================

static uint8_t currentSetting = 0;

static const char *settingsMenu[] =
{
    "Brightness",
    "Theme",
    "About"
};

//==================================================
// Settings Functions
//==================================================

bool settingsBegin()
{
    topBarSetTitle("Settings");

    currentSetting = 0;

    return true;
}

void settingsUpdate()
{
    if (buttonWasLongPressed())
    {
        uiNextScreen();
        return;
    }
    else if (buttonWasPressed())
    {
        currentSetting++;

        if (currentSetting >= 3)
        {
            currentSetting = 0;
        }

        uiRequestRedraw();
    }

    animationUpdate();

    popupUpdate();

    topBarUpdate();
}

void settingsDraw()
{
    displayClear();

    topBarDraw();

    widgetDrawTitle("Settings");

    for (uint8_t i = 0; i < 3; i++)
    {
        widgetDrawMenuItem(
            20,
            50 + (i * 50),
            200,
            40,
            settingsMenu[i],
            (i == currentSetting)
        );
    }

    popupDraw();
}