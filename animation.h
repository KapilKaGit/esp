#ifndef ANIMATION_H
#define ANIMATION_H

#include "all.h"

bool animationBegin();

void animationUpdate();

void animationStart(uint16_t duration);

void animationStop();

bool animationRunning();

void animationReset();

float animationProgress();

bool animationFinished();

#endif