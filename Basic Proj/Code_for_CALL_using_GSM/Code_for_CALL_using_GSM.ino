#include<SoftwareSerial.h>
SoftwareSerial GPRS(7,8); //RX,TX

char phone[]="9868492400";
void setup() 
{
GPRS.begin(9600);
Serial.begin(9600);
}

void loop() 
{
while(GPRS.available())// GPRS sends something
Serial.write(GPRS.read());// read by monitor

while (Serial.available())// serial sends something
GPRS.write(Serial.read());

}
