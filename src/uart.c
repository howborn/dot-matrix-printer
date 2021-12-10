#include"config.h"

/*****************************************************************
//串口通信模块
******************************************************************/
 uchar Buffer =0;      //从串口接收的数据
 uint i=0,j,URTAReceivedCount=0,n=1;
 bit busy;
 uchar data Tempdatatable[5],CommandDatatable[5];//数据包
 
/********************************************************************
* 名称 : Com_Init()
* 功能 : 串口初始化,波特率9600，使能了串口中断
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Com_Init()
{
	TH2 = 0xFF;                 //9600波特率,11.0592Mhz晶振 
	TL2 = 0xDC;  
	RCAP2H = 0xFF;  
	RCAP2L = 0xDC;
	T2MOD=0x01;  
	SCON = 0x50;
	T2CON=0x34;
	TR2=1;
	ES = 1;                     //使能串口1中断
	EA = 1;
}

/********************************************************************
* 名称 : Com_Int()
* 功能 : 串口中断子函数
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Com_Int() interrupt 4 using 1
{
    if (RI)
    {       
        uchar temp;
        RI = 0;                 //清除RI位
		temp=SBUF;
			if(temp==0XFF && URTAReceivedCount<2)
			{	
				Tempdatatable[0]=0xFF;  //包头
				URTAReceivedCount++;
			}
				else
			{ 
				Tempdatatable[n]=temp;
				n++;   
			}
		if(URTAReceivedCount==2&&n==4)//包尾
		{
			Tempdatatable[4]=0XFF;
			n=1;
			URTAReceivedCount=0;  //组包完毕
		}
		CommandDatatable[0]=Tempdatatable[0];
		CommandDatatable[1]=Tempdatatable[1];
		CommandDatatable[2]=Tempdatatable[2];
		CommandDatatable[3]=Tempdatatable[3];
		CommandDatatable[4]=Tempdatatable[4];
	}
    if (TI)
    {
        TI = 0;                 //清除TI位
        busy = 0;               //清忙标志
    }
}

/********************************************************************
* 名称 : Send_Data()
* 功能 : 向上位机传送字符
* 输入 : 无
* 输出 : 无
***********************************************************************/
void Send_Data(uchar data type,uchar data cmd,uchar data date)
{   
    uchar data Buffer[5]; //构建数据包	
	uchar *p;
 	uint Send_Count=0;
    Buffer[0]=0XFF;
	Buffer[1]=type;
	Buffer[2]=cmd;
	Buffer[3]=date;
	Buffer[4]=0XFF;
	p = Buffer;		
	while(1)
	{
		if(*p==0XFF)
		{
			Send_Count++;  //0XFF标志统计位
		}
	while (busy); 
	busy = 1;
	SBUF=*p;
	p++;          
	if(Send_Count == 2)  //当统计到两次出现0XFF，则认为一个数据包发送完毕，跳出循环
	{
		break;    
	}     
	}
}