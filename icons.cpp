#include "all.h"

static const uint16_t homeIconPixels[] PROGMEM = { COLOR_WHITE };
static const uint16_t batteryIconPixels[] PROGMEM = { COLOR_GREEN };
static const uint16_t bluetoothIconPixels[] PROGMEM = { COLOR_BLUE };
static const uint16_t galleryIconPixels[] PROGMEM = { COLOR_CYAN };
static const uint16_t clockIconPixels[] PROGMEM = { COLOR_YELLOW };
static const uint16_t sensorIconPixels[] PROGMEM = { COLOR_ORANGE };
static const uint16_t levelIconPixels[] PROGMEM = { COLOR_MAGENTA };
static const uint16_t stopwatchIconPixels[] PROGMEM = { COLOR_RED };
static const uint16_t settingsIconPixels[] PROGMEM = { COLOR_GRAY };
static const uint16_t aboutIconPixels[] PROGMEM = { COLOR_WHITE };
static const uint16_t backIconPixels[] PROGMEM = { COLOR_WHITE };

const Bitmap homeIcon = { homeIconPixels, 1, 1 };
const Bitmap batteryIcon = { batteryIconPixels, 1, 1 };
const Bitmap bluetoothIcon = { bluetoothIconPixels, 1, 1 };
const Bitmap galleryIcon = { galleryIconPixels, 1, 1 };
const Bitmap clockIcon = { clockIconPixels, 1, 1 };
const Bitmap sensorIcon = { sensorIconPixels, 1, 1 };
const Bitmap levelIcon = { levelIconPixels, 1, 1 };
const Bitmap stopwatchIcon = { stopwatchIconPixels, 1, 1 };
const Bitmap settingsIcon = { settingsIconPixels, 1, 1 };
const Bitmap aboutIcon = { aboutIconPixels, 1, 1 };
const Bitmap backIcon = { backIconPixels, 1, 1 };
