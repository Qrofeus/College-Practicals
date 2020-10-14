#include <iostream>
#include <graphics.h>
using namespace std;

void line(int x1, int y1, int x2, int y2) 
{
	int dx=x2-x1, dy=y2-y1;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	float xi=dx/(float)steps, yi=dy/(float)steps;
	float x=x1, y=y1;
	for(int i=0;i<=steps;i++)
	{
		putpixel(x,y,WHITE);
		x+=xi;
		y+=yi;
	}
}

void dispC(int xc_,int yc_, int x, int y)
{
    putpixel(xc_+x, yc_+y, WHITE);
    putpixel(xc_-x, yc_+y, WHITE);
    putpixel(xc_+x, yc_-y, WHITE);
    putpixel(xc_-x, yc_-y, WHITE);
    putpixel(xc_+y, yc_+x, WHITE);
    putpixel(xc_-y, yc_+x, WHITE);
    putpixel(xc_+y, yc_-x, WHITE);
    putpixel(xc_-y, yc_-x, WHITE);
}

void BCircle(int _x, int _y, int _r)
{
	int x=0, y=_r;
	int d=3-2*_r;
	dispC(_x, _y, x, y);
	while(y>=x)
	{
		x++;
		if(d>0)
		{
			y--;
			d=d+4*(x-y)+10;
		}
		else
			d=d+4*x+6;			
		dispC(_x, _y, x, y);
	}
}

int main(){
	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	BCircle(200,200,75);
	BCircle(200,200,150);
	line(200,50,70,275);
	line(70,275,330,275);
	line(330,275,200,50);

	
	getch();
	closegraph();
}

