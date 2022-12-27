byte r = 0, g = 0, b = 0, flag = 0;
constexpr int CHECK = 13;
constexpr int RED = 11;
constexpr int GREEN = 10;
constexpr int BLUE = 9;

void set(unsigned long ms,unsigned int pb1,unsigned int pb4,unsigned int pb3){
  analogWrite(GREEN, pb1);
  analogWrite(BLUE, pb4);
  if (pb3 == 0U || pb3 == 255U) {
    digitalWrite(RED, pb3 == 255U ?  HIGH : LOW);
    delay(ms);
    return;
  }

  for (long us = ms * 1000L / 255L; us > 0L; us--) {
    digitalWrite(RED, HIGH);
    delayMicroseconds(pb3);
    
    digitalWrite(RED, LOW);
    delayMicroseconds(255u - pb3);
  }
  
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(CHECK, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(CHECK, HIGH);
  Serial.write(0);//準備okのサイン

  //analogWrite(RED, r);
  //analogWrite(GREEN, g);
  //analogWrite(BLUE, b);

  set(10, g,b,r);
  //set(1000, 255,255,255);
  //set(1000, 0,0,127);
  //set(1000, 5,5,254);
  //set(1000, 0,0,255U);
}
/*/////////////////////////////////////////*/
void serialEvent() { //シリアルに4バイト以上の値が送られてきたときに行う処理
  if (Serial.available() >= 4) {
    flag = Serial.read();
    r = Serial.read();
    g = Serial.read();
    b = Serial.read();


  }
}
