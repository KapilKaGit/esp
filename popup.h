#ifndef POPUP_H
#define POPUP_H

#include "all.h"

bool popupBegin();

void popupShow(const char *title,
               const char *message);

void popupHide();

void popupUpdate();

void popupDraw();

bool popupVisible();

#endif