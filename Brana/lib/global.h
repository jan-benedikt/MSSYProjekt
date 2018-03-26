/*
 * global.h
 *
 * Created: 21.3.2018 15:33:15
 *  Author: Jaroslav Hájek
 */


#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <avr/io.h>
/*- Includes ---------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum device_type
{
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













#endif /* GLOBAL_H_ */
