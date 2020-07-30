int in = 2; // the input to the relay pin
void setup() {

  pinMode(in, OUTPUT); // initialize pin as OUTPUT

}
void loop() {

  digitalWrite(in, HIGH); // turn relay on

  delay(1000);

  digitalWrite(in, LOW); // turn relay off

  delay(1000);

}
