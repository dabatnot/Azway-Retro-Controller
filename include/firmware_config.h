// constants.h
#ifndef FIRMWARE_CONFIG_H
#define FIRMWARE_CONFIG_H

const char CONTROLLER_VERSION[] = "v1.1.16";

//===============================
// USED PINS.
// Some pins should be avoided as they are used by builtin features like on board OLED screen.
// This pin list is safe, some other will work as well but you can run into an issue where ESPTOOL won't be able to
// flash the ESP.
// Be warned :)
#ifdef HELTEC
// CustomDisplay display(U8G2_R0, /* reset=*/21, /* clock=*/18, /* data=*/17);
const int I2CSDA = 17;
const int I2CSCL = 18;
const int I2CRESET = 21;
const int RELAY1 = 7;
const int RELAY2 = 6;
const int RELAY3 = 5;
const int RELAY4 = 4;
const int RELAY5 = 3;
const int RELAY6 = 2;
const int RELAY7 = 26;
const int RELAY8 = 48;
const int RELAY[8] = {RELAY1, RELAY2, RELAY3, RELAY4, RELAY5, RELAY6, RELAY7, RELAY8};
// Pin definitions
const int ledPin = LED; // LED connected to GPIO pin
#endif

/// CustomDisplay display(U8G2_R0, /* reset=*/21);
// CustomDisplay display(U8G2_R0, /* reset=*/21, /* clock=*/18, /* data=*/17);
// CustomDisplay display(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
#ifdef DEVKIT
const int I2CSDA = 21;
const int I2CSCL = 22;
const int I2CRESET = U8X8_PIN_NONE;
const int RELAY1 = 15;
const int RELAY2 = 2;
const int RELAY3 = 4;
const int RELAY4 = 16;
const int RELAY5 = 17;
const int RELAY6 = 5;
const int RELAY7 = 18;
const int RELAY8 = 19;
const int RELAY[8] = {RELAY1, RELAY2, RELAY3, RELAY4, RELAY5, RELAY6, RELAY7, RELAY8};
// Pin definitions
const int ledPin = 2; // LED connected to GPIO pin
#endif
#endif