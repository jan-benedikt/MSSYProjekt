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
void dhcp_sendAddress(NWK_DataInd_t *prijem){
	appDataReq.dstAddr = prijem->srcAddr;
	appDataReq.dstEndpoint = 1;
	uint8_t new_address = FindFreeAddress();
	appDataReq.data= new_address;
	NWK_DataReq(&appDataReq);
}

