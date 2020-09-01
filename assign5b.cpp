//============================================================================
// Name        : assign5b.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
	int seat_no;
	node* prev;
	node* next;
	friend class cinemax;

public:
	node()
	{
		seat_no = 0;
		prev = next = NULL;
	}
};

class cinemax
{
	node* row[10];
	node* current;
	int seat;

public:
	cinemax()
	{
		for (int i = 0; i < 10; i++)
		{
			row[i] = NULL;
		}
		seat = 0;
		current = NULL;
	}

	void seats()
	{
		node* temp;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				node *new1 = new node;

				new1->seat_no = (j + 1);

				if (row[i] == NULL)
				{
					row[i] = new1;
				}
				else
				{
					temp = row[i];

					while (temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = new1;
					temp->next->prev = temp;
					temp = temp->next;
				}

			}
		}
	}

	void available()
	{
		node* temp = NULL;
		for (int i = 0; i < 10; i++)
		{
			cout << "ROW " << i << " : ";
			temp = row[i];
			for (int j = 0; j < 7; j++)
			{
				if (temp == NULL)
				{
					break;
				}
				cout << temp->seat_no << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void book(int r,int s)
	{
		node* temp = NULL;
		temp = row[r];
		if (temp == NULL)
		{
			cout << "no seats available in this row" << endl;
		}
		else if (temp->seat_no == s)
		{
			row[r] = temp->next;
			if(row[r]==NULL)
			{
				delete(temp);
				row[r]=NULL;
			}
			else
			{
				temp->next->prev = NULL;
				temp->next = NULL;
				delete(temp);
			}
		}
		else
		{
			temp = temp->next;
			while (temp->seat_no != s)
			{
				temp = temp->next;
			}
			if (temp->next == NULL)
			{
				temp->prev->next = NULL;
				temp->prev = NULL;
				delete(temp);
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				temp->next = NULL;
				temp->prev = NULL;
				delete(temp);
			}
		}
	}

	void cancle()
	{
		node* temp;
		int n, r, s;
		available();

		cout << "how many tickets do you want to cancle?" << endl;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cout << "enter row and seat" << endl;
			cin >> r >> s;

			temp = row[r];
			if (temp == NULL)
			{
				node* new1 = new node;
				new1->seat_no = s;
				row[r] = new1;
				temp = new1;
				temp->next=NULL;
			}
			else if (temp->seat_no > s)
			{
				node* new1 = new node;
				new1->seat_no = s;
				row[r] = new1;
				new1->next = temp;
				temp->prev = new1;
			}
			else
			{
				while (temp->seat_no < s && temp->next!=NULL)
				{
					temp = temp->next;
				}
				node* new1 = new node;
				if(temp->next!=NULL)
				{
					new1->seat_no = s;
					new1->next = temp;
					temp->prev->next = new1;
					new1->prev=temp->prev;
					temp->prev=new1;
				}
				else
				{
					new1->seat_no=s;
					temp->next=new1;
					new1->prev=temp;
					new1->next=NULL;
				}
			}
		}
	}

};


int main()
{
	cinemax c;
	c.seats();
	char resp;
	int n=0,row_no=0,seat_no=0,cine;

	cout << "welcome to CINEMAX" << endl;

	do
	{
		cout << "1. check available seats" << endl;
		cout << "2. book a seat" << endl;
		cout << "3. delete booking" << endl;
		cout << "4.exit" << endl;
		cin >> cine;

		switch (cine)
		{
		case 1:
			c.available();
			break;

		case 2:
			cout << "available seats" << endl;
			c.available();

			cout << "how many seats do you want to book?" << endl;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "enter row number and seat number" << endl;
				cin >> row_no >> seat_no;
				c.book(row_no, seat_no);
			}
			cout << "BOOKING SUCCESSFUL" << endl;
			break;

		case 3:
			c.cancle();
			cout << "tickets canclled" << endl;
			break;

		case 4:
			cout << "have a great day!" << endl;
			break;
		}
	}
	while (cine != 4);

	return 0;

}

