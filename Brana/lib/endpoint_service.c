/*
 * endpoint_service.c
 *
 * Created: 11.4.2018 11:20:44
 *  Author: Benedikt
 */

#include "endpoint_service.h"

bool endpointHandler1 (NWK_DataInd_t *ind)
{
	int cislo = ind->srcAddr;
	char buffer[3] = "000";
	sprintf (buffer,"%d",cislo);
	
	UART_SendString("from :0x");
	UART_SendString(buffer);
	
	dhcp_sendAddress(ind);
	
	UART_SendString(HELLO_ACK_t_size);
	
	UART_SendString("| data :");
	for (int p = 0;p< ind->size;p++){
		
		UART_SendChar(ind->data[p]);
	}
	
	UART_SendString("\r\n");
	return true;
}

bool endpointHandler2 (NWK_DataInd_t *ind)
{
	int cislo = ind->srcAddr;
	char buffer[3] = "000";
	sprintf (buffer,"%d",cislo);
	
	UART_SendString("from :0x");
	UART_SendString(buffer);
	
	dhcp_sendAddress(ind);
	
	UART_SendString(HELLO_ACK_t_size);
	
	UART_SendString("| data :");
	for (int p = 0;p< ind->size;p++){
		
		UART_SendChar(ind->data[p]);
	}
	
	UART_SendString("\r\n");
	return true;
}

bool endpointHandler3 (NWK_DataInd_t *ind)
{
	int cislo = ind->srcAddr;
	char buffer[3] = "000";
	sprintf (buffer,"%d",cislo);
	
	UART_SendString("from :0x");
	UART_SendString(buffer);
	
	dhcp_sendAddress(ind);
	
	UART_SendString(HELLO_ACK_t_size);
	
	UART_SendString("| data :");
	for (int p = 0;p< ind->size;p++){
		
		UART_SendChar(ind->data[p]);
	}
	
	UART_SendString("\r\n");
	return true;
}

bool endpointHandler4 (NWK_DataInd_t *ind)
{
	int cislo = ind->srcAddr;
	char buffer[3] = "000";
	sprintf (buffer,"%d",cislo);
	
	UART_SendString("from :0x");
	UART_SendString(buffer);
	
	dhcp_sendAddress(ind);
	
	UART_SendString(HELLO_ACK_t_size);
	
	UART_SendString("| data :");
	for (int p = 0;p< ind->size;p++){
		
		UART_SendChar(ind->data[p]);
	}
	
	UART_SendString("\r\n");
	return true;
}