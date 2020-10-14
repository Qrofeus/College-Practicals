#include<iostream>
#include<graphics.h>
using namespace std;

//Chess Board Coordinates
float points1[18][2]={{100,100},{300,100},{300,150},{100,150},{100,200},{300,200},{300,250},{100,250},
{100,300},{300,300},{300,100},{250,100},{250,300},{200,300},{200,100},{150,100},{150,300},{100,300}};
//Post Transform Storage for Chessboard
float points2[18][2];
//Flood Fill Coordinates
int ffpoints1[8][2]={{125,125},{225,125},{175,175},{275,175},{125,225},{225,225},{175,275},{275,275}};
//Post Transform Storage for Flood Fill
int ffpoints2[8][2];

void draw(float p[][2], int ff[][2])    //Construct the Chessboard
{
	for(int i=0;i<18;i++)
		line(p[i][0],p[i][1],p[(i+1)%18][0],p[(i+1)%18][1]);
	for(int i=0;i<8;i++)
		floodfill(ff[i][0],ff[i][1],WHITE);
}

void rotate_chess(int mx, int my, float ang)
{
	ang=(float)ang*3.14/180;
	for(int i=0;i<18;i++)
	{
		points2[i][0]=(float)((points1[i][0]-mx)*cos(ang)-(points1[i][1]-my)*sin(ang)+mx);
		points2[i][1]=(float)((points1[i][0]-mx)*sin(ang)+(points1[i][1]-my)*cos(ang)+my);
	}
	for(int i=0;i<8;i++)
	{
		ffpoints2[i][0]=(float)((ffpoints1[i][0]-mx)*cos(ang)-(ffpoints1[i][1]-my)*sin(ang)+mx);
		ffpoints2[i][1]=(float)((ffpoints1[i][0]-mx)*sin(ang)+(ffpoints1[i][1]-my)*cos(ang)+my);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	draw(points1,ffpoints1);
	getch();
	cleardevice();
	rotate_chess(200,200,45);
	draw(points2,ffpoints2);
	getch();
}
