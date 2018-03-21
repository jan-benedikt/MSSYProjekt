/*
 * tabulka_zarizeni.c
 *
 * Created: 21.3.2018 15:26:09
 *  Author: Jaroslav Hájek
 */



devices_table BIG_TABLE;


int AddDeviceToTable(device){
	/* add devicec to table

	return 0 = device added
	return 1 = device not added
	*/
if (BIG_TABLE->devices_count<255)
	{
		BIG_TABLE[BIG_TABLE->devices_count]=device;
		BIG_TABLE->devices_count++;
		return 0;
	}
	else
	{
		return 1;
	}
}

int FindDevice(uint8_t address){
	/* find position of device in table

	address = address of device in table
	return int = position of founded device
	return -1 = device not found
	*/
	for(int i =0;i<BIG_TABLE->devices_count;i++)
	{
		if (BIG_TABLE[i]->address==address)
			{
				return i;
			}
		else
			{
				return -1;
			}
	}

}

device GetDevice(uint8_t address){
	/* find position of device in table, return device at found position

	address = address of device in table
	return device = founded device
	return null = device not found
	*/
	tmp=FindDevice(address);
	if (tmp!=-1){
		return BIG_TABLE->devices[tmp];
	}
	else
		return null;
}

int RemoveDeviceFromTable(device){
	/* find position of device in table, remove device from table, resort the table

	device = sturct of device
	return 0 = removed
	return 1 = device not found
	*/
	position=FindDevice(device->address);
	if (position!=-1){
				 			for ( c = position - 1 ; c < BIG_TABLE->devices_count - 1 ; c++ )
							BIG_TABLE->devices[c] = BIG_TABLE->devices[c+1];
							BIG_TABLE->devices_count--;
							return 0;
						}
	return 1;
	}
}
