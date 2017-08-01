// Update the configuration file of the TLC to put 3 TLC in cascade
#include "Tlc5940.h"
#include "led.h"


// Initialization of a table of Leds and its RGB components
Led leds[16];
int red[16];
int green[16];
int blue[16];

// Initialization of tables of predefined colors
int predefined_red[16];
int predefined_green[16];
int predefined_blue[16];

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
  //predefinedColors(300, predefined_red, predefined_green, predefined_blue);
  for(int i=0 ; i<1024 ; ++i){
    singleColor(i, predefined_red, predefined_green, predefined_blue);
    for(int j=0 ; j<9 ; ++j){
      //lightLed(leds[i], predefined_red[i], predefined_green[i], predefined_blue[i]);
      lightLed(leds[j], predefined_red[0], predefined_green[0], predefined_blue[0]);
    }
    Tlc.update();
    delay(20);
    Tlc.clear();
  }
  
}
