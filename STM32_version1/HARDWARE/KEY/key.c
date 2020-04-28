#include "key.h"
#include "delay.h"

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

