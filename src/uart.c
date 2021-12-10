#include"config.h"

/*****************************************************************
//����ͨ��ģ��
******************************************************************/
 uchar Buffer =0;      //�Ӵ��ڽ��յ�����
 uint i=0,j,URTAReceivedCount=0,n=1;
 bit busy;
 uchar data Tempdatatable[5],CommandDatatable[5];//���ݰ�
 
/********************************************************************
* ���� : Com_Init()
* ���� : ���ڳ�ʼ��,������9600��ʹ���˴����ж�
* ���� : ��
* ��� : ��
***********************************************************************/
void Com_Init()
{
	TH2 = 0xFF;                 //9600������,11.0592Mhz���� 
	TL2 = 0xDC;  
	RCAP2H = 0xFF;  
	RCAP2L = 0xDC;
	T2MOD=0x01;  
	SCON = 0x50;
	T2CON=0x34;
	TR2=1;
	ES = 1;                     //ʹ�ܴ���1�ж�
	EA = 1;
}

/********************************************************************
* ���� : Com_Int()
* ���� : �����ж��Ӻ���
* ���� : ��
* ��� : ��
***********************************************************************/
void Com_Int() interrupt 4 using 1
{
    if (RI)
    {       
        uchar temp;
        RI = 0;                 //���RIλ
		temp=SBUF;
			if(temp==0XFF && URTAReceivedCount<2)
			{	
				Tempdatatable[0]=0xFF;  //��ͷ
				URTAReceivedCount++;
			}
				else
			{ 
				Tempdatatable[n]=temp;
				n++;   
			}
		if(URTAReceivedCount==2&&n==4)//��β
		{
			Tempdatatable[4]=0XFF;
			n=1;
			URTAReceivedCount=0;  //������
		}
		CommandDatatable[0]=Tempdatatable[0];
		CommandDatatable[1]=Tempdatatable[1];
		CommandDatatable[2]=Tempdatatable[2];
		CommandDatatable[3]=Tempdatatable[3];
		CommandDatatable[4]=Tempdatatable[4];
	}
    if (TI)
    {
        TI = 0;                 //���TIλ
        busy = 0;               //��æ��־
    }
}

/********************************************************************
* ���� : Send_Data()
* ���� : ����λ�������ַ�
* ���� : ��
* ��� : ��
***********************************************************************/
void Send_Data(uchar data type,uchar data cmd,uchar data date)
{   
    uchar data Buffer[5]; //�������ݰ�	
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
			Send_Count++;  //0XFF��־ͳ��λ
		}
	while (busy); 
	busy = 1;
	SBUF=*p;
	p++;          
	if(Send_Count == 2)  //��ͳ�Ƶ����γ���0XFF������Ϊһ�����ݰ�������ϣ�����ѭ��
	{
		break;    
	}     
	}
}