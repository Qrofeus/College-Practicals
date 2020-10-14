//Chapters Sections Subsections
//Multi-way trees used for dynamic implementation
#include<iostream>
using namespace std;
#define max 10
class node{
public:
    string info;
    node *sec[max];
    node(string val=""){
        info=val;
        for(int m=0;m<max;m++)
            sec[m]=NULL;
    }
};

class tree{
public:
    node *root;
    int tabs;   //Ease of access variable
    node *insert_node(node *,string);
    void create_tree(node *);
    void display_tree(node *);
    tree(){
        root=NULL;  tabs=0;
    }
};

node *tree::insert_node(node *tmp,string val){
    tmp=new node(val);
    return tmp;
}

void tree::create_tree(node *tmp){
    if(tmp==NULL){
        return;
    }
    tabs++;
    string st;  int n;
    for(int i=0;i<tabs-1;i++)
        cout<<'\t';
    cout<<"Name: "<<tmp->info<<"\tSection Count: ";
    cin>>n;
    if(n>0){
        for(int i=0;i<n;i++){
            for(int m=0;m<tabs;m++)
                cout<<'\t';
            cout<<"Section Name: ";
            cin>>st;
            tmp->sec[i]=insert_node(tmp->sec[i],st);
            create_tree(tmp->sec[i]);
        }
    }
    tabs--;
}

void tree::display_tree(node *tmp){
    if(tmp==NULL){
        return;
    }
    cout<<tmp->info<<'\n';
    for(int i=0;i<max;i++)
        display_tree(tmp->sec[i]);
}

int main(){
    tree T; string str;
    cout<<"Chapter Name: ";
    cin>>str;
    T.root=T.insert_node(T.root,str);
    T.create_tree(T.root);
    cout<<"\nName of Chapter--";
    T.display_tree(T.root);
}
