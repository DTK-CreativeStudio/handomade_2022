long r,g,b,flag = -1;
long v1[5] = {};
long v2[5] = {};
long v3[5] = {}; 
const int check = 13;
const int red = 11;
const int green = 9;
const int blue = 10;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(check,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  Serial.begin(9600);
}

void execute(long v1[],long v2[],long v3[]){
    for(int i = 0; i < 5;i ++){
        analogWrite(red, v1[i]);
        analogWrite(green,v2[i]);
        analogWrite(blue,v3[i]);
        delay(500);  
      }
  }

// the loop function runs over and over again forever
void loop() {
    Serial.write(0);//準備okのサイン

    if(flag != -1){//シリアルで値を読み取ったら
        if(flag < 1){
            analogWrite(red,r);
            analogWrite(green,g);
            analogWrite(blue,b);
          }
        else{//もしflagが0出なけらば1から5のflagをvの0から4の中に格納
          v1[flag - 1] = r;
          v2[flag - 1] = g;
          v3[flag - 1] = b;
          if(flag == 5){
              execute(v1,v2,v3);
            }
        }
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
