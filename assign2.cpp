//============================================================================
// Name        : assign2.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class matrix
{
	int row,collom;
	int mat[3][3];

public:
	void getmatrix()
	{
		cout<<"no. of rows="<<endl;
		cin>>row;
		cout<<"no. of collom="<<endl;
		cin>>collom;

		cout<<"enter elements of matrix"<<endl;

		for(int i=0;i<row;i++)
		{
			for(int j=0;j<collom;j++)
			{
				cin>>mat[i][j];
			}
		}

	}

	void dispmatrix()
	{
		cout<<"matrix is:"<<endl;

		for(int i=0;i<row;i++)
				{
					for(int j=0;j<collom;j++)
					{
						cout<<mat[i][j];
						cout<<" ";
					}
					cout<<endl;
				}

	}

	void trimatrix()
	{
		int count=0;
		if(row==collom)
		{
			for(int i=1;i<row;i++)
					{
						for(int j=0;j<i;j++)
						{
							if(mat[i][j]==0)
							{
								count+=1;
							}
						}
					}
			if(count==3)
			{
				cout<<"it is upper triangular matrix"<<endl;
			}
			else
			{
				cout<<"it is not a upper triangular matrix"<<endl;
			}
		}
		else
		{
			cout<<"it is not a square martix"<<endl;
		}
	}

	void sum_di()
	{
		int sum=0;
		for(int i=0;i<row;i++)
		{
			sum+=mat[i][i];
		}
		cout<<"sum of diagonal elements is:"<<sum<<endl;
	}

	void transmatrix()
	{
		matrix tmat;
		tmat.row=collom;
		tmat.collom=row;

		for(int i=0;i<row;i++)
				{
					for(int j=0;j<collom;j++)
					{
						tmat.mat[j][i]=mat[i][j];
					}
				}

		tmat.dispmatrix();
	}

	void addition(matrix p)
		{
			matrix q, r;
			cout<<"we need second matrix"<<endl;
			q.getmatrix();


			if(q.row==p.row && p.collom==q.collom)
			{
				for(int i=0;i<row;i++)
					{
						for(int j=0;j<collom;j++)
							{
								r.mat[i][j]=p.mat[i][j]+q.mat[i][j];
							}
					}
				r.row=p.row;
				r.collom=p.collom;
				r.dispmatrix();
			}
			else
			{
				cout<<"please enter a valid matrix"<<endl;
			}

		}

	void subtract(matrix p)
		{
			matrix q, r;
			cout<<"we need second matrix"<<endl;
			q.getmatrix();

			if(q.row==p.row && q.collom==p.collom)
			{
				for(int i=0;i<row;i++)
					{
						for(int j=0;j<collom;j++)
						{
							r.mat[i][j]=p.mat[i][j]-q.mat[i][j];
						}
					}
			r.row=p.row;
			r.collom=p.collom;
			r.dispmatrix();
			}
			else
			{
				cout<<"please enter a valid matrix"<<endl;
			}

		}

	void multiply(matrix p)
	{
     matrix q, r;
	 int t;
	 cout<<"we need second matrix"<<endl;
	 q.getmatrix();

	 if(p.collom==q.row)
	  {
		for(int i=0;i<row;i++)
		{
		 for(int j=0;j<collom;j++)
		 {
		   r.mat[i][j]=0;
			for(t=0;t<collom;t++)
			{
			r.mat[i][j]=r.mat[i][j]+(p.mat[i][t]*q.mat[t][j]);
			}
		 }
		}
			r.row=p.row;
			r.collom=q.collom;
			r.dispmatrix();
	  }
		else
		{
			cout<<"please enter a valid matrix"<<endl;
		}

	}

	void saddle()
	{
		int c1,c2,c3,p,q;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<collom;j++)
			{
				c1=0,c2=0;
				for(int l=0;l<collom;l++)
				{
					if(mat[i][j]<mat[i][l])
					{
						c1+=1;
					}
				}
				for(int m=0;m<row;m++)
				{
					if(mat[i][j]>mat[m][j])
					{
						c2+=1;
					}
				}
				if(c1==2 && c2==2)
				{
					c3+=1;
					p=i;
					q=j;
			}
		}
				}
		if(c3>0)
		{
			cout<<"saddle point is present in the matrix at the position "<<p<<","<<q<<endl;
			cout<<"it's value is "<<mat[p][q]<<endl;


		}
	}

};



int main()
{
	matrix a;
	a.getmatrix();
	a.dispmatrix();
	int x;

	while(x!=8)
	{
		cout<<"enter a choice:"<<endl;
		cout<<"1. to check if it is upper triangular matrix or not"<<endl;
		cout<<"2. to find the sum of diagonal elements"<<endl;
		cout<<"3. to find the transpose of given matrix"<<endl;
		cout<<"4. to find sum"<<endl;
		cout<<"5. to find difference"<<endl;
		cout<<"6. to find multiplication"<<endl;
		cout<<"7. to check if the matrix has a saddle point"<<endl;
		cout<<"8. EXIT"<<endl;
		cin>>x;

		switch(x)
		{
		case 1:
			a.trimatrix();
			break;

		case 2:
			a.sum_di();
			break;

		case 3:
			a.transmatrix();
			break;

		case 4:
			a.addition(a);
			break;

		case 5:
			a.subtract(a);
			break;

		case 6:
			a.multiply(a);
			break;

		case 7:
			a.saddle();
			break;

		case 8:
			break;

		default:
			cout<<"enter a valid choice:"<<endl;
			break;
		}
	}

	return 0;
}
