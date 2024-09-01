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
 * This file contains the declaration of the CustomDisplay class, which is used to manage
 * the OLED display. It includes necessary libraries and defines several macros for text
 * alignment and display dimensions. The CustomDisplay class is derived from the
 * U8G2_SSD1306_128X64_NONAME_F_HW_I2C class and includes custom functions for rendering
 * elements like progress bars on the display.
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

/**
 * @class CustomDisplay
 * @brief A class derived from U8G2_SSD1306_128X64_NONAME_F_HW_I2C to add custom drawing functions.
 *
 * The CustomDisplay class extends the functionality of the U8G2_SSD1306_128X64_NONAME_F_HW_I2C
 * class by adding methods to render custom UI components, such as progress bars, on the OLED screen.
 */
class CustomDisplay : public U8G2_SSD1306_128X64_NONAME_F_HW_I2C
{
public:
    /**
     * @brief Constructor for CustomDisplay.
     *
     * This constructor initializes the CustomDisplay object with specific parameters
     * that are passed to the base class constructor.
     *
     * @param rotation Pointer to the u8g2_cb_t rotation structure.
     * @param reset Reset pin number.
     * @param clock Clock pin number.
     * @param data Data pin number.
     */
    CustomDisplay(const u8g2_cb_t *rotation, uint8_t reset, uint8_t clock, uint8_t data)
        : U8G2_SSD1306_128X64_NONAME_F_HW_I2C(rotation, reset, clock, data) {}

    /**
     * @brief Draws a progress bar on the OLED display.
     *
     * This method renders a progress bar at the specified location on the OLED display.
     * The progress is represented as a percentage of the bar's total width.
     *
     * @param x The x-coordinate of the upper-left corner of the progress bar.
     * @param y The y-coordinate of the upper-left corner of the progress bar.
     * @param width The width of the progress bar.
     * @param height The height of the progress bar.
     * @param progress The progress percentage (0-100) to be displayed.
     */
    void drawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress);
};

/**
 * @brief Global instance of the CustomDisplay class used to manage the OLED display.
 *
 * This global object provides an interface for rendering content on the OLED display
 * throughout the program. It is declared as an external variable to ensure that
 * multiple files in the project can access and manipulate the display.
 */
extern CustomDisplay display;

// Definitions

/** @brief Macro for getting the display width in pixels. */
#ifndef LCDWidth
#define LCDWidth display.getDisplayWidth()
#endif

/** @brief Macro for getting the display height in pixels. */
#ifndef LCDHeight
#define LCDHeight display.getDisplayHeight()
#endif

/** @brief Macro for calculating the height of the text based on ascent and descent. */
#ifndef TEXT_HEIGHT
#define TEXT_HEIGHT (display.getAscent() - display.getDescent())
#endif

/** @brief Macro for horizontally centering text on the display. */
#ifndef TEXT_ALIGN_CENTER
#define TEXT_ALIGN_CENTER(t) ((LCDWidth - (display.getUTF8Width(t))) / 2)
#endif

/** @brief Macro for vertically centering text on the display. */
#ifndef TEXT_ALIGN_CENTER_V
#define TEXT_ALIGN_CENTER_V(t) ((LCDHeight + TEXT_HEIGHT) / 2)
#endif

/** @brief Macro for aligning text to the right edge of the display. */
#ifndef TEXT_ALIGN_RIGHT
#define TEXT_ALIGN_RIGHT(t) (LCDWidth - display.getUTF8Width(t))
#endif

/** @brief Macro for aligning text to the left edge of the display. */
#ifndef TEXT_ALIGN_LEFT
#define TEXT_ALIGN_LEFT 0
#endif

#endif // DISPLAY_H
