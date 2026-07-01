#ifndef PINS_H
#define PINS_H

//====================================================
// TFT ST7789 Display (SPI)
//====================================================

#define TFT_CS      2
#define TFT_DC      1
#define TFT_RST     44

#define TFT_MOSI    9
#define TFT_SCLK    7

// MISO is not used by the ST7789
#define TFT_MISO   -1

//====================================================
// MPU6500 (I2C)
//====================================================

#define MPU_SDA     5
#define MPU_SCL     6

#define MPU_ADDRESS 0x68

//====================================================
// Push Button
//====================================================

#define BUTTON_PIN  8
#define BTN_PIN     BUTTON_PIN

//====================================================
// Battery Monitoring
//====================================================

// Change this if your board uses another ADC pin
#define BATTERY_PIN A0

//====================================================
// Future Expansion
//====================================================

// RGB LED
// #define RGB_PIN 10

// Buzzer
// #define BUZZER_PIN 11

// Vibration Motor
// #define MOTOR_PIN 12

#endif