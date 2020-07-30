int echo=2;
int trig=3;
int dist,d;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(echo,OUTPUT);

pinMode(trig,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig, LOW);

 delay(500);



 digitalWrite(trig, HIGH);

 delay(500);



 digitalWrite(trig,LOW);


 d = pulseIn (echo, HIGH);



 //This gives us distance in cm

 dist = d/58.2;



 Serial.println (dist);



 //Milliseconds

 delay(50);

}
