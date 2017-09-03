#include "led.h"


// Turn on a Led with the RGB components in parameter
void lightLed(Led led, int r, int g, int b) {
  Tlc.set(led.red, r / 5);                           // Red component of the LED
  Tlc.set(led.green, g / 5);                         // Green component of the LED
  Tlc.set(led.blue, b / 5);                          // Blue component of the LED
}


// Turn on gradually a Led to its RGB commands
// Return 1 if the Led reaches the command, 0 if not yet
int graduallyTurnOn(Led led, int red_command, int green_command, int blue_command, int * red, int * green, int * blue) {
  
  if (*red == red_command && *green == green_command && *blue == blue_command) {
      lightLed(led, *red, *green, *blue);
      return 1;
  }
  
  else {
    if (*red < red_command)
      *red += red_command / 50;
    if (*green < green_command)
      *green += green_command / 50;
    if (*blue < blue_command)
    *  blue += blue_command / 50;  
  }
  
  if (*red > red_command)
    *red = red_command;
  if (*green > green_command)
    *green = green_command;
  if (*blue > blue_command)
    *blue = blue_command;
  
  lightLed(led, *red, *green, *blue);
  return 0;
  
}


// Turn off gradually a Led
// Return 1 when the Led is turned off, 0 if not yet
int graduallyTurnOff(Led led, int * red, int * green, int * blue) {
  
  if (*red == 0 && *green == 0 && *blue == 0)
    return 1;
    
  else {
    if (*red > 0)
      *red -= 82 * (*red / max3(*red, *green, *blue));
    if (*green > 0)
      *green -= 82 * (*green / max3(*red, *green, *blue));
    if (*blue > 0)
      *blue -= 82 * (*blue / max3(*red, *green, *blue));  
  }
  
  
  
  if (*red < 0) 
    *red = 0;
  if (*green < 0) 
    *green = 0;
  if (*blue < 0) 
    *blue = 0;
    
  lightLed(led, *red, *green, *blue);
  return 0;
 
}



// Set predefined colors to the Leds, according to the potentiometer that controls color
void predefinedColors(int color_pot, int * red, int * green, int * blue) {
  
  if (color_pot < 200){
    int predefined_red[16] = {0, 0, 0, 0, 0, 0, 0, 0, 800, 1600, 1900, 2400, 3000, 3500, 3800, 4095};
    int predefined_green[16] = {0, 600, 1000, 1600, 2400, 3200, 3800, 4095, 4095, 3800, 3200, 1900, 1300, 800, 300, 0};
    int predefined_blue[16] = {4095, 4000, 3800, 3600, 3500, 3200, 2400, 800, 0, 0, 0, 0, 0, 0, 0, 0};
    memcpy(red, predefined_red, 32);      // 32 is the number of bytes to be copied, and an int is on 2 bytes
    memcpy(green, predefined_green, 32);
    memcpy(blue, predefined_blue, 32);
  }
  
  else if (color_pot < 400) {
    int predefined_red[16] = {4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 3000, 2000, 1500, 500, 0};
    int predefined_green[16] = {0, 0, 20, 50, 100, 200, 400, 700, 1000, 1500, 2000, 3000, 4095, 4095, 4095, 4095};
    int predefined_blue[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 500, 1000, 2000};
    memcpy(red, predefined_red, 32);
    memcpy(green, predefined_green, 32);
    memcpy(blue, predefined_blue, 32);
  }
  
  else if (color_pot < 600) {
    int predefined_red[16] = {4095, 4095, 4095, 4095, 4095, 0, 0, 0, 0, 0, 0, 500, 1500, 4095, 4095, 4095};
    int predefined_green[16] = {0, 200, 1000, 2000, 4095, 4095, 4095, 4095, 4095, 1500, 500, 0, 0, 0, 0, 0};
    int predefined_blue[16] = {0, 0, 0, 0, 0, 0, 500, 1500, 4095, 4095, 4095, 4095, 4095, 2500, 500, 0};
    memcpy(red, predefined_red, 32);
    memcpy(green, predefined_green, 32);
    memcpy(blue, predefined_blue, 32);
  }

}


// Set a manual color to a Led from the color potentiometer
void singleColor(int color_pot, int * red, int * green, int * blue) {
  if (color_pot < 170) {          // Red + >green
    red[0] = 4095;
    green[0] = map(color_pot, 0, 170, 0, 4095);
    blue[0] = 0;
  }
  else if (color_pot < 340) {     // Green + <red
    red[0] = map(color_pot, 170, 340, 4095, 0);
    green[0] = 4095;
    blue[0] = 0;
  }
  else if (color_pot < 510) {     // Green + >blue
    red[0] = 0;
    green[0] = 4095;
    blue[0] = map(color_pot, 340, 510, 0, 4095);
  }
  else if (color_pot < 680) {     // Blue + <green
    red[0] = 0;
    green[0] = map(color_pot, 510, 680, 4095, 0);
    blue[0] = 4095;
  }
  else if (color_pot < 850) {     // Blue + >red
    red[0] = map(color_pot, 680, 850, 0, 4095);
    green[0] = 0;
    blue[0] = 4095;
  }
  else if (color_pot < 1020) {    // Red + <blue
    red[0] = 4095;
    green[0] = 0;
    blue[0] = map(color_pot, 850, 1020, 4095, 0);
  }
  else {                          // Red
    red[0] = 4095;
    green[0] = 0;
    blue[0] = 0;
  }
}


