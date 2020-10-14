#include<iostream>
#include<graphics.h>
using namespace std;

void line(int x1, int y1, int x2, int y2, int color)
{
	int dx=x2-x1, dy=y2-y1;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	float xi=dx/(float)steps, yi=dy/(float)steps;
	int x=x1, y=y1;
	for(int i=0;i<=steps;i++)
	{
		putpixel(x,y,color);
		x+=xi;
		y+=yi;
	}
}

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	for(int k=0;k<170;k++)
	{
		cleardevice();
		//Flag Pole
		for(int i=0;i<5;i++)
			line(10+(i*1),10,10+(i*1),210,BROWN);
		//Flag of France
		//Proportion 2:3
		//Red Stripe
		for(int i=0;i<15;i++)
			line(15+(i*1),180-k,15+(i*1),210-k,RED);
		//White Stripe
		for(int i=0;i<15;i++)
			line(30+(i*1),180-k,30+(i*1),210-k,WHITE);
		//Blue Stripe
		for(int i=0;i<15;i++)
			line(45+(i*1),180-k,45+(i*1),210-k,BLUE);
		delay(50);
	}
	
	getch();
}
