#include<iostream>
#include<graphics.h>
using namespace std;
#define box 10   //distance between space points

#define up 1
#define right 2
#define down 3
#define left 4  //Direction Coordinates

void draw_line(int j,int &x,int &y){
    if(j==1)    //UP
        y-=box;
    else if(j==2)   //Right
        x+=box;
    else if(j==3)   //Down
        y+=box;
    else if(j==4)   //Right
        x-=box;
    lineto(x,y);
}

void hilbert(int r,int d,int l,int u,int ord,int &x,int &y){
    //With every iteration first and fourth quadrant change orientations
    if(ord>0){
        ord--;
        hilbert(d,r,u,l,ord,x,y);
        draw_line(r,x,y);   //Connecting Line
        hilbert(r,d,l,u,ord,x,y);
        draw_line(d,x,y);   //Connecting Line
        hilbert(r,d,l,u,ord,x,y);
        draw_line(l,x,y);   //Connecting Line
        hilbert(u,l,d,r,ord,x,y);
    }
}

int main(){
    int order;
    int x0=10,y0=10;    //Starting position
    cout<<"Order for Hilbert Curve: ";
    cin>>order;

    //Start with "Right-Down-Left-Up" pattern because Origin of graphic window is top-left
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    moveto(x0,y0);
    hilbert(right,down,left,up,order,x0,y0);
    //delay(10000);
    getch();
}
