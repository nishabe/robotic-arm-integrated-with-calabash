#include <Servo.h>

int gripperPin = 6;
int elbowPin = 9;
int shoulderPin = 10;
int basePin = 11;

int inpin = 1;

Servo *servo;
int angle = 90;

Servo base, shoulder, elbow, gripper;

void setup() {
  Serial.begin(9600);

  base.attach(basePin);
  servo = &base;
}

void loop() {
  angle = map(analogRead(inpin), 0, 1023, 0, 180);
  servo->write(angle);
  Serial.println(angle);
  
  if (Serial.available() > 0){
    char c = Serial.read();
    switch(c){
      case 'b':
      Serial.print(c);
        servo->detach();
        servo = &base;
        servo->attach(basePin);
      break;
      case 'g':
            Serial.print(c);

        servo->detach();      
        servo = &gripper;
        servo->attach(gripperPin);        
      break;
      case 'e':
            Serial.print(c);

        servo->detach();
        servo = &elbow;
        servo->attach(elbowPin);        
      break;
      case 's':
            Serial.print(c);

        servo->detach();
        servo = &shoulder;
        servo->attach(shoulderPin);        
      break;
      default:
      break;
    }
  }  
}
