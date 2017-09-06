#include "program.h"


// Led scrolling, one color defined by the user with the color potentiometer
void independantProgram1(int color, int updates, int * counter, Led * leds, int * red, int * green, int * blue, int * predefined_red, int * predefined_green, int * predefined_blue){
  
  singleColor(color, predefined_red, predefined_green, predefined_blue);
  
  updates = 10 + updates / 50;

  while(!graduallyTurnOn(leds[*counter], predefined_red[0], predefined_green[0], predefined_blue[0], &red[*counter], &green[*counter], &blue[*counter])) {
    if (*counter > 0)
      graduallyTurnOff(leds[(*counter)-1], &red[(*counter)-1], &green[(*counter)-1], &blue[(*counter)-1]);
    else
      graduallyTurnOff(leds[15], &red[15], &green[15], &blue[15]);
    delay(updates);
    Tlc.update();
  }
 
 (*counter)++;
 if (*counter > 15)
   *counter = 0;
  
}


// Led scrolling, one color defined by the user with the color potentiometer
void independantProgram2(int color, int updates, int * counter, Led * leds, int * red, int * green, int * blue, int * predefined_red, int * predefined_green, int * predefined_blue){
  
  predefinedColor(color, predefined_red, predefined_green, predefined_blue);
  
  updates = 10 + updates / 50;

  while(!graduallyTurnOn(leds[*counter], predefined_red[*counter], predefined_green[*counter], predefined_blue[*counter], &red[*counter], &green[*counter], &blue[*counter])) {
    if (*counter > 0)
      graduallyTurnOff(leds[(*counter)-1], &red[(*counter)-1], &green[(*counter)-1], &blue[(*counter)-1]);
    else
      graduallyTurnOff(leds[15], &red[15], &green[15], &blue[15]);
    delay(updates);
    Tlc.update();
  }
 
 (*counter)++;
 if (*counter > 15)
   *counter = 0;
  
}


// 
/*int independantProgram3(int updates, int * counter, int * number, Led * leds, int * red, int * green, int * blue, int * predefined_red, int * predefined_green, int * predefined_blue) {
  
  if (*counter >= *number || *counter == 0) {
    int i = 0;
    while(!graduallyTurnOff(leds[0], &red[0], &green[0], &blue[0])) {
      for (i=1 ; i<*counter ; ++i) {
        graduallyTurnOff(leds[i], &red[i], &green[i], &blue[i]);
        delay(updates);
        Tlc.update();   
      }
    }
    *number = random(3, 15);
    randomColor(predefined_red, predefined_green, predefined_blue);
    *counter = 0;
  }
  
  updates = 10 + updates / 50;
  
  while(!graduallyTurnOn(leds[*counter], predefined_red[0], predefined_green[0], predefined_blue[0], &red[*counter], &green[*counter], &blue[*counter])) {
    delay(updates);
    Tlc.update();    
  }
  (*counter)++;
   
}*/
