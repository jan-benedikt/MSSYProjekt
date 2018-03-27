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

static SYS_Timer_t appTimer;

//obsluha prichozich ramcu
static bool funkceObsluhy (NWK_DataInd_t *ind)
{
	UART_SendString(ind->dstAddr);
	for (int p = 0;p< ind->size;p++){
		UART_SendString(ind->data[p]);
	}
	
	
	UART_SendString("m\r\n");
	return true;
}

static void appTimerHandler(SYS_Timer_t *timer)
{
	//send(0x01, 1, 3, 1);
	(void)timer;
}

void appInit(){
	 NWK_SetAddr(APP_ADDR);
	 NWK_SetPanId(APP_PANID);
	 PHY_SetChannel(APP_CHANNEL);
	 PHY_SetRxState(true);
	
	NWK_OpenEndpoint(APP_ENDPOINT, funkceObsluhy);
	UART_init(9600);
	  HAL_BoardInit();

	  appTimer.interval = APP_FLUSH_TIMER_INTERVAL;
	  appTimer.mode = SYS_TIMER_INTERVAL_MODE;
	  appTimer.handler = appTimerHandler;
}

static void APP_TaskHandler(void)
{
	switch (appState)
	{
		case APP_STATE_INITIAL:
		{
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
	appInit();
	while (1)
	{
		SYS_TaskHandler();
		APP_TaskHandler();
	}
}