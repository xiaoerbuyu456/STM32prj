/*
 *本文件是对LED初始化的功能函数，由原理图与参考手册可知
 *1.需要使能GPIOB与GPIOE的时钟总线
 *2.配置输出模式（推完输出）
 *3.配置相应寄存器进行点灯？（思考位带操作）
*/

#include "LED.h"


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
