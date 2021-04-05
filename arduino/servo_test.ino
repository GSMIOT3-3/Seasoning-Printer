#include <Servo.h> 
 
int servoPin = 10;
int sensor  = A2;
int val = 0;

Servo servo; 

int angle = 0; // servo position in degrees 

void setup() 
{ 
  Serial.begin(9600);    
  servo.attach(servoPin); 
        for(angle = 0; angle < 90; angle++) 
      { 
        servo.write(angle); 
        delay(15); 
      } 
       for(angle = 90; angle > 0; angle--) 
      { 
        servo.write(angle); 
        delay(15); 
      } 
} 


void loop() 
{ 

      //서보모터 (뚜껑 열기)
//      for(angle = 0; angle < 180; angle++) 
//      { 
//        servo.write(angle); 
//        delay(15); 
//      } 
//
//      for(angle = 180; angle > 0; angle--) 
//      { 
//        servo.write(angle); 
//        delay(15); 
//      }
  
    

} 