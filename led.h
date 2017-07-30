#include "Tlc5940.h"

typedef struct {
  int red;
  int green;
  int blue;
} Led;

void lightLed(Led led, int r, int g, int b);
