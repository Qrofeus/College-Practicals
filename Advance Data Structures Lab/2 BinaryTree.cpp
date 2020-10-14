//Binary Tree
//Insert Node
//Longest Path
//Minimum data
//Reverse Polarities
//Search Value
#include"iostream"
using namespace std;

class node{
public:
    node(int inf=0){
        info=inf;   left=NULL;  right=NULL;
    }
    int info;
    node *left,*right;
};

class BinaryTree{
public:
    node* root;
    BinaryTree(){
        root=NULL;
    }
    node *insert_node(node *,int);
    int longest_path(node *);
    void min_data();
    void polarity(node *);
    bool search_node(node *,int);
};

node *BinaryTree::insert_node(node *tmp,int val){
    if(tmp==NULL){
        node *temp=new node(val);
        return temp;
    }
    if(val>tmp->info)
        tmp->right=insert_node(tmp->right,val);
    if(val<tmp->info)
        tmp->left=insert_node(tmp->left,val);
    return tmp;
    cout<<"Never Printed";
}

int BinaryTree::longest_path(node *temp){
    if(temp==NULL)
        return 0;
    else
        return (max(longest_path(temp->left),longest_path(temp->right))+1);
}

void BinaryTree::min_data(){
    if(root==NULL){
        cout<<"Empty Tree";
        return;
    }
    node *cn=root;
    while(cn->left!=NULL)
        cn=cn->left;
    cout<<"Minimum Data:: "<<cn->info;
}

void BinaryTree::polarity(node *tmp){
    if(tmp==NULL)
        return;
    polarity(tmp->left);
    polarity(tmp->right);
    swap(tmp->left,tmp->right);
}

bool BinaryTree::search_node(node *tmp,int val){
    if(root==NULL)
        return false;
    if(tmp->info==val)
        return true;
    if(val>tmp->info)
        return search_node(tmp->right,val);
    return search_node(tmp->left,val);
}

int main(){
    BinaryTree bt;  int opcode,value;
    while(1){
        cout<<"Operations:\n1.Insert Node\n2.Longest Path\n3.Minimum Value\n4.Reverse Polarities\n5.Search Value\n6.Exit\nOpcode: ";
        cin>>opcode;
        switch(opcode){
        case 1:
            cout<<"Enter Value: ";  cin>>value;
            bt.root=bt.insert_node(bt.root,value);  break;
        case 2:
            cout<<"Longest Path: "<<bt.longest_path(bt.root);    break;
        case 3:
            bt.min_data();  break;
        case 4:
            bt.polarity(bt.root);  break;
        case 5:
            cout<<"Enter Value: ";  cin>>value;
            if(bt.search_node(bt.root,value))
                cout<<"Node Found";
            else
                cout<<"Node not Found";
            break;
        case 6:
            return 0;
        }
        cout<<'\n';
    }
}
