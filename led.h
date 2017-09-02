#ifndef LED_H
#define LED_H


#include "Tlc5940.h"
#include <stdio.h>


typedef struct {
  int red;
  int green;
  int blue;
} Led;

void lightLed(Led led, int r, int g, int b);
void graduallyTuenOn(Led led, int red_command, int green_command, int blue_command, int * red, int * green, int * blue);
void predefinedColors(int color_pot, int * red, int * green, int * blue);
void singleColor(int color_pot, int * red, int * green, int * blue);


#endif // LED_H
