#include "driver.h"
#include "delay.h"


void LED_Init(void)
{
	RCC->APB2ENR |= 1<<3; //使能PORTB时钟
	RCC->APB2ENR |= 1<<6;  //使能PORTE时钟
	GPIOB->CRL &= 0XFF0FFFFF; 
	GPIOB->CRL &= 0X00300000; //PB.5推挽输出
	GPIOB->ODR |= 1<<5;        //PB.5输出高
	GPIOE->CRL &= 0XFF0FFFFF;  
	GPIOE->CRL &= 0X00300000;  // PE5推挽输出
	GPIOE->ODR |= 1<<5;         //PE5输出高
}

void BEEP_Init(void)
{
	RCC->APB2ENR |= 1<<3;
	GPIOB->CRH &= 0XFFFFFFF0;
	GPIOB->CRH |= 0X00000003;
	BEEP = 0;
}

void KEY_Init(void)
{
	RCC->APB2ENR |= 1<<2;
	RCC->APB2ENR |= 1<<6;
	GPIOA->CRL &= 0XFFFFFFF0;
	GPIOA->CRL &= 0X00000008;
	GPIOE->CRL &= 0XFFF000FF;
	GPIOE->CRL |= 0X00088800;
	GPIOE->ODR |= 7<<2;
}

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0,没有任何按键按下
//1,KEY0 按下
//2,KEY1 按下
//3,KEY2 按下
//4,KEY3 按下 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY2>KEY3!!
u8 KEY_Scan(u8 mode)
{
static u8 key_up=1;//按键按松开标志
if(mode)key_up=1; //支持联安
if(key_up&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
{
delay_ms(10);//去抖动
key_up=0;
if(KEY0==0)return 1;
else if(KEY1==0)return 2;
else if(KEY2==0)return 3;
else if(WK_UP==1)return 4;
}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1; 
return 0;// 无按键按下
}

