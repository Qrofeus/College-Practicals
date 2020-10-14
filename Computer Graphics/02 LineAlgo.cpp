#include<iostream>
#include<graphics.h>
using namespace std;

class cl_pixel{
public:
    int x,y,color;
};

class Inherit:public cl_pixel{
public:
    void line(int,int,int,int,int);
    void bresenline(int,int,int,int);
}H;

void Inherit::bresenline(int x1, int y1, int x2, int y2)
{
	int dx=abs(x2-x1), dy=abs(y2-y1), x=x1, y=y1, len;
	int e=(2*dy)-dx;
	len=dx>dy?dx:dy;
	for(int i=0;i<=len;i++)
	{
		putpixel(x,y,WHITE);
		while(e>0)
		{
			y++;
			e=e-2*dx;
		}
		x++;
		e=e+2*dy;
	}
}

void Inherit::line(int x1,int y1, int x2, int y2, int color)	//DDA Line Drawing Algorithm
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

void cube()
{
	//Cube Drawing
	H.line(100,100,200,100,14);
	H.line(200,100,200,200,14);
	H.line(200,200,100,200,14);
	H.line(100,200,100,100,14);
	H.line(100,100,75,75,14);
	H.line(100,200,75,175,14);
	H.line(200,100,175,75,14);
	H.line(75,75,175,75,14);
	H.line(75,75,75,175,14);
	//Hidden Edges
	H.line(175,75,175,175,12);
	H.line(75,175,175,175,12);
	H.line(200,200,175,175,12);
}

int main()
{
	int gd=DETECT,gm;
	char ch[]="Cube";
	initgraph(&gd,&gm,NULL);
	//ddaline(0,0,100,100);
	//bresenline(10,0,110,100);
	outtextxy(50,40,ch);
	cube();
	getch();
}
