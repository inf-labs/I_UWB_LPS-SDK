#include "ilink_ahrs.h"
#include "inf_math_lib.h"

i_ahrs_struct i_ahrs;

uint8 AHRS_DataFrame0_Unpack(uint8 *data_frame)
{
	uint8 data_frame_sum = 0;//校验位
	uint8 i = 0;
	unsigned char buf[4];
	
	if((data_frame[0] == 0x56) && (data_frame[1] == 0x00))//帧头包头检测
	{
		for(i = 0;i < (I_AHRS_DATAFRAME0_LENGTH - 1);i++)//最后字节为校验和
		{
			data_frame_sum += data_frame[i];
		}

		if(data_frame_sum == data_frame[I_AHRS_DATAFRAME0_LENGTH-1])//检验和检查
		{
			buf[0] = data_frame[2];buf[1] = data_frame[3];buf[2] = data_frame[4];buf[3] = data_frame[5];
			Byte_to_Float(&i_ahrs.gyro.x,buf);
			
			buf[0] = data_frame[6];buf[1] = data_frame[7];buf[2] = data_frame[8];buf[3] = data_frame[9];
			Byte_to_Float(&i_ahrs.gyro.y,buf);
			
			buf[0] = data_frame[10];buf[1] = data_frame[11];buf[2] = data_frame[12];buf[3] = data_frame[13];
			Byte_to_Float(&i_ahrs.gyro.z,buf);
			
			buf[0] = data_frame[14];buf[1] = data_frame[15];buf[2] = data_frame[16];buf[3] = data_frame[17];
			Byte_to_Float(&i_ahrs.acc.x,buf);
			
			buf[0] = data_frame[18];buf[1] = data_frame[19];buf[2] = data_frame[20];buf[3] = data_frame[21];
			Byte_to_Float(&i_ahrs.acc.y,buf);
			
			buf[0] = data_frame[22];buf[1] = data_frame[23];buf[2] = data_frame[24];buf[3] = data_frame[25];
			Byte_to_Float(&i_ahrs.acc.z,buf);
		
			i_ahrs.angle.x = (float) (Byte16(sint16, data_frame[39],  data_frame[38])) / 100.0f;
			i_ahrs.angle.y = (float) (Byte16(sint16, data_frame[41],  data_frame[40])) / 100.0f;
			i_ahrs.angle.z = (float) (Byte16(sint16, data_frame[43],  data_frame[42])) / 100.0f;
			
			buf[0] = data_frame[44];buf[1] = data_frame[45];buf[2] = data_frame[46];buf[3] = data_frame[47];
			Byte_to_Float(&i_ahrs.Q.q0,buf);
			
			buf[0] = data_frame[48];buf[1] = data_frame[49];buf[2] = data_frame[50];buf[3] = data_frame[51];
			Byte_to_Float(&i_ahrs.Q.q1,buf);
			
			buf[0] = data_frame[52];buf[1] = data_frame[53];buf[2] = data_frame[54];buf[3] = data_frame[55];
			Byte_to_Float(&i_ahrs.Q.q2,buf);
			
			buf[0] = data_frame[56];buf[1] = data_frame[57];buf[2] = data_frame[58];buf[3] = data_frame[59];
			Byte_to_Float(&i_ahrs.Q.q3,buf);
			
			i_ahrs.system_time = Byte32(uint32,data_frame[71], data_frame[70], data_frame[69],  data_frame[68]);
			
			i_ahrs.sensor_status = data_frame[72];
			
			return 1;
		}
	}
	
	return 0;
	
}


	

