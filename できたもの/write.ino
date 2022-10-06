#include "header.h"

void setup(){
	pinMode(PB2,OUTPUT);
	pinMode(PB4,OUTPUT);
	pinMode(PB1,OUTPUT);
}
void loop(){
	set_led(115,249,34,500);
	set_led(228,66,255,500);
}