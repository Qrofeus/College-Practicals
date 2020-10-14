#include<iostream>

using namespace std;

class password
{
	char pass[6],in;
	int n,i,num;
	int a1,a2,a3,a4,a5,a6;

	public:
	password()
	{
		for(i=0;i<6;i++)
		pass[i]=0;
	};

	void getchar();
	void length();
	void generate();
};

void password::getchar()
{
	cout<<"Enter Six Characters:\n";

	for(i=0;i<6;i++)
		cin>>pass[i];
}

void password::length()
{
	in='Y';

    do
	{
	cout<<"Enter the password length:\n";
	cin>>n;

	if(n<1 || n>6)
	{
		cout<<"Enter valid password length";
		in='N';
	}
	}while(in=='N');
}

void password::generate()
{
	num=0;
	cout<<"All possible passwords for selected characters are:\n\n";
	switch(n)
	{
		case 1:
			for(a1=0;a1<6;a1++)
			{
			cout<<pass[a1]<<endl;
			num++;
			}
			break;
		case 2:
			for(a1=0;a1<6;a1++)
			for(a2=0;a2<6;a2++)
			{
			if(a2!=a1)
			{
                cout<<pass[a1]<<"-"<<pass[a2]<<endl;
                num++;}
			}
			break;
		case 3:
			for(a1=0;a1<6;a1++)
			for(a2=0;a2<6;a2++)
			for(a3=0;a3<6;a3++)
			{
			if(a3!=a1&&a3!=a2&&a2!=a1)
			{
                cout<<pass[a1]<<"-"<<pass[a2]<<"-"<<pass[a3]<<endl;
                num++;
            }
			}
			break;
		case 4:
			for(a1=0;a1<6;a1++)
			for(a2=0;a2<6;a2++)
			for(a3=0;a3<6;a3++)
			for(a4=0;a4<6;a4++)
			{
			if(a4!=a1&&a4!=a2&&a4!=a3&&a3!=a1&&a3!=a2&&a2!=a1)
			{
			    cout<<pass[a1]<<"-"<<pass[a2]<<"-"<<pass[a3]<<"-"<<pass[a4]<<endl;
                num++;
            }
			}
			break;
		case 5:
			for(a1=0;a1<6;a1++)
			for(a2=0;a2<6;a2++)
			for(a3=0;a3<6;a3++)
			for(a4=0;a4<6;a4++)
			for(a5=0;a5<6;a5++)
			{
			if(a5!=a1&&a5!=a2&&a5!=a3&&a5!=a4&&a4!=a1&&a4!=a2&&a4!=a3&&a3!=a1&&a3!=a2&&a2!=a1)
			{
			    cout<<pass[a1]<<"-"<<pass[a2]<<"-"<<pass[a3]<<"-"<<pass[a4]<<"-"<<pass[a5]<<endl;
                num++;
            }
			}
			break;
		case 6:
			for(a1=0;a1<6;a1++)
			for(a2=0;a2<6;a2++)
			for(a3=0;a3<6;a3++)
			for(a4=0;a4<6;a4++)
			for(a5=0;a5<6;a5++)
			for(a6=0;a6<6;a6++)
			{
			if(a6!=a1&&a6!=a2&&a6!=a3&&a6!=a4&&a6!=a5&&a5!=a1&&a5!=a2&&a5!=a3&&a5!=a4&&a4!=a1&&a4!=a2&&a4!=a3&&a3!=a1&&a3!=a2&&a2!=a1)
			{
			    cout<<pass[a1]<<"-"<<pass[a2]<<"-"<<pass[a3]<<"-"<<pass[a4]<<"-"<<pass[a5]<<"-"<<pass[a6]<<endl;
                num++;
			}
			}
			break;
	}
	cout<<"Total number of passwords available are: "<<num<<endl<<endl;
}

int main()
{
    char cont,out;
    cont='N';
    out='N';
	password p;

	do
    {
        p.getchar();
        do
        {
            p.length();
            p.generate();

            cout<<"Do you want to select different length of password? (Y/N)\n";
            cin>>cont;
        }while(cont=='y' || cont=='Y');
        cout<<"Do you want to select another set of characters? (Y/N)\n";
        cin>>out;
    }while(out=='Y' || out=='y');

	return 0;
}
