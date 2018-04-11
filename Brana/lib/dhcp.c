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
 * @param  prijem           [NWK_DataInd_t packet po prijeti]
 */
void dhcp_sendAddress(NWK_DataInd_t *receive){
	HELLO_PACK_t *test;
	//NWK_DataInd_t newreceive = receive;
	memcpy(test, &receive->data, receive->size);
	static HELLO_ACK_t hello_ack;
	hello_ack.ADRESA = 0xff;
	hello_ack.ID = 0x00;
	hello_ack.reserved = receive->dstAddr;
	com_reply(receive, hello_ack, 56);
}

