//Expression Tree
//PostOrder Traversal non recursive
#include<iostream>
using namespace std;
#include<stack>

#define maxm 10
class node{
public:
    node(char xh=' '){
        info=xh;    left=NULL;  right=NULL;
    }
    char info;
    node *left,*right;
};

class exptree{
public:
    node *root;
    node *create_tree(node *,char [],int,int);
    void postorder(node *);
    void non_rec_post(node *);
    exptree(){
        root=NULL;
    }
};

node *exptree::create_tree(node *tmp,char str[],int st,int en){
    for(int i=st;i<en;i++){
        if(str[i]=='+'||str[i]=='-'){
            tmp=new node(str[i]);
            tmp->left=create_tree(tmp->left,str,st,i);
            tmp->right=create_tree(tmp->right,str,i+1,en);
            return tmp;
        }
    }
    for(int i=st;i<en;i++){
        if(str[i]=='*'||str[i]=='/'){
            tmp=new node(str[i]);
            tmp->left=create_tree(tmp->left,str,st,i);
            tmp->right=create_tree(tmp->right,str,i+1,en);
            return tmp;
        }
    }
    tmp=new node(str[st]);
    return tmp;
}

void exptree::postorder(node *tmp){
    if(tmp==NULL)
        return;
    postorder(tmp->left);
    postorder(tmp->right);
    cout<<tmp->info<<' ';
}

void exptree::non_rec_post(node *tmp){
    if(tmp==NULL){
        cout<<"Empty Tree";
        return;
    }
    stack<node *> s,op;
    s.push(root);
    while(!s.empty()){
        node *cn=s.top();
        op.push(cn);
        s.pop();
        if(cn->left)
            s.push(cn->left);
        if(cn->right)
            s.push(cn->right);
    }
    while(!op.empty()){
        cout<<op.top()->info<<' ';
        op.pop();
    }
}
int len(char str[]){
    int num=0;
    for(int i=0;i<maxm;i++){
        if(str[i]=='\0')
            break;
        num+=1;
    }
    return num;
}

int main(){
    char exp[maxm];
    cout<<"Enter Expression: ";
    cin>>exp;
    //cout<<len(exp);
    exptree tr;
    int last=len(exp);
    tr.root=tr.create_tree(tr.root,exp,0,last);
    cout<<"Recursive PostOrder:: ";
    tr.postorder(tr.root);
    cout<<"\nNon Recursive PostOrder:: ";
    tr.non_rec_post(tr.root);
}
