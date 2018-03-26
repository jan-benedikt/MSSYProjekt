/*
 * devices_table.h
 *
 * Created: 21.3.2018 15:26:30
 *  Author: Student
 */


#ifndef DEVICES_TABLE_H_
#define DEVICES_TABLE_H_

#include <avr/io.h>
/*- Includes ---------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct devices_table
{
	device devices[20];
	int devices_count;
} devices_table;

int AddDeviceToTable(device);
int FindDevice(uint8_t address);
device GetDevice(uint8_t address);
int RemoveDeviceFromTable(device);
uint8_t FindFreeAddress();



#endif /* DEVICES_TABLE_H_ */
