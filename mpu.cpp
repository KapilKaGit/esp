#include "all.h"

//==================================================
// Internal MPU6500 state
//==================================================

static bool mpuConnected = false;

// Accelerometer (g)
static float accelX = 0.0f;
static float accelY = 0.0f;
static float accelZ = 0.0f;

// Gyroscope (°/s)
static float gyroX = 0.0f;
static float gyroY = 0.0f;
static float gyroZ = 0.0f;

// Temperature (°C)
static float mpuTemperature = 0.0f;

// Orientation
static float pitch = 0.0f;
static float roll = 0.0f;
bool mpuBegin()
{
    Wire.begin(MPU_SDA, MPU_SCL);
    Wire.setClock(400000);

    Wire.beginTransmission(MPU_ADDRESS);
    Wire.write(0x75);                 // WHO_AM_I register
    Wire.endTransmission(false);

    Wire.requestFrom(MPU_ADDRESS, (uint8_t)1);

    if (Wire.available() != 1)
    {
        mpuConnected = false;
        return false;
    }

    uint8_t whoAmI = Wire.read();

    if (whoAmI != 0x70)
    {
        mpuConnected = false;
        return false;
    }

    // Wake up MPU6500
    Wire.beginTransmission(MPU_ADDRESS);
    Wire.write(0x6B);                 // PWR_MGMT_1
    Wire.write(0x00);
    Wire.endTransmission();

    delay(100);

    mpuConnected = true;

    return true;
}

bool mpuIsConnected()
{
    return mpuConnected;
}

void mpuGetAcceleration(float &x, float &y, float &z)
{
    x = accelX;
    y = accelY;
    z = accelZ;
}

void mpuGetGyroscope(float &x, float &y, float &z)
{
    x = gyroX;
    y = gyroY;
    z = gyroZ;
}

void mpuGetTemperature(float &temperature)
{
    temperature = mpuTemperature;
}


float mpuGetAccelX()
{
    return accelX;
}

float mpuGetAccelY()
{
    return accelY;
}

float mpuGetAccelZ()
{
    return accelZ;
}

float mpuGetPitch()
{
    return pitch;
}

float mpuGetRoll()
{
    return roll;
}
void mpuUpdate()
{
    if (!mpuConnected)
    {
        return;
    }

    Wire.beginTransmission(MPU_ADDRESS);
    Wire.write(0x3B);                     // ACCEL_XOUT_H
    Wire.endTransmission(false);

    Wire.requestFrom(MPU_ADDRESS, (uint8_t)14);

    if (Wire.available() != 14)
    {
        return;
    }

    int16_t rawAccelX = (Wire.read() << 8) | Wire.read();
    int16_t rawAccelY = (Wire.read() << 8) | Wire.read();
    int16_t rawAccelZ = (Wire.read() << 8) | Wire.read();

    int16_t rawTemp = (Wire.read() << 8) | Wire.read();

    int16_t rawGyroX = (Wire.read() << 8) | Wire.read();
    int16_t rawGyroY = (Wire.read() << 8) | Wire.read();
    int16_t rawGyroZ = (Wire.read() << 8) | Wire.read();

    // Default sensitivity
    accelX = (float)rawAccelX / 16384.0f;
    accelY = (float)rawAccelY / 16384.0f;
    accelZ = (float)rawAccelZ / 16384.0f;

    gyroX = (float)rawGyroX / 131.0f;
    gyroY = (float)rawGyroY / 131.0f;
    gyroZ = (float)rawGyroZ / 131.0f;

    mpuTemperature = ((float)rawTemp / 333.87f) + 21.0f;

    pitch = atan2(accelY,
                  sqrt(accelX * accelX + accelZ * accelZ))
            * 180.0f / PI;

    roll = atan2(-accelX,
                 accelZ)
           * 180.0f / PI;
}