/*
 * UART.c
 *
 * Created: 12.2.2018 15:32:36
 *  Author: Benedikt
 */ 
#include "UART.h"
#include <string.h>
#include <avr/interrupt.h>

void UART_init(int Baudrate){
	volatile double test=((8000000/16)/Baudrate)-1;
	int ubrr=((F_CPU/16/Baudrate)-1);
	UBRR1H = (uint8_t)(ubrr>>8);
	UBRR1L = (uint8_t)ubrr;
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);// Povolit prijem/vydej
	UCSR1C = (1<<UCSZ01)|(1<<UCSZ00);// Async, Parity-Disabled, 1 Stop bit, 8 data bits
	UCSR1B |= (1 << RXCIE1); //Povoleni preruseni pri prijmu
	UART_Clc();
	UART_HomePos();
}
void UART_SendChar(uint8_t data)
{
	while ( !( UCSR1A & (1<<UDRE0)) )
	;
	UDR1 = data;
}

uint8_t UART_GetChar( void )
{
	while ( !(UCSR1A & (1<<RXC0)) )
	;
	return UDR1;
}

void UART_Clc(){
	UART_SendChar(27);   // this is the escape
	UART_SendChar('[');
	UART_SendChar('2');
	UART_SendChar('J');  // uppercase J
}

void UART_HomePos(){
	UART_SendString("\033[H");
}

void UART_SendString(char *text)
{
	while (*text != 0x00)
	{
		UART_SendChar(*text);
		text++;
	}
}