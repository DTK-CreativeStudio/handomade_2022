import processing.serial.*;
Serial myPort;
Volume v1, v2, v3;//ヴォリューム
swich s1,s2,s3,s4;//スイッチ
int count = 0;//何個目の明滅タイプか見るやつ


Data data[] = new Data[5];//Data型の構造体っぽいやつ(クラス)を作成

class Data{
    intflag;
    intv1;
    intv2;
    intv3;
}

void write(int flag,int v1,int v2,int v3) {//一気にシリアルに書いてくれるやつ
    myPort.write(flag);
    myPort.write(v1);
    myPort.write(v2);
    myPort.write(v3);
}

void delay(int ms) {
    intm1 = millis();
    while(millis() < m1 + ms) {
        }
}

void execute(Data data[]) {
    for (int i = 0;i < 5; i++) {
        	write(data[i].flag ,data[i].v1 , data[i].v2 , data[i].v3);
        }
}
void saving(String text,String file) {
    String[] list = split(text,"\n");
    saveStrings(file,list);
}

/*/////////////////////////////こっから本題///////////////////////*/
void setup(){
	myPort = new Serial(this, "COM3", 9600);
	for(int i = 0; i< 5; i++){//
		data[i] = new Data();
	}
	background(255);
	size(700, 700);
	line(500,0,500,700);
	v1 = new Volume(400, 50, 200, 0, 255, 255, 0, 0);
	v2 = new Volume(400, 50, 250, 0, 255, 0, 255, 0);
	v3 = new Volume(400, 50, 300, 0, 255, 0, 0, 255);
	s1 = new swich(30,30,255,255,255 ,1,0);
	s2 = new swich(30,500,255,255,255 ,1,0);
	s3 = new swich(350,500,255,255,255,1,0);
	s4 = new swich(350,30,255,255,255,1,0);

	v1.pre();
	v2.pre();
	v3.pre();

}

void draw(){
	if(count < 5){
	v1.volume();//volumeを表示
	v2.volume();
	v3.volume();
	s1.bottun();//色選択ボタン
	s4.bottun();//クリアボタン
	resetMatrix();
	textSize(30);
	fill(0);
	text("Select", 35, 65);
	text("Clear", 355, 65);
	
	fill(v1.result(),v2.result(),v3.result());
	rect(200,95,50,50);
	int val = s1.result();//スイッチの状態
	
	if(myPort.available() > 0){//if文内はarduinoとの同期処理
		write(0,v1.result(),v2.result(),v3.result());//フラグ0で値をシリアルに渡す。
	}
	
	
	if(val == 1){//色選択スイッチが押されたら
		data[count].flag = count + 1;
		data[count].v1 = v1.result();//volumeの値を保持
		data[count].v2 = v2.result();
		data[count].v3 = v3.result();
		fill(v1.result(),v2.result(),v3.result());
		rect(520,10 + count*(100),100,100);
		count++;
		delay(100);
		val = 0;
		
	}
	//myPort.write(v1.result());
	}
	else{
		s2.bottun();
		s3.bottun();
		textSize(30);
		fill(0);
		resetMatrix();
		text("Act!!",50,540);
		text("Write!!",355,540);
		int val2 = s2.result();
		int val3 = s3.result();
		if(val2 == 1){
			execute(data);
		} 
		if(val3 == 1){
			StringBuilder code = new StringBuilder();
			String file = "../attiny13a_writing/attiny13a_writing.ino";
			String setting = "void setup(){\npinMode(PB2,OUTPUT);\npinMode(PB4,OUTPUT);\npinMode(PB1,OUTPUT);\n}\nvoid loop(){\n";
			code.append(setting);
			for(int i = 0; i < 5; i ++){
				code.append("analogWrite(PB2,");
				code.append(String.valueOf(data[i].v1));
				code.append(");\n"); 
				code.append("analogWrite(PB4,");
				code.append(String.valueOf(data[i].v2));
				code.append(");\n");
				code.append("analogWrite(PB1,");
				code.append(String.valueOf(data[i].v3));
				code.append(");\n"); 
				code.append("delay(500);\n");
			}
			code.append("}");
			String result = code.toString();
			saving(result,file);
			delay(500);
		}
	}
	
	int val4 = s4.result();
	
	if(val4 == 1){
		for(int i = 0; i< 5; i++){//dataの初期化
			data[i] = new Data();
		}
		background(255);
		line(500,0,500,700); 
		count = 0;	 
		val4 = 0;
		delay(100);
		v1.pre();
		v2.pre();
		v3.pre();		
	}

}
