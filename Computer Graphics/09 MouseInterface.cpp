#include<iostream>
using namespace std;

//#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<cstdlib>
union REGS in,out;

int callmouse();
int hidemouse();
void getmousepos(int &,int &,int &);
void setmousepos(int &,int &);
void restrictmouseptr(int,int,int,int);
void seedfill(int,int,int,int);

int main()
{
    cleardevice();
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int x,y,clk;
    int ax1[30],ay1[30],i=0,flag=0,j;
    int ax2[30],ay2[30];
    cout<<"\n Use the mouse to draw any convex polygon ";
    callmouse();
    restrictmouseptr(0,0,getmaxx(),getmaxy());
    do{
        getmousepos(x,y,clk);
        if(clk==1)
        {
            do{
                getmousepos(x,y,clk);
                putpixel(x,y,WHITE);
                if(flag==0)
                    {
                        ax1[i]=x;
                        ay1[i]=y;
                        i++;
                        flag=1;
                    }
            }while(clk==1);
            ax2[i-1]=x;
            ay2[i-1]=y;
            flag=0;
        }
    }while(!kbhit());
    getch();
    cleardevice();
    cout<<"\n The polygon is: ";
    for(j=0;j<i-1;j++)
        line(ax1[j],ay1[j],ax2[j],ay2[j]);
    line(ax1[j],ay1[j],ax2[j],ay2[j]);
    // seedfill(ax1[0]+1,ay1[0]+1,WHITE,BLACK);
    getch();
}

int callmouse(){
    in.x.ax=1;
    int86(51,&in,&out);
    return 1;
}

int hidemouse(){
    in.x.ax=2;
    int86(51,&in,&out);
    return 1;
}

void getmousepos(int &xpos,int&ypos,int&click){
    in.x.ax=3;
    int86(51,&in,&out);
    click=out.x.bx;
    xpos=out.x.cx;
    ypos=out.x.dx;
}

void setmousepos(int &xpos,int&ypos){
in.x.ax=4;
in.x.cx=xpos;
in.x.dx=ypos;
int86(51,&in,&out);
}

void restrictmouseptr(int x1,int y1,int x2,int y2){
    in.x.ax=7;
    in.x.cx=x1;
    in.x.dx=x2;
    int86(51,&in,&out);
    in.x.ax=8;
    in.x.cx=y1;
    in.x.dx=y2;
    int86(51,&in,&out);
}

void seedfill(int x,int y,int newcolor,int oldcolor){
    int current;
    current=getpixel(x,y);
    if(current==oldcolor){
        putpixel(x,y,WHITE);
        seedfill(x-1,y,newcolor,oldcolor);
        seedfill(x+1,y,newcolor,oldcolor);
        seedfill(x,y-1,newcolor,oldcolor);
        seedfill(x,y+1,newcolor,oldcolor);
        //seedfill(x+1,y+1,newcolor,oldcolor);
        //seedfill(x+1,y-1,newcolor,oldcolor);
        //seedfill(x-1,y+1,newcolor,oldcolor);
        //seedfill(x-1,y-1,newcolor,oldcolor);
    }
}
