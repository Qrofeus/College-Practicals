/*
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system.
If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue.
Write functions to add job and delete job from queue. 
*/
#include"iostream"
#define max 10
using namespace std;
bool empty();
bool full();
void enqueue(int val);
int dequeue();
void display(int n);

int q[max],front=-1,rear=-1;

int main()
{
	int n,val;
	bool greater;
	do
	{
	greater=false;
	cout<<"Enter number of Job Applications: ";
	cin>>n;
	if(n>max)
		greater=true;
	}while(greater);
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Application Number: ";
		cin>>val;
		enqueue(val);
		if(full())
		{
			cout<<"Queue is Full\nPlease wait for next session\n";
			break;
		}
	}
	if(!empty())
	{
		cout<<"\nApplications in Queue are:\n";
		display(n);
		cout<<"\nProcessing Jop Applications:\n";
		for(int i=0;i<n;i++)
		{
			cout<<"Application Number "<<dequeue()<<"...\nComplete.\n";
		}
	}
	return 0;
}

void display(int n)
{
	for(int i=0;i<n;i++)
		cout<<q[i]<<"\t";
	cout<<"\n";
}

int dequeue()
{
	int temp;
	temp=q[0];
	for(int i=0;i<max-2;i++)
		q[i]=q[i+1];
	rear--;
	return temp;
}

void enqueue(int val)
{
	rear++;
	q[rear]=val;
	if(empty())
	front++;
}

bool full()
{
	if(rear==max-1)
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
