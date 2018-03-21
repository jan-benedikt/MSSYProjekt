/*
 * global.c
 *
 * Created: 19.3.2018 15:05:44
 *  Author: Jaroslav Hájek
 */



/**
 * [adding sensors to device]
 * @method AddSensorToDevice
 * @param  sen               [sensor]
 * @param  dev               [device]
 * @return                   [int 1:succes, int 0:bad]
 */
int AddSensorToDevice(sensor sen,device dev){
	if (dev->count_sensors<255)
		{
		dev[dev->count_sensor]=sen;
		dev->count_sensors++;
		return 0;
		}
	else
		{
		return 1;
		}

}
