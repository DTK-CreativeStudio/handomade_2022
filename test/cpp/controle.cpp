#define NOMINMAX
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

HANDLE arduino;
bool Ret;

int main(){
	BYTE data = 1;
	//1.ポートをオープン
	arduino = CreateFile("COM4",GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	//2014/01/22追記　これでつながらない場合には"\\\\.\\COM7"とするとつながるかもしれません。

	if(arduino == INVALID_HANDLE_VALUE){
		printf("PORT COULD NOT OPEN\n");
		system("PAUSE");
		exit(0);
	}
	//2.送受信バッファ初期化
	Ret = SetupComm(arduino,1024,1024);
	if(!Ret){
		printf("SET UP FAILED\n");
		CloseHandle(arduino);
		system("PAUSE");
		exit(0);
	}
	Ret = PurgeComm(arduino,PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);
	if(!Ret){
		printf("CLEAR FAILED\n");
		CloseHandle(arduino);
		exit(0);
	}
	//3.基本通信条件の設定
	DCB dcb;
	GetCommState(arduino,&dcb);
	dcb.DCBlength = sizeof(DCB);
	dcb.BaudRate = 9600;
	dcb.fBinary = TRUE;
	dcb.ByteSize = 8;
	dcb.fParity =NOPARITY;
	dcb.StopBits = ONESTOPBIT;

	Ret = SetCommState(arduino,&dcb);
	if(!Ret){
		printf("SetCommState FAILED\n");
		CloseHandle(arduino);
		system("PAUSE");
		exit(0);
	}
	//4.送信
	while(true){
		DWORD dwSendSize;
		DWORD dwErrorMask;

		int val = 0;
		scanf("%d", &val);
		if(val < 0 || val > 255) break;
		data = (BYTE)val;
		
		Ret = WriteFile(arduino,&data,sizeof(data),&dwSendSize,NULL);
		if(!Ret){
			printf("SEND FAILED\n");
			CloseHandle(arduino);
			system("PAUSE");
			exit(0);
		}
	}
	printf("FINISH\n");
	CloseHandle(arduino);
	system("PAUSE");

	return 0;
}