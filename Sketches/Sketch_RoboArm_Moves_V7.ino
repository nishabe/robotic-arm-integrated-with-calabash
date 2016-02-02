#include <fk.h>
#include <ik.h>
#include <meArm.h>
#include <Servo.h>

int gripperPin = 6;
int elbowPin = 9; // Left
int shoulderPin = 10; // Right
int basePin = 11;

meArm arm(
      173,24, -pi/2, pi/2,    //Base     (-90 to  90 degrees)
      178,50, pi/4, 3*pi/4,   //Shoulder ( 45 to 135 degrees)
      //178,73, 0, -pi/4,      //Elbow    (  0 to -45 degrees)
      88,9, 0, -pi/4,      //Elbow    (  0 to -45 degrees)
      2,101, pi/2, 0);        //Gripper  ( 90 to   0 degrees)
      
void setup() {
  arm.begin(basePin, shoulderPin, elbowPin, gripperPin);
  Serial.begin(9600);
  Serial.write('1'); 
}

void loop() {
    arm.closeGripper(); 
   
 if(Serial.available()){
    int ch = Serial.read();
    Serial.print(ch);

    int startingXPos=0;
    int startingYPos=191;
    int startingZPos=160;
    int endingZPos=50;
arm.closeGripper();      
delay(2000);
arm.gotoPoint(startingXPos,startingYPos,endingZPos);
delay(2000);
Serial.write('0');
Serial.flush();
 }
}

