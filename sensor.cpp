#include "all.h"

//==================================================
// Internal Variables
//==================================================

static float accelX = 0.0f;
static float accelY = 0.0f;
static float accelZ = 0.0f;
bool sensorBegin()
{
    topBarSetTitle("Sensors");

    accelX = 0.0f;
    accelY = 0.0f;
    accelZ = 0.0f;

    return true;
}
void sensorUpdate()
{
    if (buttonWasPressed())
    {
        uiNextScreen();
        return;
    }

    mpuUpdate();

    accelX = mpuGetAccelX();
    accelY = mpuGetAccelY();
    accelZ = mpuGetAccelZ();

    animationUpdate();

    popupUpdate();

    topBarUpdate();

    uiRequestTimedRedraw(100);
}
void sensorDraw()
{
    displayClear();

    topBarDraw();

    widgetDrawTitle("Sensors");

    char xText[10];
    char yText[10];
    char zText[10];

    snprintf(xText,
             sizeof(xText),
             "%.2f",
             accelX);

    snprintf(yText,
             sizeof(yText),
             "%.2f",
             accelY);

    snprintf(zText,
             sizeof(zText),
             "%.2f",
             accelZ);

    widgetDrawValueBox(
        10,
        45,
        220,
        50,
        "Accel X",
        xText
    );

    widgetDrawValueBox(
        10,
        105,
        220,
        50,
        "Accel Y",
        yText
    );

    widgetDrawValueBox(
        10,
        165,
        220,
        50,
        "Accel Z",
        zText
    );

    popupDraw();
}