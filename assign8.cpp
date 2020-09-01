//============================================================================
// Name        : assign8.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int N=20;

class STACK
{
	friend class expression;

	int top;
	char A[20];

public:
	STACK()
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

	void pop()
	{
		if(top==-1)
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			top--;
		}
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
	char peek()
	{
		return A[top];
	}
};

class expression
{
	STACK s;
	char input[N];
	char output[N];

public:

	void get_expression()
	{
		cout<<"enter expression"<<endl;
		cin>>input;
	}

	void infix_postfix()
	{
		int j=0;
		for(int i=0;input[i]!='\0';i++)
		{
			switch(input[i])
			{
			case '(':
				s.push(input[i]);
				break;

			case ')':
				while(s.peek() != '(')
				{
					output[j]=s.peek();
					j++;
					s.pop();
				}
				s.pop();
				break;

			case '+':case '-': case '*':case '/':
				while((!s.isempty()) && (s.peek() != '(') && (pre(input[i])<=pre(s.peek())))
				{
					output[j] = s.peek();
					j++;
					s.pop();
				}

				s.push(input[i]);
				break;


			default:
				output[j]=input[i];
				j++;
				break;

			}
		}
		while(s.top!=-1){
			output[j]=s.peek();
			j++;
			s.pop();
		}

		output[j]='\0';
	}

	int pre(char ch)
	{
		if(ch == '+' || ch == '-')
			return 1;
		if(ch == '*' || ch == '/')
			return 2;
		return 0;
	}

	void postfix_disp()
	{
		cout<<output;
	}

	char eval_post()
	{
		STACK st;

		int i = 0;
		char temp,result;

		do
		{
			temp = output[i];

			switch (temp)
			{
			case '+':case '-': case '*':case '/':
				char A, B;
				A = st.peek();
				st.pop();
				B = st.peek();
				st.pop();

				if (temp == '+')
					result = B + A;
				else if (temp == '-')
					result = B - A;
				else if (temp == '*')
					result = B * A;
				else
					result = B / A;

				st.push(result);
				break;

			default:
				st.push(temp);
				break;
			}
			i++;
		} while (temp != '\0');

		cout << result << endl;
		return result;
	}

};

int main()
{
	expression a;
	char result;
	a.get_expression();
	a.infix_postfix();
	a.postfix_disp();

	result = a.eval_post();

	cout << result << endl;


	return 0;
}
