#ifndef HD44780BigFont_h
#define HD44780BigFont_h

#include <Arduino.h>
#include <HD44780.h>


enum class fontMode : uint8_t
    {
    fixed2x2,				// fixed 2 rows * 2 cols
    fixed2x3,				// fixed 2 rows * 3 cols
    proportional2,			// proportional 2 rows
    nmbrFontModes
    };

const uint8_t segments[][8] PROGMEM =                          // Custom character definitions
    {
        { 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00 }, // char 1
        { 0x18, 0x1C, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F }, // char 2
        { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x07, 0x03 }, // char 3
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F }, // char 4
        { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1E, 0x1C, 0x18 }, // char 5
        { 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F }, // char 6
        { 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F }, // char 7
        { 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F }  // char 8
    };

class BigFont
    {
    public :
        BigFont(HD44780* theDisplay, fontMode theFontMode);				// Constructor
        ~BigFont();														// Destructor

        void clear();													// clears the bigFont displayRam to all spaces
		void initialize();												// fills the LCD CGRam with custom characters
        uint8_t print(char* string, uint8_t row, uint8_t col);			// returns nmbr of cols consumed

    private:
        HD44780* theDisplay;											// pointer to the display object
        fontMode theFontMode;
		uint8_t* CGData;												// points to an array holding the Character Generator patterns - set to point to the correct ROM data upon initialization fo a certain font type
		uint8_t* fontData;												// points to an array holding the data to translate from ASCII to font-segments..
        uint8_t* displayData;											// pointer to dynamic storage which holds a copy of the data to be shown on the display
		uint8_t cols;													// how many cols - chars on one line
		uint8_t rows;													// how many rows = lines no the display
		uint8_t chars;													// how many chars in total
    };

#endif

