/*
 * var.h
 *
 * Created: 21.3.2018 15:08:25
 *  Author: Student
 */

#ifndef VAR_H_
#define VAR_H_
/************************************************************************/
/* ZARIZENI                                                             */
/************************************************************************/
#define Brana 255
#define Klavesnice 128
#define Kontakt 64
#define Rele 32
#define Termohlavice 16
#define Cidlo 8
#define Motor 4

/************************************************************************/
/* DATOVE TYPY                                                          */
/************************************************************************/

#define Teplota 2
#define Tlak 4
#define Vlhkost 8
#define BinIN 16
#define BinOUT 32
#define Relative_Val 64
#define Light 128
#define TEXT1 256
#define Byte_Val 8192
#define Integer_Val 16384
#define Float_val 32768
#define Command 65535

/************************************************************************/
/* Sprava                                                               */
/************************************************************************/
#define HELLO 128
#define SLEEP 64
#define RECONNECT 32
#define HELLO_ACK 2
#define ACK 1

/************************************************************************/
/* Prenos dat                                                           */
/************************************************************************/

#define Set_VALUE 128
#define Get_VALUE 64
#define VALUE 2

/************************************************************************/
/* ALARM                                                                */
/************************************************************************/

#define ALARM 128
#define DATA_OVER 64
#define DATA_UNDER 32



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



typedef struct PACK
{
	uint8_t ID;
	uint8_t TYP;
	uint16_t DATA;
	uint8_t *pocet;
	uint8_t spanek;
	uint16_t r_w;
}HELLO_PACK_t;

typedef struct PACK
{
	uint8_t ID;
	uint16_t ADRESA;
	uint16_t Perioda_spanku;
	uint16_t reserved;
}HELLO_ACK_t;

#define HELLO_ACK_t_size 56

typedef struct PACK
{
	uint8_t ID;
	uint16_t ADRESA;
	uint16_t Perioda_spanku;
	uint16_t reserved;
}ACK_H_t;

typedef struct PACK
{
	uint8_t ID;
	uint16_t Perioda_spanku;
	uint16_t reserved;
}SLEEP_t;

typedef struct PACK
{
	uint8_t ID;
	uint16_t Perioda_spanku;
	uint16_t reserved;
}SLEEP_ACK_t;

 NWK_DataReq_t *FRONTA;
 //int QUEUE_size;
 
 	TEPLOTA, 		   //float
	TLAK,					 //float
	VLHKOST,   		 //float
	BINARNI_VSTUP, //uint8_t
	BINARNI_VYSTUP, //uint8_t
	RELATIVNI_HODNOTA, //uint8_t
	OSVETLENI,	//uint8_t
	TEXT,	//string
	OBECNY_BYTE,	//uint8_t
	OBECNY_INTEGER,	//uint8_t
	OBECNY_FLOAT,	//uint8_t
	PRIKAZ,	//string
} device_type;



typedef struct sensor
{
	uint8_t id;
	uint8_t status;
	device_type type;
} sensor;


typedef struct device
{
	uint8_t id;
	uint16_t address;
	sensor sensors[255];
	int count_sensors;
} device;

int AddSensorToDevice(sensor sen,device dev);

#endif /* VAR_H_ */


static HELLO_ACK_t hello_ack;
static HELLO_PACK_t packet;