#include "all.h"

//==================================================
// Internal Variables
//==================================================

static float pitch = 0.0f;

static float roll = 0.0f;
bool levelBegin()
{
    topBarSetTitle("Level");

    pitch = 0.0f;
    roll = 0.0f;

    return true;
}
void levelUpdate()
{
    if (buttonWasPressed())
    {
        uiNextScreen();
        return;
    }

    mpuUpdate();

    pitch = mpuGetPitch();
    roll = mpuGetRoll();

    animationUpdate();
    popupUpdate();
    topBarUpdate();

    uiRequestTimedRedraw(100);
}

void levelDraw()
{
    displayClear();

    topBarDraw();

    widgetDrawTitle("Level");

    char pitchText[10];
    char rollText[10];

    snprintf(pitchText,
             sizeof(pitchText),
             "%.1f",
             pitch);

    snprintf(rollText,
             sizeof(rollText),
             "%.1f",
             roll);

    widgetDrawValueBox(
        10,
        45,
        105,
        60,
        "Pitch",
        pitchText
    );

    widgetDrawValueBox(
        125,
        45,
        105,
        60,
        "Roll",
        rollText
    );

    displayDrawCircle(
        SCREEN_WIDTH / 2,
        220,
        40
    );

    displayFillCircle(
        (SCREEN_WIDTH / 2) + (int16_t)roll,
        220 - (int16_t)pitch,
        5
    );

    popupDraw();
}