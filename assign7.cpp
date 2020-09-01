//============================================================================
// Name        : assign7.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int N=20;

class stack
{
	int top;
	char A[20];

public:
	stack()
	{
		top=-1;
	}

	void push(char ch)
	{
		if(top==N-1)
		{
			cout<<"overflow"<<endl;
		}
		else
		{
			top++;
			A[top]=ch;
		}
	}

	char pop()
	{
		char item;

		if(top==-1)
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			item = A[top];
			top--;
		}

		return item;
	}

	bool isempty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}

	bool isfull()
	{
		if(top==N-1)
			return 1;
		else
			return 0;
	}

	void check_error()
	{
		char B[20];
		int i=0,n=0;

		while(B[i-1] != '.')
		{
			cin>>B[i];
			i++;
			n++;
		};
		n-=1;

		for(int i=0;i<n;i++)
		{
			if(B[i] == '(' || B[i] == '{' || B[i] =='[')
			{
				push(B[i]);
			}
			else if(B[i]== ')' || B[i]== '}' || B[i]== ']')
			{
				char temp=pop();
				if((B[i]==')' && temp == '(' ) || (B[i]=='}' && temp == '{') || (B[i]==']' && temp == '['))
				{
					if( isempty() && (i==n-1))
					{
						cout<<"NO ERROR"<<endl;
						break;
					}
					else
						continue;
				}
				else
				{
					cout<<"ERROR"<<endl;
				}
			}
			else
				continue;
		}

		if(isempty())
			return;
		else
			cout<<"ERROR"<<endl;
	}

};

int main()
{
	stack s;
	int a,choice,p;
	char ch;

	while(choice!=6)
	{
		cout<<"what do you want to perform with this stack?"<<endl;
		cout<<"1.Add element."<<endl;
		cout<<"2.delete element."<<endl;
		cout<<"3.check if list is empty"<<endl;
		cout<<"4.check if list is full"<<endl;
		cout<<"5.check error in a expression"<<endl;
		cout<<"6.exit";
		cin>>choice;

		switch (choice)
		{
		case 1:

			cout<<"how many elements do you want to add"<<endl;
			cin>>a;

			while(a!=0)
			{
				cout<<"enter element"<<endl;
				cin>>ch;
				s.push(ch);
				a--;
			}

			break;

		case 2:

			cout<<"how man elements do you want to delete"<<endl;
			cin>>a;

			while(a!=0)
			{
				s.pop();
				a--;
			}

			break;

		case 3:

			p=s.isempty();

			if(p==1)
				cout<<"EMPTY"<<endl;
			else
				cout<<"NOT EMPTY"<<endl;

			break;

		case 4:

			p=s.isfull();

			if(p==1)
				cout<<"FULL"<<endl;
			else
				cout<<"NOT FULL"<<endl;

			break;

		case 5:

			cout<<"enter a expression"<<endl;
			s.check_error();
			break;

		case 6:

			cout<<"ta da!!"<<endl;
			break;

		}
	}

		return 0;
}
