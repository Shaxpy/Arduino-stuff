/* This code works with DS3231 RTC module and OLED display
 * It shows a format of date and time in the OLED screen and some cases the temperature too
 * Refer to www.Surtrtech.com for more details
 * This is Code #6 of the tutorial 
 */

#include <SPI.h> //i2c and the display libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DS3231.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

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

void loop() {                    //This code displays the Time(Hours:minutes) as 12h format with (AM or PM) and the Date (Month/Day of the month and year)
  
  dt = clock.getDateTime();

  display.clearDisplay();
  display.setTextSize(3);       //size of the text that will follow              
  display.setTextColor(WHITE);  //its color            
  display.setCursor(1,1);      //position from where you want to start writing           
  display.print(clock.dateFormat("g:i", dt)); //text todisplay
  display.setTextSize(1);
  display.setCursor(90,1);
  display.print(clock.dateFormat("A", dt));
  display.setCursor(90,10);
  display.print(clock.dateFormat("M j", dt));
  display.setCursor(90,20);
  display.print(clock.dateFormat("Y", dt));
  display.display();
  delay(1000);
}
