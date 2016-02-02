#include <Servo.h> 

int servoPin = 11;
 
Servo servo;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(servoPin); 
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 2; angle < 168; angle++)  
  {                                  
    servo.write(angle);               
    delay(50);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 168; angle > 2; angle--)    
  {                                
    servo.write(angle);           
    delay(50);       
  } 
} 
