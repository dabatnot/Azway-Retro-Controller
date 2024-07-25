/***************************************************************************************
 * MIT License
 *
 * Copyright (c) 2024 Daboule, Azway Retro
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

// Helpers ===============================================

/**
 * @brief Draws the logo on the OLED display.
 */
void drawLogo()
{
    display.drawXbm(29, 10, Azway_Logo_width, Azway_Logo_height, Azway_Logo);

    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.setFont(ArialMT_Plain_10);
    int x = display.width() / 2;
    int y = display.height() / 2;
    display.drawString(x, y + 5, "AZWAY RETRO");
}

/**
 * @brief Displays a loading screen with progress bars for joystick initialization.
 *
 * This function sets the LED status to CONFIG and iterates through the joysticks,
 * displaying a progress bar for each one. Once done, it sets the display to a "Ready" state.
 */
void loadingScreen()
{
    display.clear();
    drawLogo();
    int x = display.width() / 2;
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.setFont(ArialMT_Plain_10);
    display.drawString(x, 52, "Only Retrogaming");
    display.display();
    delay(10000);
    display.clear();
    display.display();
    currentStatus = WAITING;
}

/**
 * @brief Draws the top frame on the OLED display.
 */
void topFrame()
{
    display.drawXbm(0, 0, Frame_width, Frame_height, BmpFrame[0]);
}

/**
 * @brief Draws the bottom frame on the OLED display.
 */
void bottomFrame()
{
    display.drawXbm(0, 32, Frame_width, Frame_height, BmpFrame[1]);
}

/**
 * @brief Displays the main screen on the OLED display.
 */
void mainScreen()
{
    topFrame();
    display.drawXbm(32, 11, bmpStatus_width, bmpStatus_height, bmpStatus);
    if (currentStatus == READY)
    {
        // Use white stars
        display.drawXbm(6, 8, bmpStar_width, bmpStar_height, bmpStar[1]);
        display.drawXbm(106, 8, bmpStar_width, bmpStar_height, bmpStar[1]);
    }
    else
    {
        // Use black stars
        display.drawXbm(6, 8, bmpStar_width, bmpStar_height, bmpStar[0]);
        display.drawXbm(106, 8, bmpStar_width, bmpStar_height, bmpStar[0]);
    }
}

/**
 * @brief Displays the joystick screen on the OLED display.
 */
void joystickScreen()
{
    mainScreen();
}

/**
 * @brief Displays the status screen on the OLED display.
 */
void statusScreen()
{
    mainScreen();
    bottomFrame();
}

/**
 * @brief Displays the waiting screen on the OLED display.
 */
void waitingScreen()
{
    display.clear();
    statusScreen();
    display.drawXbm(4, 38, bmpConnection_width, bmpConnection_height, ConnectionStateallArray[1]);
    display.display();
}

/**
 * @brief Displays the ready screen on the OLED display.
 */
void readyScreen()
{
    display.clear();
    statusScreen();
    display.drawXbm(4, 38, bmpConnection_width, bmpConnection_height, ConnectionStateallArray[0]);
    display.display();
}

/**
 * @brief Displays the starting screen on the OLED display.
 */
void startingScreen()
{
    display.clear();
    statusScreen();
    display.drawXbm(6, 39, bmpRocket_width, bmpRocket_height, bmpRocket);
    display.drawXbm(109, 39, bmpRocket_width, bmpRocket_height, bmpRocket);
    display.drawXbm(25, 43, bmpStarting_width, bmpStarting_height, bmpStarting);
    display.display();
}

/**
 * @brief Displays the stopping screen on the OLED display.
 */
void stoppingScreen()
{
    display.clear();
    statusScreen();
    display.drawXbm(4, 41, bmpZZZ_width, bmpZZZ_height, bmpZZZ);
    display.drawXbm(107, 41, bmpZZZ_width, bmpZZZ_height, bmpZZZ);
    display.drawXbm(24, 43, bmpStopping_width, bmpStopping_height, bmpStopping);
    display.display();
}

#endif // BITMAPMANAGER_H
