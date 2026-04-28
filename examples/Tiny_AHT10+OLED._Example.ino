/*-----------------------------------------------------------------------------------------------------*/
/*                         This is an EXAMPLE usecase of the Tiny_AHT10 Library.                       */
/*       By Utilising the TinyWireM library by AdaFruit, as well as the Tiny4kOLED.h lib, we can       */
/*                    display temperature data on an interval at low power consumption!                */
/*                            Dedicated to the public domain via The Unlicense.                        */
/*                              See https://unlicense.org/ for details.                                */
/*                                                                                                     */
/*         For more information about this project, please visit https://github.com/Edward-Blaha       */
/*                                    Code design by Edward Blaha                                      */
/*-----------------------------------------------------------------------------------------------------*/

#include <Tiny4kOLED.h>
#include "Tiny_AHT10.h"

// Create an instance of your library
Tiny_AHT10 mySensor;

// Standard I2C address for AHT10 is 0x38
const byte AHT10_I2C_ADDR = 0x38;

void setup() {

  // 3. Initialize your AHT10 library
  mySensor.aht10Init(AHT10_I2C_ADDR);
  oled.begin();
  oled.on();
  oled.setFont(FONT6X8);
  oled.clear();

  oled.setCursor(0, 0);
  oled.print(F("System Ready..."));
  delay(300);
}

void loop() {
  int16_t temp;
  uint16_t hum;

  // Request data in Fahrenheit (DEGREES_FAHRENHEIT) or Celsius (DEGREES_CELSIUS)
  if (mySensor.aht10Read(temp, hum, DEGREES_CELSIUS)) {
    oled.clear();

    // --- Display Temperature ---
    oled.setCursor(0, 0);
    oled.print(F("Temp: "));
    oled.print(temp / 10);
    oled.print('.');
    oled.print(abs(temp % 10)); // abs ensures decimal digit is always positive
    oled.print(DEGREES_CELSIUS);

    // --- Display Humidity ---
    oled.setCursor(0, 1);
    oled.print(F("Hum:  "));
    oled.print(hum / 10);
    oled.print('.');
    oled.print(hum % 10);
    oled.print(F(" %"));

  } else {
    // If the sensor is busy or not found
    oled.setCursor(0, 0);
    oled.print(F("Sensor Error!"));
  }

  // AHT10 shouldn't be read faster than once every 2 seconds
  delay(2000);
}
