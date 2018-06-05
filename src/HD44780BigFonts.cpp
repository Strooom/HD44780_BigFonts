#include "HD44780BigFont.h"




BigFont::BigFont(HD44780* theDisplay, fontMode theFontMode) : theDisplay(theDisplay), theFontMode(theFontMode)
    {
    cols = ((uint16_t)theDisplay->getDisplayType() & 0xFF00) >> 8;		// nmbr of cols (chars) per line - horizontal
    rows = ((uint16_t)theDisplay->getDisplayType() & 0x00FF);			// nmbr of lines - vertical
    switch (theFontMode)
        {
        case fontMode::fixed2x2:
            break;
        case fontMode::fixed2x3:
            break;
        case fontMode::proportional2:
            break;
        default:
            break;
        }
    chars = rows * cols;
    displayData = new uint8_t[chars];									// dynamically allocate memory, depending on the size of the display..
    }

BigFont::~BigFont()
    {
    delete[] displayData;												// release the dynamic memory

    }

uint8_t BigFont::print(char* string, uint8_t row, uint8_t col)
    {
    // translate data from bigFont displayRam to HD44780 (object) displayRam
    }

void BigFont::clear()
    {
    for (uint8_t i = 0; i < chars; i++)
        {
        displayData[i] = 0x20;
        }
    }


void BigFont::initialize()
    {
    switch (theFontMode)
        {
        case fontMode::fixed2x2:
            break;
        case fontMode::fixed2x3:
            break;
        case fontMode::proportional2:
            break;
        default:
            break;
        }
    }