//============================================================================
// Name        : LinkedList.cpp
// Author      : Pranav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LL.h"
using namespace std;

int main()
{
	Node* head=NULL;
	LL s;
	int ch,n;
	do
	{
		cout<<"\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n\n";
		cout<<"Please enter your choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			head=s.create(head);
			break;
		case 2:
			s.display(head);
			break;
		case 3:
			cout<<"\nEnter the position\n";
			cin>>n;
			head=s.insert(head,n);
			break;
		case 4:
			cout<<"\nEnter the position\n";
			cin>>n;
			head=s.Delete(head,n);
			break;
		case 5:
			return 1;
		}

	}
	while (1);
}
