#include"config.h"

extern uint time_1;

void Delay_1ms(uint i)//1msÑÓÊ±
{
    time_1=0;
	while(time_1!=i);
} 
void Delay_ms(uint t)//1msÑÓÊ±
{
    uint j;
	for(;t>0;t--)
	   for(j=19;j>0;j--);
} 