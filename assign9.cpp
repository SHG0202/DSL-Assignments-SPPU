//============================================================================
// Name        : assign9.cpp
// Author      : saket
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#define max 5
using namespace std;


class job
{
	int id;
	int job_execution_time;
	int priority;
	friend class QUEUE;

public:
	job()
	{
		id = 0;
		job_execution_time = 0;
		priority = 0;
	}

	void getdetails()
	{
		cout << "ENTER ID:" << endl;
		cin >> id;
		cout << "ENTER EXECUTION TIME:" << endl;
		cin >> job_execution_time;
		cout << "ENTER PRIORITY" << endl;
		cin >> priority;
	}

	void putdetails()
	{
		cout << "ENTER ID: " << id << endl;
		cout << "ENTER EXECUTION TIME: " << job_execution_time << endl;
	}
};

class QUEUE
{
	int front;
	int rear;
	job A[max];

public:
	QUEUE()
	{
		front = -1;
		rear = -1;
	}

	void push(job j)
	{
		if (rear == max - 1)
			cout << "overflow" << endl;
		if (front == -1)
		{
			front = 0;
			rear = 0;
			A[rear] = j;
		}
		else
		{
			rear++;
			int i = rear - 1;
			while ((A[i].priority < j.priority) && (i >= 0))
			{
				A[i + 1] = A[i];
				i--;
			}
			A[i + 1] = j;
		}

	}

	job pop()
	{
		job j;
		if ((front == -1) || (front == rear + 1))
			cout << "underflow" << endl;
		else
		{
			j = A[front];
			front = front + 1;
		}
		return j;
	}

	job get_rear()
	{
		job j;
		j = A[rear];
		return j;
	}

	job get_front()
	{
		job j;
		j = A[front];
		return j;
	}

	bool is_empty()
	{
		if ((front == -1) || (front = rear + 1))
			return 1;
		else
			return 0;
	}

	bool is_full()
	{
		if ((front = rear + 1) || ((front == 0) && (rear = max - 1)))
			return 1;
		else
			return 0;
	}

	void display()
	{
		int i = front;
		while (i != rear + 1)
		{
			A[i].putdetails();
			i++;
		}
	}
};



int main()
{
	QUEUE q;
	int n,k;


	do
	{
		cout << "WHAT OPERATION DO YOU WANT TO PEFORM ?" << endl;
		cout << "1. ADD A NEW JOB" << endl;
		cout << "2. END A JOB" << endl;
		cout << "3. GET THE FIRST JOB" << endl;
		cout << "4. GET THE LAST JOB" << endl;
		cout << "5. DISPALY ALL JOBS" << endl;
		cout << "6. EXIT" << endl;
		cin >> k;

		switch (k)
		{
		case 1:
			cout << "how many jobs you want to enter?" << endl;
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				job obj;
				obj.getdetails();
				q.push(obj);
			}
			break;

		case 2:
		{
			job obj;
			obj = q.pop();
			cout << "deleted object details: " << endl;
			obj.putdetails();
			break;
		}
		case 3:
		{
			job obj;
			obj = q.get_front();
			obj.putdetails();
			break;
		}

		case 4:
		{
			job obj;
			obj = q.get_rear();
			obj.putdetails();
			break;
		}

		case 5:
			q.display();
			break;

		case 6:
			break;

		default:
			cout << "enter a valid choice" << endl;
			break;
		}
	} while (k != 6);

	return 0;
}

