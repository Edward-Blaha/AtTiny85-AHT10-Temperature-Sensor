Tiny_AHT10
A lightweight Arduino library specifically optimized for the ATtiny25/45/85 series to read temperature and humidity from the AHT10 sensor. 
By utilizing the TinyWireM library instead of the standard Wire library, this project maintains a minimal memory footprint, 
making it ideal for small-scale AVR projects.
- Small Footprint: Optimized for ATtiny microcontrollers.
- Dual Unit Support: Code is optimised to output temperature in both Celsius ('C') and Fahrenheit ('F').
- Fixed-Point Precision: Returns values multiplied by 10 (e.g., 25.5°C is returned as 255) to avoid the heavy memory overhead of float calculations.

Please! Make sure to install the TinyWireM.h prior to use, otherwise program will fail to compile.

