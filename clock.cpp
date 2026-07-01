#include "all.h"

//==================================================
// Internal Clock State
//==================================================

static uint8_t currentHour = 12;
static uint8_t currentMinute = 0;
static uint8_t currentSecond = 0;

static unsigned long lastClockUpdate = 0;

static char timeString[12];  // "HH:MM:SS"
bool clockBegin()
{
    currentHour = 12;
    currentMinute = 0;
    currentSecond = 0;

    lastClockUpdate = millis();

    return true;
}

void clockSetTime(uint8_t hour, uint8_t minute, uint8_t second)
{
    currentHour = hour % 24;
    currentMinute = minute % 60;
    currentSecond = second % 60;

    lastClockUpdate = millis();
}

void clockGetTime(uint8_t &hour, uint8_t &minute, uint8_t &second)
{
    hour = currentHour;
    minute = currentMinute;
    second = currentSecond;
}

const char* clockGetTimeString()
{
    snprintf(timeString,
             sizeof(timeString),
             "%02u:%02u:%02u",
             (unsigned int)currentHour,
             (unsigned int)currentMinute,
             (unsigned int)currentSecond);

    return timeString;
}
void clockUpdate()
{
    unsigned long currentMillis = millis();

    if (currentMillis - lastClockUpdate >= 1000)
    {
        lastClockUpdate += 1000;

        currentSecond++;

        if (currentSecond >= 60)
        {
            currentSecond = 0;
            currentMinute++;

            if (currentMinute >= 60)
            {
                currentMinute = 0;
                currentHour++;

                if (currentHour >= 24)
                {
                    currentHour = 0;
                }
            }
        }
    }
}