#ifndef MPU_H
#define MPU_H

#include <Arduino.h>

//==================================================
// MPU6500
//==================================================

bool mpuBegin();

void mpuUpdate();

bool mpuIsConnected();

void mpuGetAcceleration(float &x, float &y, float &z);

void mpuGetGyroscope(float &x, float &y, float &z);

void mpuGetTemperature(float &temperature);

float mpuGetAccelX();

float mpuGetAccelY();

float mpuGetAccelZ();

float mpuGetPitch();

float mpuGetRoll();

#endif