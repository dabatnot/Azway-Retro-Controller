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
 * @brief Header file for managing bitmap creation and display on the OLED screen.
 *
 * This file provides declarations for functions that handle the drawing of various bitmaps
 * and screens on an OLED display using the HT_SSD1306Wire library. These functions are used
 * to draw logos, loading screens, and various status screens that are essential for the user
 * interface of the device.
 */

#ifndef BITMAPMANAGER_H
#define BITMAPMANAGER_H

#include <Arduino.h>
#include <Wire.h>
#include "images.h"
#include "display.h" // Include display.h to use the display object
#include "ledStatus.h"
#include "firmware_config.h"

/**
 * @brief Draws the company logo on the OLED display.
 *
 * This function is responsible for rendering the company logo on the OLED screen.
 * It typically runs during the device startup to give a visual indication of the
 * branding or during certain idle states.
 */
void drawLogo();

/**
 * @brief Displays the loading screen during initialization.
 *
 * This function renders a loading screen on the OLED display, which can include
 * animations or progress indicators. It is typically used during system boot or
 * when waiting for a process to complete.
 */
void loadingScreen();

/**
 * @brief Draws the top frame on the OLED display.
 *
 * This function draws a static or dynamic top frame on the OLED display.
 * The top frame may include elements such as a title, time, or status indicators.
 */
void topFrame();

/**
 * @brief Draws the bottom frame on the OLED display.
 *
 * This function draws a static or dynamic bottom frame on the OLED display.
 * The bottom frame may include elements such as controls, status messages, or navigation hints.
 */
void bottomFrame();

/**
 * @brief Displays the main screen on the OLED display.
 *
 * This function renders the primary user interface on the OLED display,
 * which is typically the screen the user interacts with most frequently.
 * It may include various interactive elements like buttons or real-time data.
 */
void mainScreen();

/**
 * @brief Displays the joystick screen on the OLED display.
 *
 * This function displays the joystick control interface on the OLED screen.
 * It is used when the device is in a mode that requires joystick input from the user.
 */
void joystickScreen();

/**
 * @brief Displays the status screen on the OLED display.
 *
 * This function shows the status screen on the OLED display, which typically
 * provides feedback about the current state or mode of the device, such as
 * connectivity status or operational mode.
 */
void statusScreen();

/**
 * @brief Displays the waiting screen on the OLED display.
 *
 * This function renders a waiting screen on the OLED display, indicating that
 * the user needs to wait for a certain process or event to complete.
 * It may include a visual indicator like a spinner or a message.
 */
void waitingScreen();

/**
 * @brief Displays the ready screen on the OLED display.
 *
 * This function displays a ready screen, indicating that the device is ready
 * for the next operation or input from the user. It often follows the loading or waiting screen.
 */
void readyScreen();

/**
 * @brief Displays the starting screen on the OLED display.
 *
 * This function renders a screen that indicates the device or an application
 * is starting up or initializing a certain process.
 */
void startingScreen();

/**
 * @brief Displays the stopping screen on the OLED display.
 *
 * This function shows a screen indicating that the device or an application
 * is in the process of stopping or shutting down a particular operation.
 */
void stoppingScreen();

/**
 * @brief Displays the stopped screen on the OLED display.
 *
 * This function renders a screen indicating that the device or application has
 * successfully stopped and is no longer active.
 */
void stoppedScreen();

#endif // BITMAPMANAGER_H
