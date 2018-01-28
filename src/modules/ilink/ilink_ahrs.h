#ifndef __ILINK_AHRS_H
#define __ILINK_AHRS_H

#include "inf_typedef.h"

#define I_AHRS_DATAFRAME0_LENGTH 74


typedef struct
{
	S_FLOAT_XYZ gyro;
	S_FLOAT_XYZ acc;
	
	S_FLOAT_XYZ angle;
	
	Quaternion Q;
	
	uint32 system_time;
	uint8 sensor_status;
	
} i_ahrs_struct;

extern i_ahrs_struct i_ahrs;

uint8 AHRS_DataFrame0_Unpack(uint8 *data_frame);

#endif


