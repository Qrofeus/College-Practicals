#include<iostream>
using namespace std;

class node
{
public:
	node()
	{
		status=0;
		next=prev=NULL;
	}
	int status;
	node* next;
	node* prev;
};

class link
{
public:
	node* start[10];
	link()
	{
		for(int i=0;i<10;i++)
			start[i]=NULL;
        create();
	}
	void create();
	void display();
	void bookseat(int row, int col);
	void cancelseat(int row, int col);
};

void link::cancelseat(int row, int col)
{
	node* temp;
	temp=start[row-1];
	for(int i=1;i<col;i++)
	{
		temp=temp->next;
	}
	if(temp->status==0)
		cout<<"This seat has no previous booking to cancel.\n";
	else
	{
		temp->status=0;
		cout<<"Booking Cancelled for seat: "<<row<<" "<<col<<"\n";
	}
}

void link::bookseat(int row, int col)
{
	node* temp;
	temp=start[row-1];
	for(int i=1;i<col;i++)
	{
		temp=temp->next;
	}
	if(temp->status==1)
		cout<<"This seat is already booked.\n";
	else
	{
		temp->status=1;
		cout<<"Seat Booked: "<<row<<" "<<col<<"\n";
	}
}

void link::create()
{
	for(int i=0;i<10;i++)
    {
        for(int j=0;j<7;j++)
        {
            node* temp;
            temp=new node();
            if(start[i]==NULL)
                start[i]=temp;
            else
            {
                temp->next=start[i];
                start[i]->prev=temp;
                start[i]=temp;
            }
        }
        node* q;
        q=start[i];
        while(q->next!=NULL)
            q=q->next;
        q->next=start[i];
    }
}

void link::display()
{
	node* q;
	cout<<"Available Seats: <>\nBooked Seats: X\n\n";
	cout<<" \t1 \t2 \t3 \t4 \t5 \t6 \t7 \n";
	for(int i=0;i<10;i++)
	{
		cout<<i+1<<"\t";
		q=start[i];
		do
		{
			if(q->status==0)
				cout<<"<>\t";
			else
				cout<<"X\t";
			q=q->next;
		}while(q!=start[i]);
		cout<<"\n";
	}
}

int main()
{
	int r,c,num;
	char ans='Y';
	link l;
	l.display();
	cout<<"\nDo You want to Book Seats?\n";
	cin>>ans;
	if(ans=='Y')
	{
		cout<<"Enter Number of Seats to Boook: ";
		cin>>num;
		cout<<"\n";
		for(int i=0;i<num;i++)
		{
			cout<<"Enter Seat Address to Book: ";
			cin>>r;
			cin>>c;
			l.bookseat(r,c);
        }
        cout<<"\n";
        l.display();
	}
	cout<<"\nDo you want to cancel booked seats?\n";
	cin>>ans;
	if(ans=='Y')
	{
		cout<<"Enter Number of booked seats to cancel: ";
		cin>>num;
		cout<<"\n";
		for(int i=0;i<num;i++)
		{
			cout<<"Enter seat number of cancel booking: ";
			cin>>r;
			cin>>c;
			l.cancelseat(r,c);
		}
		cout<<"\n";
		l.display();
	}
	return 0;
}
