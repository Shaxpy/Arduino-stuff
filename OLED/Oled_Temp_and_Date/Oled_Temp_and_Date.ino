/* This code works with DS3231 RTC module and OLED display
 * It shows a format of date and time in the OLED screen and some cases the temperature too
 * Refer to www.Surtrtech.com for more details
 * This is Code #4_v2 of the tutorial 
 */
 
#include <SPI.h> //i2c and the display libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DS3231.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

int a;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)
DS3231 clock;
RTCDateTime dt;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  clock.begin();
  delay(1000); 
  display.clearDisplay();
  display.display();
  a=millis();
}

void loop() {
                            //This code displays the Time (Hours:Minutes) and Date (Day of week/Day of month) and every 6s the temperature instead of date
  dt = clock.getDateTime();
  

  display.clearDisplay();
  display.setTextSize(3);       //size of the text that will follow              
  display.setTextColor(WHITE);  //its color            
  display.setCursor(1,1);      //position from where you want to start writing           
  display.print(clock.dateFormat("H:i", dt)); //text todisplay
  display.setTextSize(1);
  display.setCursor(10,10);
  display.print(clock.dateFormat("D", dt));
  display.setTextSize(2);
  display.setCursor(100,10);
  display.print(clock.dateFormat("d", dt));
  display.setCursor(100,25);
  display.display();

  if (millis()>=a+4000 && millis()<=a+5000){     //Temperature display refresh time (every 6-7 seconds)
  dt = clock.getDateTime();
  a=millis();
  
  display.clearDisplay();
  display.setTextSize(3);       //size of the text that will follow              
  display.setTextColor(WHITE);  //its color            
  display.setCursor(1,1);      //position from where you want to start writing           
  display.print(clock.dateFormat("H:i", dt)); //text todisplay
  display.setTextSize(2);
  display.setCursor(40,10);
  display.print(clock.readTemperature(),0);
  display.setCursor(80,20);
  display.setTextSize(1);
  display.print("C");
  display.setCursor(100,20);
  display.display();
  delay(1000);        //delay of displaying the temperature
  
  }
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
