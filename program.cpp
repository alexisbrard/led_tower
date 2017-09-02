#include "program.h"


// Led scrolling
void independantProgram1(int color, int scrolling_speed, int * counter, Led * leds, int * red, int * green, int * blue){
  
  //singleColor(color, red, green, blue);
  predefinedColors(color, red, green, blue);
  
  int i=0;
  for (i=0 ; i<16 ; ++i) 
  {
    //lightLed(leds[i], red[0], green[0], blue[0]);
    lightLed(leds[i], red[i], green[i], blue[i]);
  }

 
  
}
