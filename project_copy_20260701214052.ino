#include "all.h"

//==================================================
// Setup
//==================================================

void setup()
{
    Serial.begin(115200);

    buttonBegin();
    displayBegin();
    batteryBegin();
    clockBegin();
    mpuBegin();
    bitmapBegin();
    animationBegin();
    popupBegin();
    topBarBegin();
    themeBegin();

    uiBegin();

    bootBegin();
    homeBegin();
    galleryBegin();
    clockScreenBegin();
    sensorBegin();
    levelBegin();
    stopwatchBegin();
    settingsBegin();
    aboutBegin();
}

//==================================================
// Main Loop
//==================================================

void loop()
{
    buttonUpdate();

    uiUpdate();

    uiDraw();
}