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
 * @file ledStatus.h
 * @brief Header file for managing an LED using FreeRTOS tasks on an Arduino-compatible microcontroller.
 *
 * This file contains the definitions and function prototypes required to manage an LED connected to a GPIO pin.
 * The LED can be in one of four states: OFF, READY, WAITING, or CONFIG, each causing different behavior in the LED.
 * The management of the LED state is handled by FreeRTOS tasks to ensure efficient multitasking.
 *
 * The tasks defined in this file include:
 * - manageLED: Controls the LED behavior based on the current status.
 * - setupLED: Initializes the LED pin, serial communication, and creates the FreeRTOS tasks.
 * - activateLeds: Activates LEDs based on the number of players.
 */

#ifndef LEDSTATUS_H
#define LEDSTATUS_H

#include <Arduino.h>
#include "HT_SSD1306Wire.h"
#include "images.h"
#include "display.h" // Include display.h to use the display object
#include "firmware_config.h"

// Pin definitions
const int ledPin = LED; // LED connected to GPIO pin

/**
 * @enum LedStatus
 * @brief Enumeration for the different states of the LED.
 *
 * This enum defines the possible states for the LED:
 * - OFF: LED is turned off.
 * - READY: LED is turned on continuously.
 * - WAITING: LED blinks with a specific pattern indicating waiting status.
 * - CONFIG: LED blinks with a specific pattern indicating configuration status.
 */
enum LedStatus
{
    OFF,
    READY,
    WAITING,
    CONFIG
};

extern int joyPos[4];                    ///< Positions of the joysticks on the display
extern volatile LedStatus currentStatus; ///< Current status of the LED.
extern TaskHandle_t Task1;               ///< Handle for the LED management task.

/**
 * @brief Task function to manage the LED behavior based on the current status.
 *
 * This function runs in an infinite loop, checking the current status of the LED and
 * updating its state accordingly. The behavior of the LED changes depending on the value of currentStatus.
 *
 * @param pvParameters Pointer to the parameters passed to the task (not used in this case).
 */
void manageLED(void *pvParameters);

/**
 * @brief Activates LEDs based on the number of players.
 *
 * @param nbPlayers The number of players.
 * @param showStatus Whether to show the status on the display.
 */
void activateLeds(int nbPlayers, bool showStatus = true);

/**
 * @brief Initializes the LED pin, serial communication, and creates the FreeRTOS tasks.
 */
void setupLED();

/**
 * @brief Physically disconnect all joysticks
 */
void disconnectAllRelays();
#endif // LEDSTATUS_H
