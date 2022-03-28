
#include"config.h"

void Z_Axis()
{
		P2_2=1;
		P2_3=0;
		P2_5=1;
		while(1)
		    if(P0_0==0)
			    break;
		P2_2=0;
		P2_3=1;
		P2_5=1;	
		Delay_ms(100);
		P2_5=0;
}