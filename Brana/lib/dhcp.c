/*
 * dhcp.c
 *
 * Created: 19.3.2018 15:05:44
 *  Author: Benedikt
 */ 
#include "var.h"


void dhcp_sendAddress(NWK_DataInd_t prijem){
	NWK_DataReq_t dhcppacket;
	
	dhcppacket.dstAddr = prijem.srcAddr;
	dhcppacket.dstEndpoint = 1;
	dhcppacket.data
	
	
}