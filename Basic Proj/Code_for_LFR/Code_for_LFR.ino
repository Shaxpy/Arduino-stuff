int irleft = 4;
int irright = 5;
int motora1 = 6;
int motora2 = 7;
int motorb1 = 8;
int motorb2 = 9;
int virtualvcc = 11;



void setup() {
  pinMode(irright, INPUT);
  pinMode(irleft, INPUT);
  pinMode(motora1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorb1, OUTPUT);
  pinMode(motorb2, OUTPUT);
  pinMode(virtualvcc, OUTPUT);
  digitalWrite(virtualvcc, HIGH);
}

void loop() {
  if (digitalRead(irleft) == 1 && digitalRead(irright) == 1) {
    forward();
  }
  if (digitalRead(irleft) == 0 && digitalRead(irright) == 1) {
    leftturn();
  }
  if (digitalRead(irleft) == 1 && digitalRead(irright) == 0) {
    rightturn();
  }



}

void forward() {
  motorrfwd();
  motorlfwd();
}
void rightturn() {
  motorrstp();
  motorlfwd();
}
void leftturn() {
  motorrfwd();
  motorlstp();
}

void motorrfwd() {
  digitalWrite(motora1, HIGH);
  digitalWrite(motora2, LOW);
}
void motorlfwd() {
  digitalWrite(motorb1, HIGH);
  digitalWrite(motorb2, LOW);
}
void motorrstp() {
  digitalWrite(motora1, LOW);
  digitalWrite(motora2, LOW);
}
void motorlstp() {
  digitalWrite(motorb1, LOW);
  digitalWrite(motorb2, LOW);
}
