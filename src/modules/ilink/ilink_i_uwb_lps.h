#ifndef __ILINK_I_UWB_LPS_H
#define __ILINK_I_UWB_LPS_H
	
#include "inf_typedef.h"

#define I_UWB_LPS_TAG_DATAFRAME0_LENGTH 128


typedef struct
{
	uint8 id;
	
	S_FLOAT_XYZ position;
	S_FLOAT_XYZ velocity;
	float dis_buf[8];
	
	S_FLOAT_XYZ gyro;
	S_FLOAT_XYZ acc;
	
	S_FLOAT_XYZ angle;
	Quaternion Q;
	
	uint32 system_time;
	uint8 sensor_status;	
	
} i_uwb_lps_tag_struct;

extern i_uwb_lps_tag_struct i_uwb_lps_tag;


uint8 I_UWB_LPS_Tag_DateFrame0_Unpack(uint8 *data_frame);


#endif

