/*
 * global.h
 *
 * Created: 21.3.2018 15:33:15
 *  Author: Student
 */


#ifndef GLOBAL_H_
#define GLOBAL_H_


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
} cidlo;


typedef struct device
{
	uint8_t id;
	uint16_t address;
	sensor sensors[255];
	int count_sensors=0;
} device;

AddSensorToDevice(sensor,device){
device[device->count_sensor]=sensor;
device->count_sensor++;
}
















#endif /* GLOBAL_H_ */
