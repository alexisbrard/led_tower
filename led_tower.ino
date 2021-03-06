// Update the configuration file of the TLC to put 3 TLC in cascade
#include "led.h"
#include "program.h"
#include "Tlc5940.h"


// Definition of the pin that receive the signal from the micro
#define MIC_INPUT A0

// Definition of the potentiometer of color adjustment
#define COLOR_INPUT A1

// Definition of the potentiometer of speed adjustment
#define SPEED_INPUT A2

// Definition of the potentiometer of threshold adjustment
#define THRESHOLD_INPUT A3

// Definition of the potentiometer of gain adjustment
#define GAIN_INPUT A4


// Initialization of a table of Leds and its RGB components
Led leds[16];
int red[16];
int green[16];
int blue[16];
int predefined_red[16];
int predefined_green[16];
int predefined_blue[16];

// Initialization of the variables from the Arduino analog inputs 
int micro;
int color_pot;
int speed_pot;
int threshold_pot;
int gain_pot;
long average;

// Delay between two updates of Leds
int updates;

// Variables useful for independant programs
int counter;           // programs 1, 2, 3
int number_of_leds;    // program 3

void setup() {
  
  // Declaration of A0, A1, A2, A3 and A4 as inputs
  pinMode(MIC_INPUT, INPUT);
  pinMode(COLOR_INPUT, INPUT);
  pinMode(SPEED_INPUT, INPUT);
  pinMode(THRESHOLD_INPUT, INPUT);
  pinMode(GAIN_INPUT, INPUT);
  

  // Association of Leds to its RGB components
  for (int i=0 ; i<16 ; ++i){
    leds[i].red = i;
    leds[i].green = i + 16;
    leds[i].blue = i + 32;
  }

  // TLC initialization
  Tlc.init();
  Tlc.clear();
  
  // Initialization of useful variables
  counter = 0;
  number_of_leds = 0;
  
  // Initialization of the average value from the micro
  average = 0;
  
  for (int i=0 ; i<15000 ; ++i) 
    average += analogRead(MIC_INPUT);
  average /= 15000;
  
  // Initialise the random number generator with a fairly random input (A5 is an unconnected pin)
  randomSeed(analogRead(A5));
  
  // Debug
  Serial.begin(9600);
  
}

void loop() {
  
  // Read the value from the inputs
  micro = analogRead(MIC_INPUT) - average;
  color_pot = analogRead(COLOR_INPUT);
  updates = analogRead(SPEED_INPUT);
  threshold_pot = analogRead(THRESHOLD_INPUT);
  gain_pot = analogRead(GAIN_INPUT);
  
  
  
  //independantProgram2(color_pot, updates, &counter, leds, red, green, blue, predefined_red, predefined_green, predefined_blue);
  //independantProgram3(updates, &counter, &number_of_leds, leds, red, green, blue, predefined_red, predefined_green, predefined_blue);
  //independantProgram4(color_pot, updates, &counter, leds, red, green, blue);
  //independantProgram5(updates, &counter, leds, red, green, blue, predefined_red, predefined_green, predefined_blue);
  program1(micro, color_pot, updates, threshold_pot, gain_pot, leds, red, green, blue);
  
}
