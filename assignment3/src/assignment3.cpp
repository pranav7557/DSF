//============================================================================
// Name        : assignment3.cpp
// Author      : Pranav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "tree.h"
int main()
{
	tree bt;
	int ch;
	int height;
	do
	{
		cout << "\nMENU \n1)Insert\n2)Display\n3)Depth\n4)Leaf Nodes\n5)Copy Of Tree\n\nEnter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			bt.insert();
			bt.preordertrav(bt.root);
			cout << endl;
			break;
		case 2:
			bt.display(bt.root, 0);
			cout << endl;
			cout << "\nPreorder display is : ";
			bt.preordertrav(bt.root);
			cout << endl;
			break;
		case 3:
			height = bt.depth(bt.root);
			cout << "\nThe Depth is : " << height << endl;
			break;
		case 4:
			cout << "\nLeaf Nodes Are : ";
			int l;
			l = bt.count(bt.root);
			cout << endl;
			cout << "The Total Leaf Nodes Are : " << l << endl;
			break;
		case 5:
			cout << "\nCopy of Tree is : ";
			node *p;
			p = bt.copy(bt.root);
			bt.display(p, 0);
			cout << endl;
			cout << "\nPreorder display is : ";
			bt.preordertrav(p);
			cout << endl;
			break;
		}

	} while (ch != 0);
}
