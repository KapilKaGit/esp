#include "all.h"

//==================================================
// Home Screen
//==================================================

bool homeBegin()
{
    topBarSetTitle("Home");
    return true;
}

void homeUpdate()
{
    if (buttonWasPressed())
    {
        uiNextScreen();
        return;
    }

    clockUpdate();

    mpuUpdate();

    batteryUpdate();

    animationUpdate();

    popupUpdate();

    topBarUpdate();

    uiRequestTimedRedraw(1000);
}

void homeDraw()
{
    displayClear();

    topBarDraw();

    widgetDrawTitle("Home");

    widgetDrawValueBox(
        10,
        45,
        105,
        60,
        "Time",
        clockGetTimeString()
    );

    char batteryText[8];

    snprintf(
        batteryText,
        sizeof(batteryText),
        "%u%%",
        batteryGetPercent()
    );

    widgetDrawValueBox(
        125,
        45,
        105,
        60,
        "Battery",
        batteryText
    );

    widgetDrawValueBox(
        10,
        120,
        220,
        60,
        "Screen",
        "Home"
    );

    popupDraw();
}