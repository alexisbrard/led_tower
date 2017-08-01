#include "led.h"


// Turn on a Led with the RGB components in parameter
void lightLed(Led led, int r, int g, int b) {
  Tlc.set(led.red, r);                           // Red component of the LED
  Tlc.set(led.green, g);                         // Green component of the LED
  Tlc.set(led.blue, b);                          // Blue component of the LED
}


// Set predefined colors to the Leds, according to the potentiometer that controls color
void predefinedColors(int color_pot, int * predefined_red, int * predefined_green, int * predefined_blue) {
  
  if (color_pot < 200){
    int red[16] = {0, 0, 0, 0, 0, 0, 0, 0, 800, 1600, 1900, 2400, 3000, 3500, 3800, 4095};
    int green[16] = {0, 600, 1000, 1600, 2400, 3200, 3800, 4095, 4095, 3800, 3200, 1900, 1300, 800, 300, 0};
    int blue[16] = {4095, 4000, 3800, 3600, 3500, 3200, 2400, 800, 0, 0, 0, 0, 0, 0, 0, 0};
    memcpy(predefined_red, red, 16);
    memcpy(predefined_green, green, 16);
    memcpy(predefined_blue, blue, 16);
  }
  
  else if (color_pot < 400) {
    int red[16] = {4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 3000, 2000, 1500, 500, 0};
    int green[16] = {0, 0, 20, 50, 100, 200, 400, 700, 1000, 1500, 2000, 3000, 4095, 4095, 4095, 4095};
    int blue[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 500, 1000, 2000};
    memcpy(predefined_red, red, 16);
    memcpy(predefined_green, green, 16);
    memcpy(predefined_blue, blue, 16);
  }
  
  else if (color_pot < 600) {
    int red[16] = {4095, 4095, 4095, 4095, 4095, 0, 0, 0, 0, 0, 0, 500, 1500, 4095, 4095, 4095};
    int green[16] = {0, 200, 1000, 2000, 4095, 4095, 4095, 4095, 4095, 1500, 500, 0, 0, 0, 0, 0};
    int blue[16] = {0, 0, 0, 0, 0, 0, 500, 1500, 4095, 4095, 4095, 4095, 4095, 2500, 500, 0};
    memcpy(predefined_red, red, 16);
    memcpy(predefined_green, green, 16);
    memcpy(predefined_blue, blue, 16);
  }

}


// 
void singleColor(int color_pot, int * predefined_red, int * predefined_green, int * predefined_blue) {
  if (color_pot < 170) {          // Red + >green
    predefined_red[0] = 4095;
    predefined_green[0] = map(color_pot, 0, 170, 0, 4095);
    predefined_blue[0] = 0;
  }
  else if (color_pot < 340) {     // Green + <red
    predefined_red[0] = map(color_pot, 170, 340, 4095, 0);
    predefined_green[0] = 4095;
    predefined_blue[0] = 0;
  }
  else if (color_pot < 510) {     // Green + >blue
    predefined_red[0] = 0;
    predefined_green[0] = 4095;
    predefined_blue[0] = map(color_pot, 340, 510, 0, 4095);
  }
  else if (color_pot < 680) {     // Blue + <green
    predefined_red[0] = 0;
    predefined_green[0] = map(color_pot, 510, 680, 4095, 0);
    predefined_blue[0] = 4095;
  }
  else if (color_pot < 850) {     // Blue + >red
    predefined_red[0] = map(color_pot, 680, 850, 0, 4095);
    predefined_green[0] = 0;
    predefined_blue[0] = 4095;
  }
  else if (color_pot < 1020) {    // Red + <blue
    predefined_red[0] = 4095;
    predefined_green[0] = 0;
    predefined_blue[0] = map(color_pot, 850, 1020, 4095, 0);
  }
  else {                          // Red
    predefined_red[0] = 4095;
    predefined_green[0] = 0;
    predefined_blue[0] = 0;
  }
}
