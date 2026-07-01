#include "all.h"

//==================================================
// Internal Variables
//==================================================

static bool animationActive = false;
static bool animationDone = false;

static unsigned long animationStartTime = 0;
static unsigned long animationDuration = 0;

static float progress = 0.0f;
bool animationBegin()
{
    animationReset();
    return true;
}

void animationStart(uint16_t duration)
{
    animationActive = true;
    animationDone = false;

    animationDuration = duration;
    animationStartTime = millis();

    progress = 0.0f;
}

void animationStop()
{
    animationActive = false;
}

bool animationRunning()
{
    return animationActive;
}

void animationReset()
{
    animationActive = false;
    animationDone = false;

    animationStartTime = 0;
    animationDuration = 0;

    progress = 0.0f;
}

float animationProgress()
{
    return progress;
}

bool animationFinished()
{
    return animationDone;
}
void animationUpdate()
{
    if (!animationActive)
    {
        return;
    }

    unsigned long elapsed = millis() - animationStartTime;

    if (elapsed >= animationDuration)
    {
        progress = 1.0f;
        animationActive = false;
        animationDone = true;
        return;
    }

    progress = (float)elapsed / (float)animationDuration;
}
