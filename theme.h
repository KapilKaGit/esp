#ifndef THEME_H
#define THEME_H

#include "all.h"

//==================================================
// Colors (RGB565)
//==================================================

#define COLOR_BACKGROUND     0x0000
#define COLOR_PRIMARY        0x07FF
#define COLOR_SECONDARY      0xFFFF
#define COLOR_TEXT           0xFFFF
#define COLOR_CARD           0x18C3
#define COLOR_BORDER         0x39E7
#define COLOR_SUCCESS        0x07E0
#define COLOR_WARNING        0xFFE0
#define COLOR_ERROR          0xF800

//==================================================
// Layout
//==================================================

#define TOPBAR_HEIGHT        30

#define CARD_RADIUS          6

#define SCREEN_PADDING       10

#define MENU_ITEM_HEIGHT     40

//==================================================
// Text
//==================================================

#define TEXT_SMALL           1
#define TEXT_MEDIUM          2
#define TEXT_LARGE           3

//==================================================
// Theme Functions
//==================================================

bool themeBegin();

#endif