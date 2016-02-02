#include <Servo.h> 

int servoPin = 8;
 
Servo servo;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(servoPin); 
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 7; angle < 101; angle++)  
  {                                  
    servo.write(angle);               
    delay(50);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 101; angle > 7; angle--)    
  {                                
    servo.write(angle);           
    delay(50);       
  } 
} 
