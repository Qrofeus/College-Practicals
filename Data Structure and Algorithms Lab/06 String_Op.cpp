/*
Assignment 6

NINAD DESHPANDE
Roll No.:10
SE COMP II
Batch: S1

Question:
Write C++ program for string operations- copy, concatenate, check sub-string, equal, reverse and length.
*/
#include<iostream>
#include<cstdlib>
using namespace std;

const int size=50;

char str[size],str1[size];
void copystr();
void concat();
bool substring();
bool equalstr();
void reversestr();
int length(char s[]);
void display(char s[]);

int main()
{
    int n;
    cout<<"Enter String: ";
    cin>>str;
    while(1)
    {
        cout<<"-----------------------------------------\n";
        cout<<"Select Operation to perform:\n1.Copy String\n2.Concatenate Strings\n3.Check SubString\n4.Check Equality of Strings\n";
        cout<<"5.Reverse String\n6.Check Length\n\n7.Exit\n\nEnter Operation Code: ";
        cin>>n;
        switch(n)
        {
        case 1:
            copystr();
            cout<<"Copied String is: ";
            display(str1);
            break;
        case 2:
            cout<<"Enter String to add to Original string: ";
            cin>>str1;
            concat();
            cout<<"The Merged String is: ";
            display(str);
            break;
        case 3:
            cout<<"Enter SubString to check: ";
            cin>>str1;
            if(substring())
                cout<<"Input string is a SubString of Original String.\n";
            else
                cout<<"Input string is not a SubString of Original String.\n";
            break;
        case 4:
            cout<<"Enter String to check equality: ";
            cin>>str1;
            if(equalstr())
                cout<<"Strings are equal.\n";
            else
                cout<<"Strings are not equal.\n";
            break;
        case 5:
            reversestr();
            cout<<"Reversed String is: ";
            display(str);
            reversestr();
            break;
        case 6:
            cout<<"Length of input string is: "<<length(str)<<" Characters"<<endl;
            break;
        case 7:
            exit(0);
        }
        cout<<'\n';
    }
}

void copystr()
{
    int i,n=length(str);
    for(i=0;i<n;i++)
        str1[i]=str[i];
    str[i]='\0';
}

void concat()
{
    int i,n=length(str),m=length(str1);
    for(i=0;i<m;i++)
    {
        str[n]=str1[i];
        n++;
    }
    str[n]='\0';
    cout<<"***Original String Updated***\n";
}

bool substring()
{
    int j,n=length(str1),k;
    bool c=false;
    for(int i=0;i<size;i++)
    {
        j=0;
        if(str[i]==str1[j])
        {
            for(k=i,j=0;j<n;k++,j++)
                if(str[k]==str1[j])
                    c=true;
                else
                {
                    c=false;
                    break;
                }
            if(c)
                break;
        }
    }
    return c;
}

bool equalstr()
{
    bool c;
    for(int i=0;i<size;i++)
        if(str[i]==str1[i])
            c=true;
        else
        {
            c=false;
            break;
        }
    return c;
}

void reversestr()
{
    int n=length(str);
    for(int i=0;i<n/2;i++)
        swap(str[i],str[n-i-1]);
}

int length(char s[])
{
    int counter=0;
    for(int i=0;i<size;i++)
    {
        if(s[i]=='\0')
            break;
        counter++;
    }
    return counter;
}

void display(char s[])
{
    for(int i=0;s[i]!='\0'&&i<size;i++)
        cout<<s[i];
    cout<<'\n';
}
