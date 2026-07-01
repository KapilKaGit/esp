#ifndef UI_H
#define UI_H

#include "all.h"

//==================================================
// Screen IDs
//==================================================

enum UIScreen
{
    UI_SCREEN_BOOT = 0,
    UI_SCREEN_HOME,
    UI_SCREEN_GALLERY,
    UI_SCREEN_CLOCK,
    UI_SCREEN_SENSOR,
    UI_SCREEN_LEVEL,
    UI_SCREEN_STOPWATCH,
    UI_SCREEN_SETTINGS,
    UI_SCREEN_ABOUT,

    UI_SCREEN_COUNT
};

//==================================================
// UI Manager
//==================================================

bool uiBegin();

void uiUpdate();

void uiDraw();

void uiSetScreen(uint8_t screen);

uint8_t uiGetScreen();

void uiNextScreen();

void uiPreviousScreen();

#endif