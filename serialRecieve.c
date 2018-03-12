#include <REGX51.H>
#include <string.h>


sbit rs=P3^2;
sbit rw=P3^3;
sbit en=P3^4;
sbit led2=P1^1;
sbit led1=P1^0;
sbit m1=P1^2;
sbit m2=P1^3;


void delay(x)
{ int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<1000;j++);
	}
	
}
void cmd()
{
	rs=0;
	rw=0;
	en=1;
	delay(10);
	en=0;
}

void display()
{
	rs=1;
	rw=0;
	en=1;
	delay(10);
	en=0;
}

void main()
{
  char on[]={"on"};
  char off[]={"of"};
	char user[4];
  int i;
	P2=P1=0x00;
  P2=0x38;
	cmd();
	P2=0x0e;
	cmd();
	P2=0x06;
	cmd();
	P2=0x01;
	cmd();
while(1)
{
		for(i=0;i<2;i++)
{
		TMOD=0x20;
		SCON=0x50;
		TH1=0xfd;
		TR1=1;
		while(RI==0);

			P2=SBUF;
		 	display();	
      user[i]=SBUF;	  
}
P2=0x01;
cmd();
if(strcmp(on,user)==0)
{
led1=1;
led2=1;

	}

 else if(strcmp(off,user)==0)
{
led1=0;
led2=0;

}

}}