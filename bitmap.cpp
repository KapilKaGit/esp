#include "all.h"

static const uint16_t placeholderPixel[] PROGMEM = { COLOR_BLACK };

static const Bitmap placeholderBitmap = { placeholderPixel, 1, 1 };

bool bitmapBegin()
{
    return true;
}

const Bitmap* bitmapGetPortrait()
{
    return &portraitBitmap;
}

const Bitmap* bitmapGetBootLogo()
{
    return &bootLogoBitmap;
}

const Bitmap* bitmapGetWallpaper()
{
    return &wallpaperBitmap;
}

const Bitmap* bitmapGet(uint8_t id)
{
    switch (id)
    {
        case 0:
            return bitmapGetBootLogo();
        case 1:
            return bitmapGetPortrait();
        case 2:
            return bitmapGetWallpaper();
        default:
            return &placeholderBitmap;
    }
}
