/*
 * dhcp.c
 *
 * Created: 19.3.2018 15:05:44
 *  Author: Benedikt
 */
#include "var.h"
#include "global.h"
#include "devices_table.h"

/**
 * [vygeneruje a zasle adresu zarizeni]
 * @method dhcp_sendAddress
 * @param  prijem           [NWK_DataInd_t packet po prijeti]
 */
void dhcp_sendAddress(NWK_DataInd_t prijem){
	NWK_DataReq_t dhcppacket;

	dhcppacket.dstAddr = prijem.srcAddr;
	dhcppacket.dstEndpoint = 1;
	unit8_t new_address = FindFreeAddress();
	dhcppacket.data= new_address();
	dhcppacket.confirm();
}
