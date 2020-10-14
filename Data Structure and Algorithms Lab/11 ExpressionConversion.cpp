/*
ASSIGNMENT 11

NINAD DESHPANDE
Roll No.: 10
SE COMP II
Batch: S1

Question:
Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions
i. Operands and operator, both must be single character.
ii. Input Postfix expression must be in a desired format.
iii. Only '+', '-', '*' and '/ ' operators are expected.
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define SIZE 50
char s[SIZE];
int top=-1;

void push(char elem)
{
    s[++top]=elem;
}

char pop()
{
    return(s[top--]);
}

int priority(char elem)
{
    switch(elem)
    {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
}

int main()
{
    char infx[50],postfx[50],ch,elem;
    int i=0,k=0;
    cout<<"Enter Infix Expression: ";
    cin>>infx;
    push('#');
    while((ch=infx[i++])!='\0')
    {
        if(ch=='(')
            push(ch);
        else
            if(isalnum(ch))
            postfx[k++]=ch;
            else
            if(ch==')')
            {
                while(s[top]!='(')
                postfx[k++]=pop();
                elem=pop();
            }
            else
            {
                while(priority(s[top])>=priority(ch))
                postfx[k++]=pop();
                push(ch);
            }
    }
    while(s[top]!='#')
    postfx[k++]=pop();
    postfx[k]='\0';
    cout<<"\n\nPostfix Expression: "<<postfx<<"\n\n";
    return 0;
}
