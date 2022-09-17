void set(long us,int pb1,int pb4,int pb3){
 
  analogWrite(PB1,pb1);
  analogWrite(PB4,pb4);
  if(pb3 == 0 || pb3 == 255){
    digitalWrite(PB3, pb3 == 0 ? LOW : HIGH);
    delay(us / 1000);
    return;
  }
  us /= 255;
  while(us > 0){
    digitalWrite(PB3,HIGH);
    delayMicroseconds(pb3);
    digitalWrite(PB3,LOW);
    delayMicroseconds(255 - pb3);
    us--;
  }
}

void setup() {
  pinMode(PB1,OUTPUT);
  pinMode(PB3,OUTPUT);
  pinMode(PB4,OUTPUT);
}

void loop(){
  set(100000,0,0,0);
  set(100000,0,0,50);
  set(100000,1,0,100);
  set(100000,0,2,200);
  set(100000,5,0,0);
  set(100000,0,8,50);
  set(100000,6,0,100);
  set(100000,0,12,200);
  set(100000,45,0,0);
  set(100000,0,57,50);
  set(100000,85,0,100);
  set(100000,0,785,200);
  set(100000,0,52,0);
}
