#include "ilink_i_uwb_lps.h"
#include "inf_math_lib.h"


i_uwb_lps_tag_struct i_uwb_lps_tag;

/*
 * 函数名：I_UWB_LPS_Tag_DateFrame0_Unpack
 * 描述  ：
 * 输入  ：无
 * 输出  ：无
 */ 
uint8 I_UWB_LPS_Tag_DateFrame0_Unpack(uint8 *data_frame)
{
	uint8 data_frame_sum = 0;//校验位
	uint8 i = 0;
	unsigned char buf[4];
	
	if((data_frame[0] == 0x55) && (data_frame[1] == 0x01))//帧头包头检测
	{
		for(i = 0;i < (128 - 1);i++)//最后字节为校验和
		{
			data_frame_sum += data_frame[i];
		}

		if(data_frame_sum == data_frame[128-1])//检验和检查
		{
			i_uwb_lps_tag.id = data_frame[2];
			
			i_uwb_lps_tag.position.x = (float)Byte32(sint32 ,data_frame[6],data_frame[5],data_frame[4], 0) / 256000.0f;
			i_uwb_lps_tag.position.y = (float)Byte32(sint32 ,data_frame[9],data_frame[8],data_frame[7], 0) / 256000.0f;
			i_uwb_lps_tag.position.z = (float)Byte32(sint32 ,data_frame[12],data_frame[11],data_frame[10], 0) / 256000.0f;
			
			i_uwb_lps_tag.velocity.x = (float)Byte32(sint32 ,data_frame[15],data_frame[14],data_frame[13], 0) / 2560000.0f;
			i_uwb_lps_tag.velocity.y = (float)Byte32(sint32 ,data_frame[18],data_frame[17],data_frame[16], 0) / 2560000.0f;
			i_uwb_lps_tag.velocity.z = (float)Byte32(sint32 ,data_frame[21],data_frame[20],data_frame[19], 0) / 2560000.0f;
			
			i_uwb_lps_tag.dis_buf[0] = (float)Byte32(sint32 ,data_frame[24],data_frame[23],data_frame[22], 0) / 256000.0f;
			i_uwb_lps_tag.dis_buf[1] = (float)Byte32(sint32 ,data_frame[27],data_frame[26],data_frame[25], 0) / 256000.0f;
			i_uwb_lps_tag.dis_buf[2] = (float)Byte32(sint32 ,data_frame[30],data_frame[29],data_frame[28], 0) / 256000.0f;
			i_uwb_lps_tag.dis_buf[3] = (float)Byte32(sint32 ,data_frame[33],data_frame[32],data_frame[31], 0) / 256000.0f;
			i_uwb_lps_tag.dis_buf[4] = (float)Byte32(sint32 ,data_frame[36],data_frame[35],data_frame[34], 0) / 256000.0f;
			i_uwb_lps_tag.dis_buf[5] = (float)Byte32(sint32 ,data_frame[39],data_frame[38],data_frame[37], 0) / 256000.0f;
			i_uwb_lps_tag.dis_buf[6] = (float)Byte32(sint32 ,data_frame[42],data_frame[41],data_frame[40], 0) / 256000.0f;
			i_uwb_lps_tag.dis_buf[7] = (float)Byte32(sint32 ,data_frame[45],data_frame[44],data_frame[43], 0) / 256000.0f;
			
			buf[0] = data_frame[46];buf[1] = data_frame[47];buf[2] = data_frame[48];buf[3] = data_frame[49];
			Byte_to_Float(&i_uwb_lps_tag.gyro.x,buf);
			
			buf[0] = data_frame[50];buf[1] = data_frame[51];buf[2] = data_frame[52];buf[3] = data_frame[53];
			Byte_to_Float(&i_uwb_lps_tag.gyro.y,buf);
			
			buf[0] = data_frame[54];buf[1] = data_frame[55];buf[2] = data_frame[56];buf[3] = data_frame[57];
			Byte_to_Float(&i_uwb_lps_tag.gyro.z,buf);
			
			buf[0] = data_frame[58];buf[1] = data_frame[59];buf[2] = data_frame[60];buf[3] = data_frame[61];
			Byte_to_Float(&i_uwb_lps_tag.acc.x,buf);
			
			buf[0] = data_frame[62];buf[1] = data_frame[63];buf[2] = data_frame[64];buf[3] = data_frame[65];
			Byte_to_Float(&i_uwb_lps_tag.acc.y,buf);
			
			buf[0] = data_frame[66];buf[1] = data_frame[67];buf[2] = data_frame[68];buf[3] = data_frame[69];
			Byte_to_Float(&i_uwb_lps_tag.acc.z,buf);
		
			i_uwb_lps_tag.angle.x = (float) (Byte16(sint16, data_frame[83],  data_frame[82])) / 100.0f;
			i_uwb_lps_tag.angle.y = (float) (Byte16(sint16, data_frame[85],  data_frame[84])) / 100.0f;
			i_uwb_lps_tag.angle.z = (float) (Byte16(sint16, data_frame[87],  data_frame[86])) / 100.0f;
			
			
			buf[0] = data_frame[88];buf[1] = data_frame[89];buf[2] = data_frame[90];buf[3] = data_frame[91];
			Byte_to_Float(&i_uwb_lps_tag.Q.q0,buf);
			
			buf[0] = data_frame[92];buf[1] = data_frame[93];buf[2] = data_frame[94];buf[3] = data_frame[95];
			Byte_to_Float(&i_uwb_lps_tag.Q.q1,buf);
			
			buf[0] = data_frame[96];buf[1] = data_frame[97];buf[2] = data_frame[98];buf[3] = data_frame[99];
			Byte_to_Float(&i_uwb_lps_tag.Q.q2,buf);
			
			buf[0] = data_frame[100];buf[1] = data_frame[101];buf[2] = data_frame[102];buf[3] = data_frame[103];
			Byte_to_Float(&i_uwb_lps_tag.Q.q3,buf);
			
			i_uwb_lps_tag.system_time = Byte32(uint32,data_frame[115], data_frame[114], data_frame[113],  data_frame[112]);
			
			i_uwb_lps_tag.sensor_status = data_frame[116];
			
			return 1;
		}
	}
	
	return 0;
}




