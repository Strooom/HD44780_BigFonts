// #############################################################################
// ### Library for Big Fonts for LCDs based on Hitachi HD44780               ###
// ### https://github.com/Strooom/HD44780_BigFonts                           ###
// ### Author(s) : Pascal Roobrouck - @strooom                               ###
// ### License : https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode ###
// ### June 2018                                                             ###
// #############################################################################

#ifndef HD44780_BigFonts_h
#define HD44780_BigFonts_h

#include <Arduino.h>
#include <HD44780.h>														// this library is needed to drive the HD44780 display

// ##########################
// ### Base Class BigFont ###
// ##########################

class BigFont
    {
    public :
        BigFont(HD44780* theDisplay);										// Constructor

        virtual void initialize() = 0;										// fills the LCD CGRam with custom characters
        virtual void print(char* string, uint8_t row, uint8_t col) = 0;		// returns nmbr of cols consumed

    protected:
        HD44780* theDisplay;												// pointer to the display object
    };


// ##################################################
// ## Derived Class BigFont                        ##
// ## 2 rows high, 3 chars wide, spacing included  ##
// ## Supports glyps 0..9                          ##
// ## Designed by Ronivaldo Sampaio                ##
// ##################################################

class BigFontSampaio : BigFont
    {
    private:
        const static char customCharData[];
        const static char fontData[];
        char* getOffset(char);

    public:
        BigFontSampaio(HD44780* theDisplay);

        virtual void initialize();
        virtual void print(char* string, uint8_t row, uint8_t col);
    };


// ######################################################
// ## Derived Class BigFont                            ##
// ## 2 rows high, 2 chars wide, spacing NOT included  ##
// ## Supports glyps 0..9                              ##
// ## Designed by kiwimew                              ##
// ######################################################

class BigFontKiwimew : BigFont
    {
    private:
        const static char customCharData[];
        const static char fontData[];
        char* getOffset(char);

    public:
        BigFontKiwimew(HD44780* theDisplay);

        virtual void initialize();
        virtual void print(char* string, uint8_t row, uint8_t col);
    };



// ##################################################
// ## Derived Class BigFont                        ##
// ## 3 rows high, 3 chars wide, spacing included  ##
// ## Supports glyps 0..9                          ##
// ## Designed by china92                          ##
// ##################################################

class BigFontChina92 : BigFont
    {
    private:
        const static char customCharData[];
        const static char fontData[];
        char* getOffset(char);

    public:
        BigFontChina92(HD44780* theDisplay);

        virtual void initialize();
        virtual void print(char* string, uint8_t row, uint8_t col);
    };




// ##################################################
// ## Derived Class BigFont                        ##
// ## 3 rows high, 3 chars wide, spacing included  ##
// ## Supports glyps 0..9                          ##
// ## Designed by ???????                          ##
// ##################################################

class BigFont3x3fixed : BigFont
    {
    private:
        const static char customCharData[];
        const static char fontData[];
        char* getOffset(char);

    public:
        BigFont3x3fixed(HD44780* theDisplay);

        virtual void initialize();
        virtual void print(char* string, uint8_t row, uint8_t col);
    };





#endif

