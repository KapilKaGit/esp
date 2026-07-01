#include "all.h"

//==================================================
// Internal Variables
//==================================================

static char topBarTitle[32] = "Home";
bool topBarBegin()
{
    topBarSetTitle("Home");
    return true;
}

void topBarUpdate()
{
    // Reserved for future use.
}

void topBarSetTitle(const char *title)
{
    strncpy(topBarTitle, title, sizeof(topBarTitle) - 1);
    topBarTitle[sizeof(topBarTitle) - 1] = '\0';
}

const char* topBarGetTitle()
{
    return topBarTitle;
}
void topBarDraw()
{
    displayFillRect(0, 0, SCREEN_WIDTH, 30);

    displaySetTextSize(2);

    displayPrint(10, 8, topBarTitle);

    displaySetTextSize(1);

    displayPrint(SCREEN_WIDTH - 70, 10, clockGetTimeString());
}
