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
 * @file powerManagement.h
 * @brief Header file for managing power supply (Vext) on the microcontroller.
 *
 * This file contains the function declarations for turning on and off the Vext power supply.
 */

#ifndef POWERMANAGEMENT_H
#define POWERMANAGEMENT_H

#include <Arduino.h>

// Function declarations

/**
 * @brief Turns on the Vext power supply.
 *
 * This function sets the Vext pin to OUTPUT mode and writes a LOW signal to turn on the Vext power supply.
 */
void VextON(void);

/**
 * @brief Turns off the Vext power supply.
 *
 * This function sets the Vext pin to OUTPUT mode and writes a HIGH signal to turn off the Vext power supply.
 */
void VextOFF(void);

// Manage VEXT
void VextON(void)
{
    pinMode(Vext, OUTPUT);
    digitalWrite(Vext, LOW);
}

void VextOFF(void) // Vext default OFF
{
    pinMode(Vext, OUTPUT);
    digitalWrite(Vext, HIGH);
}
#endif // POWERMANAGEMENT_H
