#include<iostream>
using namespace std;

int count=0;
void gen(char ar[],int pass,string s,int len)
{
    if(pass==0)
    {
        cout<<s<<endl;
        count++;
        return;
    }
    for(int i=0;i<len;i++)
    {
        string append=s+ar[i];
        gen(ar,pass-1,append,len);
    }
}

void passwordlen(char ar[], int len)
{
    for(int i=1;i<=len;i++) //generate all passwords of character lengths up to maximum length
        gen(ar,i,"",len);
}

int main()
{
    char pass[]={'a','s','1','3','6','i'};
    int len=sizeof(pass)/sizeof(pass[0]);
    //passwordlen(pass,len);
    gen(pass,4,"",len); //generate all passwords of 4 character length
    cout<<"Total Count "<<count<<endl;
    return 0;
}
