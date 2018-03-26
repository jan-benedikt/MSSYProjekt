/*
 * dhcp.h
 *
 * Created: 26.3.2018 16:27:57
 *  Author: Student
 */ 


#ifndef DHCP_H_
#define DHCP_H_

#include "var.h"
#include "global.h"
#include "devices_table.h"

void dhcp_sendAddress(NWK_DataInd_t *prijem);

#endif /* DHCP_H_ */