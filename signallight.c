#include <REGX51.H>
int led[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
sbit green=P1^0;
sbit red=P1^1;
void loop();
void sub();

void delay()
{ int i,j;
	for(i=0;i<5000;i++)
	{
	for(j=0;j<6;j++);
	}}
void main()
{
	while(1)
	{ red=0;
		green=1;
		sub();
		red=1;
		green=0;
		sub();
	}
}
void sub()
{ int i; 

for(i=2;i>=0;i--)
{ 
	P2=led[i];
	loop();
}
}
void loop()
{ int i;
	for(i=9;i>=0;i--)
	{
		P3=led[i];
		delay();
	}
}