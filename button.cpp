#include "all.h"

//==================================================
// Internal Variables
//==================================================

static bool currentState = HIGH;
static bool lastState = HIGH;

static bool pressedEvent = false;
static bool longPressEvent = false;

static unsigned long debounceTime = 0;
static unsigned long pressStartTime = 0;

static const unsigned long DEBOUNCE_DELAY = 50;
static const unsigned long LONG_PRESS_TIME = 2000;

//==================================================
// Button Functions
//==================================================

bool buttonBegin()
{
    pinMode(BTN_PIN, INPUT_PULLUP);

    currentState = digitalRead(BTN_PIN);
    lastState = currentState;

    return true;
}

void buttonUpdate()
{
    bool reading = digitalRead(BTN_PIN);

    if (reading != lastState)
    {
        debounceTime = millis();
    }

    if ((millis() - debounceTime) > DEBOUNCE_DELAY)
    {
        if (reading != currentState)
        {
            currentState = reading;

            if (currentState == LOW)
            {
                pressStartTime = millis();
            }
            else
            {
                if ((millis() - pressStartTime) >= LONG_PRESS_TIME)
                {
                    longPressEvent = true;
                }
                else
                {
                    pressedEvent = true;
                }
            }
        }
    }

    lastState = reading;
}

bool buttonIsPressed()
{
    return (currentState == LOW);
}

bool buttonWasPressed()
{
    if (pressedEvent)
    {
        pressedEvent = false;
        return true;
    }

    return false;
}

bool buttonWasLongPressed()
{
    if (longPressEvent)
    {
        longPressEvent = false;
        return true;
    }

    return false;
}