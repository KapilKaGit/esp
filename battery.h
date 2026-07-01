#ifndef BATTERY_H
#define BATTERY_H

#include "all.h"

//==================================================
// Battery
//==================================================

bool batteryBegin();

void batteryUpdate();

uint8_t batteryGetPercent();

float batteryGetVoltage();

bool batteryIsLow();

#endif