// Update the configuration file of the TLC to put 3 TLC in cascade
#include "Tlc5940.h"
#include "led.h"
#include <stdio.h>

//Definition du potentiometre de réglage de couleur
#define pin_pot_couleur A1


// Initialization of a table of Leds and its RGB components
Led leds[16];
int red[16];
int green[16];
int blue[16];

// Initialization of tables of predefined colors
int predefined_red[16];
int predefined_green[16];
int predefined_blue[16];

void setup() {
  
  //Declaration du pin A1 de l'arduino comme entree pour le reglage de couleur
  pinMode(pin_pot_couleur, INPUT);
  
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
  predefinedColors(400, predefined_red, predefined_green, predefined_blue);
  for(int i=0 ; i<16 ; ++i)
    lightLed(leds[i], predefined_red[i], predefined_green[i], predefined_blue[i]);
  Tlc.update();
  delay(1000);
}
