#ifndef TOPBAR_H
#define TOPBAR_H

#include "all.h"

//==================================================
// Top Bar
//==================================================

bool topBarBegin();

void topBarUpdate();

void topBarDraw();

void topBarSetTitle(const char *title);

const char *topBarGetTitle();

#endif