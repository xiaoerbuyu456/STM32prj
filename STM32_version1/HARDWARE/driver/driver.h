#ifndef __DRIVER_H
#define __DRIVER_H
#include "sys.h"

#endif

#define LED0 PBout(5)  //DS0
#define LED1 PEout(5)  //DS1
#define BEEP PBout(8)
#define KEY0 PEin(4) //PE4
#define KEY1 PEin(3) //PE3 
#define KEY2 PEin(2) //PE2
#define WK_UP PAin(0) //PA0 WK_UP �� KEY_UP 
#define KEY0_PRES 1 //KEY0 ����
#define KEY1_PRES 2 //KEY1 ����
#define KEY2_PRES 3 //KEY2 ����
#define WKUP_PRES 4 //KEY_UP ����(���� WK_UP/KEY_UP)

void LED_Init(void);   //��ʼ��


void BEEP_Init(void);


void KEY_Init(void);//IO ��ʼ��


u8 KEY_Scan(u8); //����ɨ�躯��

