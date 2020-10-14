/*
ASSIGNMENT 15

NINAD DESHPANDE
Roll No.: 10
SE COMP II
Batch: S1

Question:
Write C++ program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort
Display top five scores.
*/
#include<iostream>
#define max 50
using namespace std;

template<typename T>
void selectionsort(T arr[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i;j<n;j++)
            if(arr[j]>arr[i])
                swap(arr[j],arr[i]);
}

template<typename T>
void bubblesort(T arr[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j+1]>arr[j])
                swap(arr[j+1],arr[j]);
}

int main()
{
    float percent[max];
    int n,ch;
    bool flag=false;
    cout<<"Enter number of students in the database: ";
    cin>>n;
    cout<<"Enter first year percentages scored by students:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Student "<<i+1<<": ";
        cin>>percent[i];
    }
    cout<<"Sorting Options:\n";
    cout<<"1.Selection Sort\n2.Bubble Sort\nSelect Operation: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        selectionsort(percent, n);
        break;
    case 2:
        bubblesort(percent, n);
        break;
    default:
        cout<<"Wrong Operation Code\n";
        flag=true;
    }
    if(!flag)
    {
        cout<<"\nTop 5 Scores of first year:\n";
        for(int i=0;i<5;i++)
            cout<<percent[i]<<endl;
    }
    return 0;
}
