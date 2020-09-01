//============================================================================
// Name        : assign6b.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class term
{
	int coeff;
	int expo;
	term *next;
	friend class polynomial;

public:
	term()
	{
		coeff=0;
		expo=0;
		next=NULL;
	}
};

class polynomial
{
	term *last;

public:
	polynomial()
	{
		last=NULL;
	}

	void getpoly()
	{
		start:
		term *new1=new term;

		cout<<"\n coeff: ";
		cin>>new1->coeff;

		cout<<"\n expo: ";
		cin>>new1->expo;

		if(new1->coeff!=0 && new1->expo!=-1)
		{
			if(last==NULL)
			{
				last=new1;
				last->next=last;
			}
			else
			{
				new1->next=last->next;
				last->next=new1;
				last=new1;
			}
			goto start;
		}
	}

	void display()
	{
		term *temp;
		temp=last->next;

		while(temp!=last)
		{
			if(temp->expo!=0)
			{
				cout<<temp->coeff<<" X^"<<temp->expo<<" + ";
			}
			else
			{
				cout<<temp->coeff<<endl;
			}
			temp=temp->next;
		}
		cout<<temp->coeff<<endl;
	}

	int eval(int a)
	{
		term *temp;
		int sum=0;
		temp=last->next;
		while(temp!=last)
		{
			sum+=(temp->coeff * (pow(a,temp->expo)));
			temp=temp->next;
		}
		sum+=temp->coeff;
		return sum;
	}

	polynomial addition(polynomial q)
	{
		polynomial r;
		term *temp1;
		term *temp2;

		temp1=last->next;
		temp2=q.last->next;
		r.last=NULL;


		term *new1=new term;
		if(temp1->expo>temp2->expo)
		{
			new1->coeff=temp1->coeff;
			new1->expo=temp1->expo;
			temp1=temp1->next;
		}
		else if(temp1->expo<temp2->expo)
		{
			new1->coeff=temp2->coeff;
			new1->expo=temp2->expo;
			temp2=temp2->next;
		}
		else
		{
			new1->coeff=temp1->expo+temp2->coeff;
			new1->expo=temp1->expo;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		r.last=new1;
		r.last->next=r.last;


		while(temp1!=last && temp2!=q.last)
		{
			term *new1=new term;

			if(temp1->expo>temp2->expo)
			{
				new1->coeff=temp1->coeff;
				new1->expo=temp1->expo;
				temp1=temp1->next;
			}
			else if(temp1->expo<temp2->expo)
			{
				new1->coeff=temp2->coeff;
				new1->expo=temp2->expo;
				temp2=temp2->next;
			}
			else
			{
				new1->coeff=temp1->coeff+temp2->coeff;
				new1->expo=temp1->expo;
				temp1=temp1->next;
				temp2=temp2->next;
			}


			new1->next=r.last->next;
			r.last->next=new1;
			r.last=new1;
		}

		while(temp1!=last->next)
		{
			term *new1=new term;
			new1->coeff=temp1->coeff;
			new1->expo=temp1->expo;
			temp1=temp1->next;

			new1->next=r.last->next;
			r.last->next=new1;
			r.last=new1;

		}

		while(temp2!=q.last->next)
		{
			term *new1=new term;
			new1->coeff=temp2->coeff;
			new1->expo=temp2->expo;
			temp2=temp2->next;

			new1->next=r.last->next;
			r.last->next=new1;
			r.last=new1;

		}


		return r;
	}
};

int main()
{
	polynomial p,q,add;
	int a,output,resp;

	do
	{
		cout<<"what operation do you wabt to perform?"<<endl;
		cout<<"1.accept a polynomial"<<endl;
		cout<<"2.display polynomial"<<endl;
		cout<<"3.evaluate polynomial at a value of X"<<endl;
		cout<<"4.add two polynomial"<<endl;
		cout<<"5.exit"<<endl;
		cin>>resp;

		switch(resp)
		{
		case 1:
			cout<<"enter the polynomial"<<endl;
			p.getpoly();
			break;

		case 2:
			p.display();
			break;

		case 3:
			cout<<"enter value of X"<<endl;
			cin>>a;
			output=p.eval(a);
			cout<<"at X = "<<a<<" value of polynoial is "<<output<<endl;
			break;

		case 4:
			cout<<"enter second polynomial"<<endl;
			q.getpoly();
			q.display();
			add=p.addition(q);
			add.display();
			break;

		case 5:
			cout<<"ta da!!"<<endl;
			break;
		}
	}
	while(resp!=5);



	return 0;
}
