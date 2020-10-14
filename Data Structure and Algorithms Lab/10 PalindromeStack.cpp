/*
ASSIGNMENT 10

NINAD DESHPANDE
Roll No.: 10
SE COMP II
Batch: S1

Question:
A palindrome is a string of character that is the same forward and backward.
Typically, punctuation, capitalization, and spaces are ignored.
For example, "Poor Dan is in a droop" is a palindrome, as can be seen by examining the characters
―poordanisinadroop- and observing that they are the same forward and backward.
One way to check for a palindrome is to reverse the characters in the string and then compare with them the original in a palindrome, the sequence will be identical.
Write C++ program with functions-
1. to check whether given string is palindrome or not that uses a stack to determine whether a string is a palindrome.
2. to remove spaces and punctuation in string, convert all the characters to lower-case, and then call above Palindrome checking function to check for a palindrome
3. to print string in reverse order using stack
*/
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
#define MAX 50
class Stack
{
private:
    char data[MAX],str[MAX];
    int top,length,count;
    void pushData(char);
    char popData();
public:
    Stack()
    {
        top=-1;
        length=0;
        count=0;
    }
    void getString();
    void check();
    void modifyString();
    void displayReverse();
};
int main()
{
    Stack obj;
    obj.getString();
    cout<<"Modified String: ";
    obj.modifyString();
    cout<<"\nReversed String: ";
    obj.displayReverse();
    obj.check();
    return 0;
}
void Stack::getString()
{
    cout<<"Enter a String: ";
    cin.getline(str,MAX);
    length=strlen(str);
}

void Stack::modifyString()
{
    char temp[MAX];
    int i,j;
    for(i=0; i<length; i++)
    {
        temp[i]=str[i];
    }
    j=0;
    for(i=0; i<length; i++ )
    {
        if(isalpha(temp[i]))
        {
            str[j]=tolower(temp[i]);
            j++;
        }
    }
    length=j;
    for(int i=0; i<length; i++)
        cout<<str[i];
}

void Stack::check()
{
    for(int i=0; i<length; i++)
        pushData(str[i]);
    for(int i=0; i<length; i++)
    {
        if(str[i]==popData())
        count++;
    }
    if(count==length)
        cout<<"\n\nEntered string is a Palindrome\n";
    else
        cout<<"\n\nEntered string is not a Palindrome\n";
}

void Stack::displayReverse()
{
    for(int i=length-1; i>=0; i--)
        cout<<str[i];
}

void Stack::pushData(char temp)
{
    if(top==MAX-1)
    {
        cout<<"\n Stack Overflow!!!";
        return;
    }
    top++;
    data[top]=temp;
}

char Stack::popData()
{
    if(top==-1)
    {
        cout<<"\n Stack Underflow!!!";
        return 0;
    }
    char temp=data[top];
    top--;
    return temp;
}
