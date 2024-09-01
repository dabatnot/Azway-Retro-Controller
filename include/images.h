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
 * @file images.h
 * @brief Header file containing bitmap definitions for the OLED display.
 *
 * This file provides the declarations for various bitmap images that are used in the
 * application to be displayed on the OLED screen. The bitmaps are stored in PROGMEM
 * to optimize memory usage. Each bitmap is associated with specific dimensions and
 * a byte array containing the image data.
 */

#ifndef IMAGES_H
#define IMAGES_H

#include <Arduino.h>

/**
 * @brief Width of the Azway logo bitmap in pixels.
 */
#define Azway_Logo_width 70

/**
 * @brief Height of the Azway logo bitmap in pixels.
 */
#define Azway_Logo_height 25

/**
 * @brief Bitmap representing the Azway logo.
 */
extern const uint8_t Azway_Logo[];

/**
 * @brief Width of the player icon bitmaps in pixels.
 */
#define Player_icon_width 25

/**
 * @brief Height of the player icon bitmaps in pixels.
 */
#define Player_icon_height 25

/**
 * @brief Bitmap representing the "Player 1 ON" state.
 */
extern const uint8_t player1_on[];

/**
 * @brief Bitmap representing the "Player 2 ON" state.
 */
extern const uint8_t player2_on[];

/**
 * @brief Bitmap representing the "Player 3 ON" state.
 */
extern const uint8_t player3_on[];

/**
 * @brief Bitmap representing the "Player 4 ON" state.
 */
extern const uint8_t player4_on[];

/**
 * @brief Bitmap representing the "Player 1 OFF" state.
 */
extern const uint8_t player1_off[];

/**
 * @brief Bitmap representing the "Player 2 OFF" state.
 */
extern const uint8_t player2_off[];

/**
 * @brief Bitmap representing the "Player 3 OFF" state.
 */
extern const uint8_t player3_off[];

/**
 * @brief Bitmap representing the "Player 4 OFF" state.
 */
extern const uint8_t player4_off[];

/**
 * @brief Number of player "OFF" state bitmaps.
 */
extern const int player_off_LEN;

/**
 * @brief Array of pointers to player "OFF" state bitmaps.
 */
extern const uint8_t *player_off[];

/**
 * @brief Number of player "ON" state bitmaps.
 */
extern const int player_on_LEN;

/**
 * @brief Array of pointers to player "ON" state bitmaps.
 */
extern const uint8_t *player_on[];

/**
 * @brief Width of the joystick icon bitmaps in pixels.
 */
#define Joystick_icon_width 32

/**
 * @brief Height of the joystick icon bitmaps in pixels.
 */
#define Joystick_icon_height 32

/**
 * @brief Bitmap representing the "Joystick 1 ON" state.
 */
extern const uint8_t JoyONJ1On[];

/**
 * @brief Bitmap representing the "Joystick 2 ON" state.
 */
extern const uint8_t JoyONJ2On[];

/**
 * @brief Bitmap representing the "Joystick 3 ON" state.
 */
extern const uint8_t JoyONJ3On[];

/**
 * @brief Bitmap representing the "Joystick 4 ON" state.
 */
extern const uint8_t JoyONJ4On[];

/**
 * @brief Bitmap representing the "Joystick 1 OFF" state.
 */
extern const uint8_t JoyOFFJ1Off[];

/**
 * @brief Bitmap representing the "Joystick 2 OFF" state.
 */
extern const uint8_t JoyOFFJ2Off[];

/**
 * @brief Bitmap representing the "Joystick 3 OFF" state.
 */
extern const uint8_t JoyOFFJ3Off[];

/**
 * @brief Bitmap representing the "Joystick 4 OFF" state.
 */
extern const uint8_t JoyOFFJ4Off[];

/**
 * @brief Number of joystick "ON" state bitmaps.
 */
extern const int JoyON_LEN;

/**
 * @brief Array of pointers to joystick "ON" state bitmaps.
 */
extern const uint8_t *JoyON[];

/**
 * @brief Number of joystick "OFF" state bitmaps.
 */
extern const int JoyOFF_LEN;

/**
 * @brief Array of pointers to joystick "OFF" state bitmaps.
 */
extern const uint8_t *JoyOFF[];

/**
 * @brief Width of the frame bitmaps in pixels.
 */
#define Frame_width 128

/**
 * @brief Height of the frame bitmaps in pixels.
 */
#define Frame_height 32

/**
 * @brief Bitmap representing the top frame of the display.
 */
extern const uint8_t FrameTopFrame[];

/**
 * @brief Bitmap representing the bottom frame of the display.
 */
extern const uint8_t FrameBottomFrame[];

/**
 * @brief Number of frame bitmaps.
 */
extern const int BmpFrame_LEN;

/**
 * @brief Array of pointers to frame bitmaps.
 */
extern const uint8_t *BmpFrame[];

/**
 * @brief Width of the status bitmap in pixels.
 */
#define bmpStatus_width 63

/**
 * @brief Height of the status bitmap in pixels.
 */
#define bmpStatus_height 10

/**
 * @brief Bitmap representing a status icon.
 */
extern const uint8_t bmpStatus[];

/**
 * @brief Width of the star bitmaps in pixels.
 */
#define bmpStar_width 16

/**
 * @brief Height of the star bitmaps in pixels.
 */
#define bmpStar_height 15

/**
 * @brief Bitmap representing a black star.
 */
extern const uint8_t FrameStarBlack[];

/**
 * @brief Bitmap representing a white star.
 */
extern const uint8_t FrameStarWhite[];

/**
 * @brief Number of star bitmaps.
 */
extern const int bmpStar_LEN;

/**
 * @brief Array of pointers to star bitmaps.
 */
extern const uint8_t *bmpStar[];

/**
 * @brief Width of the connection state bitmaps in pixels.
 */
#define bmpConnection_width 120

/**
 * @brief Height of the connection state bitmaps in pixels.
 */
#define bmpConnection_height 22

/**
 * @brief Bitmap representing the "Connected" state.
 */
extern const uint8_t ConnectionStateConnected[];

/**
 * @brief Bitmap representing the "Connecting" state.
 */
extern const uint8_t ConnectionStateConnecting[];

/**
 * @brief Number of connection state bitmaps.
 */
extern const int ConnectionStateallArray_LEN;

/**
 * @brief Array of pointers to connection state bitmaps.
 */
extern const uint8_t *ConnectionStateallArray[];

/**
 * @brief Width of the rocket bitmap in pixels.
 */
#define bmpRocket_width 14

/**
 * @brief Height of the rocket bitmap in pixels.
 */
#define bmpRocket_height 19

/**
 * @brief Bitmap representing a rocket icon.
 */
extern const uint8_t bmpRocket[];

/**
 * @brief Width of the "Starting" bitmap in pixels.
 */
#define bmpStarting_width 80

/**
 * @brief Height of the "Starting" bitmap in pixels.
 */
#define bmpStarting_height 10

/**
 * @brief Bitmap representing a "Starting" status.
 */
extern const uint8_t bmpStarting[];

/**
 * @brief Width of the "ZZZ" bitmap in pixels.
 */
#define bmpZZZ_width 17

/**
 * @brief Height of the "ZZZ" bitmap in pixels.
 */
#define bmpZZZ_height 15

/**
 * @brief Bitmap representing a "Sleeping" or "ZZZ" icon.
 */
extern const uint8_t bmpZZZ[];

/**
 * @brief Width of the "Stopping" bitmap in pixels.
 */
#define bmpStopping_width 80

/**
 * @brief Height of the "Stopping" bitmap in pixels.
 */
#define bmpStopping_height 10

/**
 * @brief Bitmap representing a "Stopping" status.
 */
extern const uint8_t bmpStopping[];

/**
 * @brief Width of the "Stopped" bitmap in pixels.
 */
#define bmpStopped_width 74

/**
 * @brief Height of the "Stopped" bitmap in pixels.
 */
#define bmpStopped_height 10

/**
 * @brief Bitmap representing a "Stopped" status.
 */
extern const uint8_t bmpStopped[];

/**
 * @brief Width of the "Bye" bitmap in pixels.
 */
#define bmpBye_width 20

/**
 * @brief Height of the "Bye" bitmap in pixels.
 */
#define bmpBye_height 14

/**
 * @brief Bitmap representing a "Bye" message.
 */
extern const uint8_t bmpBye[];

#endif // IMAGES_H
