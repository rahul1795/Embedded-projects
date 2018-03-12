#include <REGX51.H>

sbit sw1=P1^0;sbit sw2=P1^1;sbit sw3=P1^2;sbit sw4=P1^3;

sbit r1=P2^0;sbit r2=P2^1;sbit r3=P2^2;sbit r4=P2^3;
sbit r5=P2^4;sbit r6=P2^5;sbit r7=P2^6;sbit r8=P2^7;

sbit c1=P3^0;sbit c2=P3^1;sbit c3=P3^2;sbit c4=P3^3;
sbit c5=P3^4;sbit c6=P3^5;sbit c7=P3^6;sbit c8=P3^7;


void delay(x)
{ int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<111;j++);

	}
}

void main()
{ 
	P3=P2=0x00;
	while(1)
	{
		sw1=sw2=sw3=sw4=0;
		r1=r2=r3=r4=r5=r6=r7=r8=1;
	c1=c2=c3=c4=c5=c6=c7=c8=0;
		
		if(sw1==1)	
		{
		r8=0;
		c8=1;
		delay(99);
		r7=0;
		c7=1;
		delay(99);
		r6=0;
		c6=1;		
		delay(99);
		r5=0;
		c5=1;		
		delay(99);
		r4=0;
		c4=1;		
		delay(99);
		r3=0;
		c3=1;		
		delay(99);
		r2=0;
		c2=1;
		delay(99);
		r1=0;
		c1=1;
		delay(99);
	}
	else if(sw2==1)
	{
		r1=0;
		c1=1;
		c8=1;	
		delay(251);
		r1=0;c1=0;
		c2=1;
		c7=1;c8=0;
		delay(91);
		r2=0;r1=1;
		c2=1;
		c7=1;
		delay(251);
		r2=0;
		c3=1;c2=0;
		c6=1;c7=0;
		delay(91);
		r3=0;r2=1;
		c3=1;
		c6=1;
		delay(251);
		r3=0;
		c4=1;c3=0;
		c5=1;c6=0;
		delay(91);
		r4=0;r3=1;
		c4=c5=1;
		delay(91);
		c6=c3=1;
		delay(91);
    c2=c7=1;
		delay(91);
    c1=c8=1;
		delay(1111);
		c6=c3=0;
		delay(91);
    c2=c7=0;
		delay(91);
    c1=c8=0;	
		delay(251);
		r4=0;
		c5=1;c4=0;
		c4=1;
		delay(91);
		r5=0;r4=1;
		c5=1;
		c4=1;
		delay(251);
		r5=0;
		c6=1;c5=0;
		c3=1;c4=0;
		delay(91);
		r6=0;r5=1;
		c6=1;
		c3=1;
		delay(91);
		r6=0;
		c7=1;c6=0;
		c2=1;c3=0;
		delay(251);
		r7=0;r6=1;
		c7=1;
		c2=1;
		delay(91);
		r7=0;
		c8=1;c7=0;
		c1=1;c2=0;
		delay(251);
		r8=0;r7=1;
		c8=1;
		c1=1;
		delay(91);
	}
	else if(sw3==1)
	{
		r4=r5=0;
		c4=c5=1;
		delay(251);
		r3=r6=0;
		c3=c6=1;
		delay(251);
		r2=r7=0;
		c2=c7=1;
		delay(251);
		r1=r8=0;
		c1=c8=1;
		delay(251);
	}
	else if(sw4==1)
	{
		r1=0;
		c2=1;
		delay(121);
		r1=1;
		r2=0;
		delay(121);
				r2=1;
		r3=0;
		delay(121);
				r3=1;
		r4=0;
		delay(121);
				r4=1;
		r5=0;
		delay(121);
				r5=1;
		r6=0;
		delay(121);
				r6=1;
		r7=0;
		delay(121);
				r7=1;
		r8=0;
		delay(121);
		r8=1;
		r7=0;
		delay(121);
		r7=1;
		r6=0;
		delay(121);
		c2=0;
		c3=1;
		r6=1;
		r5=0;
		delay(121);
		c3=0;
		c4=1;
		r5=1;
		r4=0;
		delay(121);
    r4=1;
		c4=0;
		r5=0;
		c5=1;
		delay(121);
     r5=1;
		 c5=0;
		 r6=0;
		 c6=1;
		delay(121);
    r6=1;
		r7=0;
		delay(121);
    r7=1;
		r8=0;
		delay(121);
    c6=0;
		r8=1;
		c7=1;
		r7=0;
		delay(141);
    c7=0;
		r7=1;
		c8=1;
		r6=0;
		delay(141);

	}
	}
}