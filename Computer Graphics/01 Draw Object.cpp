#include<iostream>
#include<graphics.h>
using namespace std;

int endpoints[16][2]={{305,485},{325,252},{395,293},{350,225},{505,200},{350,180},{395,112},{325,155},{305,5},{285,155},{215,112},
                {260,180},{105,200},{260,225},{215,293},{285,252}};

void draw(){
    for(int i=0;i<16;i++)
        line(endpoints[i][0],endpoints[i][1],endpoints[(i+1)%16][0],endpoints[(i+1)%16][1]);
    setcolor(YELLOW);
    floodfill(305,205,WHITE);
    //setcolor(BLACK);
    //for(int i=0;i<16;i++)
        //line(305,205,endpoints[i][0],endpoints[i][1]);
}

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd,&gm,NULL);
	draw();

	getch();
}
