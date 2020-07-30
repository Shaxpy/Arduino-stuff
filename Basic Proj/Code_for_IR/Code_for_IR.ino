void setup() {
  // put your setup code here, to run once:
for(int i=0;i<=3;i++)
{
  pinMode(i,INPUT);
}
for (int j=4;j<=13;j++)
  pinMode(j,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
   if(digitalRead(3)== LOW)

   { 
    digitalWrite(13,HIGH);
   }
   else if(digitalRead(3)== LOW)
   {
    digitalWrite(13,LOW);
  }
 
 
}
