/*
  Flinduino Version of the Arduino_Grove_Library.h - Library wrapper for the Arduino Sensor Kit https://sensorkit.arduino.cc/
  Created by Craig Dawson, 2021
  Released into the public domain.
*/

#ifndef Flinduino_SensorKit_h
#define Flinduino_SensorKit_h

#include "Arduino.h"
#include "Wire.h"

//Libraries for components
#include "Flinduino_SensorKit_BMP280.h"   	// Pressure
#include "Flinduino_SensorKit_LIS3DHTR.h" 	// Accel
#include "Flinduino_SensorKit_DHTLINK_Class.h"
#include "DHT.h"                        	// Temp & Humidity
#include "DHT20.h"                        	// Temp & Humidity
#include "U8x8lib.h"                    	// OLED Display
#include "U8G2lib.h"						// OLED Graphics Library



//flinduino pins for I2C
#define SCL 24
#define SDA 23

//Make the declared components from the .cpp to the sketch available
//extern U8X8_SSD1306_128X64_NONAME_SW_I2C Oled;
extern U8X8_SSD1306_128X64_NONAME_HW_I2C Oled;
extern U8G2_SSD1306_128X64_NONAME_1_HW_I2C OledG;
extern SensorKit_LIS3DHTR Accelerometer;
extern SensorKit_BMP280 Pressure;
extern DHTLINK Environment;
#endif
