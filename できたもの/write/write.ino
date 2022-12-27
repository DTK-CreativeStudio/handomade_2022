void setup() {
  pinMode(PB2,OUTPUT);
  pinMode(PB4,OUTPUT);
  pinMode(PB1,OUTPUT);
}

void set_led(byte r, byte g, byte b, long _time){
  analogWrite(PB4, g);
  analogWrite(PB1, b);

  for(; _time > 10; _time -= 10) {
      digitalWrite(PB2, HIGH);
      delayMicroseconds(10000 * (r / 255.0));
      digitalWrite(PB2, LOW);
      delayMicroseconds(10000 - (10000 * (r / 255.0)));
  }
  digitalWrite(PB2, LOW);
  
  delayMicroseconds(_time * 1000);
}

void loop(){
	set_led(255,255,255,5000);
	set_led(255,127,000,5000);
	set_led(000,255,255,5000);
	set_led(128,128,128,5000);
  set_led(255,255,255,5000);
  set_led(255,127,000,5000);
  set_led(000,255,255,5000);
  set_led(128,128,128,5000);
}
