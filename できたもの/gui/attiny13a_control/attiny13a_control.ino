#include <SPI.h>                  // ライブラリのインクルード
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8);                 // CE,CSNピンの指定
const byte address[6] = "00001";  // データを受信するアドレス
int radicon[4] = {};
void setup() {
   Serial.begin(9600);
   pinMode(10,OUTPUT);
   radio.begin();                      // 無線オブジェクトの初期化
   radio.openReadingPipe(0, address);  // データ受信アドレスを指定
   radio.setPALevel(RF24_PA_MIN);      // 出力を最小に
   radio.startListening();             // 受信側として設定
}
 void loop() {
  digitalWrite(10,LOW);
   while(radio.available()) {                         // 受信データの確認
     radio.read(&radicon, sizeof(radicon));
     Serial.print("right_x:");
     Serial.print(radicon[0]);
     Serial.print("\t");
     Serial.print("right_y:");
     Serial.print(radicon[1]);
     Serial.print("\t");
     Serial.print("left_x:");
     Serial.print(radicon[3]);
     Serial.print("\t");
     Serial.print("left_y:");
     Serial.print(radicon[2]);
     Serial.print("\t");
     Serial.println("");
     }
    delay(10);
}
