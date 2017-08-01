#include "Tlc5940.h"
#include <stdio.h>


typedef struct {
  int red;
  int green;
  int blue;
} Led;

void lightLed(Led led, int r, int g, int b, float brightness);
void predefinedColors(int color_pot, int * predefined_red, int * predefined_green, int * predefined_blue);
void singleColor(int color_pot, int * predefined_red, int * predefined_green, int * predefined_blue);
float modifiedMap(float x, float in_min, float in_max, float out_min, float out_max);
