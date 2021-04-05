#include <Servo.h> 
 
int servoPin1 = 9;
int servoPin2 = 10;
int sensor  = A3;
int val = 0;

Servo servo1; 
Servo servo2;

int angle = 0; // servo position in degrees 

void setup() 
{ 
  Serial.begin(9600);    
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2); 
} 


void loop() 
{ 
  if (Serial.available()) {
      int inNum = Serial.parseInt();
      Serial.println(inNum);
      
      //서보모터 (뚜껑 열기)
      for(angle = 100; angle > 0; angle--) 
      { 
        servo1.write(angle); 
        delay(15); 
      }
      while(val <= inNum){
        val = analogRead(sensor);
        Serial.println(val);
      }
      
      Serial.println( " ** Method End ** ");
      
      //서보모터 (뚜껑 닫기)


      for(angle = 0; angle < 100; angle++) 
      { 
        servo1.write(angle); 
        delay(15); 
      } 
      val = 0;

      
      for(angle = 100; angle > 0; angle--) 
      { 
        servo2.write(angle); 
        delay(15); 
      }

      delay(2000);
      for(angle = 0; angle < 100; angle++) 
      { 
        servo1.write(angle); 
        delay(15); 
      } 
  }
}
      