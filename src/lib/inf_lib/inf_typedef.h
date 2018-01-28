#ifndef __INF_TYPEDEF_H
#define __INF_TYPEDEF_H

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed short int sint16;
typedef signed int sint32;

//取一个数据的地址强制转换成指向char型的，然后取前八位
#define BYTE0(BYTE_TEMP)       ( *( char *)(&BYTE_TEMP))
#define BYTE1(BYTE_TEMP)       ( *( (char *)(&BYTE_TEMP) + 1))
#define BYTE2(BYTE_TEMP)       ( *( (char *)(&BYTE_TEMP) + 2))
#define BYTE3(BYTE_TEMP)       ( *( (char *)(&BYTE_TEMP) + 3))
	
#define Byte16(Type, ByteH, ByteL)  ((Type)((((uint16)(ByteH))<<8) | ((uint16)(ByteL))))
//#define Byte24(Type, Byte3, Byte2, Byte1)  ((Type) ((Type)( (((u32)(Byte3))<<16) | (((u32)(Byte2))<<8) | ((u32)(Byte1))))
#define Byte32(Type, Byte4, Byte3, Byte2, Byte1)  ((Type)( (((uint32)(Byte4))<<24) | (((uint32)(Byte3))<<16) | (((uint32)(Byte2))<<8) | ((uint32)(Byte1))))




typedef struct
{
	float x;
	float y;
	float z;
}S_FLOAT_XYZ;

typedef struct
{
	signed short int x;
	signed short int y;
	signed short int z;
}S_INT16_XYZ;//s16

typedef struct
{
	signed int x;
	signed int y;
	signed int z;
}S_INT32_XYZ;//s32

typedef struct {
  float q0;
  float q1;
  float q2;
  float q3;
} Quaternion;

typedef volatile struct {
  float M[9];
} Matrix9;

typedef volatile struct {
	float P,Pout;
	float I,Iout;
	float D,Dout;
	float Out;
	float Out_Limit;
	float Iout_Limit;
	float err;
}PID;

typedef volatile struct {
	S_FLOAT_XYZ P,Pout;
	S_FLOAT_XYZ I,Iout;
	S_FLOAT_XYZ D,Dout;
	S_FLOAT_XYZ Out;
	S_FLOAT_XYZ Iout_Limit;
	
	
}PID_XYZ;

#endif



