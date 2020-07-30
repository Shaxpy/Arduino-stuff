#include<Wire.h>

int motora1 = 6;
int motora2 = 7;
int motorb1 = 8;
int motorb2 = 9;

const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

int minVal = 265;
int maxVal = 402;

double x;
double y;
double z;



void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  pinMode(motora1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorb1, OUTPUT);
  pinMode(motorb2, OUTPUT);
}
void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  int xAng = map(AcX, minVal, maxVal, -90, 90);
  int yAng = map(AcY, minVal, maxVal, -90, 90);
  int zAng = map(AcZ, minVal, maxVal, -90, 90);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  Serial.print("AngleX= ");
  Serial.println(x);

  Serial.print("AngleY= ");
  Serial.println(y);

  Serial.print("AngleZ= ");
  Serial.println(z);
  Serial.println("-----------------------------------------");
  delay(400);

  if (x > 320) {
    forward();
  } else if (x < 300) {
    reverse();
  } else {
    motorrstp();
    motorlstp();
  }
  if (y > 320) {
    rightturn();
  } else if (y < 300) {
    leftturn();
  } else {
    motorrstp();
    motorlstp();
  }


}
void forward() {
  motorrfwd();
  motorlfwd();
}
void reverse() {
  motorrbck();
  motorlbck();
}
void rightturn() {
  motorrstp();
  motorlfwd();
}
void leftturn() {
  motorrfwd();
  motorlstp();
}

void motorrbck() {
  digitalWrite(motora1, LOW);
  digitalWrite(motora2, HIGH);
}
void motorlbck() {
  digitalWrite(motorb1, LOW);
  digitalWrite(motorb2, HIGH);
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
