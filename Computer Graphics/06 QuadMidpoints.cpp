#include<iostream>
#include<graphics.h>
using namespace std;

void line(int x1, int y1, int x2, int y2)
{
	int dx=x2-x1,dy=y2-y1;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	int xi=dx/(float)steps,yi=dy/(float)steps;
	float x=x1,y=y1;
	for(int i=0;i<=steps;i++)
	{
		putpixel(x,y,14);
		x+=xi;
		y+=yi;
	}

}

void draw(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int i)
{
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);

	int r1,r2,r3,r4,s1,s2,s3,s4;
	r1=(x1+x2)/2;	r2=(x2+x3)/2;	r3=(x3+x4)/2;	r4=(x4+x1)/2;
	s1=(y1+y2)/2;	s2=(y2+y3)/2;	s3=(y3+y4)/2;	s4=(y4+y1)/2;

	i++;
	if(i==3)
		return;
	draw(r1,s1,r2,s2,r3,s3,r4,s4,i);
}

int main()
{
	int x1,x2,x3,x4,y1,y2,y3,y4;
	cout<<"Enter Co-ordinates of vertices of Quad:\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
		draw(x1,y1,x2,y2,x3,y3,x4,y4,0);
		
	getch();
}
