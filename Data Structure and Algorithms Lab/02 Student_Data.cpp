/*

ASSIGNMENT 2

SE COMPUTER II
NINAD DESHPANDE
Roll Number: 10
Batch: S1

Question:
Write a code that takes number of marks obtained by students of DSA as input.
If the student is absent Enter -1 as Marks.
1. Calculate Average.
2. Display the maximum marks obtained.
3. Display the minimum marks obtained.
4. Display the same marks scored by many students.

*/
#include<iostream>
#define max 50
using namespace std;

int s[max];
void getdata(int num, int marks);
float average(int num);
void maximum(int num);
void minimum(int num);
int modal(int num);

int main()
{
    int n,marks;
    cout<<"Enter maximum marks for the test: ";
    cin>>marks;
    cout<<"Enter Number of Students in the class: ";
    cin>>n;
    getdata(n,marks);
    cout<<"\nAverage Marks obtained by all the students is "<<average(n)<<endl;
    cout<<"\nMaximum marks obtained are:\n";
    maximum(n);
    cout<<"\nMinimum marks obtained are:\n";
    minimum(n);
    if(modal(n)==0)
        cout<<"\nNo repetition of marks.\n";
    else
        cout<<"\nMarks obtained by maximum students: "<<modal(n)<<endl;
    return 0;
}

int modal(int num)
{
    int number=s[0];
    int mode=number;
    int count=1;
    int countMode=1;
    for(int i=1;i<num;i++)
    {
        if(s[i]!=-1)
            if(s[i]==number)
            {
                ++count;
            }
            else
            {
                if(count>countMode)
                {
                    countMode=count;
                    mode=number;
                }
                count=1;
                number=s[i];
            }
    }
    if(mode!=-1&&countMode>1)
        return mode;
    else
        return 0;
}

void minimum(int num)
{
    int temp;
    for(int i=0;i<num;i++)
        if(s[i]!=-1)
            if(temp>s[i])
                temp=s[i];
    for(int i=0;i<num;i++)
        if(temp==s[i])
            cout<<temp<<" by roll number "<<i+1<<endl;
}

void maximum(int num)
{
    int temp=s[0];
    for(int i=0;i<num;i++)
        if(temp<s[i])
            temp=s[i];
    for(int i=0;i<num;i++)
        if(temp==s[i])
            cout<<temp<<" by roll number "<<i+1<<endl;
}

float average(int num)
{
    int temp=num, sum=0;
    for(int i=0;i<num;i++)
    {
        if(s[i]==-1)
            temp--;
        else
            sum=sum+s[i];
    }
    return (float)sum/temp;
}

void getdata(int num, int marks)
{
    bool cont;
    cout<<"\nEnter -1 for absent students\n\n";
    for(int i=0;i<num;i++)
    {
        do
        {
            cont=false;
            cout<<"Marks obtained by student "<<i+1<<": ";
            cin>>s[i];
            if(s[i]>marks||s[i]<-1)
            {
                cout<<"Invalid marks...\nPlease Re-enter marks\n";
                cont=true;
            }
        }while(cont);
    }
}
