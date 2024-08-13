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
 * @file main.cpp
 * @brief Main program file for managing an OLED display and LED statuses using FreeRTOS tasks on an Arduino-compatible microcontroller.
 *
 * This program initializes the OLED display, manages joystick initialization and displays various statuses based on serial input.
 * It also controls LED statuses to indicate different system states.
 */

#include <Arduino.h>
// #include <SPI.h>
#include "powerManagement.h"
#include "images.h"
#include "ledStatus.h"
#include "bitmapManager.h"
#include "display.h" // Assuming CustomDisplay and display instance are declared here
CustomDisplay display(U8G2_R0, /* reset=*/I2CRESET, /* clock=*/I2CSCL, /* data=*/I2CSDA);
/**
 * @brief Initializes the joystick with the given number.
 * @param joystickNum The number of the joystick to initialize.
 */
void initJoystick(int joystickNum);

// Setup ==================================================
/**
 * @brief Setup function called once at startup.
 *
 * This function initializes serial communication, the OLED display, and the LED management system.
 */
void setup()
{
  disconnectAllRelays();

  // Initialize serial communication
  Serial.begin(115200);

  while (!Serial)
  {
    ; // Wait for the serial port to be ready
  }
  Serial.println("ESP32 ready to receive messages...");

  // Setup LED management
  setupLED();

  // Power on the external voltage (Vext)
  VextON();
  delay(100);

  // Initialize the display
  display.begin();

  // Display the loading screen
  loadingScreen();

  // Display the waiting screen
  waitingScreen();
}

/**
 * @brief Initializes the joystick with the given number.
 * @param joystickNum The number of the joystick to initialize.
 */

void initJoystick(int joystickNum)
{
  int progress = joystickNum * 25;
  // Draw the progress bar
  display.drawProgressBar(5, 42, 116, 10, progress);

  // Physically reconnect the joystick and the buttons LEDS
  digitalWrite(RELAY[joystickNum * 2 - 2], HIGH);
  delay(1000);
  digitalWrite(RELAY[joystickNum * 2 - 1], HIGH);
  delay(1000);
}

// Main loop =============================================
/**
 * @brief Main loop function called repeatedly.
 *
 * This function checks for incoming serial messages and updates the OLED display and LED status based on the received messages.
 */

void loop()
{
  // Check if data is available on the serial port
  if (Serial.available() > 0)
  {
    // Read the message
    String message = Serial.readStringUntil('\n');
    message.trim(); // Call trim() on a separate line

    if (message == "ESP32?")
    {
      Serial.println("ESP32 ready");
      currentStatus = CONFIG;

      for (int currentJoystick = 1; currentJoystick < 5; currentJoystick++)
      {
        // Clear the display buffer
        display.clearBuffer();

        // Draw the status screen
        statusScreen();

        // Initialize the joystick
        initJoystick(currentJoystick);

        // Send the buffer content to the display
        display.sendBuffer();

        // Wait for 1 second
        delay(1000);
      }
      currentStatus = READY;
      readyScreen();
    }
    else if ((message.charAt(0) == 'N' || message.charAt(0) == 'L' || message.charAt(0) == 'Q') && currentStatus == READY)
    {
      // Extract the number of players from the message
      int separatorIndex = message.indexOf(':');
      String nbPlayersStr = message.substring(separatorIndex + 1);
      int nbPlayers = nbPlayersStr.toInt();

      // Handle the message based on the event
      char event = message.charAt(0);
      String ack = "ACK:" + String(message);

      switch (event)
      {
      case 'N':
      case 'L':
      case 'Q':
        display.clearBuffer();
        joystickScreen();
        activateLeds(nbPlayers);
        display.sendBuffer();
        break;
      default:
        ack = "ACK:?";
        break;
      }
      Serial.println(ack);
    }
    else
    {
      // Handle other messages
      switch (message.charAt(0))
      {
      case 'S':
        Serial.println("ACK:S"); // Starting
        startingScreen();
        activateLeds(0);
        break;
      case 'D':
        Serial.println("ACK:D"); // Started
        startingScreen();
        activateLeds(0);
        break;
      case 'E':
        Serial.println("ACK:E"); // stopping
        stoppingScreen();
        activateLeds(4);
        break;
      case 'P':
        Serial.println("ACK:P"); // stopped
        stoppedScreen();
        activateLeds(0);
        break;
      default:
        Serial.println("ACK:?");
        // Do nothing with buttons LEDs
        break;
      }
    }
  }
}
