//============================================================================
// Name        : assignment2.cpp
// Author      : Pranav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "pqueue.h"
#include "pqueue.cpp"
#include <iostream>
using namespace std;

struct database
{
	char name[20];
	char phone[11];
	int pr;
};

queue<database> q;

int getdata()
{
	database d;
	int temp;

	cout << "\nEnter the name of the patient\n";
	cin >> d.name;
	cout << "\nEnter the phone number\n";
	cin >> d.phone;
	cout << "\nPlease select the type of disease you have\n\t1.General\n\t2.Medium\n\t3.Serious\n";
	cin >> temp;
	d.pr = temp;
	q.enqueue(d, temp);
}

int serve()
{
	struct database d2;
	if (q.isEmpty())
		cout << "\n\t\tEMPTY QUEUE\n";
	else
	{
		d2 = q.dqueue();
		cout << "\nThe patient to be served is :\n";
		cout << "\nPATIENT NAME\t\tPATIENT NO.\t\tDISEASE PRIORITY\n\n";
		cout << d2.name << "\t\t\t" << d2.phone << "\t\t\t" << d2.pr << "\n";
	}
}

int main()
{
	int ch;
	do
	{
		cout << "\nMENU\n1.Take the input\n2.Display\n3.Serve the patient\n4.Remove\n5.Exit\n\n";
		cout << "Please enter your choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			getdata();
			break;
		case 2:
			q.display();
			break;
		case 3:
			serve();
			break;
		case 4:
			if (q.isEmpty())
				cout << "\n\t\tEMPTY QUEUE\n";
			else
			{
				q.dqueue();
				cout << "\nThe patient has been removed successfully\n";
			}
			break;
		case 5:
			return (1);
			break;
		}
	} while (1);
}
