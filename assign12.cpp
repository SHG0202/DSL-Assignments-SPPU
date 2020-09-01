//============================================================================
// Name        : assign12.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class student
{
	string name;
	float percentage;
	friend class SORT;

public:
	student()
	{
		percentage = 0;
	}

	bool operator >(student &s1)
	{
		return (percentage>s1.percentage);
	}

	void display()
	{
		cout<<"NAME : "<<name<<"  -->  "<<percentage<<endl;
	}
};


class SORT
{
	int N;
	student *st;

public:
	SORT(int n)
	{
		N = n;
		st = new student[n];

		for(int i=0;i<N;i++)
		{
			cout<<"Student "<<i+1<<":"<<endl;
			cout<<"NAME : ";
			cin>>st[i].name;
			cout<<"SCORE : ";
			cin>>st[i].percentage;
		}
	}

	void BUBBLE_SORT()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N-i-1;j++)
			{
				if(st[j] > st[j+1])
					swap(st[j], st[j+1]);
			}
		}
	}

	void SELECTION_SORT()
	{
		int min_index;
		for(int i=0;i<N;i++)
		{
			min_index = i;
			for(int j=i+1;j<N;j++)
			{
				if(st[min_index]>st[j])
					min_index = j;
			}
			swap(st[i], st[min_index]);
		}
	}

	void INSERTION_SORT()
	{
		for(int i=1;i<N;i++)
		{
			int j = i-1;

			while((st[j] > st[i]) && (j >= 0))
			{
				st[j+1] = st[j];
				j--;
			}

			st[j+1] = st[i];
		}
	}

	void SHELL_SORT()
	{
		int interval;
		student temp;
		for(interval = 3; interval !=0 ; interval--)
		{
			for(int i=interval-1;i<N;i++)
			{
				temp = st[i];
				int j = i-interval;

				while((st[j] > temp) && (j >= 0))
				{
					st[j+interval] = st[j];
					j-=interval;
				}

				st[j+interval] = temp;
			}
		}
	}

	void QUICK_SORT(int low,int high)
	{
		int i,j;
		student pivot;

		if(low >= high)
			return;
		else
		{
			pivot = st[low];
			i = low + 1;
			j = high;

			do
			{
				while((pivot > st[i]) && (i <= high))
					i++;
				while((st[j] > pivot) && (j >= low))
					j--;
				if(i<j)
				{
					swap(st[i], st[j]);
					i++;
					j--;
				}
			}while(i <= j);

			swap(st[low], st[j]);
			QUICK_SORT(low,j-1);
			QUICK_SORT(j+1,high);
		}
	}

	void display()
	{
		cout<<"TOP SCORERS:"<<endl;
		for(int i=N-1;(i>N-6 && i>=0);i--)
		{
			st[i].display();
		}
		cout<<endl;
	}
};

int main()
{
	int N,option;
	cout<<"How many elements do you want to sort ?"<<endl;
	cin>>N;

	do
	{
		cout<<"Which sorting technique do you want to use ?"<<endl;
		cout<<"1. BUBBLE SORT"<<endl;
		cout<<"2. SELECTION SORT"<<endl;
		cout<<"3. INSERTION SORT"<<endl;
		cout<<"4. SHELL SORT"<<endl;
		cout<<"5. QUICK SORT"<<endl;
		cout<<"6. EXIT"<<endl;
		cin>>option;

		cout<<"enter marks"<<endl;
		SORT s(N);

		switch(option)
		{
		case 1:
			s.BUBBLE_SORT();
			s.display();
			break;

		case 2:
			s.SELECTION_SORT();
			s.display();
			break;

		case 3:
			s.INSERTION_SORT();
			s.display();
			break;

		case 4:
			s.SHELL_SORT();
			s.display();
			break;

		case 5:
			s.QUICK_SORT(0,N-1);
			s.display();
			break;

		case 6:
			break;

		default:
			cout<<"select a valid option"<<endl;
		}

	}while(option != 6);

	return 0;
}
