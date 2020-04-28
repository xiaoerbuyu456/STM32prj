#include "sys.h"
#include "usart.h"		
#include "delay.h"	 
#include "led.h"
//ALIENTEK战舰STM32开发板 实验0
//新建工程 实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
int main(void)
{				 
	u8 t=0; 
	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);	  		//延时初始化
	uart_init(72,115200); 	//串口初始化为115200
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






