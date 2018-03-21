/*
 * var.h
 *
 * Created: 21.3.2018 15:08:25
 *  Author: Student
 */ 


#ifndef VAR_H_
#define VAR_H_












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



#endif /* VAR_H_ */