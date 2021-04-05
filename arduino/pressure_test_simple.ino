#include <Servo.h> 
 
int sensor  = A2;
int val = 0;


int angle = 0; // servo position in degrees 

void setup() 
{ 
  Serial.begin(9600);    
} 


void loop() 
{ 
  if (Serial.available()) {
      
 
        val = analogRead(sensor);
        Serial.println(val);
    
      
  }
}
      