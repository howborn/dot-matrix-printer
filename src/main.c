#include"config.h"

//ȫ�ֱ�������
extern  uint time_1;
extern  uint time_2;
extern  uchar data Tempdatatable[5],CommandDatatable[5];//���ݰ�

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
		P2_6=~P2_6;					//δ���빤����ָʾ��ͣ����˸ 
		Delay_ms(260);	
	}						
}

