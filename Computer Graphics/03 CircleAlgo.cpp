#include<iostream>
#include<graphics.h>
using namespace std;

class cl_pixel{
public:
    int x,y,color;
};

class Inherit:public cl_pixel{
public:
    void dispC(int,int,int,int,int);
    void Circle(int,int,int,int,int);
}H;

void Inherit::dispC(int xc, int yc, int x, int y, int color)
{
    putpixel(xc+x, yc+y, color);
    putpixel(xc-x, yc+y, color);
    putpixel(xc+x, yc-y, color);
    putpixel(xc-x, yc-y, color);
    putpixel(xc+y, yc+x, color);
    putpixel(xc-y, yc+x, color);
    putpixel(xc+y, yc-x, color);
    putpixel(xc-y, yc-x, color);
}

void Inherit::Circle(int _x, int _y, int _r, int color){

	int x=0, y=_r;
	int d=3-2*_r;
	dispC(_x, _y, x, y, color);
	while(y >= x)
	{
		x++;
		if(d > 0)
		{
			y--;
			d=d+4*(x-y)+10;
		}
		else
			d=d+4*x+6;
		dispC(_x, _y, x, y, color);
	}
}

void design()
{
	H.Circle(250,250,100,1);
	H.Circle(300,163,100,2);
	H.Circle(200,163,100,3);
	H.Circle(150,250,100,4);
	H.Circle(200,337,100,5);
	H.Circle(300,337,100,6);
	H.Circle(350,250,100,7);
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	//BCircle(50,50,49);
	design();
	getch();
}
