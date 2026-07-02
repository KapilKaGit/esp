#include "all.h"

//==================================================
// Internal Variables
//==================================================

static bool stopwatchRunning = false;

static unsigned long stopwatchStartTime = 0;

static unsigned long stopwatchElapsed = 0;

//==================================================
// Stopwatch Functions
//==================================================

bool stopwatchBegin()
{
    topBarSetTitle("Stopwatch");

    stopwatchRunning = false;
    stopwatchStartTime = 0;
    stopwatchElapsed = 0;

    return true;
}

void stopwatchUpdate()
{
    if (buttonWasLongPressed())
    {
        stopwatchRunning = false;
        stopwatchElapsed = 0;
        stopwatchStartTime = 0;
        uiNextScreen();
        return;
    }
    else if (buttonWasPressed())
    {
        if (stopwatchRunning)
        {
            stopwatchRunning = false;
        }
        else
        {
            stopwatchRunning = true;
            stopwatchStartTime = millis() - stopwatchElapsed;
        }

        uiRequestRedraw();
    }

    if (stopwatchRunning)
    {
        stopwatchElapsed = millis() - stopwatchStartTime;
    }

    animationUpdate();

    popupUpdate();

    topBarUpdate();

    if (stopwatchRunning)
    {
        uiRequestTimedRedraw(UI_REFRESH_TIME);
    }
}

void stopwatchDraw()
{
    displayClear();

    topBarDraw();

    widgetDrawTitle("Stopwatch");

    unsigned long totalSeconds = stopwatchElapsed / 1000;

    unsigned long minutes = (totalSeconds / 60) % 100;

    unsigned long seconds = totalSeconds % 60;

    unsigned long centiseconds =
        (stopwatchElapsed % 1000) / 10;

    char timeText[16];

    snprintf(
        timeText,
        sizeof(timeText),
        "%02lu:%02lu.%02lu",
        minutes,
        seconds,
        centiseconds
    );

    displaySetTextSize(4);

    widgetDrawCenteredText(
        100,
        timeText
    );

    displaySetTextSize(1);

    widgetDrawCenteredText(
        180,
        stopwatchRunning ? "Running" : "Paused"
    );

    widgetDrawCenteredText(
        210,
        "Tap: Start/Pause"
    );

    widgetDrawCenteredText(
        225,
        "Hold: Reset"
    );

    popupDraw();
}