#include "all.h"

//==================================================
// Internal Variables
//==================================================
bool clockScreenBegin()
{
    topBarSetTitle("Clock");

    return true;
}
void clockScreenUpdate()
{
    if (buttonWasPressed())
    {
        uiNextScreen();
    }

    clockUpdate();

    animationUpdate();

    popupUpdate();

    topBarUpdate();
}
void clockScreenDraw()
{
    displayClear();

    topBarDraw();

    displaySetTextSize(4);

    widgetDrawCenteredText(
        80,
        clockGetTimeString()
    );

    displaySetTextSize(2);

    widgetDrawCenteredText(
        150,
        "Digital Clock"
    );

    popupDraw();
}