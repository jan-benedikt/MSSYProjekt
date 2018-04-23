/*
 * dhcp.c
 *
 * Created: 19.3.2018 15:05:44
 *  Author: Benedikt
 */

#include "dhcp.h"

/**
 * [vygeneruje a zasle adresu zarizeni]
 * @method dhcp_sendAddress
 * @param prijem [NWK_DataInd_t packet po prijeti]
 */
void dhcp_sendAddress(NWK_DataInd_t *receive){
	
	
	hello_ack.ADRESA = FindFreeAddress();
	hello_ack.ID = 0x00;
	hello_ack.reserved = receive->dstAddr;
	
	HELLO_PACK_t *test = malloc (receive->size);
	NWK_DataInd_t newreceive = receive;
	memcpy(&test, &receive->data,receive->size);

	device.address = FindFreeAddress();
	device.count_sensors = test->pocet;
	
	for(int i = 1; i<256; i = i*2){
		uint8_t pozice = i;
		if(tbi(test->TYP, pozice)){
			switch(pozice){
				case device_type.BINARNI_VSTUP:
				
				break;
				case device_type.BINARNI_VYSTUP:
				
				break;
				case device_type.OBECNY_BYTE:
				
				break;
				case device_type.OBECNY_FLOAT:
				
				break;
				case device_type.OBECNY_INTEGER:
				
				break;
				case device_type.OSVETLENI:
				
				break;
				case device_type.PRIKAZ:
				
				break;
				case device_type.RELATIVNI_HODNOTA:
				
				break;
				case device_type.TEPLOTA:
				
				break;
				case device_type.TEXT:
				
				break;
				case device_type.TLAK:
				
				break;
				case device_type.VLHKOST:
				
				break;
			}
		}
	} 
	
	device.sensors = 
	device.id = test->ID;
	
	com_send(0x09, 1, &hello_ack, 56);
	//com_reply(receive, hello_ack, sizeof(hello_ack));
}

