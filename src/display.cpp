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
 * This file contains the implementation of the CustomDisplay class, which extends the capabilities
 * of the U8G2 library by adding custom methods for drawing on the OLED display, such as a progress bar
 * with rounded corners.
 */

#include "display.h"

/**
 * @brief Draw a progress bar on the display.
 *
 * This method draws a progress bar with rounded corners at the specified position and size.
 * The progress is represented as a percentage, filling the bar accordingly. The progress bar
 * is visually appealing with smooth rounded corners and dynamically adjusts based on the progress value.
 *
 * @param x The X-coordinate of the top-left corner of the progress bar.
 * @param y The Y-coordinate of the top-left corner of the progress bar.
 * @param width The width of the progress bar.
 * @param height The height of the progress bar.
 * @param progress The progress percentage (0-100) to display.
 */
void CustomDisplay::drawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress)
{
    uint16_t radius = height >> 1;       ///< Radius of the rounded corners.
    uint16_t xRadius = x + radius;       ///< X-coordinate of the left rounded corner center.
    uint16_t yRadius = y + radius;       ///< Y-coordinate of the left rounded corner center.
    uint16_t doubleRadius = radius << 1; ///< Diameter of the rounded corners.

    // Draw the outer frame of the progress bar
    drawDisc(xRadius, yRadius, radius, U8G2_DRAW_ALL);            // Left rounded corner
    drawHLine(xRadius, y, width - doubleRadius + 1);              // Top horizontal line
    drawHLine(xRadius, y + height, width - doubleRadius + 1);     // Bottom horizontal line
    drawDisc(x + width - radius, yRadius, radius, U8G2_DRAW_ALL); // Right rounded corner

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
