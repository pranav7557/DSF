//============================================================================
// Name        : assignment5.cpp
// Author      : Pranav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "bst.h"
#define max 50
#include <string.h>

int main()
{
	int data;
	int ch, key;
	bst bt;
	do
	{
		cout << "\nMENU \n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Mirror Image\n6.Level Wise Display\n\nEnter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\nEnter data: ";
			cin >> data;
			bt.insert(bt.getroot(), data); //Calling insert function
			cout << endl;
			break;
		case 2:
			bt.display(bt.getroot(), 0);
			cout << endl;
			cout << "\nPreorder display is : "; //Calling display function
			bt.preordertrav(bt.getroot());
			cout << endl;
			break;
		case 3:
			cout << "\nEnter The Element You Want to Search : ";
			cin >> key;
			bt.searchbst(bt.getroot(), key); //Calling search function
			break;
		case 4:
			cout << "\nEnter The Element You Want to delete : ";
			cin >> key;
			bt.removebst(bt.getroot(), key); //Calling remove function
			break;
		case 5:
			cout << "\nMirror Image Of Tree Is : ";
			bt.mirrorimage(bt.getroot()); //Calling mirror imgage function
			bt.display(bt.getroot(), 0);
			cout << endl;
			break;
		case 6:
			cout << "\nLevel Wise Display  Is : ";
			bt.levelwise(bt.getroot()); //Calling levelwise function
			cout << endl;
			break;
		}

	} while (ch != 0);
	return 0;
}
