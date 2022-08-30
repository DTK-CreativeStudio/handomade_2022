#ifndef BUTTON_H_INCLUDE
#define BUTTON_H_INCLUDE

class Button{
	int pin;
	uint32_t ms, lastChange = millis(), dbTime = 25, Time = lastChange;
	bool lastState = false, state = false, invert = false, changed = false, pinVal = false;
public:
	Button(int n);
	bool read();

};

#endif