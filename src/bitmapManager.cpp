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
 * This file contains the implementations of functions that draw various bitmaps and screens on an OLED display
 * using the HT_SSD1306Wire library. The functions include drawing logos, loading screens,
 * and different status screens to enhance the user interface.
 */

#include "bitmapManager.h"
#include "display.h"

/**
 * @brief Draws the Azway logo on the OLED display.
 *
 * This function displays the Azway logo at a fixed position on the OLED screen.
 * The logo is drawn using the XBM format, and the text "AZWAY RETRO" is centered beneath the logo.
 */
void drawLogo()
{
    display.setFont(u8g2_font_helvR10_tf); // Replace with the appropriate font

    // Draw the logo at a fixed position
    display.drawXBMP(29, 10, Azway_Logo_width, Azway_Logo_height, Azway_Logo);

    // Text to display under the logo
    const char *text = "AZWAY RETRO";

    // Use macros to center the text
    int x = TEXT_ALIGN_CENTER(text);
    int y = TEXT_ALIGN_CENTER_V(text) + 10;

    display.drawStr(x, y, text);
}

/**
 * @brief Displays a loading screen with progress bars for joystick initialization.
 *
 * This function clears the display, draws the logo, and displays the controller version
 * at the center of the screen. It then pauses for a fixed duration before clearing the screen again.
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
    int y = TEXT_ALIGN_CENTER_V(versionText) + 26;

    // Draw the version text
    display.drawStr(x, y, versionText);

    // Send the buffer content to the display
    display.sendBuffer();

    // Wait for 10 seconds
    delay(10000);

    // Clear the display
    display.clearBuffer();
    display.sendBuffer();

    // Update the current status (if applicable)
    // currentStatus = WAITING;

    // Disconnect all relays
    disconnectAllRelays();
}

/**
 * @brief Draws the top frame on the OLED display.
 *
 * This function renders the top frame of the OLED display using the appropriate bitmap.
 * The top frame usually contains static elements like the title or status indicators.
 */
void topFrame()
{
    display.drawXBMP(0, 0, Frame_width, Frame_height, BmpFrame[0]);
}

/**
 * @brief Draws the bottom frame on the OLED display.
 *
 * This function renders the bottom frame of the OLED display using the appropriate bitmap.
 * The bottom frame usually contains static elements like controls or navigation hints.
 */
void bottomFrame()
{
    display.drawXBMP(0, 32, Frame_width, Frame_height, BmpFrame[1]);
}

/**
 * @brief Displays the main screen on the OLED display.
 *
 * This function renders the main user interface screen on the OLED display.
 * It includes the top frame and various status indicators, with dynamic elements
 * based on the current system status.
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
 *
 * This function displays the joystick status screen by reusing the main screen layout.
 * It is typically used to show the status of connected joysticks or other input devices.
 */
void joystickScreen()
{
    mainScreen();
}

/**
 * @brief Displays the status screen on the OLED display.
 *
 * This function renders the status screen, which includes both the top and bottom frames,
 * along with any relevant status indicators. It serves as a general-purpose screen for
 * displaying system status.
 */
void statusScreen()
{
    mainScreen();
    bottomFrame();
}

/**
 * @brief Displays the waiting screen on the OLED display.
 *
 * This function shows a waiting screen on the OLED display, indicating that the system is
 * in a temporary holding state. It displays a connecting animation to inform the user
 * that a process is ongoing.
 */
void waitingScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the connection status bitmap
    display.drawXBMP(4, 38, bmpConnection_width, bmpConnection_height, ConnectionStateallArray[1]);

    // Send the buffer content to the display
    display.sendBuffer();
}

/**
 * @brief Displays the ready screen on the OLED display.
 *
 * This function shows a ready screen on the OLED display, indicating that the system
 * is prepared for the next operation. It displays a connected animation to inform the user
 * that the system is ready.
 */
void readyScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the connection status bitmap
    display.drawXBMP(4, 38, bmpConnection_width, bmpConnection_height, ConnectionStateallArray[0]);

    // Send the buffer content to the display
    display.sendBuffer();
}

/**
 * @brief Displays the starting screen on the OLED display.
 *
 * This function shows a starting screen on the OLED display, indicating that the system
 * is beginning an operation. It includes animations like rockets and a "Starting" message
 * to visually represent the system startup.
 */
void startingScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the rocket bitmap
    display.drawXBMP(6, 39, bmpRocket_width, bmpRocket_height, bmpRocket);
    display.drawXBMP(109, 39, bmpRocket_width, bmpRocket_height, bmpRocket);

    // Draw the "Starting" bitmap
    display.drawXBMP(25, 43, bmpStarting_width, bmpStarting_height, bmpStarting);

    // Send the buffer content to the display
    display.sendBuffer();
}

/**
 * @brief Displays the stopping screen on the OLED display.
 *
 * This function shows a stopping screen on the OLED display, indicating that the system
 * is in the process of halting operations. It includes animations like "ZZZ" and a "Stopping"
 * message to visually represent the system shutdown.
 */
void stoppingScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the ZZZ bitmap
    display.drawXBMP(4, 41, bmpZZZ_width, bmpZZZ_height, bmpZZZ);
    display.drawXBMP(107, 41, bmpZZZ_width, bmpZZZ_height, bmpZZZ);

    // Draw the "Stopping" bitmap
    display.drawXBMP(24, 43, bmpStopping_width, bmpStopping_height, bmpStopping);

    // Send the buffer content to the display
    display.sendBuffer();
}

/**
 * @brief Displays the stopped screen on the OLED display.
 *
 * This function shows a stopped screen on the OLED display, indicating that the system
 * has halted its operations completely. It includes a "Bye" message and a "Stopped" status
 * to inform the user that the system is no longer active.
 */
void stoppedScreen()
{
    // Clear the display buffer
    display.clearBuffer();

    // Draw the status screen
    statusScreen();

    // Draw the "Bye" bitmap
    display.drawXBMP(4, 42, bmpBye_width, bmpBye_height, bmpBye);
    display.drawXBMP(104, 42, bmpBye_width, bmpBye_height, bmpBye);

    // Draw the "Stopped" bitmap
    display.drawXBMP(27, 43, bmpStopped_width, bmpStopped_height, bmpStopped);

    // Send the buffer content to the display
    display.sendBuffer();
}
