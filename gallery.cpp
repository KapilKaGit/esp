#include "all.h"

//==================================================
// Internal Variables
//==================================================

static uint8_t currentImage = 0;
bool galleryBegin()
{
    topBarSetTitle("Gallery");

    currentImage = 0;

    return true;
}
void galleryUpdate()
{
    if (buttonWasLongPressed())
    {
        uiNextScreen();
        return;
    }
    else if (buttonWasPressed())
    {
        currentImage++;

        if (currentImage >= 3)
        {
            currentImage = 0;
        }

        uiRequestRedraw();
    }

    topBarUpdate();

    popupUpdate();
}
void galleryDraw()
{
    displayClear();

    topBarDraw();

    const Bitmap *image = bitmapGet(currentImage);

    if (image != nullptr)
    {
        widgetDrawBitmap(
            (SCREEN_WIDTH - image->width) / 2,
            (SCREEN_HEIGHT - image->height) / 2,
            image
        );
    }

    char imageNumber[8];

    snprintf(
        imageNumber,
        sizeof(imageNumber),
        "%u/%u",
        currentImage + 1,
        3
    );

    widgetDrawCenteredText(
        SCREEN_HEIGHT - 20,
        imageNumber
    );

    popupDraw();
}