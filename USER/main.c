#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "tools.h"
#include "timer.h"
#include "lcd.h"
#include "motor.h"
#include "encoder.h"


//74 bytes
const char PUB1[] = {0xFF,0xFE,0x4A,0x00,0xB5,0x00,0x00,0x7D,0x00,0x09,0x00,0x00,0x00,0x6D,0x62,0x65,0x64,
    0x5F,0x6F,0x64,0x6F,0x6D,0x0F,0x00,0x00,0x00,0x73,0x74,0x64,0x5F,0x6D,0x73,0x67,0x73,0x2F,0x53,0x74,
    0x72,0x69,0x6E,0x67,0x20,0x00,0x00,0x00,0x39,0x39,0x32,0x63,0x65,0x38,0x61,0x31,0x36,0x38,0x37,0x63,0x65,
    0x63,0x38,0x63,0x38,0x62,0x64,0x38,0x38,0x33,0x65,0x63,0x37,0x33,0x63,0x61,0x34,0x31,0x64,0x31,0x00,
0x02,0x00,0x00,0x66};

//81 bytes
const char PUB2[]={0xFF,0xFE,0x51,0x00,0xAE,0x00,0x00,0x7E,0x00,0x10,0x00,0x00,0x00,0x6D,0x6F,0x74,0x6F,0x72,
0x5F,0x63,0x6F,0x6E,0x74,0x72,0x6F,0x6C,0x5F,0x43,0x42,0x0F,0x00,0x00,0x00,0x73,0x74,0x64,0x5F,0x6D,0x73,0x67,
0x73,0x2F,0x53,0x74,0x72,0x69,0x6E,0x67,0x20,0x00,0x00,0x00,0x39,0x39,0x32,0x63,0x65,0x38,0x61,0x31,0x36,0x38,0x37,
0x63,0x65,0x63,0x38,0x63,0x38,0x62,0x64,0x38,0x38,0x33,0x65,0x63,0x37,0x33,0x63,0x61,0x34,0x31,0x64,0x31,0x00,
0x02,0x00,0x00,0x8F};

//78 bytes
const char SUB[]={0xFF,0xFE,0x4E,0x00,0xB1,0x01,0x00,0x64,0x00,0x0D,0x00,0x00,0x00,0x6D,0x6F,0x74,0x6F,0x72,
0x5F,0x63,0x6F,0x6E,0x74,0x72,0x6F,0x6C,0x0F,0x00,0x00,0x00,0x73,0x74,0x64,0x5F,0x6D,0x73,0x67,0x73,0x2F,0x53,
0x74,0x72,0x69,0x6E,0x67,0x20,0x00,0x00,0x00,0x39,0x39,0x32,0x63,0x65,0x38,0x61,0x31,0x36,0x38,0x37,0x63,0x65,0x63,
0x38,0x63,0x38,0x62,0x64,0x38,0x38,0x33,0x65,0x63,0x37,0x33,0x63,0x61,0x34,0x31,0x64,0x31,0x00,0x02,0x00,0x00,
0x8F};

const char odom[]={0xFF,0xFE,0x16,0x00,0xE9,0x7D,0x00,0x12,0x00,0x00,0x00,0x5B,0x6F,0x64,0x6F,0x6D,0x5D,0x4C,
0x3A,0x32,0x2C,0x52,0x3A,0x32,0x2C,0x38,0x32,0x37,0x31,0x69};

char uartTxBuffer[100];

extern u8 ifTopicDefine;
extern const char TIME_TOPIC[];



u8 ifStartToPublish=0;
u16 heartBeatCounter = 0;

int main_test(void){
    initMotor();
    while(1){
    }
        
}

int main(void)
{		

 	volatile u16 t = 0;
	//volatile u8 xxxxx;
    volatile u16 strLength;    
	u16 len;	
	u16 times=0;

	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
    //TIM3_Int_Init(4999,7199);//10Khz的计数频率，计数到5000为500ms 
    TIM3_Int_Init(99,7199);//10Khz的计数频率，计数到100为10ms 
    
    initMotor();
    intEncoder();
    
    //LCD_Init();
    //POINT_COLOR=BLACK;//设置字体为红色 
    
    //txBufferSize = printCharArray(TIME_TOPIC,sizeof(TIME_TOPIC));
    //xxxxx = lengthOfInt(33443543434354);
 	while(1)
	{
        if(ifTopicDefine){
            ifTopicDefine = 0;
            printCharArray(TIME_TOPIC,16);
            printCharArray(PUB1,sizeof(PUB1));
            printCharArray(PUB2,sizeof(PUB2));
            printCharArray(SUB,sizeof(SUB));
            ifStartToPublish = 1;
        }

             
	}	 
 }

