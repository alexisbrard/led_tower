// Update the configuration file of the TLC to put 3 TLC in cascade
#include "Tlc5940.h"
#include "led.h"

Led led1;
Led led2;

void setup() {
  led1.red = 0;
  led1.green = 16;
  led1.blue = 32;
  
  led2.red = 1;
  led2.green = 17;
  led2.blue = 33;
}

void loop() {

}
