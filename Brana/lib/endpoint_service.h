/*
 * endpoint_service.h
 *
 * Created: 26.3.2018 16:27:57
 *  Author: Benedikt
 */ 


#ifndef ENDPOINT_SERVICE_H_
#define ENDPOINT_SERVICE_H_

#include "var.h"

bool endpointHandler1 (NWK_DataInd_t *ind);
bool endpointHandler2 (NWK_DataInd_t *ind);
bool endpointHandler3 (NWK_DataInd_t *ind);
bool endpointHandler4 (NWK_DataInd_t *ind);

#endif /* ENDPOINT_SERVICE_H_ */