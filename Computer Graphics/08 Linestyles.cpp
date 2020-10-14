#include<iostream>
#include<graphics.h>
using namespace std;
void line(int x1,int y1, int x2, int y2,int color=1)
{
	int dx=x2-x1,dy=y2-y1;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	int xi=dx/(float)steps,yi=dy/(float)steps;
	float x=x1,y=y1;
	for(int i=0;i<=steps;i++)
	{
		putpixel(x,y,color);
		x+=xi;
		y+=yi;
	}
}
void dashline(int x1,int y1, int x2, int y2, int color=1)
{
	int dx=x2-x1,dy=y2-y1;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	int xi=dx/(float)steps,yi=dy/(float)steps;
	float x=x1,y=y1;
	for(int i=0;i<=steps;i++)
	{
		if(i%8!=0)
			putpixel(x,y,color);
		x+=xi;
		y+=yi;
	}
}
void thicc(int x1, int y1, int x2, int y2, int th)
{
	int wy,wx;
	line(x1,y1,x2,y2,WHITE);
	if((y2-y1)/(x2-x1)<1)
	{
		wy=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(x2-x1));
		for(int i=0;i<=wy;i++)
		{
			line(x1,y1-i,x2,y2-i,WHITE);
			line(x1,y1+i,x2,y2+i,WHITE);
		}
	}
	else
	{
		wx=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(y2-y1));
		for(int i=0;i<=wx;i++)
		{
			line(x1-i,y1,x2-i,y2,WHITE);
			line(x1+i,y1,x2+i,y2,WHITE);
		}

	}
}
void dotdashline(int x1,int y1, int x2, int y2, int color=14)
{
	int dx=x2-x1,dy=y2-y1;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	int xi=dx/(float)steps,yi=dy/(float)steps;
	float x=x1,y=y1;
	int j=0;
	for(int i=0;i<=steps;i++)
	{
		if(j!=7&&j!=8&&j!=9)
			putpixel(x,y,color);
		if(j==8)
			putpixel(x,y,color);
		x+=xi;
		y+=yi;
		j++;
		if(j==10)
			j=0;
	}
}
void dotline(int x1,int y1, int x2, int y2, int color=14)
{
	int dx=x2-x1,dy=y2-y1;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	int xi=dx/(float)steps,yi=dy/(float)steps;
	float x=x1,y=y1;
	for(int i=0;i<=steps;i++)
	{
		if(i%2)
			putpixel(x,y,color);
		x+=xi;
		y+=yi;
	}
}
void cube()
{
	//Cube Drawing
	line(100,100,200,100,14);
	line(200,100,200,200,14);
	line(200,200,100,200,14);
	line(100,200,100,100,14);
	line(100,100,50,50,14);
	line(100,200,50,150,14);
	line(200,100,150,50,14);
	line(50,50,150,50,14);
	line(50,50,50,150,14);
	
	dashline(150,50,150,150);
	dashline(50,150,150,150);
	dashline(200,200,150,150);
}
void oct1()
{
	int i=MAGENTA;
	dotline(394,104,356,104,i);
	dotline(356,104,329,131,i);
	dotline(329,131,329,169,i);
	dotline(329,169,356,196,i);
	dotline(356,196,394,196,i);
	dotline(394,196,421,169,i);
	dotline(421,169,421,131,i);
	dotline(421,131,394,104,i);
	
	dotdashline(375,80,375,220,YELLOW);
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	cube();
	oct1();
	thicc(10,450,400,450,4);
	getch();
}
