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
#include "hal.h"
#include "phy.h"
#include "sys.h"
#include "nwk.h"
#include "sysTimer.h"
#include "halBoard.h"
#include "halUart.h"

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

typedef struct NWK_DataInd_t
{
	uint16_t srcAddr;
	uint16_t dstAddr;
	uint8_t srcEndpoint;
	uint8_t dstEndpoint;
	uint8_t options;
	uint8_t *data;
	uint8_t size;
	uint8_t lqi;
	int8_t rssi;
} NWK_DataInd_t;

typedef struct NWK_DataReq_t
{
	// service fields
	void *next;
	void *frame;
	uint8_t state;
	// request parameters
	uint16_t dstAddr;
	uint8_t dstEndpoint;
	uint8_t srcEndpoint;
	uint8_t options;
	#ifdef NWK_ENABLE_MULTICAST
	uint8_t memberRadius;
	uint8_t nonMemberRadius;
	#endif
	uint8_t *data;
	uint8_t size;
	void (*confirm)(struct NWK_DataReq_t *req);
	// confirmation parameters
	uint8_t status;
	uint8_t control;
} NWK_DataReq_t;

//Registrace endpointu
NWK_OpenEndpoint(APP_ENDPOINT, funkceObluhy);

//obsluha prichozich ramcu
static bool funkceObluhy (NWK_DataInd_t *ind)
{
	// obsluha
	return true;
}

static void APP_TaskHandler(void)
{
	switch (AppState_t)
	{
		case APP_STATE_INITIAL:
		{
			appInit();
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
	SYS_Init();
	while (1)
	{
		SYS_TaskHandler();
		APP_TaskHandler();
	}
}