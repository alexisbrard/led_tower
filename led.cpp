#include "led.h"

//
void lightLed(Led led, int r, int g, int b) {
  Tlc.set(led.red, r);                           // Red component of the LED
  Tlc.set(led.green, g);                         // Green component of the LED
  Tlc.set(led.blue, b);                          // Blue component of the LED
}
