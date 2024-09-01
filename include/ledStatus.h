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
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ****************************************************************************************/

/**
 * @file ledStatus.h
 * @brief Header file for managing LED statuses using FreeRTOS tasks on an Arduino-compatible microcontroller.
 *
 * This file contains definitions, enumerations, and function prototypes for controlling LED behavior
 * based on different system statuses. The LED can represent various states such as OFF, READY, WAITING,
 * and CONFIG, each with distinct blinking patterns or illumination behaviors. The control is managed
 * using FreeRTOS tasks to allow concurrent operations within the system.
 */

#ifndef LEDSTATUS_H
#define LEDSTATUS_H

#include <Arduino.h>
#include <Wire.h>
#include "images.h"
#include "display.h"         ///< Includes the display functionalities.
#include "firmware_config.h" ///< Includes firmware configuration settings.

/**
 * @enum LedStatus
 * @brief Enumeration defining the various LED states.
 *
 * This enumeration represents the different statuses that the LED can indicate:
 * - **OFF**: The LED is turned off.
 * - **READY**: The LED is steadily lit, indicating readiness.
 * - **WAITING**: The LED blinks slowly, indicating a waiting state.
 * - **CONFIG**: The LED blinks rapidly, indicating configuration mode.
 */
enum LedStatus
{
    OFF,     ///< LED is turned off.
    READY,   ///< LED is steadily lit.
    WAITING, ///< LED blinks slowly.
    CONFIG   ///< LED blinks rapidly.
};

/**
 * @brief Array storing the positions of the joysticks on the display.
 *
 * This array holds the positional values for up to 4 joysticks, which are used
 * to render their status correctly on the display.
 */
extern int joyPos[4];

/**
 * @brief Current operational status of the LED.
 *
 * This volatile variable represents the current status of the LED, which can be
 * modified by different tasks or interrupt service routines to reflect the system's state.
 */
extern volatile LedStatus currentStatus;

/**
 * @brief Handle for the FreeRTOS task managing the LED behavior.
 *
 * This task handle is used to control and monitor the task responsible for updating
 * the LED based on the currentStatus value.
 */
extern TaskHandle_t Task1;

/**
 * @brief FreeRTOS task function that manages LED behavior based on system status.
 *
 * This function runs as a FreeRTOS task and continuously monitors the `currentStatus` variable
 * to update the LED's state accordingly. It adjusts the LED's blinking pattern or illumination
 * to represent different statuses such as OFF, READY, WAITING, and CONFIG.
 *
 * @param pvParameters Pointer to task parameters (unused in this context).
 */
void manageLED(void *pvParameters);

/**
 * @brief Activates the LEDs corresponding to the connected players and updates the display.
 *
 * This function turns on the LEDs associated with the specified number of players and optionally
 * updates the display to reflect the current player status.
 *
 * @param nbPlayers The number of players currently connected (range: 1 to 4).
 * @param showStatus Optional parameter to control display update:
 *                   - `true` (default): Update the display with the current player status.
 *                   - `false`: Do not update the display.
 */
void activateLeds(int nbPlayers, bool showStatus = true);

/**
 * @brief Initializes the LED system and related FreeRTOS tasks.
 *
 * This function sets up the necessary hardware and software components for LED management,
 * including configuring the LED pin modes, initializing serial communication if needed,
 * and creating the FreeRTOS task `manageLED` responsible for controlling LED behavior.
 */
void setupLED();

/**
 * @brief Disconnects all joysticks by deactivating their respective relays.
 *
 * This function ensures that all joystick connections are physically disconnected by
 * turning off all associated relays. It is useful for resetting the system or entering
 * a safe state where no input is registered.
 */
void disconnectAllRelays();

#endif // LEDSTATUS_H
