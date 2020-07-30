void setup() {
  // put your setup code here, to run once:
for(int i=0;i<4;i++)
  {
    pinMode(i,OUTPUT);
  Serial.begin(9600);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=0;i<4;i++)
{
  digitalWrite(i,HIGH);
Serial.println("The led is ON");
delay(1000); 
digitalWrite(i,LOW);
Serial.println("The led is OFF");
delay(1000);
}
}    
