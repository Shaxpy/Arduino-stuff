/*****************************************************************************
Author: Ashish Adhikari
Version: 1.0
Blog:   http://diyfactory007.blogspot.com.au
******************************************************************************/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "modified_font.h"

#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)

#endif

void setup()   { 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);   // initialize with the I2C addr 0x3C (for the 128x64)
  
  display.clearDisplay();                      // Make sure the display is cleared
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(3,4);
  display.setFont(&DejaVu_Sans_Mono_13);   // Set the custom font
  display.println("Desperate\nEngineers"); 
 //http://oleddisplay.squix.ch/#/home 
  display.display();                           // Update the display
}


void loop() {
  
}
