void setup(){
  pinMode(3, OUTPUT);
}
void loop(){
  analogWrite(3, 255); //진동세기 임의의 값
  delay(1000);
  analogWrite(3, 0);
  delay(1000);
}