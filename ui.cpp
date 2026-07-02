#include "all.h"

//==================================================
// Internal Variables
//==================================================

static uint8_t currentScreen = UI_SCREEN_BOOT;
static bool redrawRequested = true;
static unsigned long lastRedrawRequestTime = 0;

static void uiApplyScreenTitle(uint8_t screen)
{
    switch (screen)
    {
        case UI_SCREEN_BOOT:
            topBarSetTitle("Boot");
            break;

        case UI_SCREEN_HOME:
            topBarSetTitle("Home");
            break;

        case UI_SCREEN_GALLERY:
            topBarSetTitle("Gallery");
            break;

        case UI_SCREEN_CLOCK:
            topBarSetTitle("Clock");
            break;

        case UI_SCREEN_SENSOR:
            topBarSetTitle("Sensors");
            break;

        case UI_SCREEN_LEVEL:
            topBarSetTitle("Level");
            break;

        case UI_SCREEN_STOPWATCH:
            topBarSetTitle("Stopwatch");
            break;

        case UI_SCREEN_SETTINGS:
            topBarSetTitle("Settings");
            break;

        case UI_SCREEN_ABOUT:
            topBarSetTitle("About");
            break;

        default:
            break;
    }
}

//==================================================
// UI Functions
//==================================================

bool uiBegin()
{
    currentScreen = UI_SCREEN_BOOT;
    redrawRequested = true;
    lastRedrawRequestTime = 0;
    uiApplyScreenTitle(currentScreen);
    return true;
}

void uiUpdate()
{
    switch (currentScreen)
    {
        case UI_SCREEN_BOOT:
            bootUpdate();
            uiRequestTimedRedraw(UI_REFRESH_TIME);
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
    if (!redrawRequested)
    {
        return;
    }

    redrawRequested = false;

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

void uiRequestRedraw()
{
    redrawRequested = true;
}

void uiRequestTimedRedraw(unsigned long interval)
{
    unsigned long now = millis();

    if ((now - lastRedrawRequestTime) >= interval)
    {
        redrawRequested = true;
        lastRedrawRequestTime = now;
    }
}

void uiSetScreen(uint8_t screen)
{
    if (screen < UI_SCREEN_COUNT && screen != currentScreen)
    {
        currentScreen = screen;
        uiApplyScreenTitle(currentScreen);
        uiRequestRedraw();
    }
}

uint8_t uiGetScreen()
{
    return currentScreen;
}

void uiNextScreen()
{
    uint8_t nextScreen = currentScreen + 1;

    if (nextScreen >= UI_SCREEN_COUNT)
    {
        nextScreen = UI_SCREEN_HOME;
    }

    uiSetScreen(nextScreen);
}

void uiPreviousScreen()
{
    if (currentScreen <= UI_SCREEN_HOME)
    {
        uiSetScreen(UI_SCREEN_ABOUT);
    }
    else
    {
        uiSetScreen(currentScreen - 1);
    }
}
