// Update the configuration file of the TLC to put 3 TLC in cascade
#include "led.h"
#include "program.h"
#include "Tlc5940.h"


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
int color_pot;
int speed_pot;
int threshlod_pot;
int gain_pot;

// Delay between two updates of Leds
int updates;

// Variables useful for independant programs
int counter;           // programs 1, 2, 3
int number_of_leds;    // program 3

void setup() {
  
  // Declaration of A1, A2, A3 and A4 as inputs
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
  
  // Initialise the random number generator with a fairly random input (A5 is an unconnected pin)
  randomSeed(analogRead(A5));
  
  // Debug
  Serial.begin(9600);
  
}

void loop() {
  
  // Read the value from the color potentiometer
  color_pot = analogRead(COLOR_INPUT);
  
  // Read the value from the speed potentiometer
  updates = analogRead(SPEED_INPUT);


  //independantProgram2(color_pot, updates, &counter, leds, red, green, blue, predefined_red, predefined_green, predefined_blue);
  //independantProgram3(updates, &counter, &number_of_leds, leds, red, green, blue, predefined_red, predefined_green, predefined_blue);
  independantProgram4(color_pot, updates, &counter, leds, red, green, blue, predefined_red, predefined_green, predefined_blue);
  
}
