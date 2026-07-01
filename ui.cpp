#include "all.h"

//==================================================
// Internal Variables
//==================================================

static uint8_t currentScreen = UI_SCREEN_BOOT;

//==================================================
// UI Functions
//==================================================

bool uiBegin()
{
    currentScreen = UI_SCREEN_BOOT;
    return true;
}

void uiUpdate()
{
    switch (currentScreen)
    {
        case UI_SCREEN_BOOT:
            bootUpdate();
            if (bootFinished())
            {
                uiSetScreen(UI_SCREEN_HOME);
            }
            break;

        case UI_SCREEN_HOME:
            homeUpdate();
            break;

        case UI_SCREEN_GALLERY:
            galleryUpdate();
            break;

        case UI_SCREEN_CLOCK:
            clockScreenUpdate();
            break;

        case UI_SCREEN_SENSOR:
            sensorUpdate();
            break;

        case UI_SCREEN_LEVEL:
            levelUpdate();
            break;

        case UI_SCREEN_STOPWATCH:
            stopwatchUpdate();
            break;

        case UI_SCREEN_SETTINGS:
            settingsUpdate();
            break;

        case UI_SCREEN_ABOUT:
            aboutUpdate();
            break;

        default:
            break;
    }
}

void uiDraw()
{
    switch (currentScreen)
    {
        case UI_SCREEN_BOOT:
            bootDraw();
            break;

        case UI_SCREEN_HOME:
            homeDraw();
            break;

        case UI_SCREEN_GALLERY:
            galleryDraw();
            break;

        case UI_SCREEN_CLOCK:
            clockScreenDraw();
            break;

        case UI_SCREEN_SENSOR:
            sensorDraw();
            break;

        case UI_SCREEN_LEVEL:
            levelDraw();
            break;

        case UI_SCREEN_STOPWATCH:
            stopwatchDraw();
            break;

        case UI_SCREEN_SETTINGS:
            settingsDraw();
            break;

        case UI_SCREEN_ABOUT:
            aboutDraw();
            break;

        default:
            break;
    }
}

void uiSetScreen(uint8_t screen)
{
    if (screen < UI_SCREEN_COUNT)
    {
        currentScreen = screen;
    }
}

uint8_t uiGetScreen()
{
    return currentScreen;
}

void uiNextScreen()
{
    currentScreen++;

    if (currentScreen >= UI_SCREEN_COUNT)
    {
        currentScreen = UI_SCREEN_HOME;
    }
}

void uiPreviousScreen()
{
    if (currentScreen <= UI_SCREEN_HOME)
    {
        currentScreen = UI_SCREEN_ABOUT;
    }
    else
    {
        currentScreen--;
    }
}