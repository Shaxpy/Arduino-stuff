

#include <Wire.h>


#include <MPU6050.h>



  // put your setup code here, to run once:
MPU6050 sensor ;
int b=0;

int16_t ax, ay, az ;

int16_t gx, gy, gz ;

void setup() {
  Wire.begin ( );// SPI communication
pinMode(10,OUTPUT);
Serial.begin  (9600); 

Serial.println  ( "Initializing the sensor" ); 

sensor.initialize ( ); 

Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); //checking whether mpu6050 is working alright

delay (1000); 

Serial.println ( "Taking Values from the sensor" );

delay (1000);

}

void loop() {
  // put your main code here, to run repeatedly:
sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

ax = map (ax, -17000, 17000, 0, 180) ;

Serial.println (ax);

//sg90.write (ax); 
analogWrite(10,ax);


delay (80);
}
