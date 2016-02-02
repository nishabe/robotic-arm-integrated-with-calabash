#include <fk.h>
#include <ik.h>
#include <meArm.h>
#include <Servo.h>

int basePin = 11;
int shoulderPin = 10; // Right
int elbowPin = 9; // Left
int gripperPin = 7;//6;

// Constuctor for meArm version 2 (3D Print)

meArm arm(
      175,32, -pi/2, pi/2,    //Base     (-90 to  90 degrees)
      174,49, pi/4, 3*pi/4,   //Shoulder ( 45 to 135 degrees)
      160,32, 0, -pi/4,      //Elbow    (  0 to -45 degrees)
      7,101, pi/2, 0);        //Gripper  ( 90 to   0 degrees)
      
void setup() {
  arm.begin(basePin, shoulderPin, elbowPin, gripperPin);
Serial.begin(9600);
    int defaultDelay = 10;
  
    

}

void loop() {

    int defaultXPos=0;
    int defaultYPos=180;
    int defaultZPos=230;

    int startingZPos=40;
    int endingZPos=90;

    int defaultDelay = 50;

 // Go to default position
  arm.gotoPoint(defaultXPos,defaultYPos,defaultZPos);

  for(int increment = startingZPos; increment < (endingZPos+1) ; increment ++)  
  {       
    delay(defaultDelay);                   
    Serial.print(increment); 
    Serial.println("");                       
    arm.gotoPoint(defaultXPos,defaultYPos,increment);              
    
  }

    for(int decrement = endingZPos; decrement < (startingZPos+1) ; decrement --)  
  { 
    delay(defaultDelay);                      
    Serial.print(decrement); 
    Serial.println("");                                                     
    arm.gotoPoint(defaultXPos,defaultYPos,decrement);              
  }    

}

