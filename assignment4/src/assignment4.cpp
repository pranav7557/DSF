//============================================================================
// Name        : assignment4.cpp
// Author      : Pranav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "btree.h"

int main()
{
	btree b;
	int ch;

	do
	{
		cout << "\n\nMenu\n1.Create tree from post\n2.Display Recursive\n3.Display NonRecursive\n4.Exit\n";
		cout << "\nEnter choice\n";
		cin >> ch;
		switch (ch) //Switch case
		{

		case 1:
			b.create_exptree_post(); //Creation of tree
			break;

		case 2:
			cout << "\nInorder Display : ";
			b.dispinorder(b.getroot()); //Recursive Inorder
			cout << "\nPreorder Display : ";
			b.disppreorder(b.getroot()); //Recursive Preorder
			cout << "\nPostorder Display : ";
			b.disppostorder(b.getroot()); //Recursive Postorder
			break;

		case 3:
			cout << "\nInorder Non-Recursive Display : ";
			b.dispInorderNonRec(); //Non Recursive Inorder
			cout << "\nPreorder Non-Recursive Display : ";
			b.dispPreorderNonRec(); //Non Recursive Preorder
			cout << "\nPostorder Non-Recursive Display : ";
			b.disppostorderNonRec(); //Non Recursive Postorder
			break;
		case 4:
			return (1);
			break;
		}
	} while (1);

	return 0;
}
