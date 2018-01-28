#include "inf_math_lib.h"


/* 
要点提示: 
1. float和unsigned long具有相同的数据结构长度 
2. union据类型里的数据存放在相同的物理空间 
*/  
typedef union  
{  
    float fdata;  
    unsigned long ldata;  
}FloatLongType;  
  
/* 
将浮点数f转化为4个字节数据存放在byte[4]中 
*/  
void Float_to_Byte(float f,unsigned char byte[])  
{  
    FloatLongType fl;  
    fl.fdata=f;  
    byte[0]=(unsigned char)fl.ldata;  
    byte[1]=(unsigned char)(fl.ldata>>8);  
    byte[2]=(unsigned char)(fl.ldata>>16);  
    byte[3]=(unsigned char)(fl.ldata>>24);  
}  

/* 
将4个字节数据byte[4]转化为浮点数存放在*f中 
*/  
void Byte_to_Float(float *f,unsigned char byte[])  
{  
    FloatLongType fl;  
    fl.ldata=0;  
    fl.ldata=byte[3];  
    fl.ldata=(fl.ldata<<8)|byte[2];  
    fl.ldata=(fl.ldata<<8)|byte[1];  
    fl.ldata=(fl.ldata<<8)|byte[0];  
    *f=fl.fdata;  
}  


//function:	1/(number)^(0.5)
float invSqrt(float number)
{
	volatile long i;
	volatile float x,y;
	volatile const float f = 1.5f;
	x = number * 0.5F;
	y = number;
	i = * (( long * ) &y);
	i = 0x5f375a86 - ( i >> 1 );
	y = * (( float * ) & i);
	y = y * ( f - ( x * y * y ) );
	return y;
}

double SlidingWindow_Flitter(unsigned int flitter_length,unsigned int *flitter_cnt,double buf[],double input)
{
	unsigned int cnt;
	double temp = 0,output = 0;
	
	buf[*flitter_cnt] = input;

	*flitter_cnt += 1;
	if(*flitter_cnt >= flitter_length) *flitter_cnt = 0;
	
	for(cnt = 0;cnt < flitter_length;cnt++)
	{
		temp += buf[cnt];
	}

	output = temp / flitter_length;
	
	return output;
}

void Limiting(volatile float *src,volatile float min,volatile float max)
{
	if(*src < min) *src = min;
	else if(*src > max)	*src = max;
}

