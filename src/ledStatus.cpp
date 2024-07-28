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
 * @file ledStatus.cpp
 * @brief Source file for managing an LED using FreeRTOS tasks on an Arduino-compatible microcontroller.
 *
 * This file contains the implementations of the functions required to manage an LED connected to a GPIO pin.
 * The LED can be in one of four states: OFF, READY, WAITING, or CONFIG, each causing different behavior in the LED.
 * The management of the LED state is handled by FreeRTOS tasks to ensure efficient multitasking.
 */

#include "ledStatus.h"

/// Positions of the joysticks on the display
int joyPos[4] = {0, 1, 2, 3};

/// Current status of the LED
volatile LedStatus currentStatus = OFF;

/// Handle for the LED management task
TaskHandle_t Task1;

/**
 * @brief Task function to manage the LED behavior based on the current status.
 *
 * This function runs in an infinite loop, checking the current status of the LED and
 * updating its state accordingly. The behavior of the LED changes depending on the value of currentStatus.
 *
 * @param pvParameters Pointer to the parameters passed to the task (not used in this case).
 */
void manageLED(void *pvParameters)
{
  while (1)
  {
    switch (currentStatus)
    {
    case OFF:
      digitalWrite(ledPin, LOW);
      vTaskDelay(100 / portTICK_PERIOD_MS); // Check every 100 ms
      break;
    case READY:
      digitalWrite(ledPin, HIGH);
      vTaskDelay(100 / portTICK_PERIOD_MS); // Check every 100 ms
      break;
    case WAITING:
      digitalWrite(ledPin, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS); // On for 200 ms
      digitalWrite(ledPin, LOW);
      vTaskDelay(1000 / portTICK_PERIOD_MS); // Off for 1000 ms
      break;
    case CONFIG:
      digitalWrite(ledPin, HIGH);
      vTaskDelay(25 / portTICK_PERIOD_MS); // On for 25 ms
      digitalWrite(ledPin, LOW);
      vTaskDelay(100 / portTICK_PERIOD_MS); // Off for 100 ms
      break;
    }
  }
}

/**
 * @brief Activates LEDs based on the number of players.
 *
 * This function turns on the appropriate number of LEDs based on the number of players.
 * It also updates the display to show the status of each LED.
 *
 * @param nbPlayers The number of players.
 * @param showStatus Whether to show the status on the display.
 */
void activateLeds(int nbPlayers, bool showStatus)
{
  if (nbPlayers > 4)
  {
    nbPlayers = 4;
  }
  else if (nbPlayers < 0)
  {
    nbPlayers = 1;
  }

  bool ledStatus[4] = {false, false, false, false};
  for (int currentJoy = 0; currentJoy < nbPlayers; currentJoy++)
  {
    ledStatus[currentJoy] = true;
  }
  for (int currentJoy = 0; currentJoy < 4; currentJoy++)
  {
    if (ledStatus[currentJoy])
    {
      if (showStatus)
      {
        display.drawXbm(joyPos[currentJoy] * 32, 32, Joystick_icon_width, Joystick_icon_width, JoyON[currentJoy]);
      }
    }
    else
    {
      if (showStatus)
      {
        display.drawXbm(joyPos[currentJoy] * 32, 32, Joystick_icon_width, Joystick_icon_width, JoyOFF[currentJoy]);
      }
    }
  }
}

/**
 * @brief Initializes the LED pin, serial communication, and creates the FreeRTOS tasks.
 *
 * This function sets up the necessary hardware and tasks for managing the LED.
 */
void setupLED()
{
  // Initialize pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Initialize serial port
  Serial.begin(115200);

  // Create tasks
  xTaskCreatePinnedToCore(
      manageLED,    // Task function
      "Manage LED", // Task name
      1024,         // Stack size
      NULL,         // Task parameter
      1,            // Task priority
      &Task1,       // Task handle
      1);           // CPU core to run the task
}
