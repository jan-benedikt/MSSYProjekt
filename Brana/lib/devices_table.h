/*
 * tabulka_zarizeni.h
 *
 * Created: 21.3.2018 15:26:30
 *  Author: Student
 */


#ifndef DEVICES_TABLE_H_
#define DEVICES_TABLE_H_

typedef struct devices_table
{
	device devices[255];
	int devices_count=0;
} devices_table;

int AddDeviceToTable(device);
int FindDevice(uint8_t address);
device GetDevice(uint8_t address);
int RemoveDeviceFromTable(device);




#endif /* DEVICES_TABLE_H_ */
