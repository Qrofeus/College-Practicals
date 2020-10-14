//Flight Paths
//Directed weighted graph
//Matrix Implementation
#include<iostream>
using namespace std;
#include<string>

#define maxm 10
class flights{
public:
    int n;
    string cities[maxm]={"Delhi","Bombay","Pune","Chennai","Bangalore","Amritsar","Varanasi"};
    int mat[maxm][maxm]={/*Delhi*/      {0,1163,1160,1760,1700,404,660,0,0,0,},
                         /*Bombay*/     {1163,0,120,0,845,0,1246,0,0,0,},
                         /*Pune*/       {1160,120,0,914,720,0,1208,0,0,0,},
                         /*Chennai*/    {1760,0,914,0,0,2135,0,0,0,0,},
                         /*Bangalore*/  {1700,0,720,0,0,2090,1460,0,0,0,},
                         /*Amritsar*/   {404,1409,0,2650,2080,0,0,0,0,0,},
                         /*Varanasi*/   {660,0,1246,1397,1484,0,0,0,0,0,},
                         /*None*/       {0,0,0,0,0,0,0,0,0,0,},
                         /*None*/       {0,0,0,0,0,0,0,0,0,0,},
                         /*None*/       {0,0,0,0,0,0,0,0,0,0,}};
    int get_distance(string,string);
    void check_flights();
    void city_numbers();
    void display_flights();
    flights(){
        n=7;
    }
};

int flights::get_distance(string st1,string st2){
    int var1,var2;
    bool flag1=false,flag2=false;
    for(int i=0;i<n;i++){
        if(cities[i]==st1){
            flag1=true;
            var1=i;
        }
        if(cities[i]==st2){
            flag2=true;
            var2=i;
        }
    }
    if(!flag1||!flag2){
        cout<<"Unidentified City(s)..\n";
        return -1;
    }
    return mat[var1][var2];
}

void flights::check_flights(){
    cout<<"\n-- 'exit' to close terminal --";
    int num,dist;
    string str1,str2;
    while(1){
        cout<<"\nEnter Travel Cities: ";
        cin>>str1;
        if(str1=="exit")
            break;
        cin>>str2;
        dist=get_distance(str1,str2);
        if(dist==-1)
            continue;
        if(dist==0){
            cout<<"No Flight..\n";
            continue;
        }
        cout<<"Flight Distance From "<<str1<<" To "<<str2<<"--"<<dist<<'\n';
    }
}

void flights::city_numbers(){
    cout<<"City Correspondence--\n";
    for(int i=0;i<n;i++){
        string str;
        str=cities[i];
        cout<<str<<" -> ";
        str.resize(5);
        cout<<str<<'\n';
    }
}

void flights::display_flights(){
    city_numbers();
    cout<<"\n<All distances in KM>\nFlight Lengths (Row to Column)--\n\n";
    for(int i=0;i<n;i++){
        string str=cities[i];
        str.resize(5);
        cout<<'\t'<<str;
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        string str=cities[i];
        str.resize(5);
        cout<<str;
        for(int m=0;m<n;m++){
            cout<<'\t'<<mat[i][m];
        }
        cout<<'\n';
    }
}

int main(){
    flights flight;
    flight.display_flights();
    flight.check_flights();
}
