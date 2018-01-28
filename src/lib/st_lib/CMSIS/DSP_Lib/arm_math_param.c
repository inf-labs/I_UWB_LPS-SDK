#include "arm_math_param.h"


float I_22[2*2] = {1,0,
									 0,1};
float I_44[4*4] = {1,0,0,0,
									 0,1,0,0,
									 0,0,1,0,
									 0,0,0,1};
float I_77[7*7] = {1,0,0,0,0,0,0,
									 0,1,0,0,0,0,0,
									 0,0,1,0,0,0,0,
									 0,0,0,1,0,0,0,
									 0,0,0,0,1,0,0,
									 0,0,0,0,0,1,0,
									 0,0,0,0,0,0,1};
																
									 
float	temp_11[1*1],temp_12[1*2],temp_21[2*1],temp_22[2*2];
float	temp1_11[1*1],temp1_12[1*2],temp1_21[2*1],temp1_22[2*2];
									 
float	temp_24[2*4],temp_42[4*2];
float	temp1_24[2*4],temp1_42[4*2];
									 
float temp_14[1*4],temp_41[4*1],temp_44[4*4],temp_47[4*7],temp_74[7*4],temp_77[7*7],temp_17[1*7],temp_71[7*1];
float temp1_14[1*4],temp1_41[4*1],temp1_44[4*4],temp1_47[4*7],temp1_74[7*4],temp1_77[7*7],temp1_17[1*7],temp1_71[7*1];

arm_matrix_instance_f32 _I_22 = {2,2,I_22};
arm_matrix_instance_f32 _I_44 = {4,4,I_44};
arm_matrix_instance_f32 _I_77 = {7,7,I_77};

arm_matrix_instance_f32 _temp_11 = {1,1,temp_11};
arm_matrix_instance_f32 _temp_12 = {1,2,temp_12};
arm_matrix_instance_f32 _temp_21 = {2,1,temp_21};
arm_matrix_instance_f32 _temp_22 = {2,2,temp_22};

arm_matrix_instance_f32 _temp1_11 = {1,1,temp1_11};
arm_matrix_instance_f32 _temp1_12 = {1,2,temp1_12};
arm_matrix_instance_f32 _temp1_21 = {2,1,temp1_21};
arm_matrix_instance_f32 _temp1_22 = {2,2,temp1_22};


arm_matrix_instance_f32 _temp_24 = {2,4,temp_24};
arm_matrix_instance_f32 _temp_42 = {4,2,temp_42};

arm_matrix_instance_f32 _temp1_24 = {2,4,temp1_24};
arm_matrix_instance_f32 _temp1_42 = {4,2,temp1_42};


arm_matrix_instance_f32 _temp_14 = {1,4,temp_14};
arm_matrix_instance_f32 _temp_41 = {4,1,temp_41};
arm_matrix_instance_f32 _temp_44 = {4,4,temp_44};
arm_matrix_instance_f32 _temp_47 = {4,7,temp_47};
arm_matrix_instance_f32 _temp_74 = {7,4,temp_74};
arm_matrix_instance_f32 _temp_77 = {7,7,temp_77};
arm_matrix_instance_f32 _temp_17 = {1,7,temp_17};
arm_matrix_instance_f32 _temp_71 = {7,1,temp_71};

arm_matrix_instance_f32 _temp1_14 = {1,4,temp1_14};
arm_matrix_instance_f32 _temp1_41 = {4,1,temp1_41};
arm_matrix_instance_f32 _temp1_44 = {4,4,temp1_44};
arm_matrix_instance_f32 _temp1_47 = {4,7,temp1_47};
arm_matrix_instance_f32 _temp1_74 = {7,4,temp1_74};
arm_matrix_instance_f32 _temp1_77 = {7,7,temp1_77};
arm_matrix_instance_f32 _temp1_17 = {1,7,temp1_17};
arm_matrix_instance_f32 _temp1_71 = {7,1,temp1_71};

//float X[7]= {1,2},_Y[7]= {1,2},_Z[7];
//float _N[9]= {1,1,1,2,2,2,3,3,3},_M[9]= {2,2,2,2,2,2,1,1,1},_W[9];

//arm_matrix_instance_f32 X_ = {7,1,X};
//arm_matrix_instance_f32 Y_ = {7,1,_Y};
//arm_matrix_instance_f32 Z_ = {7,1,_Z};

//arm_matrix_instance_f32 N_ = {3,3,_N};
//arm_matrix_instance_f32 M_ = {3,3,_M};
//arm_matrix_instance_f32 W_ = {3,3,_W};

//void Matrix_Test(void)
//{
//	arm_mat_add_f32(&X_,&Y_,&X_);
//	arm_mat_mult_f32(&N_,&M_,&W_);
//	arm_mat_mult_f32(&N_,&M_,&N_);
//}

