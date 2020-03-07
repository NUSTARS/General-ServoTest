#include <Servo.h>


Servo myservo;

int pin;

void setPin() {
  char buf[10];
  Serial.println("Servo pin: ");
  while (!Serial.available());
  String in = Serial.readString();
  in.toCharArray(buf, 10);
  pin = atoi(buf);
  Serial.println(pin);
  myservo.attach(pin);
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  setPin();
}

void loop() {
  while (!Serial.available());
  String in = Serial.readString();
  char buf[10];
  in.toCharArray(buf, 10);
  
  if (buf[0] == 'R') {
    setPin();
  } else {
    int angle = atoi(buf);
    Serial.println(angle);
    myservo.write(angle);
  }
  
  
}
