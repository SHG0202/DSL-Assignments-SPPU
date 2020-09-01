//============================================================================
// Name        : assign10.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 10
using namespace std;

class deque
{
	int front;
	int rear;
	int A[max];

public:

	deque()
	{
		front = -1;
		rear = -1;
	}

	void insert_front(int element)
	{
		if(front == 0)
		{
			cout<<"cannot insert the element"<<endl;
		}
		else
		{
			if(front == -1)
			{
				front = 0;
				rear = 0;
			}
			else
			{
				front = front -1;
			}
		A[front] = element;

		}
	}

	void insert_rear(int element)
	{
		if(rear == max-1)
			cout<<"OVERFLOW"<<endl;
		else
		{
			if(front == -1)
				front = 0;
			rear = rear + 1;
			A[rear] = element;
		}
	}

	int delete_front()
	{
		int element;
		if((front == -1) || (front = rear + 1))
			cout<<"QUEUE is EMPTY"<<endl;
		else
		{
			element = A[front];
			front = front + 1;
		}
		return element;
	}

	int delete_rear()
	{
		int element;
		if((front == -1) || (front == rear + 1))
			cout<<"QUEUE is EMPTY"<<endl;
		else
		{
			element = A[rear];
			rear = rear - 1;
		}
		return element;
	}

	int get_front()
	{
		int front_ele;
		if((front == -1) || (front == rear + 1))
			cout<<"QUEUE is EMPTY"<<endl;
		else
			front_ele = A[front];

		return front_ele;
	}

	int get_rear()
	{
		int rear_ele;
		if((front == -1) || (front == rear + 1))
			cout<<"QUEUE is EMPTY"<<endl;
		else
			rear_ele = A[rear];

		return rear_ele;
	}

	bool is_empty()
	{
		if((front == -1) || (front == rear + 1))
			return 1;
		else
			return 0;
	}

	bool is_full()
	{
		if((front  == 0) && (rear == max-1))
			return 1;
		else
			return 0;
	}

	void display_front()
	{
		if(is_empty())
			cout<<"DQ is EMPTY"<<endl;
		else
		{
			int temp = front;
			while(temp != rear+1)
			{
				cout<<A[temp]<<"  "<<endl;
				temp++;
			}
		}
	}

	void display_rear()
	{
		if(is_empty())
			cout<<"DQ is EMPTY"<<endl;
		else
		{
			int temp = rear;
			while(temp != front-1)
			{
				cout<<A[temp]<<"  "<<endl;
				temp--;
			}
		}
	}
};

int main()
{
	deque DQ;
	int N;

	do
	{
		cout<<"WHAT OPERATION WILL YOU PERFORM ON A DEQUE ?"<<endl;
		cout<<"1. Insert element from FRONT end"<<endl;
		cout<<"2. Delete element from FRONT end"<<endl;
		cout<<"3. Insert element from REAR end"<<endl;
		cout<<"4. Delete element from rear end"<<endl;
		cout<<"5. Get front element"<<endl;
		cout<<"6. Get rear element"<<endl;
		cout<<"7. Check if dequeue is EMPTY"<<endl;
		cout<<"8. Check if dequeue is FULL"<<endl;
		cout<<"9. DISPLAY dequeue from FRONT END"<<endl;
		cout<<"10. DISPLAY dequeue from REAR END"<<endl;
		cout<<"11. EXIT"<<endl;
		cin>>N;

		switch(N)
		{
		case 1:
		{
			int n,item;
			cout<<"How many elements do you want to insert ? "<<endl;
			cin>>n;

			for(int i=0;i<n;i++)
			{
				cout<<"ELEMENT: "<<i+1<<endl;
				cin>>item;

				DQ.insert_front(item);
			}
			break;
		}
		case 3:
		{
			int n,item;
			cout<<"How many elements do you want to insert ? "<<endl;
			cin>>n;

			for(int i=0;i<n;i++)
			{
				cout<<"ELEMENT: "<<i+1<<endl;
				cin>>item;

				DQ.insert_rear(item);
			}
			break;
		}
		case 2:
		{
			int item = DQ.delete_front();
			cout<<"front element DELETED: "<<item<<endl;
			break;
		}
		case 4:
		{
			int item = DQ.delete_rear();
			cout<<"rear element DELETED: "<<item<<endl;
			break;
		}
		case 5:
		{
			int item = DQ.get_front();
			cout<<"FRONT ELEMENT: "<<item<<endl;
			break;
		}
		case 6:
		{
			int item = DQ.get_rear();
			cout<<"REAR ELEMENT: "<<item<<endl;
			break;
		}
		case 7:
		{
			if(DQ.is_empty())
				cout<<"QUEUE is EMPTY"<<endl;
			else
				cout<<"QUEUE is NOT EMPTY"<<endl;

			break;
		}
		case 8:
		{
			if(DQ.is_full())
				cout<<"QUEUE is FULL"<<endl;
			else
				cout<<"QUEUE is NOT FULL"<<endl;

			break;
		}
		case 9:
			DQ.display_front();
			break;

		case 10:
			DQ.display_rear();
			break;

		case 11:
			cout<<"TERMINATED"<<endl;
			break;

		default:
			cout<<"SELECT a VALID option"<<endl;
			break;
		}

	}while(N != 11);
	return 0;
}
