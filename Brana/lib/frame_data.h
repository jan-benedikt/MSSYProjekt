/*
 * frame_data.h
 *
 *  Created: 12.3.2018 16:59:00
 *  Author: Benedikt
 */ 

#ifndef FRAME_DATA_H_
#define FRAME_DATA_H_

/************************************************************************/
/*				Table for identification of out/incoming data			*/
/* -------------------------------------------------------------------- */
/*		Name			Size	ID										*/
/* -------------------------------------------------------------------- */
/*		Binary input	 1B		1										*/
/*		Binary output	 1B		2										*/
/*		Analog input	 2B		3										*/
/*		Analog output	 2B		4										*/
/*		Command			 char*	5										*/
/*		File			 char*	6										*/
/*		Digital input	 2B		7										*/
/*		Digital output	 2B		8										*/
/************************************************************************/

// Type of data
#define temperature 2
#define pressure 4
#define humidity 8
#define binary_input 16
#define binary_output 32

// Devices
#define gateway 255
#define keyboard 128
#define contact 64
#define relay 32
#define thermohead 16
#define environment_sensor 8
#define engine 4

#endif /* FRAME_DATA_H_ */