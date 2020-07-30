/* This code works with DS3231 RTC module and OLED display
 * It shows a format of date and time in the OLED screen and some cases the temperature too
 * Refer to www.Surtrtech.com for more details
 * This is Code #4 of the tutorial 
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

void loop() {
                                 //This code displays the Time (Hours:Minutes) and Date (Day of week/Day of month)
  dt = clock.getDateTime();

  display.clearDisplay();
  display.setTextSize(3);       //size of the text that will follow              
  display.setTextColor(WHITE);  //its color            
  display.setCursor(1,1);      //position from where you want to start writing           
  display.print(clock.dateFormat("H:i", dt)); //text todisplay
  display.setTextSize(1);
  display.setCursor(100,1);
  display.print(clock.dateFormat("D", dt));
  display.setTextSize(2);
  display.setCursor(100,10);
  display.print(clock.dateFormat("d", dt));
  display.setCursor(100,25);
  display.display();
  delay(1000);
}
