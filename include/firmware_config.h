// constants.h
#ifndef FIRMWARE_CONFIG_H
#define FIRMWARE_CONFIG_H

const char CONTROLLER_VERSION[] = "v1.1.15";

//===============================
// USED PINS.
// Some pins should be avoided as they are used by builtin features like on board OLED screen.
// This pin list is safe
const int RELAY1 = 7;
const int RELAY2 = 6;
const int RELAY3 = 5;
const int RELAY4 = 4;
const int RELAY5 = 3;
const int RELAY6 = 2;
const int RELAY7 = 26;
const int RELAY8 = 48;
const int RELAY[8] = {RELAY1, RELAY2, RELAY3, RELAY4, RELAY5, RELAY6, RELAY7, RELAY8};

#endif