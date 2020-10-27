#include<iostream>
using namespace std;

class convert
{
public:
    float initial,converted;
    convert()
    {
        cout<<"Enter Initial: ";
        cin>>initial;
    }
    float getinit()
    {
        return initial;
    }
    float getconv()
    {
        return converted;
    }
    virtual void compute()=0;
};

class ftoc:public convert
{
public:
    ftoc()
    {
        compute();
        cout<<"\nFahrenheit: "<<getinit()<<endl;
        cout<<"Celsius: "<<getconv()<<endl;
    }
    void compute()
    {
        converted=(float)(initial-32)/1.8;
    }
};

class mtok:public convert
{
public:
    mtok()
    {
        compute();
        cout<<"\nMile: "<<getinit()<<endl;
        cout<<"Kilometre: "<<getconv()<<endl;
    }
    void compute()
    {
        converted=(float)initial*1.609;
    }
};

class ktom:public convert
{
public:
    ktom()
    {
        compute();
        cout<<"\nKilometre: "<<getinit()<<endl;
        cout<<"Mile: "<<getconv()<<endl;
    }
    void compute()
    {
        converted=(float)initial/1.609;
    }
};

class ctof:public convert
{
public:
    ctof()
    {
        compute();
        cout<<"\nCelsius: "<<getinit()<<endl;
        cout<<"Fahrenheit: "<<getconv()<<endl;
    }
    void compute()
    {
        converted=(float)(initial*1.8)+32;
    }
};

int main()
{
    cout<<"Celsius to Fahrenheit\n";
    ctof ob1;
    cout<<"\nFahrenheit to Celsius\n";
    ftoc ob2;
    cout<<"\nKilometre to Mile\n";
    ktom ob3;
    cout<<"\nMile to Kilometre\n";
    mtok ob4;
    return 0;
}
