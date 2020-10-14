/*
Assignment 7

NINAD DESHPANDE
Roll No.: 10
SE COMP II
Batch: S1

Question:
Department of Computer Engineering has student's club named "Pinnacle Club".
Students of Second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club.
First node is reserved for president of club and last node is reserved for secretary of club.
Write C++ program to maintain club member information using singly linked list.
Store student PRN and Name. Write functions to
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists
*/
#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
public:
    int prn;
    string name;
    node* next;
    node()
    {
        prn=000;
        name="default";
        next=NULL;
    }
}*head[3],*tail[3];

class pinnacle
{
public:
    pinnacle()
    {
        for(int i=0;i<3;i++)
            tail[i]=head[i]=NULL;
    }
    void addpres(int cl, int n, string m);
    void addsec(int cl, int n, string m);
    void addmem(int cl, int n,string m);
    void delpres(int cl);
    void delsec(int cl);
    void delmem(int cl, int n);
    void display(int cl);
    void total(int cl);
    void rev(int cl)
    {
        cout<<"--------------------------\nMembers in Reverse:\n";
        cout<<"\nPresident:\n";
        cout<<"Name: "<<head[cl-1]->name<<"   No: "<<head[cl-1]->prn<<endl;
        if(head[cl-1]!=tail[cl-1])
        {
            cout<<"\nSecretary:\n";
            cout<<"Name: "<<tail[cl-1]->name<<"   No: "<<tail[cl-1]->prn<<endl;
        }
        reverse(head[cl-1]->next, cl);
    }
    void reverse(node* temp, int cl);
};

void pinnacle::reverse(node* temp, int cl)
{
    int i=1;
    if(temp==NULL)
        cout<<"Club has No Additional Members.\n";
    else
    {
        if(temp->next!=tail[cl-1])
            reverse(temp->next, cl);
    }
    cout<<"\nMember "<<i;
    cout<<"\nName: "<<temp->name<<"   No: "<<temp->prn<<endl;
    i++;
}

void pinnacle::total(int cl)
{
    int c=0;
    node* temp;
    temp=head[cl-1];
    if(head[cl-1]!=NULL)
    {
        while(temp!=NULL)
        {
            temp=temp->next;
            c++;
        }
        cout<<"\nClub has "<<c<<" members.\n";
    }
    else
        cout<<"\nClub has no members.\n";
}

void pinnacle::delmem(int cl, int n)
{
    if(head[cl-1]==NULL)
        cout<<"Club has no members.\n";
    else
    {
        bool c=true;
        node *temp,*temp1;
        temp=temp1=head[cl-1];
        while(temp->prn!=n)
        {
            temp1=temp;
            temp=temp->next;
            c=false;
        }
        if(temp->prn==n)
            c=true;
        if(!c)
        {
            cout<<"Invalid Member PRN.\n";
            return;
        }
        temp1->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
}

void pinnacle::delsec(int cl)
{
    if(tail[cl-1]==NULL)
        cout<<"Club has no Secretary\n";
    else
    {
        node *temp,*temp1;
        temp=tail[cl-1];
        temp1=head[cl-1];
        while(temp1->next!=tail[cl-1])
            temp1=temp1->next;
        temp1->next=NULL;
        tail[cl-1]=temp1;
        delete temp;
    }
}

void pinnacle::delpres(int cl)
{
    if(head[cl-1]==NULL)
        cout<<"Club has No President\n";
    else
    {
        node *temp,*temp1;
        temp=temp1=head[cl-1];
        while(temp1->next!=tail[cl-1])
            temp1=temp1->next;
        temp1->next=NULL;
        tail[cl-1]->next=head[cl-1]->next;
        head[cl-1]=tail[cl-1];
        tail[cl-1]=temp1;
        delete temp;
    }
}

void pinnacle::display(int cl)
{
    if(head[cl-1]==NULL)
    {
        cout<<"Club not established.\n";
        return;
    }
    int i=1;
    node* temp;
    cout<<"----------------------------\nPresident:\n";
    cout<<"Name: "<<head[cl-1]->name<<"   No: "<<head[cl-1]->prn<<endl;
    cout<<"\nSecretary:\n";
    if(head[cl-1]!=tail[cl-1])
        cout<<"Name: "<<tail[cl-1]->name<<"   No: "<<tail[cl-1]->prn<<endl<<endl;
    temp=head[cl-1]->next;
    if(temp==tail[cl-1]||temp==NULL)
        cout<<"No Additional Members\n";
    else
    {
        while(temp->next!=NULL)
        {
            cout<<"Member: "<<i<<endl;
            cout<<"Name: "<<temp->name<<"   No: "<<temp->prn<<endl;
            i++;
            temp=temp->next;
        }
    }
}

void pinnacle::addmem(int cl, int n, string m)
{
    if(head[cl-1]==NULL)
    {
        cout<<"Add President and Secretary before adding members.\n";
        return;
    }
    node* temp;
    temp=new node;
    temp->prn=n;
    temp->name=m;
    temp->next=head[cl-1]->next;
    head[cl-1]->next=temp;
}

void pinnacle::addsec(int cl, int n, string m)
{
    node* temp;
    temp=new node;
    temp->prn=n;
    temp->name=m;
    if(tail[cl-1]==NULL)
    {
        tail[cl-1]=temp;
        head[cl-1]=tail[cl-1];
    }
    else
    {
        tail[cl-1]->next=temp;
        tail[cl-1]=temp;
    }
}

void pinnacle::addpres(int cl, int n, string m)
{
    node* temp;
    temp=new node;
    temp->prn=n;
    temp->name=m;
    if(head[cl-1]==NULL)
    {
        head[cl-1]=temp;
        tail[cl-1]=head[cl-1];
    }
    else
    {
        temp->next=head[cl-1];
        head[cl-1]=temp;
    }
}

int main()
{
    pinnacle p;
    string name;
    int num,year,choice;
    bool cont;
    do
    {
        cont=false;
        cout<<"*******************\nAcademicYear:\n1. Second Year\n2. Third Year\n3. Final Year\n";
        cout<<"Select Year: ";
        cin>>year;
        while(1)
        {
            cout<<"----------------------------------\n";
            cout<<"Operation List:\n1.Add President\n2.Add Secretary\n3.Add Member\n4.Delete President\n5.Delete Secretary\n6.Delete Member\n";
            cout<<"7.Display Number of Members in the Club\n8.Display Club Members\n9.Change Academic Year\n\n10.Exit\n\nSelect Operation: ";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"Enter Name and PRN: ";
                cin>>name>>num;
                p.addpres(year, num, name);
                break;
            case 2:
                cout<<"Enter Name and PRN: ";
                cin>>name>>num;
                p.addsec(year, num, name);
                break;
            case 3:
                cout<<"Enter Name and PRN: ";
                cin>>name>>num;
                p.addmem(year, num, name);
                break;
            case 4:
                p.delpres(year);
                break;
            case 5:
                p.delsec(year);
                break;
            case 6:
                cout<<"**Cancel Membership**\nEnter PRN: ";
                cin>>num;
                p.delmem(year, num);
                break;
            case 7:
                p.total(year);
                break;
            case 8:
                p.display(year);
                break;
            case 9:
                cont=true;
                break;
            case 10:
                exit(0);
            }
            if(cont)
                break;
        }
    }while(cont);
    return 0;
}
