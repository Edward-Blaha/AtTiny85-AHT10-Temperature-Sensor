/*-----------------------------------------------------------------------------------------------------*/
/*                                     Code done by Edward Blaha                                       */
/*                                                                                                     */
/*                        This is the CPP file for use with the Tiny_AHT10.h lib                       */
/*                          designed for the AtTiny25/45/85 AVR microcontroller                        */
/*                                  series to read data from the AHT10.                                */
/*       By Utilising the TinyWireM library by AdaFruit, This sensor outputs two uint16 values for     */
/*                                         temperature and humidity                                    */
/*                                                                                                     */
/*                            Dedicated to the public domain via The Unlicense.                        */
/*                              See https://unlicense.org/ for details.                                */
/*                                                                                                     */
/*         For more information about this project, please visit https://github.com/Edward-Blaha       */
/*-----------------------------------------------------------------------------------------------------*/
#include "Tiny_AHT10.h"

void Tiny_AHT10::aht10Init(byte AHT10_ADDR_INPUT) {
  _AHT10_ADDR = AHT10_ADDR_INPUT;
  TinyWireM.beginTransmission(_AHT10_ADDR);
  TinyWireM.send(0xE1); // initialization command
  TinyWireM.send(0x08);
  TinyWireM.send(0x00);
  TinyWireM.endTransmission();
  delay(23);
}

bool Tiny_AHT10::aht10Read(int16_t &_temp_x10, uint16_t &_hum_x10, char units) {
  // Trigger measurement

  TinyWireM.beginTransmission(_AHT10_ADDR);
  TinyWireM.send(0xAC);
  TinyWireM.send(0x33);
  TinyWireM.send(0x00);
  TinyWireM.endTransmission();
  delay(40);
  

  TinyWireM.requestFrom(_AHT10_ADDR, 6);
  if (TinyWireM.available() != 6) return false;

  uint8_t b[6];
  for (uint8_t i = 0; i < 6; i++) b[i] = TinyWireM.receive();

  if (b[0] & 0x80) return false; // busy

  uint32_t rawHum =
    ((uint32_t)b[1] << 12) |
    ((uint32_t)b[2] << 4) |
    (b[3] >> 4);

  uint32_t rawTemp = (((uint32_t)b[3] & 0x0F) << 16) | ((uint32_t)b[4] << 8) | b[5];
  
  _hum_x10  = (rawHum * 1000UL) >> 20;        // %RH ×10
  int32_t celsius_x10 = ((rawTemp * 2000UL) >> 20) - 500;
  
  if(units == 'C'){
    _temp_x10 = celsius_x10;
  }
  else if(units == 'F'){
    _temp_x10 = (int16_t)((celsius_x10 * 9 / 5) + 320);
  }
  
  return true;
}


