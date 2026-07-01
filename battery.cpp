#include "all.h"

//==================================================
// Internal Variables
//==================================================

static uint8_t batteryPercent = 100;

static float batteryVoltage = 4.20f;

static bool batteryLow = false;
bool batteryBegin()
{
    analogReadResolution(12);
#ifdef ADC_11db
    analogSetPinAttenuation(BATTERY_PIN, ADC_11db);
#endif
    batteryUpdate();
    return true;
}

uint8_t batteryGetPercent()
{
    return batteryPercent;
}

float batteryGetVoltage()
{
    return batteryVoltage;
}

bool batteryIsLow()
{
    return batteryLow;
}
void batteryUpdate()
{
    int adc = analogRead(BATTERY_PIN);

    batteryVoltage = ((float)adc / 4095.0f) * BATTERY_FULL_VOLTAGE;

    if (batteryVoltage >= BATTERY_FULL_VOLTAGE)
    {
        batteryPercent = 100;
    }
    else if (batteryVoltage <= BATTERY_EMPTY_VOLTAGE)
    {
        batteryPercent = 0;
    }
    else
    {
        batteryPercent =
            (uint8_t)(((batteryVoltage - BATTERY_EMPTY_VOLTAGE) * 100.0f) /
                      (BATTERY_FULL_VOLTAGE - BATTERY_EMPTY_VOLTAGE));
    }

    batteryLow = (batteryPercent <= BATTERY_LOW_PERCENT);
}
