//============================================================================
// Name        : assign1.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

class student
{
	int rollno;
	char name[30];
	int marks;
	bool attendence;

public:
	int n;
	int getmarks()
	{
		return marks;
	}
	char getname()
	{
		return name[30];
	}
	int getrollno()
	{
		return rollno;
	}
	bool getattendence()
	{
		return attendence;
	}
	void getstudentdata()
	{
		cout<<"roll no."<<endl;
		cin>>rollno;
		cout<<"name"<<endl;
		cin>>name;
		cout<<"present or absent"<<endl;
		cin>>attendence;
		if(attendence==1)
		{
		cout<<"score out of 100"<<endl;
		cin>>marks;
		}
		else
		{
			marks=0;
		}
	}
	void displaystudent()
	{
		cout<<rollno<<" "<<name<<" "<<marks<<endl;
	}
};

class marksheet
{
	student s[10];

public:
	int n,sum=0;
	float avg;
	void getstudentlist()
	{
		cout<<"enter number of students in the class";
		cin>>n;

		for(int i=0;i<n;i++)
		{
			s[i].getstudentdata();
		}

		for(int i=0;i<n;i++)
		{
			s[i].displaystudent();
		}
	}

	void getavg()
	{
		for(int i=0;i<n;i++)
		{
			if(s[i].getattendence()==true)
			{
			sum=sum+s[i].getmarks();
			}
		}
		avg=sum/n;
		cout<<"average score of class is"<<avg<<endl;
	}

	void min_max()
	{
		int min=101,max=-1;

		for(int x=0;x<n;x++)
			{
				if(s[x].getmarks()>max)
				{
					max=s[x].getmarks();
				}
			}
			cout<<"\n\n highest marks scored are "<<max<<endl;;

			for(int y=0;y<n;y++)
			{
				if(s[y].getattendence()==true)
				{
					if(s[y].getmarks()<min)
					{
						min=s[y].getmarks();
					}
				}
			cout<<"lowest marks scored are "<<min<<endl;;

				}
	}

	void frequent_marks()
	{
		int count[n];
		int temp,freq=0;
		for(int p=0;p<n;p++)
		{
			if(s[p].getattendence()==true)
			{
				count[p]=0;
				temp=s[p].getmarks();
				for(int q=0;q<n;q++)
				{
					if(s[q].getattendence()==true)
					{
						if(temp==s[q].getmarks())
						{
							count[p]+=1;
						}
						if(count[p]>freq)
						{
							freq=count[p];
							cout<<"\n"<<temp<<" "<<freq<<"  "<<endl;
						}
					}
				}
			}
		}
	}


	void absent()
	{
		for(int k=0;k<n;k++)
		{
			if(s[k].getattendence()==false)
			{
				cout<<s[k].getrollno()<<" "<<s[k].getname()<<endl;
			}
		}
	}
};

int main()
{
	marksheet ms;

	ms.getstudentlist();

	int ch=1;

    while(ch!=5)
    {
    	cout<<"\n Choose any one option:"<<endl;
		cout<<"1. average marks"<<endl;
		cout<<"2. minimum and maximum score"<<endl;
		cout<<"3. most frequest marks"<<endl;
		cout<<"4. list of abscent students"<<endl;
		cout<<"5. Exit"<<endl;
		cin>>ch;
			switch(ch)
			{
				case 1:
				ms.getavg();
				break;

				case 2:
				ms.min_max();
				break;

				case 3:
				ms.frequent_marks();
				break;

				case 4:
				ms.absent();
				break;

				case 5:
				break;

				default:
				cout<<"please enter a valid option.";
				break;
			}
    }
	return 0;
}
