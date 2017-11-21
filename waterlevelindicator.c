#include <REG51.H>
void string(char );

sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
sbit quart=P3^7;
sbit half=P3^6;
sbit quart_3=P3^5;
sbit full=P3^4;
sbit m1_1=P1^0;
sbit m1_2=P1^1;
sbit r1=P1^2;
sbit r2=P1^3;
sbit r3=P1^4;
sbit r4=P1^5;

char vac[]={"VACANT"};
char qua[]={"QUATER"};
char hal[]={"HALF"};
char qua_3[]={"QUATER_3"};
char ful[]={"TANK FULL"};
char kee[]={"KEEP EYES"};
char tri[]={"MOTOR TRIPPED"};
char err[]={"SYSTEM ERROR"};

void delay(x)
{  int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<1111;j++);
	}
}

void cmd()
{
rs=0;
rw=0;
en=1;
delay(5);	
en=0;	
}

void display()
{
rs=1;
rw=0;
en=1;
delay(5);	
en=0;	
}

void init()
{
 P2=0x38;
cmd();	
	P2=0x0c;
cmd();	
	P2=0x06;
cmd();	
	P2=0x01;
cmd();
  P2=0x81;
cmd();		
}

void main()
{ int i,j,k,l,m,n,o,q;
	P2=P1=0x00;
	rs=rw=en=0;
	quart=half=quart_3=full=1;
	while(1)
	{ 
	  quart=half=quart_3=full=0;
		if (quart==0 && half==0 && quart_3==0 && full==0)
		{ 
			r1=r2=r3=r4=1;
			init();
			for(i=0;i<6;i++)
			{
				P2=vac[i];
				display();
				delay(5);
			}
			m1_1=0;
			m1_2=1;
		
		}
		else if(quart==1 && half==0 && quart_3==0 && full==0)
		{ 
			r1=r2=r3=1;
      r4=0;
			init();
			for(j=0;j<6;j++)
			{
				P2=qua[j];
				display();
				delay(9);
			}
			m1_1=0;
			m1_2=1;
		}
		else if(quart==1&&half==1&&quart_3==0&&full==0)
		{  
			r1=r2=1;
      r3=r4=0;
			init();
			for(k=0;k<4;k++)
			{
				P2=hal[k];
				display();
				delay(9);
			}
			m1_1=0;
			m1_2=1;
		}
		else if(quart==1&&half==1&&quart_3==1&&full==0)
		{
			r1=1;
      r2=r3=r4=0;
			init();
			for(l=0;l<8;l++)
			{
				P2=qua_3[l];
				display();
				delay(5);
			}
			P2=0xc0;
			cmd();
				for(n=0;n<9;n++)
			{
				P2=kee[n];
				display();
       delay(35);
			}
			
			m1_1=0;
			m1_2=1;
		}
		else if(quart==1&&half==1&&quart_3==1&&full==1)
		{
      r1=r2=r3=r4=0;
			init();
			for(m=0;m<9;m++)
			{
				P2=ful[m];
				display();
				delay(9);
			}
			P2=0xc0;
			cmd();
			for(q=0;q<13;q++)
			{
				P2=tri[q];
				display();
				delay(9);
			}
			
			m1_1=0;
			m1_2=0;
		}
		else
		{
      r1=r2=r3=r4=0;
			init();
			for(o=0;o<12;o++)
			{
				P2=err[o];
				display();
       delay(31);
			}
		}
	}
}