const int LED = 11;
int incomingByte = 0;   // for incoming serial data

void setup() {
	Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
	//pinMode(LED,OUTPUT);
	//digitalWrite(LED,LOW);
}

void loop() {

	// send data only when you receive data:
	if (Serial.available() > 0) {
		incomingByte = Serial.read();
		//Serial.write(incomingByte);
		analogWrite(LED,incomingByte);
	}
	
	delay(10);
}