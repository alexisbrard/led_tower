#include "Tlc5940.h"
#include <stdio.h>

typedef struct {
  int red;
  int green;
  int blue;
} Led;

void lightLed(Led led, int r, int g, int b);
void predefinedColors(int colors_pot, int * predefined_red, int * predefined_green, int * predefined_blue);
