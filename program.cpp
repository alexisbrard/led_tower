#include "program.h"


// Led scrolling
void independantProgram1(int color, int scrolling_speed, int * counter, Led * leds, int * predefined_red, int * predefined_green, int * predefined_blue){
  
  //singleColor(color, predefined_red, predefined_green, predefined_blue);
  predefinedColors(color, predefined_red, predefined_green, predefined_blue);
  
  int i=0;
  for (i=0 ; i<16 ; ++i)
    lightLed(leds[i], predefined_red[i], predefined_green[i], predefined_blue[i]);

 
  
}
