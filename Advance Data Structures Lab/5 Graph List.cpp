//Adjacency List and Adjacency Matrix Representation for Graph
//Adjacency List
#include"iostream"
using namespace std;

#define maxm 10
class node{         //vertex structure
public:
    string info;    //node name
    node *conn;     //graph links
    node(string val=""){
        info=val;   conn=NULL;
    }
};

class adjlist{
public:
    adjlist(int n){
        maxi=n;
        for(int i=0;i<n;i++)
            ver[i]=NULL;
    }
    int maxi;
    node *ver[maxm];
    void get_vertices();
    void add_link(string,string);
    void get_links();
    void display_list();
};

void adjlist::get_vertices(){
    for(int i=0;i<maxi;i++){
        string str;
        cout<<"Node name: ";
        cin>>str;
        ver[i]=new node(str);
    }
}

void adjlist::add_link(string st1,string st2){
    int var1,var2;
    bool flag1=false,flag2=false;
    for(int i=0;i<maxi;i++){
        if(ver[i]->info==st1){
            flag1=true;
            var1=i;
        }
        if(ver[i]->info==st2){
            flag2=true;
            var2=i;
        }
    }
    if(!flag1||!flag2){
        cout<<"Node Unavailable";
        return;
    }
    node *cn1,*cn2;
    cn1=ver[var1];
    while(cn1->conn)
        cn1=cn1->conn;
    cn1->conn=new node(st2);
    cn2=ver[var2];
    while(cn2->conn)
        cn2=cn2->conn;
    cn2->conn=new node(st1);
}

void adjlist::get_links(){
    int num;
    string str1,str2;
    cout<<"Number of Links: ";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"Enter link nodes: ";
        cin>>str1>>str2;
        add_link(str1,str2);
    }
}

void adjlist::display_list(){
    for(int i=0;i<maxi;i++){
        node *cn;
        cn=ver[i];
        while(cn){
            cout<<cn->info<<"->";
            cn=cn->conn;
        }
        cout<<"NULL\n";
    }
}

int main(){
    int n;
    cout<<"No. of vertices: ";
    cin>>n;
    adjlist lst(n);
    cout<<"\nEnter Nodes--\n";
    lst.get_vertices();
    cout<<"\nEnter Links--\n";
    lst.get_links();
    cout<<"\nDisplaying List Representation--\n";
    lst.display_list();
}
