#include"config.h"

//全局变量声明
extern  uint time_1;
extern  uint time_2;
extern  uchar data Tempdatatable[5],CommandDatatable[5];//数据包

void main()
{
	Main_Int();	
 	while(P0_1!=0)
	{	
	    while(P0_7!=0)
		{						
		  	X_Axis_Left(11);
		}
		while(P0_6!=0)
		{
	     	X_Axis_Right(11);
		}
		Y_Axis();	 
    }
 	X_Axis_Stop();	 
	while(1)
	{
		P2_6=~P2_6;					//未进入工作，指示不停灯闪烁 
		Delay_ms(260);	
	}						
}

