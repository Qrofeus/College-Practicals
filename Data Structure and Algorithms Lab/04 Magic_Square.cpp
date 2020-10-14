/*
 * Assignment 4
 *
 * SE COMPUTER II
 * NINAD DESHPANDE
 * ROll No: 10
 * Batch: S1
 *
 * Question:
 * A magic square is a n x n matrix of integers i to n^2 such that the sum of each row, column and diagonal is the same.
 * Write a C++ program for generating a Magic Square.
 *
 */

#include<iostream>

using namespace std;

class msquare
{
	int square[11][11],n;
	int i,j,r,c,m;

public:
	void getdata()
	{
		cout<<"Enter an odd number (<12):\n";
		cin>>n;
	};

	msquare()
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				square[i][j]=0;
			}
		}
	};

	void arrange()
	{
		r=n/2;
		c=n-1;

		square[r][c]=1;

		for(m=2;m<=n*n;m++)
		{
			r--;
			c++;

			if(r==-1 && c==n)
			{
				r=0;
				c=n-2;
			}
			else
			{
				if(r==-1)
				{
					r=n-1;
				}
				else
				{
					if(c==n)
					{
						c=0;
					}
				}
			}
			if(square[r][c]!=0)
			{
				r++;
				c-=2;
			}

			square[r][c]=m;
		}
	};

	void display()
	{
		int sum;

		sum=0;

		cout<<"The Magic Square of "<<n<<"x"<<n<<" is:\n";

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j==0)
				cout<<"\n";

				cout<<square[i][j]<<"\t";
			}
		}

		cout<<"\n\nThe Sum of all number in any Row, Column or Diagonal is:\n";
		cout<<"n[(n*n)+1]\n";
		sum=n*(n*n+1);
		cout<<sum<<"\n\n";
	};
};

int main()
{
	msquare m;

	m.getdata();
	m.arrange();
	m.display();

	return 0;
}
