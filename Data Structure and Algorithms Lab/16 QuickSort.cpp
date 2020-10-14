/*
ASSIGNMENT 16

NINAD DESHPANDE
Roll No.: 10
SE COMP II
Batch: S1

Question:
Write C++ program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.
*/
#include<iostream>
#define max 50
using namespace std;

template<typename T>
T part(T arr[], int low, int high)
{
    T pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
        if(arr[j]>pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

template<typename T>
void quicksort(T arr[], int low, int high)
{
    if(low<high)
    {
        T pi=part(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main()
{
    int n;
    float percent[max];
    cout<<"Enter number of students in database: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Student "<<i+1<<": ";
        cin>>percent[i];
    }
    quicksort(percent, 0, n-1);
    cout<<"\n\nSorting List of Percentages...\nComplete!\n\n";
    cout<<"\nTop 5 Scores of first year:\n";
    for(int i=0;i<5;i++)
        cout<<percent[i]<<endl;
}
