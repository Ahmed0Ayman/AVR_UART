# AVR_UART
this library is applicable for ATMEGA32a 
to know how to use this library you can find an example on main.c file 
but also I'll give you a concise description of how to git started with this libary 

1- include uart.c & uart.h in your project 
then 


1 - create an uart handler and set your configuration 
2 - call HAL_UART_Init() function to set peripheral with your configutrations 
3 - to send use HAL_UART_Transmit()
4 - to receive use HAL_UART_Receive()


