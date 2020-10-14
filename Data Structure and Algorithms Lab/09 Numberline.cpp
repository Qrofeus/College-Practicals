#include<iostream>
using namespace std;

class node
{
public:
    node(int val)
    {
        info=val;
        next=NULL;
    }
	int info;
	node *next;
}*start,*negative,*positive,*merger;

class list
{
	public:
	list()
	{
		start=NULL;
	}
	void insertnode(int val);
	void sortlist(node* s);
	void display(node* s);
	void splitneg(node* s);
	void mergelist(node* s1, node* s2);
};

void list::mergelist(node* s1, node* s2)
{
    node *p=s1, *q=s2;
    if((s1->info)>(s2->info))
    {
        merger=s2;
        while(q->next!=NULL)
            q=q->next;
        q->next=s1;
    }
    else
    {
        merger=s1;
        while(p->next!=NULL)
            p=p->next;
        p->next=s2;
    }
    cout<<"\nMerged List of Integer Numbers:\n";
    display(merger);
}

void list::splitneg(node* s)
{
    node* temp;
    negative=s;
    temp=s;
    if(temp->info>=0)
    {
        positive=temp;
        negative=NULL;
    }
    else
    {
        while((temp->next)->info<0)
            temp=temp->next;
        positive=temp->next;
        temp->next=NULL;
    }
    if(positive->info==0)
    {
        node* p;
        p=positive;
        positive=positive->next;
        delete p;
    }
    cout<<"\nNegative Numbers\n";
    display(negative);
    cout<<"\nPositive Numbers\n";
    display(positive);
}

void list::sortlist(node* s)
{
    node *q,*r;
    q=s;
    r=s;
    while((q->next)!=NULL)
    {
        while((r->next)!=NULL)
        {
            r=r->next;
            if((r->info)<(q->info))
                swap((r->info),(q->info));
        }
        q=q->next;
        r=q;
    }
    cout<<"\nSorted List\n";
    display(s);
}

void list::display(node* s)
{
    node* temp;
    temp=s;
    if(temp==NULL)
    {
        cout<<"Empty List.";
    }
    else
    {
        cout<<"The List is: ";
        while(temp!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
    }
    cout<<"\n";
}

void list::insertnode(int val)
{
    if(start==NULL)
        start=new node(val);
    else
    {
        node* temp;
        temp=new node(val);
        temp->next=start;
        start=temp;
    }
}

int main()
{
	int len,val;
	list l;
        cout<<"Enter number of elements in the list: ";
        cin>>len;
        for(int i=0;i<len;i++)
        {
            cout<<"Enter Value: ";
            cin>>val;
            l.insertnode(val);
        }
        l.display(start);
        l.sortlist(start);
        l.splitneg(start);
        l.mergelist(negative,positive);

        return 0;
}
