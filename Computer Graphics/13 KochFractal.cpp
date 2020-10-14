#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int get_pointx(int x1,int y1,int x2,int y2){
    return (x1+(x2-x1)*cos(M_PI/3)+(y2-y1)*sin(M_PI/3));
}

int get_pointy(int x1,int y1,int x2,int y2){
    return (y1+(y2-y1)*cos(M_PI/3)-(x2-x1)*sin(M_PI/3));
}

void kochfractal(int x1,int y1,int x4,int y4,int order){
    int x2,y2,x3,y3;
    x2=(2*x1+x4)/3; y2=(2*y1+y4)/3;
    x3=(x1+2*x4)/3; y3=(y1+2*y4)/3;
    int x5,y5;
    x5=get_pointx(x2,y2,x3,y3); y5=get_pointy(x2,y2,x3,y3);
    if(order>0){
        order--;
        kochfractal(x1,y1,x2,y2,order);
        kochfractal(x2,y2,x5,y5,order);
        kochfractal(x5,y5,x3,y3,order);
        kochfractal(x3,y3,x4,y4,order);
        return;
    }
    line(x1,y1,x2,y2);
    line(x2,y2,x5,y5);
    line(x5,y5,x3,y3);
    line(x3,y3,x4,y4);
}

int main(){
    int ord=0;
    char ch;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    while(1){
        ch=getch();
        if(ch=='w')
            ord++;
        if(ch=='s')
            ord--;
        if(ch=='e')
            break;
        cleardevice();
        kochfractal(10,300,600,300,ord);
    }
    getch();
}
