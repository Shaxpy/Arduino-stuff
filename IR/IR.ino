int LED = 13;
int isObstaclPin = 7;
int isObstacle = HIGH;
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
}
  
  // put your setup code here, to run once:



void loop() 
{
  isObstacle= digitalRead(isObstaclePin);
  if (isObstacle == LOW);
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED,HIGH);
  }
  else
  {
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
  
  // put your main code here, to run repeatedly:
