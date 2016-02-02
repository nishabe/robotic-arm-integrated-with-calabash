#include <Servo.h> 
 
int servoPin = 10;
 
Servo servo;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(servoPin); 
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  if (angle!=180)
  {
      // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo.write(angle);
    Serial.print(angle); 
    Serial.println("");           
    delay(50);       
  } 
  }
} 
