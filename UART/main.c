/*
 * UART.c
 *
 * Created: 5/10/2021 9:38:38 AM
 * Author : Ahmed_Ayman
 */ 
#define  F_CPU 16000000
#include <avr/io.h>
#include "HAL_GPIO.h"
#include "HAL_UART.h"
#include <util/delay.h>
#include "Lcd-Driver.h"

UART_Handler_t Handler;
uint8_t Data[15] = "Hallo world!" ;

uint8_t RxData =0 ;

int main(void)
{
	Handler.Init.BaudRate = 9600 ;
	Handler.Init.Mode = UART_MODE_TX_RX ;
	Handler.Init.Parity = UART_Parity_No ;
	Handler.Init.StopBits = UART_Stop_1 ;
	Handler.Init.wordLen  = UART_WordLen_8 ;
	
	HAL_UART_Init(&Handler);
	
	LCD_Initializaion();
    /* Replace with your application code */
    while (1) 
    {
	//HAL_UART_MltiProcessor_TX(&Handler,Data,10,0x3);
	HAL_UART_MltiProcessor_RX(&Handler,&RxData,1,0x3);
	//HAL_UART_RECEIVE(&Handler,&RxData,1);
	LCD_Send_An_Integer_With_CurrLoc(RxData,3);
	_delay_ms(3000);
	
		
	LCD_Send_A_Command(0x01);
    }
}

