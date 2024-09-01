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
 * @file display.cpp
 * @brief Implementation file for managing the OLED display and custom drawing functions.
 *
 * This file contains the implementation of the CustomDisplay class, including custom methods
 * for drawing on the OLED display, such as a progress bar.
 */

#include "display.h"

/**
 * @brief Global instance of the CustomDisplay class used to manage the OLED display.
 *
 * This object is used throughout the program to perform various display-related tasks.
 */
// CustomDisplay display(U8G2_R0, /* reset=*/21, /* clock=*/18, /* data=*/17); // ESP32 Thing, HW I2C with pin remapping

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

/**
 * @brief Draw a progress bar on the display.
 *
 * This method draws a progress bar with rounded corners at the specified position and size.
 * The progress is represented as a percentage, filling the bar accordingly.
 *
 * @param x The X-coordinate of the top-left corner of the progress bar.
 * @param y The Y-coordinate of the top-left corner of the progress bar.
 * @param width The width of the progress bar.
 * @param height The height of the progress bar.
 * @param progress The progress percentage (0-100) to display.
 */
void CustomDisplay::drawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress)
{
    uint16_t radius = height >> 1;       // Calculate the radius of the rounded corners
    uint16_t xRadius = x + radius;       // X-coordinate of the left rounded corner center
    uint16_t yRadius = y + radius;       // Y-coordinate of the left rounded corner center
    uint16_t doubleRadius = radius << 1; // Diameter of the rounded corners

    // Draw the outer frame of the progress bar
    drawDisc(xRadius, yRadius, radius, U8G2_DRAW_ALL);        // Left rounded corner
    drawHLine(xRadius, y, width - doubleRadius + 1);          // Top horizontal line
    drawHLine(xRadius, y + height, width - doubleRadius + 1); // Bottom horizontal line
    drawDisc(x + width - radius, yRadius, radius, U8G2_DRAW_ALL);

    // Calculate the width of the filled part based on progress
    uint16_t maxProgressWidth = (width - doubleRadius + 1) * progress / 100;

    // Draw the filled part of the progress bar
    drawBox(xRadius, y + 1, maxProgressWidth, height - 1);

    // Draw the ending disc only if the progress is less than 100%
    if (progress < 100 && maxProgressWidth > 0)
    {
        drawDisc(xRadius + maxProgressWidth, yRadius, radius - 1, U8G2_DRAW_ALL);
    }
}
