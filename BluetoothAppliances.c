#include <REGX51.H>
#include <string.h>


sbit rs=P3^2;
sbit rw=P3^3;
sbit en=P3^4;
sbit led2=P1^1;
sbit led1=P1^0;



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

void print( char *ch)
{
	int i=0;
	while (ch[i]!= '\0')
	{
		P2=ch[i];
		display();
		i++;
	}
}

void main()
{
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

if(strcmp("1n",user)==0)
{
led1=1;
	print("Load one ON");
}

 else if(strcmp("1f",user)==0)
{
led1=0;
	print("Load one OFF");
}

 else if(strcmp("2n",user)==0)
{
led2=1;
	print("Load two ON");
}
 else if(strcmp("2f",user)==0)
{
led2=0;
	print("Load two OFF");
}
}}