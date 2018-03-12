/*
 * UART.h
 *
 * Created: 12.2.2018 15:32:53
 *  Author: Benedikt
 */ 

#include <avr/io.h>

#ifndef UART_H_
#define UART_H_

void UART_init(int Baudrate);
void UART_SendChar(uint8_t data);
uint8_t UART_GetChar( void );
void UART_SendString(char *text);
void UART_Clc();
void UART_HomePos();

#endif /* UART_H_ */