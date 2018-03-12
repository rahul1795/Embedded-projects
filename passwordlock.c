#include <REGX51.H>
#include<string.h>

char check();
char scankey();

sbit ledg=P3^4;
sbit ledr=P3^3;

sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

sbit r1=P2^0;
sbit r2=P2^1;
sbit r3=P2^2;
sbit c1=P2^3;
sbit c2=P2^4;
sbit c3=P2^5;

sbit m1_1=P2^6;
sbit m1_2=P2^7;

char lock[]={'S','Y','S','T','E','M',' ','I','S',' ','L','O','C','K','E','D'};
char enter[]={'E','N','T','E','R',' ','U','S','E','R',' ','I','D'};
char match[]={'I','D',' ','M','A','T','C','H','E','D'};
char open[]={'O','P','E','N','I','N','G',' ','D','O','O','R','.','.','.'};
char close[]={'C','L','O','S','I','N','G',' ','D','O','O','R','.','.','.'};
char again[]={'T','R','Y',' ','A','G','A','I','N','.','.','.'};


char uid[]={"88261"};
char id[5];
void delay(x)
{ int i,j;
	for(i=0;i<x;i++)
	{
			for(j=0;j<1275;j++);
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
{ int i,j,k,l,m,p;
	int n=0;
	char key;
	ledg=ledr=0;
	P1=0x00;
	P2=0xff;
	rs=rw=en=0;
	//while(1)
	//{
		P1=0x38;
		cmd();
		P1=0x0c;
		cmd();
		P1=0x06;
		cmd();
		P1=0x01;
		cmd();
		P1=0x80;
		cmd();
		for(i=0;i<16;i++)
		{
		P1=lock[i];
		display();
		}	
		P1=0xc1;
		cmd();
		delay(100);
		for(j=0;j<13;j++)
		{
		P1=enter[j];
		display();
		}	
		delay(70);
    P1=0x90;
		cmd();
	while(n<5)
		{
		key=check();
			id[n]=key;
			P1='*';
			display();
			delay(100);
			n++;
		}
    P1=0x01;
		cmd();
		P1=0x02;
		cmd();
		P1=0x80;
		cmd();
		if(strcmp(uid,id)==0)
		{
			for(k=0;k<10;k++)
			{
				P1=match[k];
				display();
			}
			delay(100);
			P1=0xc0;
			cmd();
			for(l=0;l<15;l++)
			{
				P1=open[l];
				display();
			}
			ledg=1;
			delay(20);
			m1_1=1;
			m1_2=0;
			delay(400);
			m1_1=0;
			m1_2=0;
			delay(1000);
			P1=0x01;
			cmd();
			P1=0x80;
			cmd();
			for(m=0;m<15;m++)
			{
				P1=close[m];
				display();
				ledr=1;
			}
				delay(20);
	  		m1_1=0;
				m1_2=1;
				delay(400);
				m1_1=m1_2=0;
		}
		else
		{
			for(p=0;p<12;p++)
			{
				P1=again[p];
				display();
				ledr=1;
			}
			delay(500);
		}
}
//}

char check()
{ char b='a';
	while(b=='a')
	{
		b=scankey();
	}
	return b;
}

char scankey()
{ 
	r1=0;r2=r3=1;
	if(c1==0)
	{
		delay(2);
		return '1';
	}
	if(c2==0)
	{
		delay(2);
		return '2';
	}
	if(c3==0)
	{
		delay(2);
		return '3';
	}
	r1=r3=1;
	r2=0;
		if(c1==0)
	{
		delay(2);
		return '4';
	}
	if(c2==0)
	{
		delay(2);
		return '5';
	}
	if(c3==0)
	{
		delay(2);
		return '6';
	}
	r2=r1=1;
	r3=0;
		if(c1==0)
	{
		delay(2);
		return '7';
	}
	if(c2==0)
	{
		delay(2);
		return '8';
	}
	if(c3==0)
	{
		delay(2);
		return '9';
	}
}