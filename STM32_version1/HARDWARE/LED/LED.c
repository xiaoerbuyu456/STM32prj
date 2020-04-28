/*
 *���ļ��Ƕ�LED��ʼ���Ĺ��ܺ�������ԭ��ͼ��ο��ֲ��֪
 *1.��Ҫʹ��GPIOB��GPIOE��ʱ������
 *2.�������ģʽ�����������
 *3.������Ӧ�Ĵ������е�ƣ���˼��λ��������
*/

#include "LED.h"


void LED_Init(void)
{
	RCC->APB2ENR |= 1<<3; //ʹ��PORTBʱ��
	RCC->APB2ENR |= 1<<6;  //ʹ��PORTEʱ��
	GPIOB->CRL &= 0XFF0FFFFF; 
	GPIOB->CRL &= 0X00300000; //PB.5�������
	GPIOB->ODR |= 1<<5;        //PB.5�����
	GPIOE->CRL &= 0XFF0FFFFF;  
	GPIOE->CRL &= 0X00300000;  // PE5�������
	GPIOE->ODR |= 1<<5;         //PE5�����
}
