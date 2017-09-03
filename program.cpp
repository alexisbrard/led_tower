#include "program.h"
#include "Tlc5940.h"


// Led scrolling
void independantProgram1(int color, int scrolling_speed, int * counter, Led * leds, int * red, int * green, int * blue){
  
  //singleColor(color, red, green, blue);
  /*predefinedColors(color, red, green, blue);
  
  int i=0;
  for (i=0 ; i<16 ; ++i) 
  {
    //lightLed(leds[i], red[0], green[0], blue[0]);
    lightLed(leds[i], red[i], green[i], blue[i]);
  }*/

  while(!graduallyTurnOn(leds[0], 3000, 2000, 4095, &red[0], &green[0], &blue[0])) {
    delay(20);
    Tlc.update();
  }
  while(!graduallyTurnOff(leds[0], &red[0], &green[0], &blue[0])) {
    delay(20);
    Tlc.update();
  }

  
}
