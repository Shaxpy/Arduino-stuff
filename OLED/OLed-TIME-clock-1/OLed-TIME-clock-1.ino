#include <SPI.h> //i2c and the display libraries + DS3231
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DS3231.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)
DS3231 clock;
RTCDateTime dt;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  clock.begin();
  delay(1000); 
  display.clearDisplay();
  display.display();

}

void loop() {                       //This code displays the Time only hours:minutes
  dt = clock.getDateTime();

  display.clearDisplay();
  display.setTextSize(3);       //size of the text that will follow              
  display.setTextColor(WHITE);  //its color            
  display.setCursor(1,1);      //position from where you want to start writing           
  display.print(dt.hour); //text todisplay
  display.print(":");
  display.print(dt.minute);
  display.display();

}
