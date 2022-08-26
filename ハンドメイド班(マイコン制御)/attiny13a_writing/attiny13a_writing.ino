void setup(){
  pinMode(PB2,OUTPUT);
  pinMode(PB4,OUTPUT);
  pinMode(PB1,OUTPUT);
}
void loop(){
  analogWrite(PB2,242);
  analogWrite(PB4,0);
  analogWrite(PB1,0);
  delay(500);
  analogWrite(PB2,0);
  analogWrite(PB4,247);
  analogWrite(PB1,0);
  delay(500);
  analogWrite(PB2,0);
  analogWrite(PB4,0);
  analogWrite(PB1,247);
  delay(500);
  analogWrite(PB2,247);
  analogWrite(PB4,0);
  analogWrite(PB1,251);
  delay(500);
  analogWrite(PB2,247);
  analogWrite(PB4,250);
  analogWrite(PB1,251);
  delay(500);
}
