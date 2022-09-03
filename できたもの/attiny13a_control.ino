byte r,g,b,flag = 0;
constexpr int CHECK = 13;
constexpr int RED = 11;
constexpr int GREEN = 9;
constexpr int BLUE = 10;

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
	Serial.write(0);//準備okのサイン

	if(flag != 0){//シリアルで値を読み取ったら
		analogWrite(RED,duty(r));
		analogWrite(GREEN,duty(g));
		analogWrite(BLUE,duty(b));
		analogWrite(CHECK, 255);
	}
	else{
		analogWrite(RED, 0);
		analogWrite(GREEN, 0);
		analogWrite(BLUE, 0);
		analogWrite(CHECK, 0);
	}
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
