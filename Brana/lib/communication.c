/*
 * communication.c
 *
 * Created: 21.3.2018 15:48:13
 *  Author: Student
 */ 

#include "communication.h"

void send(uint16_t adresa, uint8_t endpoint, uint8_t *data){
	char delka;
	
	for(delka = 0; data[delka] != '\0'; ++delka);
	
	appDataReq.dstAddr = adresa;
	appDataReq.dstEndpoint = endpoint;
	appDataReq.srcEndpoint = endpoint;
	appDataReq.data = data;
	appDataReq.size = delka;
	NWK_DataReq(&appDataReq);
}

void receive(){
		
}