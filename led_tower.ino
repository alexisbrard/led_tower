// Update the configuration file of the TLC to put 3 TLC in cascade
#include "Tlc5940.h"
#include "led.h"


// Definition of the potentiometer of color adjustment
#define COLOR_INPUT A1
// Definition of the potentiometer of color adjustment
#define BRIGHT_INPUT A2


// Initialization of a table of Leds and its RGB components
Led leds[16];
int red[16];
int green[16];
int blue[16];

// Initialization of tables of predefined colors
int predefined_red[16];
int predefined_green[16];
int predefined_blue[16];

// Initialization of the variables from the Arduino analog inputs 
int color_pot;
float bright_pot;


void setup() {
  
  // Declaration of A1 as an input
  pinMode(COLOR_INPUT, INPUT);
  
  // Declaration of A1 as an input
  pinMode(BRIGHT_INPUT, INPUT);

  // Association of Leds to its RGB components
  for (int i=0 ; i<16 ; ++i){
    leds[i].red = i;
    leds[i].green = i + 16;
    leds[i].blue = i + 32;
  }

  // TLC initialization
  Tlc.init();
  Tlc.clear();
  
}

void loop() {
  
  // Read the value from the color potentiometer
  color_pot = analogRead(COLOR_INPUT);

  // Read the value from the brightness potentiometer
  bright_pot = analogRead(BRIGHT_INPUT);
  bright_pot = modifiedMap(bright_pot, 0, 1023, 0.1, 1);
  
  //predefinedColors(300, predefined_red, predefined_green, predefined_blue);
  singleColor(color_pot, predefined_red, predefined_green, predefined_blue);
  
  for(int i=0 ; i<1 ; ++i){
    //lightLed(leds[i], predefined_red[i], predefined_green[i], predefined_blue[i]);
    lightLed(leds[i], predefined_red[0], predefined_green[0], predefined_blue[0], bright_pot);
  }
  
  Tlc.update();
  delay(20);
  Tlc.clear();
  
}
