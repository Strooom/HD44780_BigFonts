// #############################################################################
// ### Library for Big Fonts for LCDs based on Hitachi HD44780               ###
// ### https://github.com/Strooom/HD44780_BigFonts                           ###
// ### Author(s) : Pascal Roobrouck - @strooom                               ###
// ### License : https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode ###
// ### June 2018                                                             ###
// #############################################################################

#include "HD44780_BigFonts.h"

// ##########################
// ### Base Class BigFont ###
// ##########################

BigFont::BigFont(HD44780* theDisplay) : theDisplay(theDisplay)
    {
    }


// ##################################################
// ## Derived Class BigFont                        ##
// ## 2 rows high, 3 chars wide, spacing included  ##
// ## Supports glyps 0..9                          ##
// ## Designed by Ronivaldo Sampaio                ##
// ##################################################

const char  BigFontSampaio::customCharData[] =
    {
    0x1C, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1C,
    0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07,
    0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F,
    0x1E, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1C,
    0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0F,
    0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

const char BigFontSampaio::fontData[] =
    {
    1,7,0,1,5,0,			// '0'
    32,32,0,32,32,0,		// '1'
    4,2,0,1,5,5,			// '2'
    4,2,0,6,5,0,			// '3'
    1,5,0,32,32,0,			// '4'
    1,2,3,6,5,0,			// '5'
    1,2,3,1,5,0,			// '6'
    1,7,0,32,32,0,			// '7'
    1,2,0,1,5,0,			// '8'
    1,2,0,6,5,0				// '9'
    };

BigFontSampaio::BigFontSampaio(HD44780* theDisplay) : BigFont(theDisplay)
    {
    }

void BigFontSampaio::initialize()
    {
    // Set CGRam to specific values for this font
    theDisplay->setCGRam(customCharData, 0);
    theDisplay->setCGRam(customCharData + 8, 1);
    theDisplay->setCGRam(customCharData + 16, 2);
    theDisplay->setCGRam(customCharData + 24, 3);
    theDisplay->setCGRam(customCharData + 32, 4);
    theDisplay->setCGRam(customCharData + 40, 5);
    theDisplay->setCGRam(customCharData + 48, 6);
    theDisplay->setCGRam(customCharData + 56, 7);
    }

char * BigFontSampaio::getOffset(char theChar)
    {
    if ((theChar >= '0') && (theChar <= '9'))
        {
        return (char*)fontData + (theChar - '0') * 6;
        }
    else
        {
        return nullptr;
        }
    }

void BigFontSampaio::print(char* string, uint8_t row, uint8_t col)
    {
    while (*string)
        {
        char* offSet = getOffset(*string);
        if (nullptr != offSet)
            {
            theDisplay->write(offSet, 3, row, col);
            theDisplay->write(offSet + 3, 3, row + 1, col);
            }
        string++;
        col = col + 3;
        }
    }



// ######################################################
// ## Derived Class BigFont                            ##
// ## 2 rows high, 2 chars wide, spacing NOT included  ##
// ## Supports glyps 0..9                              ##
// ## Designed by kiwimew                              ##
// ######################################################

const char  BigFontKiwimew::customCharData[] =
    {
    0x1B, 0x1B, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18,
    0x1B, 0x1B, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03,
    0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x1B, 0x1B,
    0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x1B, 0x1B,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x1B,
    0x1B, 0x1B, 0x00, 0x03, 0x03, 0x00, 0x1B, 0x1B,
    0x1B, 0x1B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1B, 0x1B, 0x00, 0x18, 0x18, 0x00, 0x1B, 0x1B
    };

const char BigFontKiwimew::fontData[] =
    {
    0,1,2,3,	// '0'
    1,32,3,4,	// '1'
    6,5,7,4,	// '2'
    6,5,4,3,	// '3'
    2,3,32,1,	// '4'
    7,6,4,5,	// '5'
    0,6,7,5,	// '6'
    6,1,32,0,	// '7'
    7,5,2,3,	// '8'
    7,5,4,3		// '9'
    };

BigFontKiwimew::BigFontKiwimew(HD44780* theDisplay) : BigFont(theDisplay)
    {
    }

void BigFontKiwimew::initialize()
    {
    // Set CGRam to specific values for this font
    theDisplay->setCGRam(customCharData, 0);
    theDisplay->setCGRam(customCharData + 8, 1);
    theDisplay->setCGRam(customCharData + 16, 2);
    theDisplay->setCGRam(customCharData + 24, 3);
    theDisplay->setCGRam(customCharData + 32, 4);
    theDisplay->setCGRam(customCharData + 40, 5);
    theDisplay->setCGRam(customCharData + 48, 6);
    theDisplay->setCGRam(customCharData + 56, 7);
    }

char * BigFontKiwimew::getOffset(char theChar)
    {
    if ((theChar >= '0') && (theChar <= '9'))
        {
        return (char*) fontData + (theChar - '0') * 4;
        }
    else
        {
        return nullptr;
        }
    }

void BigFontKiwimew::print(char* string, uint8_t row, uint8_t col)
    {
    while (*string)
        {
        char* offSet = getOffset(*string);
        if (nullptr != offSet)
            {
            theDisplay->write(offSet, 2, row, col);
            theDisplay->write(offSet + 2, 2, row + 1, col);
            }
        string++;
        col = col + 3;
        }
    }


// ##################################################
// ## Derived Class BigFont                        ##
// ## 3 rows high, 3 chars wide, spacing included  ##
// ## Supports glyps 0..9                          ##
// ## Designed by china92                          ##
// ##################################################

const char  BigFontChina92::customCharData[] =
    {
    0x03, 0x0F, 0x0F, 0x1F, 0x00, 0x00, 0x00, 0x00,
    0x18, 0x1E, 0x1E, 0x1F, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x1E, 0x1E, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x0F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
    0x18, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
    };

const char BigFontChina92::fontData[] =
    {
    5,2,6,255,32,255,4,2,3,		// '0'
    0,255,32,32,255,32,2,2,2,	// '1'
    0,2,6,5,2,3,4,2,3,			// '2'
    0,2,6,32,2,255,4,2,3,		// '3'
    255,32,255,4,2,255,32,32,2,	// '4'
    255,2,3,2,2,6,4,2,3,		// '5'
    5,2,1,255,2,6,4,2,3,		// '6'
    4,2,255,32,5,3,32,2,32,		// '7'
    5,2,6,255,2,255,4,2,3,		// '8'
    5,2,6,4,2,255,4,2,3			// '9'
    };

BigFontChina92::BigFontChina92(HD44780* theDisplay) : BigFont(theDisplay)
    {
    }

void BigFontChina92::initialize()
    {
    // Set CGRam to specific values for this font
    theDisplay->setCGRam(customCharData, 0);
    theDisplay->setCGRam(customCharData + 8, 1);
    theDisplay->setCGRam(customCharData + 16, 2);
    theDisplay->setCGRam(customCharData + 24, 3);
    theDisplay->setCGRam(customCharData + 32, 4);
    theDisplay->setCGRam(customCharData + 40, 5);
    theDisplay->setCGRam(customCharData + 48, 6);
    }

char * BigFontChina92::getOffset(char theChar)
    {
    if ((theChar >= '0') && (theChar <= '9'))
        {
        return (char*)fontData + (theChar - '0') * 9;
        }
    else
        {
        return nullptr;
        }
    }

void BigFontChina92::print(char* string, uint8_t row, uint8_t col)
    {
    while (*string)
        {
        char* offSet = getOffset(*string);
        if (nullptr != offSet)
            {
            theDisplay->write(offSet, 3, row, col);
            theDisplay->write(offSet + 3, 3, row + 1, col);
            theDisplay->write(offSet + 6, 3, row + 2, col);
            }
        string++;
        col = col + 3;
        }
    }



// ##################################################
// ## Derived Class BigFont                        ##
// ## 3 rows high, 3 chars wide, spacing included  ##
// ## Supports glyps 0..9                          ##
// ## Designed by ???????                          ##
// ##################################################

const char  BigFont3x3fixed::customCharData[] =
    {
    0x03, 0x07, 0x0F, 0x1F, 0x00, 0x00, 0x00, 0x00,
    0x18, 0x1C, 0x1E, 0x1F, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x1E, 0x1C, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
    0x18, 0x1C, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
    };

const char BigFont3x3fixed::fontData[] =
    {
    5,2,6,255,32,255,4,2,3,		// '0'
    0,255,32,32,255,32,2,2,2,	// '1'
    0,2,6,5,2,3,4,2,3,			// '2'
    0,2,6,32,2,255,4,2,3,		// '3'
    255,32,255,4,2,255,32,32,2,	// '4'
    255,2,3,2,2,6,4,2,3,		// '5'
    5,2,1,255,2,6,4,2,3,		// '6'
    4,2,255,32,5,3,32,2,32,		// '7'
    5,2,6,255,2,255,4,2,3,		// '8'
    5,2,6,4,2,255,4,2,3			// '9'
    };

BigFont3x3fixed::BigFont3x3fixed(HD44780* theDisplay) : BigFont(theDisplay)
    {
    }

void BigFont3x3fixed::initialize()
    {
    // Set CGRam to specific values for this font
    theDisplay->setCGRam(customCharData, 0);
    theDisplay->setCGRam(customCharData + 8, 1);
    theDisplay->setCGRam(customCharData + 16, 2);
    theDisplay->setCGRam(customCharData + 24, 3);
    theDisplay->setCGRam(customCharData + 32, 4);
    theDisplay->setCGRam(customCharData + 40, 5);
    theDisplay->setCGRam(customCharData + 48, 6);
    }

char * BigFont3x3fixed::getOffset(char theChar)
    {
    if ((theChar >= '0') && (theChar <= '9'))
        {
        return (char*)fontData + (theChar - '0') * 9;
        }
    else
        {
        return nullptr;
        }
    }

void BigFont3x3fixed::print(char* string, uint8_t row, uint8_t col)
    {
    while (*string)
        {
        char* offSet = getOffset(*string);
        if (nullptr != offSet)
            {
            theDisplay->write(offSet, 3, row, col);
            theDisplay->write(offSet + 3, 3, row + 1, col);
            theDisplay->write(offSet + 6, 3, row + 2, col);
            }
        string++;
        col = col + 3;
        }
    }
