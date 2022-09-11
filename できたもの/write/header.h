constexpr double ar = 1.0;
constexpr double ag = 1.0;
constexpr double ab = 1.0;

constexpr byte RED = 11, GREEN = 9, BLUE = 10;

void setup() {
	pinMode(RED,OUTPUT);
	pinMode(GREEN,OUTPUT);
	pinMode(BLUE,OUTPUT);
}

void led_red(byte value, long ms, byte pin) {
	if(value == 0){
		digitalWrite(pin, LOW);
	}
	else{
        constexpr byte INTERVAL_MS = 10, INTERVAL_NS = INTERVAL_MS * 1000;
		const long hus = INTERVAL_NS * (value / 255.0), lus = INTERVAL_NS - hus;

		for(; ms > INTERVAL_MS; ms -= INTERVAL_MS) {
			digitalWrite(pin, HIGH);
			delayMicroseconds(hus);
			digitalWrite(pin, LOW);
			delayMicroseconds(lus);
		}
		if(ms < INTERVAL_MS){
			digitalWrite(pin, LOW);
		}
	}
	delay(ms);
}

byte duty(byte val){
	if(val == 0) return 0;
	if(val == 255) return 255;
	constexpr double C = 255.0;
	return round(exp(log(255.0) - ( 1 - (val / 255.0)) * log(C)));
}

void set_led(byte r, byte g, byte b, long time){
	analogWrite(GREEN, duty(g * ag));
	analogWrite(BLUE, duty(b * ab));
	led_red(duty(r * (g == b == 0 ? 1.0 : ar)), time, RED);
}