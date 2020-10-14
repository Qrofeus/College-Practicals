#include<iostream>
#include<cmath>
#include<graphics.h>
#define pi 3.1412
using namespace std;
void line(int x1,int y1, int x2, int y2, int color=WHITE)
{
	int dx=x2-x1,dy=y2-y1;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	float xi=dx/float(steps),yi=dy/float(steps);
	float x=x1,y=y1;
	for(int i=0;i<=steps;i++)
	{
		putpixel(x,y,color);
		x+=xi;
		y+=yi;
	}
}
void draw(float p[][2], int n)
{
	for(int i=0;i<n;i++)
		line(p[i][0],p[i][1],p[(i+1)%n][0],p[(i+1)%n][1],WHITE);
}
int main()
{
    int sw,n;
    float tx,ty,s,p[3][2]={{100,100},{250,250},{290,200}},p1[3][2],a;
    cout<<"enter no of vertices: ";
    //cin>>n;
    n=3;
    cout<<"enter vertex coordinates (x,y):\n";
    //for(int i=0;i<n;i++)
        //cin>>p[i][0]>>p[i][1];
    cout<<"Select Transformation:\n1.Translation\n2.Scaling\n3.Rotation\nOp Code: ";
    cin>>sw;
    switch(sw)
    {
        case 1:
            cout<<"enter tx and ty:\n";
            cin>>tx>>ty;
            for(int i=0;i<n;i++)
            {
                p1[i][0]=p[i][0]+tx;
                p1[i][1]=p[i][1]+ty;
            }
            break;
        case 2:
            cout<<"enter scaling factor:\n";
            cin>>s;
            if(s>0)
                for(int i=0;i<n;i++)
                {
                    p1[i][0]=p[i][0]*s;
	                p1[i][1]=p[i][1]*s;
                }
            else
            {
                s=-s;
                for(int i=0;i<n;i++)
                {
                    p1[i][0]=p[i][0]/s;
	                p1[i][1]=p[i][1]/s;
                }
            }
            break;
        case 3:
            cout<<"enter angle of rotation:\n";
            cin>>a;
            a=(float)a*pi/180;
            for(int i=0;i<n;i++)
            {
                p1[i][0]=(float)(p[i][0]*cos(a)-p[i][1]*sin(a));
                p1[i][1]=(float)(p[i][0]*sin(a)+p[i][1]*cos(a));
            }
            break;
        default:
            cout<<"Wrong Op-Code";
    }
    for(int i=0;i<n;i++)
    	cout<<p1[i][0]<<' '<<p1[i][1]<<endl;
	//Graphics Section
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	draw(p,n);
	draw(p1,n);	
	getch();
}
