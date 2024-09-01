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
 * @file powerManagement.h
 * @brief Header file for managing the external power supply (Vext) on the microcontroller.
 *
 * This file contains function declarations to control the Vext power supply pin, allowing the
 * microcontroller to enable or disable the external power supply as needed. This can be useful
 * for managing power consumption in battery-powered devices or controlling peripheral devices
 * connected to the microcontroller.
 */

#ifndef POWERMANAGEMENT_H
#define POWERMANAGEMENT_H

#include <Arduino.h>

// Function declarations

/**
 * @brief Turns on the external power supply (Vext).
 *
 * This function configures the Vext pin as an output and sets it to LOW, enabling the external
 * power supply. This can be used to power external peripherals or circuits connected to the Vext line.
 */
void VextON(void);

/**
 * @brief Turns off the external power supply (Vext).
 *
 * This function configures the Vext pin as an output and sets it to HIGH, disabling the external
 * power supply. This is useful for reducing power consumption when external peripherals or circuits
 * connected to the Vext line are not needed.
 */
void VextOFF(void);

#endif // POWERMANAGEMENT_H
