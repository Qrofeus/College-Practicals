/*
ASSIGNMENT 14

NINAD DESHPANDE
Roll No.: 10
SE COMP II
Batch: S1

Question:
Write C++ program to store roll numbers of student in array who attended training program in random order.
Write function for
a) Searching whether particular student attended training program or not using linear search and sentinel search.
b) Searching whether particular student attended training program or not using binary search and Fibonacci search.
*/
#include<iostream>
using namespace std;
class search
{
public:
    int n,i,data[50],son[50],sortdata[50],s;
    void intake()
    {
        cout<<"Enter No. of Students that attended the Program: ";
        cin>>n;
        cout<<"Enter Roll Number of students that attended the program: ";
        for(i=1;i<=n;i++)
        {
            cin>>data[i];
            son[i]=data[i];
        }
    }

    void search_lini(int item)
    {
        s=0;
        for(i=1;i<=n;i++)
        {
            if(data[i]==item)
            {
                s=1;
                break;
            }
        }
        if(s==1)
            cout<<"Attended the training program.\n";
        else
            cout<<"Didn't Attend the training program.\n";
    }

    void search_senti(int item)
    {
        int last = data[n-1];
        data[n-1] = item;
        int i = 0;
        while(data[i]!=item)
            i++;
        data[n-1] = last;
        if((i<n-1)||(item == data[n-1]))
            cout<<"Attended the Training Program.\n";
        else
            cout<<"Didn't Attend the Training Program.\n";
    }

    void search_bin(int x)
    {
        int y=0;
        int left,right,mid;
        left=0;
        right=n-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(data[mid]==x)
            {
            y=1;
            break;
            }
            else if(data[mid]>x)
                right = mid-1;
            else if(data[mid]<x)
                left=mid+1;
        }
        if(y==1)
            cout<<"Attended the Training Program.\n";
        else
            cout<<"Didn't Attend the Training Program.\n";
    }

    int fibsearch(int x)
    {
        int inf = 0, pos, k;
        static int kk= -1, nn = -1;
        static int fib[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141};
        if (nn != n)
        {
            k = 0;
            while (fib[k] <n)
            k++;
            kk = k;
            nn = n;
        }
        else
        k = kk;
        while (k > 0)
        {
            pos = inf + fib[--k];
            if ((pos>= n) || (x <data[pos]));
            else if (x >data[pos])
            {
                inf = pos + 1;
                k--;
            }
            else
                return pos;
        }
        return -1;
    }

    void sort()
    {
        int p,j,temp;
        for(p=1;p<=n-1;p++)
        {
            for(j=1;j<=n-1;j++)
            {
                if(data[j]>data[j+1])
                {
                    temp=data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;
                }
            }
        }
    }
};

int main()
{
    int s,r,pos;
    char ch;

    search t;
    t.intake();
    t.sort();
    do
    {
        cout<<"___________________________________________________\n";
        cout<<"Search Options:\n1.Linear Search\n2.Sentinel Search\n3.Binary Search\n4.Fibonacci Search\nEnter your choice: ";
        cin>>s;
        cout<<"Enter Roll Number of Student to check for attendance: ";
        cin>>r;
        switch(s)
        {
            case 1:
                t.search_lini(r);
                break;
            case 2:
                t.search_senti(r);
                break;
            case 3:
                t.search_bin(r);
                break;
            case 4:
                pos=t.fibsearch(r);
                if(pos>=0)
                    cout<<"Attended the Training Program"<<endl;
                else
                    cout<<"Didn't Attend the Training Program"<<endl;
                    break;
        }
        cout<<"\nDo you want to check attendance for another student?\n";
        cin>>ch;
    }while(ch=='Y'||ch=='y');
    return 0;
}
