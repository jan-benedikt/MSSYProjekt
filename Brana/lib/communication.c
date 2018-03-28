/*
 * communication.c
 *
 * Created: 21.3.2018 15:48:13
 *  Author: Student
 */ 

#include "communication.h"

static void appDataConf(NWK_DataReq_t *req)
{
	if (NWK_SUCCESS_STATUS == req->status)
	{
		//QUEUE_rm_last();
	}
	else
	{int a;}
	

}

void com_send(uint16_t adresa, uint8_t endpoint, uint8_t *data){
	char delka;
	
	for(delka = 0; data[delka] != '\0'; ++delka);
	
	appDataReq.dstAddr = adresa;
	appDataReq.dstEndpoint = endpoint;
	appDataReq.srcEndpoint = endpoint;
	appDataReq.data = data;
	appDataReq.size = delka;
	NWK_DataReq(&appDataReq);
}

void com_reply(NWK_DataInd_t *ind, uint8_t *data){
	volatile int delka;
	
	//for(delka = 0; data[delka] != '\0'; ++delka);
	delka=strlen(data);
	
	appDataReq.dstAddr = ind->srcAddr;
	appDataReq.dstEndpoint = ind->srcEndpoint;
	appDataReq.srcEndpoint = ind->dstEndpoint;
	appDataReq.data = data;
	appDataReq.size = delka;
	appDataReq.confirm= appDataConf;
	//QUEUE_add(&appDataReq);
	NWK_DataReq(&appDataReq);
	
}