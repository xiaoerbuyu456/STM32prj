#include "sys.h"
#include "usart.h"		
#include "delay.h"	 
#include "led.h"
//ALIENTEKս��STM32������ ʵ��0
//�½����� ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
int main(void)
{				 
	u8 t=0; 
	Stm32_Clock_Init(9);	//ϵͳʱ������
	delay_init(72);	  		//��ʱ��ʼ��
	uart_init(72,115200); 	//���ڳ�ʼ��Ϊ115200
	LED_Init();
  	while(1)
	{
		printf("t:%d\r\n",t);
		delay_ms(500);
		t++;
		LED0=0;
		LED1=1;
		delay_ms(300);
		
		LED0=1;
		LED1=0;
		delay_ms(300);
	}	 
} 






