//This program will only work for square parallel to axes

#include<graphics.h>
#include<math.h>    //used for sqrt() and pow()

int getx(int x, int dist, int di){
    if(di==3)   //LEFT
        x-=dist;
    if(di==1)   //RIGHT
        x+=dist;
    return x;
}

int gety(int y, int dist, int di){
    if(di==0)   //UP
        y-=dist;
    if(di==2)   //DOWN
        y+=dist;
    return y;
}

int getdist(int x1,int y1,int x4,int y4){
    return (sqrt(pow((x4-x1),2)+pow((y4-y1),2)))/3; //One third of the distance between the endpoints
}

void koch_sq(int x1,int y1,int x4,int y4,int dir,int ord){
    int x2,y2,x3,y3,xa,ya,xb,yb;
    int dist=getdist(x1,y1,x4,y4);
    x2=(2*x1+x4)/3; y2=(2*y1+y4)/3;
    x3=(x1+2*x4)/3; y3=(y1+2*y4)/3;
    xa=getx(x2,dist,dir);   ya=gety(y2,dist,dir);
    xb=getx(x3,dist,dir);   yb=gety(y3,dist,dir);
    if(ord>0){
        ord--;
        koch_sq(x1,y1,x2,y2,dir,ord);
        koch_sq(x2,y2,xa,ya,((dir+3)%4),ord);
        koch_sq(xa,ya,xb,yb,dir,ord);
        koch_sq(xb,yb,x3,y3,((dir+1)%4),ord);
        koch_sq(x3,y3,x4,y4,dir,ord);
        return;
    }
    line(x1,y1,x2,y2);
    line(x2,y2,xa,ya);
    line(xa,ya,xb,yb);
    line(xb,yb,x3,y3);
    line(x3,y3,x4,y4);
}

int main(){
    int ord=1;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    koch_sq(90,90,255,90,0,ord);  //UP=0
    koch_sq(255,90,255,255,1,ord);//RIGHT=1
    koch_sq(90,255,255,255,2,ord);//DOWN=2
    koch_sq(90,90,90,255,3,ord);  //LEFT=3

    getch();
}
