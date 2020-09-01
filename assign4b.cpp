//============================================================================
// Name        : assign4b.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class member_node
{
	int PRN;
	string name;
	member_node* link;
	friend class club;

public:
	member_node()
	{
		PRN = 0;
		link = NULL;
	}
};

class club
{
	member_node* precident;
	member_node* secreatery;
	member_node* temp;

public:
	club()
	{
		precident = NULL;
		secreatery = NULL;
	}

	void add_member()
	{
		int n, p;
		cout << "where do you want to enter" << endl;
		cout << "1. president" << endl;
		cout << "2.Secretary" << endl;
		cout << "3.general member" << endl;
		cin >> n;
		member_node* t = new member_node();

		switch (n)
		{
		case 1:
			cout << "name:" << endl;
			cin >> t->name;
			cout << "PRN:" << endl;
			cin >> t->PRN;


			if (precident == NULL)
			{
				precident = t;
			}
			else
			{
				t->link = precident;
				precident = t;

			}
			break;

		case 2:
			cout << "name:" << endl;
			cin >> t->name;
			cout << "PRN:" << endl;
			cin >> t->PRN;

			secreatery = t;

			precident->link = secreatery;
			break;

		case 3:
			cout << "name:" << endl;
			cin >> t->name;
			cout << "PRN:" << endl;
			cin >> t->PRN;

			cout << "enter position:" << endl;
			cin >> p;

			member_node* pre = precident;
			int count = 1;
			while (count < p - 1 && pre != NULL)
			{
				pre = pre->link;
				count++;
			}
			t->link = pre->link;
			pre->link = t;

			break;
		}

	}

	void del()
	{
		int prn1;
		cout << "which member you want to delete" << endl;
		member_node* temp, * prev = NULL;
		cin >> prn1;

		temp = precident;

		if (precident == NULL)
		{
			cout << "underflow" << endl;
		}
		else if (temp->PRN == prn1)
		{
			precident = precident->link;
			temp->link = NULL;
			delete(temp);
		}
		else
		{
			if (precident->link == NULL)
			{
				cout << "data not found" << endl;
			}
			else
			{
				while (temp->link != secreatery)
				{
					prev = temp;
					temp = temp->link;
					if (temp->PRN == prn1)
					{
						prev->link = temp->link;
						temp->link = NULL;
						delete(temp);
						break;
					}
				}
				if (secreatery->PRN == prn1)
				{
					delete(secreatery);
					secreatery = temp;
					secreatery->link = NULL;
				}
			}
		}
	}


	void display()
	{
		member_node* temp;
		temp = precident;

		while (temp != NULL)
		{
			cout << temp->name << "  " << temp->PRN;
			temp = temp->link;
			if (temp != NULL)
				cout << " -> ";
		}
		cout << endl;
	}

	void reverse(member_node* t)
	{
		if (t == NULL)
		{
			return;
		}
		else
		{
			reverse(t->link);
			cout << t->name << " " << t->PRN << " -> ";
		}
		cout << endl;
	}

	club concatenate(club c2)
	{
		club c3;

		member_node *current;
		member_node *previous;
		member_node *new1=new member_node;

		temp = precident;
		new1->name = temp->name;
		new1->PRN = temp->PRN;
		c3.precident = new1;

		current = temp->link;
		previous = c3.precident;

		while(current != NULL)
		{
			member_node *new2=new member_node;
			new2->name = current->name;
			new2->PRN = current->PRN;
			previous->link = new2;
			previous = previous->link;
			current = current->link;
		}

		current = c2.precident;

		while(current != NULL)
		{
			member_node *new2=new member_node;
			new2->name = current->name;
			new2->PRN = current->PRN;
			previous->link = new2;
			previous = previous->link;
			current = current->link;
		}

		c3.secreatery = previous;

		return c3;
	}

	club concatenate(club c2)
	{
		club c3;

		member_node* current;
		member_node* previous;
		member_node* new1 = new member_node;

		temp = precident;
		new1->name = temp->name;
		new1->PRN = temp->PRN;
		c3.precident = new1;

		current = temp->link;
		previous = c3.precident;

		while (current != NULL)
		{
			member_node* new2 = new member_node;
			new2->name = current->name;
			new2->PRN = current->PRN;
			previous->link = new2;
			previous = previous->link;
			current = current->link;
		}

		current = c2.precident;

		while (current != NULL)
		{
			member_node* new2 = new member_node;
			new2->name = current->name;
			new2->PRN = current->PRN;
			previous->link = new2;
			previous = previous->link;
			current = current->link;
		}

		c3.secreatery = previous;

		return c3;
	}

	club sort(club c2)
	{
		club c3;

		member_node* p1;
		member_node* p2;
		member_node* p3;

		p1 = precident;
		p2 = c2.precident;
		p3 = c3.precident;


		if (p1->PRN < p2->PRN)
		{
			member_node* new1 = new member_node;
			new1->name = p1->name;
			new1->PRN = p1->PRN;
			p3 = new1;
			p1 = p1->link;
		}
		else
		{
			member_node* new1 = new member_node;
			new1->name = p2->name;
			new1->PRN = p2->PRN;
			p3 = new1;
			p2 = p2->link;
		}

		while (p1 != NULL && p2 != NULL)
		{
			member_node* new1 = new member_node;
			if (p1->PRN < p2->PRN)
			{
				new1->name = p1->name;
				new1->PRN = p1->PRN;
				p3->link = new1;
				p1 = p1->link;
				p3 = p3->link;
			}
			else
			{
				new1->name = p2->name;
				new1->PRN = p2->PRN;
				p3->link = new1;
				p2 = p2->link;
				p3 = p3->link;
			}
		}

		while (p1 != NULL)
		{
			member_node* new2 = new member_node;
			new2->name = p1->name;
			new2->PRN = p1->PRN;
			p3->link = new2;
			p1 = p1->link;
			p3 = p3->link;
		}

		while (p2 != NULL)
		{
			member_node* new2 = new member_node;
			new2->name = p2->name;
			new2->PRN = p2->PRN;
			p3->link = new2;
			p2 = p2->link;
			p3 = p3->link;
		}

		c3.secreatery = p3;
		p3->link = NULL;
		c3.display();

		return c3;
	}

	member_node* getprecident()
	{
		return precident;
	}

};

int main()
{
	int n, t = 0;
	club c, c2, c3;

	while (t != 7)
	{
		cout << "what is the update?" << endl;
		cout << "1.add member" << endl;
		cout << "2.display member list" << endl;
		cout << "3.remove member" << endl;
		cout << "4.reverse list of members" << endl;
		cout << "5.merge two clubs" << endl;
		cout << "6.merge two sorted liste of clubs" << endl;
		cout << "7.exit" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			cout << "how many members want to join?" << endl;
			cin >> n;
			for (int i = 0; i < n; i++)
				c.add_member();
			break;

		case 3:
			c.del();
			c.display();
			break;

		case 2:
			c.display();
			break;

		case 4:
			c.reverse(c.getprecident());
			break;

		case 5:
			cout << "enter details for cub 2" << endl;
			cout << "how many members want to join?" << endl;
			cin >> n;
			for (int i = 0; i < n; i++)
				c2.add_member();
			c2.display();
			c3 = c.concatenate(c2);
			cout << "outside" << endl;
			c3.display();
			break;

		case 6:
			cout << "enter details for club 2" << endl;
			cout << "how many members want to join?" << endl;
			cin >> n;
			for (int i = 0; i < n; i++)
				c2.add_member();
			c2.display();
			c3 = c.sort(c2);
			c3.display();
			break;

		case 7:
			cout << "ta da !!" << endl;
			break;

		default:
			cout << "enter a valid choice" << endl;
			break;
		}
	}


	return 0;

}
