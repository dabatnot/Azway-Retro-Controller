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
 * @file bitmapManager.cpp
 * @brief Source file to manage bitmap creation and display on the OLED screen.
 *
 * This file contains the function implementations to draw various bitmaps and screens on an OLED display
 * using the HT_SSD1306Wire library. The functions include drawing logos, loading screens,
 * and different status screens.
 */

#include "bitmapManager.h"
#include "display.h"

/**
 * @brief Draws the logo on the OLED display.
 */
void drawLogo()
{
    display.setFont(u8g2_font_helvR10_tf); // Remplacez par la police adéquate

    // Affiche le logo à une position fixe
    display.drawXBMP(29, 10, Azway_Logo_width, Azway_Logo_height, Azway_Logo);

    // Chaîne de texte à afficher
    const char *text = "AZWAY RETRO";

    // Utilisation des macros pour centrer le texte
    int x = TEXT_ALIGN_CENTER(text);
    int y = TEXT_ALIGN_CENTER_V(text) + 10;

    display.drawStr(x, y, text);
}

/**
 * @brief Displays a loading screen with progress bars for joystick initialization.
 *
 * This function sets the LED status to CONFIG and iterates through the joysticks,
 * displaying a progress bar for each one. Once done, it sets the display to a "Ready" state.
 */
void loadingScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the logo
    drawLogo();

    // Text to display for the controller version
    const char *versionText = CONTROLLER_VERSION;

    display.setFont(u8g2_font_ncenB08_tr); // Replace with the appropriate font
    // Use macros to center the text horizontally
    int x = TEXT_ALIGN_CENTER(versionText);
    // int x = 0;
    int y = TEXT_ALIGN_CENTER_V(versionText) + 26;

    // Set the font and draw the version text
    display.drawStr(x, y, versionText);

    // Send the buffer content to the display
    display.sendBuffer();

    // Wait for 10 seconds
    delay(10000);

    // Clear the display
    display.clearBuffer();
    display.sendBuffer();

    // Update the current status
    // currentStatus = WAITING;

    // Disconnect all relays
    disconnectAllRelays();
}

/**
 * @brief Draws the top frame on the OLED display.
 */
void topFrame()
{
    display.drawXBMP(0, 0, Frame_width, Frame_height, BmpFrame[0]);
}

/**
 * @brief Draws the bottom frame on the OLED display.
 */
void bottomFrame()
{
    display.drawXBMP(0, 32, Frame_width, Frame_height, BmpFrame[1]);
}

/**
 * @brief Displays the main screen on the OLED display.
 */
void mainScreen()
{
    topFrame();
    display.drawXBMP(32, 11, bmpStatus_width, bmpStatus_height, bmpStatus);
    if (currentStatus == READY)
    {
        display.drawXBMP(6, 8, bmpStar_width, bmpStar_height, bmpStar[1]);
        display.drawXBMP(106, 8, bmpStar_width, bmpStar_height, bmpStar[1]);
    }
    else
    {
        display.drawXBMP(6, 8, bmpStar_width, bmpStar_height, bmpStar[0]);
        display.drawXBMP(106, 8, bmpStar_width, bmpStar_height, bmpStar[0]);
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
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the bitmap at the specified position
    display.drawXBMP(4, 38, bmpConnection_width, bmpConnection_height, ConnectionStateallArray[1]);

    // Send the buffer content to the display
    display.sendBuffer();
}

/**
 * @brief Displays the ready screen on the OLED display.
 */
void readyScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the bitmap at the specified position
    display.drawXBMP(4, 38, bmpConnection_width, bmpConnection_height, ConnectionStateallArray[0]);

    // Send the buffer content to the display
    display.sendBuffer();
}

/**
 * @brief Displays the starting screen on the OLED display.
 */
void startingScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the rocket bitmap at the specified positions
    display.drawXBMP(6, 39, bmpRocket_width, bmpRocket_height, bmpRocket);
    display.drawXBMP(109, 39, bmpRocket_width, bmpRocket_height, bmpRocket);

    // Draw the "Starting" bitmap at the specified position
    display.drawXBMP(25, 43, bmpStarting_width, bmpStarting_height, bmpStarting);

    // Send the buffer content to the display
    display.sendBuffer();
}

/**
 * @brief Displays the stopping screen on the OLED display.
 */
void stoppingScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the ZZZ bitmap at the specified positions
    display.drawXBMP(4, 41, bmpZZZ_width, bmpZZZ_height, bmpZZZ);
    display.drawXBMP(107, 41, bmpZZZ_width, bmpZZZ_height, bmpZZZ);

    // Draw the "Stopping" bitmap at the specified position
    display.drawXBMP(24, 43, bmpStopping_width, bmpStopping_height, bmpStopping);

    // Send the buffer content to the display
    display.sendBuffer();
}

/**
 * @brief Displays the stopped screen on the OLED display.
 */
void stoppedScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the "Bye" bitmap at the specified positions
    display.drawXBMP(4, 42, bmpBye_width, bmpBye_height, bmpBye);
    display.drawXBMP(104, 42, bmpBye_width, bmpBye_height, bmpBye);

    // Draw the "Stopped" bitmap at the specified position
    display.drawXBMP(27, 43, bmpStopped_width, bmpStopped_height, bmpStopped);

    // Send the buffer content to the display
    display.sendBuffer();
}
