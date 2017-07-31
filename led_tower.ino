// Update the configuration file of the TLC to put 3 TLC in cascade
#include "Tlc5940.h"
#include "led.h"


// Initialization of a table of Leds and its RGB components
Led leds[16];
int red[16];
int green[16];
int blue[16];

void setup() {
  
  // Association of Leds to its RGB components
  for (int i=0 ; i<16 ; ++i){
    leds[i].red = i;
    leds[i].green = i + 16;
    leds[i].blue = i + 32;
  }

  // TLC initialization
  Tlc.init();
  Tlc.clear();
}

void loop() {
  lightLed(leds[0], 255, 0, 0);
  lightLed(leds[1], 0, 0, 255);
  lightLed(leds[3], 0, 255, 0);
  Tlc.update();
  delay(1000);
  
  lightLed(leds[0], 0, 0, 255);
  lightLed(leds[1], 255, 0, 0);
  Tlc.update();
  delay(1000);
}
