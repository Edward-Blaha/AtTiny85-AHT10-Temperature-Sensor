/*-----------------------------------------------------------------------------------------------------*/
/*              This is a Library designed for the AtTiny25/45/85 AVR microcontroller                  */
/*                                  series to read data from the AHT10.                                */
/*       By Utilising the TinyWireM library by AdaFruit, This sensor outputs two uint16 values for     */
/*                                         temperature and humidity                                    */
/*                                                                                                     */
/*                            Dedicated to the public domain via The Unlicense.                        */
/*                              See https://unlicense.org/ for details.                                */
/*                                                                                                     */
/*         For more information about this project, please visit https://github.com/Edward-Blaha       */
/*-----------------------------------------------------------------------------------------------------*/
#ifndef TINY_AHT10_H
#define TINY_AHT10_H

#define DEGREES_CELSIUS 'C'
#define DEGREES_FAHRENHEIT 'F'

#include <TinyWireM.h>

class Tiny_AHT10{
  public:
  byte _AHT10_ADDR;
  void aht10Init(byte AHT10_ADDR_INPUT);
  bool aht10Read(int16_t &_temp_x10, uint16_t &_hum_x10, char units);
  char units;
};

#endif
