/***************************************************************************************
 * MIT License
 *
 * Copyright (c) 2024 Dabatnot, Azway Retro
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ****************************************************************************************/

/**
 * @file display.h
 * @brief Header file for managing the OLED display.
 *
 * This file contains the declaration of the display object used to manage the OLED display.
 * It includes necessary libraries and defines macros for text alignment on the screen.
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

/**
 * @brief CustomDisplay class derived from U8G2_SSD1306_128X64_NONAME_F_HW_I2C to add custom drawing functions.
 */
class CustomDisplay : public U8G2_SSD1306_128X64_NONAME_F_HW_I2C
{
public:
    // Constructor matching the base class constructor
    CustomDisplay(const u8g2_cb_t *rotation, uint8_t reset, uint8_t clock, uint8_t data)
        : U8G2_SSD1306_128X64_NONAME_F_HW_I2C(rotation, reset, clock, data) {}

    // Method to draw a progress bar
    void drawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress);
};

/**
 * @brief Global instance of the CustomDisplay class used to manage the OLED display.
 *
 * This object is declared as an external variable so it can be accessed and used in other files
 * that include this header.
 */
extern CustomDisplay display;


// Definitions

/** @brief Macro for getting the display width. */
#ifndef LCDWidth
// #define LCDWidth display.getDisplayWidth()
#define LCDWidth display.getDisplayWidth()
#endif

/** @brief Macro for getting the display height. */
#ifndef LCDHeight
#define LCDHeight display.getDisplayHeight()
#endif

/** @brief Macro for calculating the height of the text. */
#ifndef TEXT_HEIGHT
#define TEXT_HEIGHT (display.getAscent() - display.getDescent())
#endif

/** @brief Macro for horizontally centering text. */
#ifndef TEXT_ALIGN_CENTER
#define TEXT_ALIGN_CENTER(t) ((LCDWidth - (display.getUTF8Width(t))) / 2)
#endif

/** @brief Macro for vertically centering text. */
#ifndef TEXT_ALIGN_CENTER_V
#define TEXT_ALIGN_CENTER_V(t) ((LCDHeight + TEXT_HEIGHT) / 2)
#endif

/** @brief Macro for aligning text to the right. */
#ifndef TEXT_ALIGN_RIGHT
#define TEXT_ALIGN_RIGHT(t) (LCDWidth - display.getUTF8Width(t))
#endif

/** @brief Macro for aligning text to the left. */
#ifndef TEXT_ALIGN_LEFT
#define TEXT_ALIGN_LEFT 0
#endif

#endif // DISPLAY_H
