#include"config.h"

void Y_Axis()
{
    P2_0=0;
	P2_1=1;
	P2_4=1;
	Delay_ms(80);
	P2_1=0;
	P2_4=0;
}
