constexpr int CHECK = 13;
constexpr int RED = 11;
constexpr int GREEN = 9;
constexpr int BLUE = 10;

byte r = 0,g = 0,b = 0,flag = 0;

void setup() {	
	pinMode(CHECK,OUTPUT);
	pinMode(LED_BUILTIN,OUTPUT);
	pinMode(RED,OUTPUT);
	pinMode(GREEN,OUTPUT);
	pinMode(BLUE,OUTPUT);
	Serial.begin(9600);
}

byte liner(byte val){
	if(val == 0) return 0;
	if(val == 255) return 255;
	constexpr double C = 255.0;
	return round(exp(log(255.0) - ( 1 - (val / 255.0)) * log(C)));
}

void loop() {
	Serial.write(0);
	if(flag) digitalWrite(LED_BUILTIN, HIGH);
	else	 digitalWrite(LED_BUILTIN, LOW);
	analogWrite(RED,liner(r));
	analogWrite(GREEN,liner(g));
	analogWrite(BLUE,liner(b));
	flag = 0;	
	
	delay(10);
}

void serialEvent(){
	if(Serial.available() >= 4){
		flag = Serial.read();
		r = Serial.read();
		g = Serial.read();
		b = Serial.read();

		
	}
}
