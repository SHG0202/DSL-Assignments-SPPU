//============================================================================
// Name        : assign11.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
using namespace std;

class student
{
	int roll_no;
	friend class searching;

public:
	student()
	{
		roll_no = 0;
	}
};

class searching
{
	int N;
	student* st;

public:
	searching(int n)
	{
		N = n;
		st = new student[N];
		cout << "ENTER all the Roll NO. who attended the Seminar" << endl;

		for (int i = 0; i < N; i++)
		{
			cin >> st[i].roll_no;
		}
	}

	bool LINEAR_SEARCH(int a, int x, int index)
	{
		switch (x)
		{
		case 1:
			int temp;

			for (int i = 0; i < N; i++)
			{
				temp = st[i].roll_no;
				if (a == temp)
				{
					cout << "FOUND!" << endl;
					return 1;
				}

				while (i == N - 1)
				{
					cout << "NOT FOUND" << endl;
					return 0;
				}
			}
			break;

		case 2:
			if(index >= N)
			{
				cout<<"Not Found"<<endl;
				return 0;
			}
			else if(st[index].roll_no == a)
			{
				cout<<"Found !"<<endl;
				return 1;
			}
			else
				LINEAR_SEARCH(a, 2, index+1);

			break;

		default:
			cout << "INVALID OPTION" << endl;
			break;
		}
		return 0;
	}

	bool SENTINAL_SEARCH(int a)
	{
		int last = st[N - 1].roll_no;
		st[N - 1].roll_no = a;

		int i = 0;
		while (st[i].roll_no != a)
			i++;

		st[N - 1].roll_no = last;

		if ((i < N - 1) || (a == st[N - 1].roll_no))
		{
			cout << "FOUND!" << endl;
			return 1;
		}
		else
		{
			cout << "NOT FOUND " << endl;
			return 0;
		}
		return 0;
	}

	bool BINARY_SEARCH(int beg , int end , int a) 
	{
		int mid;
		if (end >= beg)
		{
			mid = (beg + end) / 2;

			if (st[mid].roll_no == a)
			{
				cout << "Found at location " << mid << endl;
				return 1;
			}
			else if (st[mid].roll_no > a)
				BINARY_SEARCH(beg, mid - 1, a);
			else
				BINARY_SEARCH(mid + 1, end, a);
		}
		return 0;
	}

	bool FIBO_SEARCH(int a , int n)
	{
		int flag = 0, first = 0,last = N-1,loc = -1, index;

		while(flag != 1 && first <= last)
		{
			index = FIBO(n);

			if(a == st[index + first].roll_no)
			{
				flag = 1;
				loc = index;
				break;
			}
			else if(a > st[index + first].roll_no)
				first = first + index + 1;
			else
				last = first + index - 1;

			n = last - first + 1;
		}

		if(flag == 1)
		{
			cout<<"Item found at location "<<(loc + first + 1)<<endl;
			return 1;
		}
		else
		{
			cout<<"Not found "<<endl;
			return 0;
		}
		
	}

	int FIBO(int n)
	{
		int a = 1,b = 1, c = 1;

		if( n == 0 || n == 1)
			return 0;
		else
		{
			while(c < n)
			{
				c = a + b;
				a = b;
				b = c;
			}
		}
		return a;
	}
};

int main()
{
	int N, X, ele;
	int a,b;
	cout << "How many students appeared for the test ?" << endl;
	cin >> N;
	searching st(N);

	do
	{
		cout << "Which searching algorithm do you want to use ? " << endl;
		cout << "1. LINEAR SEARCH " << endl;
		cout << "2. SENTINAL SEARCH " << endl;
		cout << "3. BINARY SEARCH " << endl;
		cout << "4. FIBONACCI SEARCH " << endl;
		cout << "5. EXIT " << endl;
		cin >> X;

		switch (X)
		{
		case 1:
			a = clock();
			int x;
			cout << "which Roll_no do you wish to search" << endl;
			cin >> ele;
			cout<<"1. regular"<<endl;
			cout<<"2. recursive"<<endl;
			cin>>x;

			st.LINEAR_SEARCH(ele,x,0);
			b = clock();
			cout<<b-a<<endl;
			break;

		case 2:
			a = clock();
			cout << "which Roll_no do you wish to search" << endl;
			cin >> ele;
			st.SENTINAL_SEARCH(ele);
			b = clock();
			cout<<b-a<<endl;
			break;

		case 3:
			a = clock();
			cout << "which Roll_no do you wish to search" << endl;
			cin >> ele;
			st.BINARY_SEARCH(0, N - 1, ele);
			b = clock();
			cout<<b-1<<endl;
			break;

		case 4:
			a = clock();
			cout << "which Roll_no do you wish to search" << endl;
			cin >> ele;
			st.FIBO_SEARCH(ele , N);
			b = clock();
			cout<<b-a<<endl;
			break;

		case 5:
			cout << "have a nice day !!" << endl;
			break;

		default:
			cout << "select a valid option " << endl;
			break;
		}
	} while (X != 5);

	return 0;    
}
