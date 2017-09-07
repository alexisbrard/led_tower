#ifndef PROGRAM_H
#define PROGRAM_H


#include "led.h"
#include "Tlc5940.h"


void independantProgram1(int color, int updates, int * counter, Led * leds, int * red, int * green, int * blue, int * predefined_red, int * predefined_green, int * predefined_blue);
void independantProgram2(int color, int updates, int * counter, Led * leds, int * red, int * green, int * blue, int * predefined_red, int * predefined_green, int * predefined_blue);
void independantProgram3(int updates, int * counter, int * number, Led * leds, int * red, int * green, int * blue, int * predefined_red, int * predefined_green, int * predefined_blue);
void independantProgram4(int color, int updates, int * counter, Led * leds, int * red, int * green, int * blue);
void independantProgram5(int updates, int * previous_led, Led * leds, int * red, int * green, int * blue, int * predefined_red, int * predefined_green, int * predefined_blue);
void program1(int micro, int color, int updates, int threshold, int gain, Led * leds, int * red, int * green, int * blue);


#endif // PROGRAM_H
