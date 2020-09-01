//============================================================================
// Name        : assign.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class terms
{
public:
	int expo;
	int coeff;
};
class polynomial
{
	terms poly[20];
	int n;
public:

	friend istream &operator>>(istream &in,polynomial &p)
	{
		cout<<"enter number of terms"<<endl;
		cin>>p.n;
		for(int i=0;i<p.n;i++)
		{
			cout<<"enter the coefficient and exponent"<<endl;
			in>>p.poly[i].coeff>>p.poly[i].expo;
		}
		return in;
	}

	friend ostream & operator<<(ostream &out,polynomial &p)
	{
		int count=p.n-1;
		cout<<"the polynomial is:"<<endl;

		for(int i=0;i<p.n;i++)
		{
			if(p.poly[i].coeff!=0)
			{
				if(p.poly[i].expo!=0)
				{
					cout<<p.poly[i].coeff<<"X^"<<p.poly[i].expo;
				}
				else
				{
					cout<<p.poly[i].coeff;
				}
				if(count==i)
				{
					break;
				}
			cout<<" + ";
			}
		}
		cout<<endl;
		return out;
	}

	int eval()
	{
		int X,eval;
		cout<<"enter X"<<endl;
		cin>>X;

		for(int i=0;i<n;i++)
		{
			eval+=poly[i].coeff*pow(X,poly[i].expo);
		}

		return eval;

	}

	polynomial add()
	{
		cout<<"enter second polynomial"<<endl;
		polynomial q,r;
		cin>>q;
		int i=0,j=0,k=0;

		r.n=0;

		while(i<n && j<q.n)
		{
			if(poly[i].expo==q.poly[j].expo)
			{
				r.poly[k].coeff=poly[i].coeff+q.poly[j].coeff;
				r.poly[k].expo=poly[i].expo;
				i++;
				j++;
				k++;
			}
			else if(poly[i].expo>q.poly[j].expo)
			{
				r.poly[k].coeff=poly[i].coeff;
				r.poly[k].expo=poly[i].expo;
				i++;
				k++;
			}
			else
			{
				r.poly[k].coeff=q.poly[j].coeff;
				r.poly[k].expo=q.poly[j].expo;
				j++;
				k++;
			}
		r.n++;
		}

			while(i<n)
			{
				r.poly[k].coeff=poly[i].coeff;
				r.poly[k].expo=poly[i].expo;
				i++;
				k++;
				r.n++;
			}

			while(j<q.n)
			{
				r.poly[k].coeff=q.poly[j].coeff;
				r.poly[k].expo=q.poly[j].expo;
				j++;
				k++;
				r.n++;
			}

		return r;

	}

	polynomial multiply()
		{
			polynomial q, r, s;
			int k = 0;
			cout << "enter the second polynomial" << endl;
			cin >> q;
			cout << q;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < q.n; j++)
				{
					r.poly[k].expo = poly[i].expo + q.poly[j].expo;
					r.poly[k].coeff = poly[i].coeff * q.poly[j].coeff;
					k++;
				}
			}
			r.n = k;
			for (int i = 0; i < r.n; i++)
			{
				s.poly[i].expo = r.poly[i].expo;
				s.poly[i].coeff = r.poly[i].coeff;
				for (int j = i + 1; j < r.n; j++)
				{
					if (r.poly[i].expo == r.poly[j].expo)
					{
						s.poly[i].coeff += r.poly[j].coeff;
						r.poly[j].coeff = 0;
					}
				}
			}
			s.n = r.n;
			cout << s;

			terms a;
			for (int i = 1; i < s.n; i++)
			{
				for (int j = i + 1; j < s.n; j++)
				{
					if (s.poly[i].expo < s.poly[j].expo)
					{
						a.expo = s.poly[i].expo;
						a.coeff = s.poly[i].coeff;
						s.poly[i].expo = s.poly[j].expo;
						s.poly[i].coeff = s.poly[j].coeff;
						s.poly[j].expo= a.expo;
						s.poly[j].coeff= a.coeff;
					}
				}
			}

			return s;
		}

};

int main()
{
	int result,N;
	polynomial p,add,mul;


	do
	{
		cout<<"choose 1 option"<<endl;
		cout<<"1. accept polynomial"<<endl;
		cout<<"2. evaluate the polynomial at a value of X"<<endl;
		cout<<"3. add two polynomial"<<endl;
		cout<<"4. multiply two polynomial"<<endl;
		cout<<"5. exit"<<endl;
		cin>>N;

		switch(N)
		{
		case 1:
			cin>>p;
			cout<<p;
			break;

		case 2:
			result=p.eval();
			cout<<"the resultant polynomial is:"<<result<<endl;
			break;

		case 3:
			add=p.add();
			cout<<add;
			break;

		case 4:
			mul=p.multiply();
			cout<<mul;
			break;

		case 5:
			break;

		default:
			break;
		}
	}
	while(N!=5);



	return 0;
}
