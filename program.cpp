#include "program.h"


// Led scrolling
void independantProgram1(int color, int updates, int * counter, Led * leds, int * red, int * green, int * blue, int * predefined_red, int * predefined_green, int * predefined_blue){
  
  //singleColor(color, predefined_red, predefined_green, predefined_blue);
  predefinedColors(color, predefined_red, predefined_green, predefined_blue);
  
  
  updates = 10 + updates / 50;

  while(!graduallyTurnOn(leds[0], predefined_red[0], predefined_green[0], predefined_blue[0], &red[0], &green[0], &blue[0])) {
    graduallyTurnOn(leds[2], predefined_red[2], predefined_green[2], predefined_blue[2], &red[2], &green[2], &blue[2]);
    graduallyTurnOn(leds[4], predefined_red[4], predefined_green[4], predefined_blue[4], &red[4], &green[4], &blue[4]);
    graduallyTurnOn(leds[6], predefined_red[6], predefined_green[6], predefined_blue[6], &red[6], &green[6], &blue[6]);
    delay(updates);
    Tlc.update();
  }
  while(!graduallyTurnOff(leds[0], &red[0], &green[0], &blue[0])) {
    graduallyTurnOff(leds[2], &red[2], &green[2], &blue[2]);
    graduallyTurnOff(leds[4], &red[4], &green[4], &blue[4]);
    graduallyTurnOff(leds[6], &red[6], &green[6], &blue[6]);
    delay(updates);
    Tlc.update();
  }

  
}
