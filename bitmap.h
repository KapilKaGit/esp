#ifndef BITMAP_H
#define BITMAP_H

#include <Arduino.h>
#include "config.h"

//==================================================
// Bitmap Structure
//==================================================

struct Bitmap
{
    const uint16_t *data;
    uint16_t width;
    uint16_t height;
};

//==================================================
// Bitmap Manager
//==================================================

bool bitmapBegin();

const Bitmap* bitmapGetPortrait();

const Bitmap* bitmapGetBootLogo();

const Bitmap* bitmapGetWallpaper();

const Bitmap* bitmapGet(uint8_t id);

#endif