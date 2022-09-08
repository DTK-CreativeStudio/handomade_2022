constexpr double ar = 0.7;
constexpr double ag = 1.0;
constexpr double ab = 1.0;

void setup() {
	pinMode(PB2,OUTPUT);
	pinMode(PB4,OUTPUT);
	pinMode(PB1,OUTPUT);
}

void led_red(byte value, long ms, byte pin) {
	if(value == 0){
		digitalWrite(pin, LOW);
	}
	else{
        constexpr byte INTERVAL_MS = 10, INTERVAL_NS = INTERVAL_MS * 1000;
		const long hns = INTERVAL_NS * (value / 255.0), lns = INTERVAL_NS - hns;

		for(; ms > INTERVAL_MS; ms -= INTERVAL_MS) {
			digitalWrite(pin, HIGH);
			delayMicroseconds(hns);
			digitalWrite(pin, LOW);
			delayMicroseconds(lns);
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
	analogWrite(PB4, duty(g * ag));
	analogWrite(PB1, duty(b * ab));
	led_red(duty(r * (g == b == 0 ? 1.0 : ar)), time, PB2);
}