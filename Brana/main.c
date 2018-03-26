/*
 * Brana.c
 *
 * Created: 12.3.2018 15:52:23
 * Author : Benedikt
 */ 

#include <avr/io.h>
/*- Includes ---------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "lib/var.h"
#include "sysTimer.h"
#include "halBoard.h"
#include "halUart.h"
#include "lib/UART.h"
#include "lib/dhcp.h"
#include "lib/communication.h"

/*- Definitions ------------------------------------------------------------*/
#ifdef NWK_ENABLE_SECURITY
#define APP_BUFFER_SIZE     (NWK_MAX_PAYLOAD_SIZE - NWK_SECURITY_MIC_SIZE)
#else
#define APP_BUFFER_SIZE     NWK_MAX_PAYLOAD_SIZE
#endif

/*- Types ------------------------------------------------------------------*/
typedef enum AppState_t
{
	APP_STATE_INITIAL,
	APP_STATE_IDLE,
} AppState_t;

AppState_t appState = APP_STATE_INITIAL;

//obsluha prichozich ramcu
static bool funkceObsluhy (NWK_DataInd_t *ind)
{
	for (int p = 0;p< ind->size;p++){
		UART_SendString(ind->data[p]);
	}
	
	UART_init(9600);
	UART_SendString("\r\n");
	return true;
}

void appInit(){
	NWK_OpenEndpoint(APP_ENDPOINT, funkceObsluhy);
	send(0x01, 1, 3, 1);
}

static void APP_TaskHandler(void)
{
	switch (appState)
	{
		case APP_STATE_INITIAL:
		{
			appInit();
			UART_SendString(appDataReq.data);
			appState = APP_STATE_IDLE;
		} break;
		case APP_STATE_IDLE:
		break;
		default:
		break;
	}
}

int main(void)
{	
	UART_init(9600);
	SYS_Init();
	while (1)
	{
		SYS_TaskHandler();
		APP_TaskHandler();
	}
}