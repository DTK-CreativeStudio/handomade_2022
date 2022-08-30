#include "Arduino.h"
#include "Button.h"

Button::Button(int n){
		pin = n;
	}
bool Button::read(){
    ms = millis(); pinVal = digitalRead(pin);
    if (invert) pinVal = !pinVal;
    if (ms - lastChange < dbTime) {
        changed = false;
    } else {
        lastState = state; state = pinVal; changed = (state != lastState);
        if (changed) lastChange = ms;
    }
    Time = ms;
    bool flag = !state && changed;
    if(flag){
        Serial.println("PUSH");
    }
    return flag;
}
