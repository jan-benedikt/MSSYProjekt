/*
 * devices_table.c
 *
 * Created: 21.3.2018 15:26:09
 *  Author: Jaroslav Hájek
 */



devices_table BIG_TABLE;

/**
 * [add devicec to table]
 * @method AddDeviceToTable
 * @param  dev              [device from table]
 * @return                  [int 1:succes, int 0:bad]
 */
int AddDeviceToTable(device dev){
if (BIG_TABLE->devices_count<255)
	{

		BIG_TABLE[BIG_TABLE->devices_count]=dev;
		BIG_TABLE->devices_count++;
		return 0;
	}
	else
	{
		return 1;
	}
}

/**
 * [try found free addres for device]
 * @method FindFreeAddress
 * @return [uint8_t addres]
 */
uint8_t FindFreeAddress(){
	for (int a = 0;a<255;a++)
	{
		for(int i =0;i<BIG_TABLE->devices_count;i++)
		{
			int f = 1;
			if (BIG_TABLE[i]->address==a)
				{
					f=0;
				}
		}
		if (f==1){
			return a;
		}
	}
}

/**
 * [find position of device in table]
 * @method FindDevice
 * @param  address    [uint8_t adress of device]
 * @return            [int position of device, int -1:bad]
 */
int FindDevice(uint8_t address){
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



/**
 * [find position of device in table, return device at found position]
 * @method GetDevice
 * @param  address   [uint8_t adress of device]
 * @return           [device from table:succes, null]
 */
device GetDevice(uint8_t address){
	tmp=FindDevice(address);
	if (tmp!=-1){
		return BIG_TABLE->devices[tmp];
	}
	else
		return null;
}

/*
 * [find position of device in table, remove device from table, resort the table]
 * @method RemoveDeviceFromTable
 * @param  dev                   [device]
 * @return                       [int 1:succes, int 0:bad]
 */
int RemoveDeviceFromTable(device dev){
	position=FindDevice(dev->address);
	if (position!=-1){
				 			for ( c = position - 1 ; c < BIG_TABLE->devices_count - 1 ; c++ )
							BIG_TABLE->devices[c] = BIG_TABLE->devices[c+1];
							BIG_TABLE->devices_count--;
							return 0;
						}
	return 1;
	}
}
