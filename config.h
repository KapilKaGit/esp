#ifndef CONFIG_H
#define CONFIG_H

//==================================================
// Firmware
//==================================================

#define FIRMWARE_NAME              "ESP32-S3 Keychain"
#define FIRMWARE_VERSION           "v1.0.0"

//==================================================
// Display
//==================================================

#define SCREEN_WIDTH               240
#define SCREEN_HEIGHT              320

#define SCREEN_ROTATION            0
#define DISPLAY_BRIGHTNESS         255

//==================================================
// UI
//==================================================

#define UI_FPS                     30
#define UI_REFRESH_TIME            33      // ms

#define BOOT_TIME                  3000    // ms
#define SCREEN_TIMEOUT             30000   // ms

//==================================================
// Clock
//==================================================

#define CLOCK_24_HOUR              true
#define CLOCK_UPDATE_TIME          1000    // ms

//==================================================
// Button
//==================================================

#define BUTTON_DEBOUNCE_TIME       50      // ms
#define BUTTON_LONG_PRESS_TIME     2000    // ms

//==================================================
// Battery
//==================================================

#define BATTERY_FULL_VOLTAGE       4.20f
#define BATTERY_EMPTY_VOLTAGE      3.30f

#define BATTERY_FULL_PERCENT       100
#define BATTERY_LOW_PERCENT        20

//==================================================
// MPU6500
//==================================================

#define MPU_UPDATE_RATE            20
#define MPU_UPDATE_TIME            50      // ms

//==================================================
// Animation
//==================================================

#define DEFAULT_ANIMATION_TIME     300     // ms
#define ANIMATION_DELAY            15

//==================================================
// Text
//==================================================

#define TEXT_SMALL                 1
#define TEXT_MEDIUM                2
#define TEXT_LARGE                 3

//==================================================
// Colors (RGB565)
//==================================================

#define COLOR_BLACK                0x0000
#define COLOR_WHITE                0xFFFF

#define COLOR_RED                  0xF800
#define COLOR_GREEN                0x07E0
#define COLOR_BLUE                 0x001F

#define COLOR_YELLOW               0xFFE0
#define COLOR_CYAN                 0x07FF
#define COLOR_MAGENTA              0xF81F

#define COLOR_ORANGE               0xFD20
#define COLOR_GRAY                 0x8410

//==================================================
// Bitmap
//==================================================

#define ICON_SIZE                  16

#define PORTRAIT_WIDTH             128
#define PORTRAIT_HEIGHT            128

#endif