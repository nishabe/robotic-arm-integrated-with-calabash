#include <Servo.h> 

int servoPin = 9;
 
Servo servo;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  Serial.begin(9600);
  servo.attach(servoPin); 
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 20; angle < 95; angle++)  
  {                                  
    servo.write(angle); 
    Serial.print(angle);               
    delay(50);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 95; angle > 20; angle--)    
  {                                
    servo.write(angle); 
    Serial.print(angle);                         
    delay(50);       
  } 
} 
