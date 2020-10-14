//Hash Tables
//Closed Addressing, Chaining
#include<iostream>
using namespace std;

#define maxm 10
class node{
public:
    string name;
    node *next;
    node(string val=""){
        name=val;
        next=NULL;
    }
};

class hashing{
public:
    node *table[maxm];
    int cal_index(char);
    void insert_node(string);
    void display_table();
    bool search_name(string);
    hashing(){
        for(int i=0;i<maxm;i++){
            table[i]=NULL;
        }
    }
};

int hashing::cal_index(char ch){
    int num=(int) ch;
    return num%maxm;    //Hash Function
}                       //ASCII of first Character divided the size of hash table

void hashing::insert_node(string st){   //Closed Addressing
    int index;
    index=cal_index(st[0]);
    if(!table[index]){
        table[index]=new node(st);
        return;
    }
    node *cn;
    cn=table[index];
    while(cn->next)
        cn=cn->next;
    cn->next=new node(st);
}

void hashing::display_table(){
    node *cn;
    cout<<"\nHash Table Display--\n\n";
    for(int i=0;i<maxm;i++){
        cout<<i<<":\t";
        cn=table[i];
        while(cn){
            cout<<cn->name<<"->";
            cn=cn->next;
        }
        cout<<"NULL\n";
    }
}

bool hashing::search_name(string st){
    int index=cal_index(st[0]);
    node *cn;
    if(table[index]){
        cn=table[index];
        while(cn){
            if(cn->name==st)
                return true;
            cn=cn->next;
        }
    }
    return false;
}

int main(){
    hashing h;
    int n;
    string str;
    cout<<"Input Count: ";
    cin>>n;
    cout<<"\nEnter Inputs--\n";
    for(int i=0;i<n;i++){
        cout<<"Name: ";
        cin>>str;
        h.insert_node(str);
    }
    h.display_table();
    cout<<"\nSearch Name: ";
    cin>>str;
    if(h.search_name(str))
        cout<<"Entry Present at index "<<h.cal_index(str[0])<<" in Hash Table\n";
    else
        cout<<"No Entry of Input Denomination is Present\n";
}
//Open Addressing Linear, Quadratic
//Linear may cause clustering of data
/*
For Open Addressing:

Declaring Hash Table--
string table[maxm];

Initialization--
for(int i=0;i<maxm;i++)
    table[i]="";

Insert Node Functions--
insert_node(string st){     //Linear Probing
    int ind=cal_index(st[0]);
    repeat:
    if(table[ind]==""){
        table[ind]=st;
    }
    else{
        ind=(ind+1)%maxm;
        goto repeat;
    }
}

insert_node(string st){     //Quadratic Probing
    int fail=0,ind=cal_index(st[0]);
    repeat:
    if(table[ind]==""){
        table[ind]=st;
    }
    else{
        fail++;
        ind=(ind+(fail*fail))%maxm;
        goto repeat;
    }
}
*/
