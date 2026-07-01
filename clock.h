#ifndef CLOCK_H
#define CLOCK_H

#include "all.h"

//==================================================
// Clock
//==================================================

bool clockBegin();

void clockUpdate();

void clockSetTime(uint8_t hour, uint8_t minute, uint8_t second);

void clockGetTime(uint8_t &hour, uint8_t &minute, uint8_t &second);

const char* clockGetTimeString();

#endif