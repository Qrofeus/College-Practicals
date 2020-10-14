#include<iostream>
#include<graphics.h>
#include<math.h>    //Used for M_PI
using namespace std;

int get_pointx(int x1,int y1,int x2,int y2){
    return (x1+(x2-x1)*cos(M_PI/3)+(y2-y1)*sin(M_PI/3));
}

int get_pointy(int x1,int y1,int x2,int y2){
    return (y1+(y2-y1)*cos(M_PI/3)-(x2-x1)*sin(M_PI/3));
}

void draw_fractal(int x1,int y1,int x4,int y4,int order){
    int x2,y2,x3,y3;
    x2=(2*x1+x4)/3; y2=(2*y1+y4)/3;
    x3=(x1+2*x4)/3; y3=(y1+2*y4)/3;
    int x5,y5;
    x5=get_pointx(x2,y2,x3,y3); y5=get_pointy(x2,y2,x3,y3);
    if(order>0){
        order--;
        draw_fractal(x1,y1,x2,y2,order);
        draw_fractal(x2,y2,x5,y5,order);
        draw_fractal(x5,y5,x3,y3,order);
        draw_fractal(x3,y3,x4,y4,order);
        return;
    }
    line(x1,y1,x2,y2);
    line(x2,y2,x5,y5);
    line(x5,y5,x3,y3);
    line(x3,y3,x4,y4);
}

void draw_flake(int poly[][2],int n,int order){
    for(int i=0;i<n;i++)
        draw_fractal(poly[i][0],poly[i][1],poly[(i+1)%n][0],poly[(i+1)%n][1],order);
}

int main(){
    int shape[][2]={{360,305},{100,305},{230,80}};
    char ch;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int i=0;
    while(1){
        ch=getch();
        if(ch=='w')
            i++;
        if(ch=='s')
            i--;
        if(ch=='e')
            break;
        cleardevice();
        draw_flake(shape,3,i);
    }
    getch();
}
