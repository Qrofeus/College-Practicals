//Bridge the Gap
//Linked List Implementation
#include"iostream"
using namespace std;
class node{
public:
    node(){
        info=0; next=NULL;
    }
    int info;
    node* next;
};

class linkedlist{
    node* head=NULL;
public:
    void add_element(int val);
    void del_element(int val);
    void search_element(int val);
    void display_list();
};

void linkedlist::add_element(int val){
    node* temp; temp=new node;
    temp->info=val;
    if(head==NULL){
        head=temp;
        return;
    }
    node* cn;   cn=head;
    while(cn->next!=NULL){
        cn=cn->next;
    }
    cn->next=temp;
}

void linkedlist::del_element(int val){
    node *cn,*pn;   cn=head; pn=NULL;
    while(cn!=NULL){
        if(cn->info==val){
            break;
        }
        pn=cn;
        cn=cn->next;
    }
    if(cn==NULL){
        cout<<"Element not found";
        return;
    }
    pn->next=cn->next;
    delete cn;
}

void linkedlist::search_element(int val){
    node* cn;   cn=head;
    while(cn!=NULL){
        if(cn->info==val){
            cout<<"Element found:: "<<cn->info;
            return;
        }
        cn=cn->next;
    }
    cout<<"Element Not Found";
}

void linkedlist::display_list(){
    node* temp; temp=head;
    while(temp!=NULL){
        cout<<temp->info<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main(){
    linkedlist ll;
    int opcode,value;
    while(1){
        cout<<"\nOperations:\n1. Add Element\n2. Delete Element\n3. Search for Element\n4. Display List\n5. Exit\nOpCode::";
        cin>>opcode;
        switch(opcode){
        case 1:
            cout<<"Enter Value: ";  cin>>value;
            ll.add_element(value);  break;
        case 2:
            cout<<"Enter Value: ";  cin>>value;
            ll.del_element(value);  break;
        case 3:
            cout<<"Enter Value: ";  cin>>value;
            ll.search_element(value);   break;
        case 4:
            ll.display_list();  break;
        case 5:
            return 0;
        default:
            cout<<"Invalid OpCode";
        }
        cout<<'\n';
    }
}
