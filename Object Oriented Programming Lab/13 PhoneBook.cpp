/*
NINAD DESHPANDE
Roll No.:10
SE COMP II
Batch: S1

Assignment 13

Question:
Write a menu driven program that will create a data file containing the list of telephone numbers in the following form
John 	23456
Ahmed 	9876
………		……….
Use a class object to store each set of data, access the file created and implement the following tasks
I. Determine the telephone number of specified person.
II. Determine the name if telephone number is known.
III. Update the telephone number, whenever there is a change.
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class phonebook
{
public:
    char name[20];
    long double ph;

    void getData()
    {
        cout<<"Enter Name :";
        cin>>name;
        cout<<"Enter Phone Number :";
        cin>>ph;
    }

    void printData()
    {
        cout<<name<<" "<<ph<<endl;
    }
};


int main()
{

    fstream f;

    long double temp_ph;
    char temp_name[20];
    int choice = 1, while_counter = 1, trial1, trial2;
    phonebook p;
    phonebook p1;

    while(while_counter)
    {
        cout<<"\n*****PHONEBOOK*****"<<endl;
        cout<<"1. Add to record."<<endl;
        cout<<"2. Find Number."<<endl;
        cout<<"3. Find Name."<<endl;
        cout<<"6. Exit."<<endl;
        cout<<"Enter choice :";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1: //Add New Record
                f.open("a.dat", ios_base::app | ios_base::binary);
                p.getData();
                f.write((char*)&p, sizeof(p));
                f.close();
                break;

            case 2: //Find Number
                f.open("a.dat", ios_base::in | ios_base::binary);
                f.seekg(0);
                cout<<"Enter ph to search:";
                cin>>temp_ph;

                while(!f.eof())
                {
                    f.read((char*)&p1, sizeof(p1));
                    trial1 = p1.ph/10000;
                    trial2 = temp_ph/10000;
                    if(trial1 == trial2)
                    {
                        cout<<"RECORD FOUND"<<endl;
                        cout<<"Name :"<<p1.name;
                        cout<<" Ph :"<<p1.ph;
                        break;
                    }

                }

                f.close();
                break;

            case 3: //Find Name
                f.open("a.dat", ios_base::in | ios_base::binary);
                cout<<"Enter the name you want to search:";
                cin>>temp_name;

                while(!f.eof())
                {
                    f.read((char*)&p1, sizeof(p1));
                    if(strcmp(p1.name, temp_name) == 0)
                    {
                        cout<<"RECORD FOUND"<<endl;
                        cout<<"Name :"<<p1.name;
                        cout<<" Ph :"<<p1.ph<<endl;
                        break;
                    }
                }
                break;

            case 6: //Exit
                while_counter = 0;
                break;
        }
    }

    return 0;
}
