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
 * @file bitmapManager.h
 * @brief Header file to manage bitmap creation and display on the OLED screen.
 *
 * This file contains functions to draw various bitmaps and screens on an OLED display
 * using the HT_SSD1306Wire library. The functions include drawing logos, loading screens,
 * and different status screens.
 */

#ifndef BITMAPMANAGER_H
#define BITMAPMANAGER_H

#include <Arduino.h>
#include "HT_SSD1306Wire.h"
#include "images.h"
#include "display.h" // Include display.h to use the display object
#include "ledStatus.h"
#include "firmware_config.h"

/**
 * @brief Draws the logo on the OLED display.
 */
void drawLogo();

/**
 * @brief Displays the loading screen during initialization.
 */
void loadingScreen();

/**
 * @brief Draws the top frame on the OLED display.
 */
void topFrame();

/**
 * @brief Draws the bottom frame on the OLED display.
 */
void bottomFrame();

/**
 * @brief Displays the main screen on the OLED display.
 */
void mainScreen();

/**
 * @brief Displays the joystick screen on the OLED display.
 */
void joystickScreen();

/**
 * @brief Displays the status screen on the OLED display.
 */
void statusScreen();

/**
 * @brief Displays the waiting screen on the OLED display.
 */
void waitingScreen();

/**
 * @brief Displays the ready screen on the OLED display.
 */
void readyScreen();

/**
 * @brief Displays the starting screen on the OLED display.
 */
void startingScreen();

/**
 * @brief Displays the stopping screen on the OLED display.
 */
void stoppingScreen();

/**
 * @brief Displays the stopped screen on the OLED display.
 */
void stoppedScreen();

#endif // BITMAPMANAGER_H
