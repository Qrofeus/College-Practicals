//Adjacency List and Adjacency Matrix Representation of Graph
//Adjacency Matrix
#include<iostream>
using namespace std;
//Undirected Graph
#define maxm 10
class matrix{
public:
    int n,mat[maxm][maxm];
    string st[maxm];
    void get_nodes();
    void get_links();
    void display_nodes();
    void display_links();
    matrix(){
        n=0;
        for(int i=0;i<maxm;i++)
            for(int j=0;j<maxm;j++)
                mat[i][j]=0;
    }
};

void matrix::get_nodes(){
    string str;
    cout<<"Node Count: ";
    cin>>n;
    cout<<"\nEnter Node Identifiers--\n";
    for(int i=0;i<n;i++){
        cout<<"Node Name: ";
        cin>>str;
        st[i]=str;
    }
}

void matrix::get_links(){
    int num;
    string str1,str2;
    cout<<"\nNumber of Links: ";
    cin>>num;
    for(int i=0;i<num;i++){
        restart:
        cout<<"Enter link nodes: ";
        cin>>str1>>str2;
        int var1,var2;
        bool flag1=false,flag2=false;
        for(int i=0;i<n;i++){   //Check for existence of nodes
            if(st[i]==str1){
                flag1=true;
                var1=i;
            }
            if(st[i]==str2){
                flag2=true;
                var2=i;
            }
        }
        if(!flag1||!flag2){
            cout<<"Unidentified Node..\n";
            goto restart;
        }
        mat[var1][var2]=1;  //Add link
        mat[var2][var1]=1;
    }
}

void matrix::display_nodes(){
    cout<<"\nNode Correspondence--\n";
    for(int i=0;i<n;i++){
        cout<<st[i]<<'-'<<i<<'\n';
    }
}

void matrix::display_links(){
    cout<<"\nMatrix Display--\n\t";
    for(int i=0;i<n;i++)
        cout<<st[i]<<'\t';
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<st[i]<<'\t';
        for(int m=0;m<n;m++){
            cout<<mat[i][m]<<'\t';
        }
        cout<<'\n';
    }
}

int main(){
    matrix m;
    m.get_nodes();
    m.get_links();
    m.display_nodes();
    m.display_links();
}
