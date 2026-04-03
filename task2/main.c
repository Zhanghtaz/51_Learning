#include <at89c51RC2.h>
#include "UART.h"
#include "LCD1602.h"
#include "AT24C02.h"
#include "Delay.h"

unsigned char Temp,Data;

void main()
{
	UART_Init();             //初始化
	LCD_Init();              //初始化
	Temp=AT24C02_ReadByte(0);     //读取
    LCD_ShowNum(1, 1,Temp,3);     //显示
	UART_SendByte(Temp);
	while(1)
	{
        
	}
}

void UART_Routine() interrupt 4
{
	if(RI==1)
	{		
		UART_SendByte(SBUF);      //发送
		Data=SBUF;
		LCD_ShowNum(1,1,Data,3);
		
		AT24C02_WriteByte(0,Data);
        Delay(5); 
		RI=0;
    } 
}
