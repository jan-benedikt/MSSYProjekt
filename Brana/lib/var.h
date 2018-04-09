/*
 * var.h
 *
 * Created: 21.3.2018 15:08:25
 *  Author: Student
 */


#ifndef VAR_H_
#define VAR_H_

#include <avr/io.h>
/*- Includes ---------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hal.h"
#include "phy.h"
#include "sys.h"
#include "nwk.h"
#include "MACROS.h"
#include "frame_data.h"

static NWK_DataReq_t appDataReq;

static void appDataConf(NWK_DataReq_t *req);
 NWK_DataReq_t *FRONTA;
 //int QUEUE_size;

#endif /* VAR_H_ */
