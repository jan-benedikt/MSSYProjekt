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
	HELLO_PACK_t *test = malloc (sizeof(receive->data));
	//NWK_DataInd_t newreceive = receive;
	memcpy(&test, &receive->data, sizeof(receive->data));
	
	static HELLO_ACK_t hello_ack;
	hello_ack.ADRESA = receive->srcAddr;
	hello_ack.ID = 0x00;
	hello_ack.reserved = receive->dstAddr;
	com_send(0x01, 0x01, &hello_ack, 40);
	//com_reply(receive, hello_ack, sizeof(hello_ack));
}

