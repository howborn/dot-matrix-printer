#include"reg52.h"

#define uchar unsigned  char
#define uint  unsigned   int

extern  void Main_Int();
extern  void Delay_1ms(uint i);
extern  void Delay_ms(uint i);
extern  void X_Axis_Right(uint a);
extern  void X_Axis_Left(uint b);
extern  void X_Axis_Stop();
extern  void Y_Axis();
extern  void Z_Axis();
extern  void Time_0_Int();
extern  void Com_Init();
extern  void Send_Data(uchar data type,uchar data cmd,uchar data date);

sfr T2MOD=0x0c9;

//步进电机（x轴）配置
sbit P1_0 = P1^0;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;

//直流电机1（y轴）配置
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_4 = P2^4;

//直流电机2配置
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P2_5 = P2^5;

sbit P2_6 = P2^6;     //工作指示灯

sbit P0_0 = P0^0;	  //触碰开关
sbit P0_1 = P0^1;
sbit P0_6 = P0^6;
sbit P0_7 = P0^7;

