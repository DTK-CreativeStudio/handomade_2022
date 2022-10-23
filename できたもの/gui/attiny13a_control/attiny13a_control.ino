byte r = 0, g = 0, b = 0, flag = 0;
constexpr int CHECK = 13;
constexpr int RED = 11;
constexpr int GREEN = 10;
constexpr int BLUE = 9;

void setup() {
  pinMode(CHECK, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);


  delay(10);
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