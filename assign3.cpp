//============================================================================
// Name        : assign3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class sparsemat
{
	int sparmat[20][3];
	int mat[20][20];
	int row,col;
	int srow;


public:
	void getmatrix()
	{
		cout<<"enter number of rows and collom"<<endl;
		cin>>row>>col;
		cout<<"enter a matrix"<<endl;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				cin>>mat[i][j];
			}
		}
	}

	void spmat()
	{
		int k=1;
		sparmat[0][2]=0;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(mat[i][j]!=0)
				{
					sparmat[k][0]=i;
					sparmat[k][1]=j;
					sparmat[k][2]=mat[i][j];
					sparmat[0][2]+=1;
					k+=1;
				}
			}
		}

	}

	void dispmat()
	{
		sparmat[0][0]=row;
		sparmat[0][1]=col;
		srow=sparmat[0][2];

		for(int i=0;i<=srow;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<sparmat[i][j]<<" ";
			}
			cout<<endl;
		}

	}

	sparsemat addition(sparsemat q)
	{
		 sparsemat p;
		 if(row==q.row && col==q.col)
		 {
			 p.row=row;
			 p.col=col;

			 p.sparmat[0][0]=row;
			 p.sparmat[0][1]=col;
			 p.sparmat[0][2]=0;

			 int i=1,j=1,k=1;

			 while(i<=sparmat[0][2] && j<=q.sparmat[0][2])
			 {
				 if(sparmat[i][0]==q.sparmat[j][0])
				 {
					 if(sparmat[i][1]==q.sparmat[j][1])
					 {
						 p.sparmat[k][0]=sparmat[i][0];
						 p.sparmat[k][1]=sparmat[i][1];
						 p.sparmat[k][2]=sparmat[i][2]+q.sparmat[j][2];
						 i+=1;
						 j+=1;
						 k+=1;
					 }
					 else if(sparmat[i][1]>q.sparmat[j][1])
					 {
						 p.sparmat[k][0]=q.sparmat[j][0];
						 p.sparmat[k][1]=q.sparmat[j][1];
						 p.sparmat[k][2]=q.sparmat[j][2];
						 j+=1;
						 k+=1;
					 }
					 else
					 {
						 p.sparmat[k][0]=sparmat[i][0];
						 p.sparmat[k][1]=sparmat[i][1];
						 p.sparmat[k][2]=sparmat[i][2];
						 i+=1;
						 k+=1;
					 }
					 p.sparmat[0][2]+=1;

				 }
				 else if(sparmat[i][0]>q.sparmat[j][0])
				 {
					 p.sparmat[k][0]=q.sparmat[j][0];
					 p.sparmat[k][1]=q.sparmat[j][1];
					 p.sparmat[k][2]=q.sparmat[j][2];
					 j+=1;
				 	 k+=1;
				 	p.sparmat[0][2]+=1;
				 }
				 else
				 {
					 p.sparmat[k][0]=sparmat[i][0];
					 p.sparmat[k][1]=sparmat[i][1];
				 	 p.sparmat[k][2]=sparmat[i][2];
				 	 i+=1;
				 	 k+=1;
				 	p.sparmat[0][2]+=1;
				 }
			 }
			 if(i>sparmat[0][2] && j<=q.sparmat[0][2])
			 {
				 while(j<=q.sparmat[0][2])
				 {
					 p.sparmat[k][0]=q.sparmat[j][0];
					 p.sparmat[k][1]=q.sparmat[j][1];
					 p.sparmat[k][2]=q.sparmat[j][2];
					 j+=1;
					 k+=1;
				 }
				 p.sparmat[0][2]+=1;
			 }
			 if(i<=sparmat[0][2] && j>q.sparmat[0][2])
			 {
				 while(i<=sparmat[0][2])
				 {
					 p.sparmat[k][0]=sparmat[i][0];
					 p.sparmat[k][1]=sparmat[i][1];
					 p.sparmat[k][2]=sparmat[i][2];
					 i+=1;
					 k+=1;
				 }
				 p.sparmat[0][2]+=1;

			 }
		 }
		 else
		 {
			 cout<<"addition is not possible"<<endl;
		 }
		 return p;
	}

	sparsemat transmat()
	{
		sparsemat t;
		int noc,nut,row_term[20],start_pos[20];

		t.srow=srow;
		t.sparmat[0][0]=sparmat[0][1];
		t.sparmat[0][1]=sparmat[0][0];
		t.sparmat[0][2]=sparmat[0][2];

		noc=sparmat[0][0];
		nut=sparmat[0][2];

		for(int i=0;i<noc;i++)
			row_term[i]=0;



		for(int j=1;j<=nut;j++)
		{
		row_term[sparmat[j][1]]++;
		}

		for(int i=0;i<nut;i++)
		{
			cout<<"row terms are: "<<row_term[i]<<endl;
		}

		start_pos[0]=1;
		for(int i=1;i<noc;i++)
		{
			start_pos[i]=start_pos[i-1]+row_term[i-1];
		}

		for(int i=0;i<noc;i++)
		{
			cout<<"starting positions are: "<<start_pos[i]<<endl;;
		}

		int j=0;
		for(int i=1;i<=nut;i++)
		{
			j=start_pos[sparmat[i][1]]++;

			t.sparmat[j][0]=sparmat[i][1];
			t.sparmat[j][1]=sparmat[i][0];
			t.sparmat[j][2]=sparmat[i][2];
		}
		return t;
	}

};

int main()
{
	sparsemat m,n,add,trans;
	int N;
	char choice;
	cout<<"matrix A:"<<endl;
	m.getmatrix();
	m.spmat();
	cout<<"sparse matrix of A is:"<<endl;
	m.dispmat();

	cout<<"matrix B:"<<endl;
	n.getmatrix();
	n.spmat();
	cout<<"sparse matrix of B is:"<<endl;
	n.dispmat();

	do
	{
		cout<<"which operation you want to perform?"<<endl;
		cout<<"1. Addition of A and B"<<endl;
		cout<<"2. Transpose of matrix A"<<endl;
		cout<<"3. Transpose of matrix B"<<endl;
		cin>>N;

		switch(N)
		{
		case 1:
			add=m.addition(n);
			cout<<"matrix A + matrix B is:"<<endl;
			add.dispmat();
			break;

		case 2:
			trans=m.transmat();
			cout<<"transpose of matrix A is:"<<endl;
			trans.dispmat();
			break;

		case 3:
			trans=n.transmat();
			cout<<"transpose of matrix B is:"<<endl;
			trans.dispmat();
			break;

		default:
			cout<<"enter a valid choice"<<endl;
			break;
		}

		cout<<"do you want to continue? Y or N"<<endl;
		cin>>choice;
		if(choice=='N')
		{
			cout<<"have a good day"<<endl;
		}
	}
	while(choice=='Y' && choice !='N');

	return 0;
}
