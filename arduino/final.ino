#include "HX711.h" //HX711로드셀 엠프 관련함수 호출
#define calibration_factor -7050.0 // 로드셀 스케일 값 선언
#define DOUT  3 //엠프 데이터 아웃 핀 넘버 선언
#define CLK  2  //엠프 클락 핀 넘버 
HX711 scale(DOUT, CLK); //엠프 핀 선언 
#include <Servo.h> 
 
int servo1 = 10;
int servo2 = 12;
int vibe1 = 11;
int vibe2 = 13;

Servo servo; 

int angle = 0; // servo position in degrees 
int weight = 0;

void open1()
{
  servo.attach(servo1); 
  for(angle = 0; angle < 100; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void close1() 
{
  servo.attach(servo1); 
  for(angle = 100; angle > 0; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void open2()
{
  servo.attach(servo2); 
  for(angle = 0; angle < 100; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void close2() 
{
  servo.attach(servo2); 
  for(angle = 100; angle > 0; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void setup() {
  Serial.begin(9600);  // 시리얼 통신 개방
  Serial.println("HX711 scale TEST");
  scale.set_scale(calibration_factor);  //스케일 지정 
  scale.tare();  //스케일 설정
  Serial.println("Readings:");
}

void loop() {
  weight = 0;
  pinMode(vibe1,OUTPUT);
  Serial.begin(9600);

  open1();
  digitalWrite(vibe1, HIGH);
  delay(500);
  digitalWrite(vibe1, LOW);
  close1();
  while(weight < 100){
    Serial.print("Reading: ");
    Serial.print(scale.get_units(), 1);  //무제 출력 
    Serial.print(" lbs"); //단위
    weight = scale.get_units();
    Serial.println(); 
    delay(50);
  }
  open2();
  delay(500);
  digitalWrite(vibe2, HIGH);
  delay(500);
  digitalWrite(vibe2, LOW);
  close2();
}
지금 이게 대충 두개 합ㅊ니거
친거
박성래 — 2021.06.11.
2개면
충분하지 않을까 싶어난..
천영민 — 2021.06.11.
ㅇㅋㅇㅋ
천영민 — 2021.06.18.
while(Serial.available()){
    char wait = Serial.read();
//    sig += wait;
    if(wait == 'E')
      break;
    sig.concat(wait);
    Serial.print("data: ");
    Serial.println(sig);
    delay(100);
  }
  if(sig.length()!=0){
      int first = sig.indexOf(":");
  int second = sig.indexOf(":", first+1);
  int third = sig.indexOf(":", second+1);
  int length = sig.length() + 1;

  String salt = sig.substring(0, first);
  String sugar = sig.substring(first+1, second);
  String pepper = sig.substring(second+1, third);
  String chilipowder = sig.substring(third+1, length);
  int salt_sum=salt.toInt();

  Serial.println(salt);
  Serial.println(sugar);
  Serial.println(pepper);
  Serial.println(chilipowder);
#include <Servo.h>

String sig;
char ard1[4] = {0};
char ard2[5] = {0};
char check[1];
확장
message.txt
3KB
기존 버전 1 코드
#include "HX711.h" //HX711로드셀 엠프 관련함수 호출
#define calibration_factor -7050.0 // 로드셀 스케일 값 선언
#define DOUT  3 //엠프 데이터 아웃 핀 넘버 선언
#define CLK  2  //엠프 클락 핀 넘버 
HX711 scale(DOUT, CLK); //엠프 핀 선언 
#include <Servo.h> 
확장
message.txt
3KB
버전 2 현재 코드
첨부 파일 형식: archive
HX711_library.zip
5.04 KB
천영민 — 2021.06.18.
#include "HX711.h" //HX711로드셀 엠프 관련함수 호출
#define calibration_factor -7050.0 // 로드셀 스케일 값 선언
#define DOUT  3 //엠프 데이터 아웃 핀 넘버 선언
#define CLK  2  //엠프 클락 핀 넘버 
HX711 scale(DOUT, CLK); //엠프 핀 선언 
#include <Servo.h> 
확장
message.txt
3KB
천영민 — 오늘 오후 4:19
#include "HX711.h" //HX711로드셀 엠프 관련함수 호출
#define calibration_factor -7050.0 // 로드셀 스케일 값 선언
#define DOUT  3 //엠프 데이터 아웃 핀 넘버 선언
#define CLK  2  //엠프 클락 핀 넘버 
HX711 scale(DOUT, CLK); //엠프 핀 선언 
#include <Servo.h> 
확장
message.txt
3KB
﻿
#include "HX711.h" //HX711로드셀 엠프 관련함수 호출
#define calibration_factor -7050.0 // 로드셀 스케일 값 선언
#define DOUT  3 //엠프 데이터 아웃 핀 넘버 선언
#define CLK  2  //엠프 클락 핀 넘버 
HX711 scale(DOUT, CLK); //엠프 핀 선언 
#include <Servo.h> 

String sig;
int servo1 = 10;
int servo2 = 12;
int servo3 = 9;
int vibe1 = 11;
int vibe2 = 13;

Servo servo; 

int angle = 0; // servo position in degrees 
int weight = 0;

void open1()
{
  servo.attach(servo1); 
  for(angle = 0; angle < 100; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void close1() 
{
  servo.attach(servo1); 
  for(angle = 100; angle > 0; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void open2()
{
  servo.attach(servo2); 
  for(angle = 0; angle < 100; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void close2() 
{
  servo.attach(servo2); 
  for(angle = 100; angle > 0; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void open3()
{
  servo.attach(servo3); 
  for(angle = 0; angle < 100; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void close3() 
{
  servo.attach(servo3); 
  for(angle = 100; angle > 0; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
void setup() {
  Serial.begin(9600);  // 시리얼 통신 개방
  Serial.println("HX711 scale TEST");  
  scale.set_scale(calibration_factor);  //스케일 지정 
  scale.tare();  //스케일 설정
  Serial.println("Readings:");
}

void loop() {
    while(Serial.available()){
    char wait = Serial.read();
//    sig += wait;
    if(wait == 'E')
      break;
    sig.concat(wait);
    Serial.print("data: ");
    Serial.println(sig);
    delay(100);
  }
  if(sig.length()!=0){
      int first = sig.indexOf(":");
  int second = sig.indexOf(":", first+1);
  int third = sig.indexOf(":", second+1);
  int length = sig.length() + 1;
  
  
  String salt = sig.substring(0, first);
  String sugar = sig.substring(first+1, second);
  String pepper = sig.substring(second+1, third);
  String chilipowder = sig.substring(third+1, length);
  int salt_sum=salt.toInt();
  
  Serial.println(salt);
  Serial.println(sugar);
  Serial.println(pepper);
  Serial.println(chilipowder);
  weight = 0;
  pinMode(vibe1,OUTPUT);
  Serial.begin(9600);    
  
  open1();
  digitalWrite(vibe1, HIGH);
  delay(500);
  digitalWrite(vibe1, LOW);
  close1();
  while(weight < salt_sum){
    Serial.print("Reading: ");
    Serial.print(scale.get_units(), 1);  //무제 출력 
    Serial.print(" lbs"); //단위
    weight = scale.get_units();
    Serial.println(); 
    delay(50);
  }
  open2();
  delay(500);
  close2();
  sig="";
  open3();
  delay(500);
  digitalWrite(vibe2, HIGH);
  delay(500);
  digitalWrite(vibe2, LOW);
  close3();
}
}