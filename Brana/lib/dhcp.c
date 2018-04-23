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
	
	hello_ack.ADRESA = receive->srcAddr;
	hello_ack.ID = 0x00;
	hello_ack.reserved = receive->dstAddr;
	
	//HELLO_PACK_t *test = malloc (receive->size);
	//NWK_DataInd_t newreceive = receive;
	//memcpy(&test, &receive->data,receive->size);


	
	com_send(0x09, 1, &hello_ack, 56);
	//com_reply(receive, hello_ack, sizeof(hello_ack));
}

