/*
Pizza parlor accepting maximum M orders. Orders are served in first come first served basis.
Order once placed can not be cancelled. Write C++ program to simulate the system using circular queue using array.
*/
#include<iostream>
#define max 10
using namespace std;

int q[max],front=-1,rear=-1;
void enqueue(int val);
int dequeue();
bool empty();
bool full();
void display();

int main()
{
	int n=0,num;
	char yes;
	bool cont;
	do
	{
		cont=false;
		cout<<"Enter Order Number: ";
		cin>>num;
		enqueue(num);
		n++;
		if(full())
		{
			cout<<"Queue is Full\nWait for sometime...\n";
			break;
		}
		cout<<"Enter Another Order? ";
		cin>>yes;
		if(yes=='Y')
		cont=true;
	}while(cont);
	if(empty())
		cout<<"\nQueue is Empty.\n";
	else
	{
		cout<<"\nOrders in Queue are:\n";
		display();
		cout<<"\nProcessing Orders:\n";
		for(int i=0;i<n;i++)
		{
			cout<<"Order number "<<dequeue()<<"...\nComplete.\n";
		}
	}
	return 0;
}

void display()
{
	int i;
	for(i=front;i!=rear;i=(i+1)%max)
		cout<<q[i]<<"\t";
	cout<<q[rear]<<"\n";
}

bool full()
{
	if(front==(rear+1)%max)
		return true;
	else
		return false;
}

bool empty()
{
	if(front==-1)
		return true;
	else
		return false;
}

int dequeue()
{
	int temp;
	temp=q[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
        front=(front+1)%max;
	return temp;
}

void enqueue(int val)
{
    rear=(rear+1)%max;
    q[rear]=val;
	if(empty())
		front=(front+1)%max;
}
