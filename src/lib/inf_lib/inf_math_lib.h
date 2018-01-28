#ifndef __INF_MATH_LIB_H
#define __INF_MATH_LIB_H

//no effect
//#define LIMIT(X,MIN,MAX ) ( (X) < (MIN)  ? (MIN) : ( (X) > (MAX) ? (MAX) : (X) ) )

#define _MIN(A, B) ((A) < (B) ? (A) : (B))
#define _MAX(A, B) ((A) > (B) ? (A) : (B))

void Float_to_Byte(float f,unsigned char byte[]);
void Byte_to_Float(float *f,unsigned char byte[]);

float invSqrt(float number);
double SlidingWindow_Flitter(unsigned int flitter_length,unsigned int *flitter_cnt,double buf[],double input);
void Limiting(volatile float *src,volatile float min,volatile float max);
#endif


