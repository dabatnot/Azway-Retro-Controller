#ifndef FIRMWARE_CONFIG_H
#define FIRMWARE_CONFIG_H

/**
 * @file constants.h
 * @brief Defines the configuration constants and pin mappings for the firmware.
 *
 * This file contains the version information, pin definitions, and other configuration
 * constants used in the firmware. It includes specific pin mappings for different hardware
 * configurations, such as HELTEC and DEVKIT, to ensure proper operation of the device.
 */

/**
 * @brief Firmware version identifier.
 *
 * This constant holds the version information of the controller firmware.
 */
const char CONTROLLER_VERSION[] = "v1.2.0";

//===============================
// USED PINS.
// Some pins should be avoided as they are used by built-in features like the on-board OLED screen.
// This pin list is safe; however, using other pins may cause issues, such as ESPTOOL being unable to
// flash the ESP. Proceed with caution when modifying pin assignments.
#ifdef HELTEC

/**
 * @brief I2C Data (SDA) pin for HELTEC configuration.
 */
const int I2CSDA = 17;

/**
 * @brief I2C Clock (SCL) pin for HELTEC configuration.
 */
const int I2CSCL = 18;

/**
 * @brief I2C Reset pin for HELTEC configuration.
 */
const int I2CRESET = 21;

/**
 * @brief GPIO pin for controlling relay 1.
 */
const int RELAY1 = 7;

/**
 * @brief GPIO pin for controlling relay 2.
 */
const int RELAY2 = 6;

/**
 * @brief GPIO pin for controlling relay 3.
 */
const int RELAY3 = 5;

/**
 * @brief GPIO pin for controlling relay 4.
 */
const int RELAY4 = 4;

/**
 * @brief GPIO pin for controlling relay 5.
 */
const int RELAY5 = 3;

/**
 * @brief GPIO pin for controlling relay 6.
 */
const int RELAY6 = 2;

/**
 * @brief GPIO pin for controlling relay 7.
 */
const int RELAY7 = 26;

/**
 * @brief GPIO pin for controlling relay 8.
 */
const int RELAY8 = 48;

/**
 * @brief Array of relay GPIO pins for HELTEC configuration.
 *
 * This array contains the GPIO pin numbers assigned to each relay, making it easier to iterate
 * through relays for operations like initialization or state changes.
 */
const int RELAY[8] = {RELAY1, RELAY2, RELAY3, RELAY4, RELAY5, RELAY6, RELAY7, RELAY8};

/**
 * @brief GPIO pin for controlling the onboard LED.
 *
 * This constant defines the GPIO pin connected to the onboard LED in the HELTEC configuration.
 */
const int ledPin = LED;

#endif // HELTEC

#ifdef DEVKIT

/**
 * @brief I2C Data (SDA) pin for DEVKIT configuration.
 */
const int I2CSDA = 21;

/**
 * @brief I2C Clock (SCL) pin for DEVKIT configuration.
 */
const int I2CSCL = 22;

/**
 * @brief I2C Reset pin for DEVKIT configuration.
 *
 * This pin is defined as U8X8_PIN_NONE, indicating that no reset pin is used for the I2C device.
 */
const int I2CRESET = U8X8_PIN_NONE;

/**
 * @brief GPIO pin for controlling relay 1 in DEVKIT configuration.
 */
const int RELAY1 = 15;

/**
 * @brief GPIO pin for controlling relay 2 in DEVKIT configuration.
 */
const int RELAY2 = 2;

/**
 * @brief GPIO pin for controlling relay 3 in DEVKIT configuration.
 */
const int RELAY3 = 4;

/**
 * @brief GPIO pin for controlling relay 4 in DEVKIT configuration.
 */
const int RELAY4 = 16;

/**
 * @brief GPIO pin for controlling relay 5 in DEVKIT configuration.
 */
const int RELAY5 = 17;

/**
 * @brief GPIO pin for controlling relay 6 in DEVKIT configuration.
 */
const int RELAY6 = 5;

/**
 * @brief GPIO pin for controlling relay 7 in DEVKIT configuration.
 */
const int RELAY7 = 18;

/**
 * @brief GPIO pin for controlling relay 8 in DEVKIT configuration.
 */
const int RELAY8 = 19;

/**
 * @brief Array of relay GPIO pins for DEVKIT configuration.
 *
 * This array contains the GPIO pin numbers assigned to each relay, making it easier to iterate
 * through relays for operations like initialization or state changes.
 */
const int RELAY[8] = {RELAY1, RELAY2, RELAY3, RELAY4, RELAY5, RELAY6, RELAY7, RELAY8};

/**
 * @brief GPIO pin for controlling the onboard LED in DEVKIT configuration.
 *
 * This constant defines the GPIO pin connected to the onboard LED in the DEVKIT configuration.
 */
const int ledPin = 2;

#endif // DEVKIT

#endif // FIRMWARE_CONFIG_H
