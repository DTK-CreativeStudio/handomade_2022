byte r = 0,g = 0,b = 0,flag = 0;
constexpr double ar = 0.7, ag = 1.0, ab = 1.0;
constexpr int CHECK = 13;
constexpr int RED = 11;
constexpr int GREEN = 10;
constexpr int BLUE = 9;

void setup() {  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(CHECK,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  Serial.begin(9600);
}

byte duty(byte val){
  if(val == 0) return 0;
  if(val == 255) return 255;
  constexpr double C = 255.0;
  return round(exp(log(255.0) - ( 1 - (val / 255.0)) * log(C)));
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(CHECK, HIGH);
  Serial.write(0);//準備okのサイン
  
  analogWrite(RED,duty(r*ar));
  analogWrite(GREEN,duty(g*ag));
  analogWrite(BLUE,duty(b*ab));
    
  
  delay(10);
}
/*/////////////////////////////////////////*/  
void serialEvent(){//シリアルに4バイト以上の値が送られてきたときに行う処理
  if(Serial.available() >= 4){
    flag = Serial.read();
    r = Serial.read();
    g = Serial.read();
    b = Serial.read();

    
  }
}
