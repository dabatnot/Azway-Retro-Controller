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
 * This file includes various bitmap images stored in PROGMEM to be used with the OLED display.
 * Each bitmap has its width, height, and byte array defined.
 */

#ifndef IMAGES_H
#define IMAGES_H

#include <Arduino.h>

#define Azway_Logo_width 70
#define Azway_Logo_height 25
extern const uint8_t Azway_Logo[];

#define Player_icon_width 25
#define Player_icon_height 25
extern const uint8_t player1_on[];
extern const uint8_t player2_on[];
extern const uint8_t player3_on[];
extern const uint8_t player4_on[];
extern const uint8_t player1_off[];
extern const uint8_t player2_off[];
extern const uint8_t player3_off[];
extern const uint8_t player4_off[];

extern const int player_off_LEN;
extern const uint8_t *player_off[];
extern const int player_on_LEN;
extern const uint8_t *player_on[];

#define Joystick_icon_width 32
#define Joystick_icon_height 32
extern const uint8_t JoyONJ1On[];
extern const uint8_t JoyONJ2On[];
extern const uint8_t JoyONJ3On[];
extern const uint8_t JoyONJ4On[];
extern const uint8_t JoyOFFJ1Off[];
extern const uint8_t JoyOFFJ2Off[];
extern const uint8_t JoyOFFJ3Off[];
extern const uint8_t JoyOFFJ4Off[];

extern const int JoyON_LEN;
extern const uint8_t *JoyON[];
extern const int JoyOFF_LEN;
extern const uint8_t *JoyOFF[];

#define Frame_width 128
#define Frame_height 32
extern const uint8_t FrameTopFrame[];
extern const uint8_t FrameBottomFrame[];

extern const int BmpFrame_LEN;
extern const uint8_t *BmpFrame[];

#define bmpStatus_width 63
#define bmpStatus_height 10
extern const uint8_t bmpStatus[];

#define bmpStar_width 16
#define bmpStar_height 15
extern const uint8_t FrameStarBlack[];
extern const uint8_t FrameStarWhite[];

extern const int bmpStar_LEN;
extern const uint8_t *bmpStar[];

#define bmpConnection_width 120
#define bmpConnection_height 22
extern const uint8_t ConnectionStateConnected[];
extern const uint8_t ConnectionStateConnecting[];

extern const int ConnectionStateallArray_LEN;
extern const uint8_t *ConnectionStateallArray[];

#define bmpRocket_width 14
#define bmpRocket_height 19
extern const uint8_t bmpRocket[];

#define bmpStarting_width 80
#define bmpStarting_height 10
extern const uint8_t bmpStarting[];

#define bmpZZZ_width 17
#define bmpZZZ_height 15
extern const uint8_t bmpZZZ[];

#define bmpStopping_width 80
#define bmpStopping_height 10
extern const uint8_t bmpStopping[];

#define bmpStopped_width 74
#define bmpStopped_height 10
extern const uint8_t bmpStopped[];

#define bmpBye_width 20
#define bmpBye_height 14
extern const uint8_t bmpBye[];

#endif // IMAGES_H
