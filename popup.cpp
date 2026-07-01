#include "all.h"

//==================================================
// Internal Variables
//==================================================

static bool popupIsVisible = false;

static char popupTitle[32];

static char popupMessage[128];
bool popupBegin()
{
    popupHide();
    return true;
}

void popupShow(const char *title,
               const char *message)
{
    strncpy(popupTitle, title, sizeof(popupTitle) - 1);
    popupTitle[sizeof(popupTitle) - 1] = '\0';

    strncpy(popupMessage, message, sizeof(popupMessage) - 1);
    popupMessage[sizeof(popupMessage) - 1] = '\0';

    popupIsVisible = true;
}

void popupHide()
{
    popupIsVisible = false;
}

bool popupVisible()
{
    return popupIsVisible;
}

void popupUpdate()
{
    // Reserved for future animations or timeout handling.
}
void popupDraw()
{
    if (!popupIsVisible)
    {
        return;
    }

    widgetDrawPopup(popupTitle,
                    popupMessage);
}
