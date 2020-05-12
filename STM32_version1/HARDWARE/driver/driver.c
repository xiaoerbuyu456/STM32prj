#include "driver.h"
#include "delay.h"


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

//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0,û���κΰ�������
//1,KEY0 ����
//2,KEY1 ����
//3,KEY2 ����
//4,KEY3 ���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>KEY3!!
u8 KEY_Scan(u8 mode)
{
static u8 key_up=1;//�������ɿ���־
if(mode)key_up=1; //֧������
if(key_up&&(KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
{
delay_ms(10);//ȥ����
key_up=0;
if(KEY0==0)return 1;
else if(KEY1==0)return 2;
else if(KEY2==0)return 3;
else if(WK_UP==1)return 4;
}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1; 
return 0;// �ް�������
}

