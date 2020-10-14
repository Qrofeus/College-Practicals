//Telephone Database using Hash Table
//Closed Hashing
#include<iostream>
using namespace std;

#define m 10
class node{
public:
    string name,phone;
    node *next;
    node(string val=""){
        name=val;
        for(int i=0;i<10;i++)
           phone[i]=0;
        next=NULL;
    }
};

class phonebook{
public:
    node *book[m];
    void get_entry();
    int cal_index(char);
    void lookup(string);
    //void display_table();
    phonebook(){
        for(int i=0;i<m;i++)
            book[i]=NULL;
    }
};

int phonebook::cal_index(char ch){
    int num=(int) ch;
    return num%m;
}

void phonebook::get_entry(){
    string str;    node *cn;
    int index;     char contact[10];
    cout<<"\nName: ";
    cin>>str;
    index=cal_index(str[0]);
    if(!book[index]){
        book[index]=new node(str);
        cn=book[index];
    }
    else{
        cn=book[index];
        while(cn->next)
            cn=cn->next;
        cn->next=new node(str);
        cn=cn->next;
    }
    cout<<"Contact: ";
    cin>>contact;
    for(int i=0;i<10;i++)
        cn->phone[i]=(int) contact[i];
}
/*
void phonebook::display_table(){
    node *cn;
    cout<<"\nPhoneBook Display--\n\n";
    for(int i=0;i<m;i++){
        cout<<i<<":\t";
        cn=book[i];
        while(cn){
            cout<<cn->name<<":";
            for(int i=0;i<10;i++)
                cout<<cn->phone[i];
            cout<<" --> ";
            cn=cn->next;
        }
        cout<<"NULL\n";
    }
}
*/
void phonebook::lookup(string str){
    int index=cal_index(str[0]);
    node *cn;
    if(book[index]){
        cn=book[index];
        while(cn){
            if(cn->name==str){
                cout<<cn->name<<"--";
                for(int i=0;i<10;i++)
                    cout<<cn->phone[i];
                cout<<'\n';
                return;
            }
            cn=cn->next;
        }
    }
    cout<<"No Matching Contact Found..\n";
}

int main(){
    phonebook bk;
    int n;
    cout<<"Number of Entries: ";
    cin>>n;
    for(int i=0;i<n;i++)
        bk.get_entry();
    //bk.display_table();
    string st;
    cout<<"\nName LookUp: ";
    cin>>st;
    bk.lookup(st);
}
