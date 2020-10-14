/*

ASSIGNMENT 5

SE COMPUTER II
NINAD DESHPANDE
Roll No: 10
Batch: S1

Question:

An m x n matrix is said to have a saddle point if some entry a[i][j] is the smallest value in row 'i' and the largest value in 'j'.
Write C/ C++ program that determines the location and value of a saddle point if one exists.

*/

#include<iostream>

using namespace std;

class saddle
{
    private:
        int matrix[10][10];
	public:
			int m,n;
		saddle()
		{
			for(int r=0;r<10;r++)
			    for(int c=0;c<10;c++)
			        matrix[r][c]=0;
		};
		void getdata();
		void row(int r);
		int col(int c);
};

void saddle::getdata()
{
	cout<<"Enter the size of matrix (m , n):\n";
	cin>>m>>n;

	cout<<"Enter the elements of the matrix:\n";
	for(int r=0;r<m;r++)
	{
		for(int c=0;c<n;c++)
		{
			cout<<"Enter the element for matrix: ["<<r+1<<"]["<<c+1<<"]: ";
			cin>>matrix[r][c];
		}
	}
}

void saddle::row(int r)
{
    int c=0;
    int _min=matrix[r][0];
    for(int i=0;i<n;i++)
    {
        if(_min>matrix[r][i])
        {
            _min-matrix[r][i];
            c=i;
        }
    }
    if(_min==col(c))
        cout<<"Saddle Point is "<<matrix[r][c]<<"\nLocated at "<<r+1<<"x"<<c+1;
}

int saddle::col(int c)
{
    int _max=matrix[0][c];
    for(int i=0;i<m;i++)
        if(_max<matrix[i][c])
            _max=matrix[i][c];

    return _max;
}

int main()
{
	saddle a;

	a.getdata();
	for(int p=0;p<a.n;p++)
        a.row(p);
}
