#include <iostream>
using namespace std;
#include "bst.h"
#include "queue.cpp"

bst::bst()
{
	root = NULL;
	// TODO Auto-generated constructor stub
}

bst::~bst()
{
	// TODO Auto-generated destructor stub
}

node *bst::getroot()
{
	return (root);
}

node *bst::maketree(int data)
{
	node *p;
	p = new (node); //Allocating memory dynamically
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void bst::insert(node *temp, int data)
{
	node *p;
	if (root == NULL)
	{
		root = maketree(data); 		//If root is not made make root
		return;
	}
	else
	{
		p = temp;
		if (data < p->data)	 	//If data to be insert is less, insert at left
		{
			if (p->left != NULL)
				insert(p->left, data);
			else
				p->left = maketree(data);
		}

		else 	//If data to be insert is greater, insert at right
		{
			if (p->right != NULL)
				insert(p->right, data);
			else
				p->right = maketree(data);
		}
	}
}

void bst::searchbst(node *root, int key)
{
	node *p;
	if (root == NULL)
		cout << "\nDATA NOT PRESENT!\n";
	else
	{
		p = root;

		if (key < p->data)
			searchbst(p->left, key);

		else if (key > p->data)
			searchbst(p->right, key);

		else if (key == p->data)
		{
			cout << "\nDATA IS PRESENT\n";
			return;
		}
		else
			cout << "\nDATA NOT PRESENT!\n";
	}
}

node *bst::findminvalue(node *T)
{
	node *current = T;			  //T is keys right subtree
	while (current->left != NULL)
		current = current->left;
	return current;
}

node *bst::removebst(node *root, int key)
{
	if (root == NULL)
	{
		cout << "\nData NOT Found !\n";
		return root;
	}
	if (key < root->data)
		root->left = removebst(root->left, key);
	else if (key > root->data)
		root->right = removebst(root->right, key);
	else
	{
		if (root->left == NULL && root->right == NULL) //For leaf node
		{
			delete root;
			root = NULL;
		}

		else if (root->left == NULL) //For lchild ie. 1 child
		{
			node *p;
			p = root;
			root = root->right;
			delete p;
		}
		else if (root->right == NULL) //For rchild ie. 1 child
		{
			node *p;
			p = root;
			root = root->left;
			delete p;
		}
		else //If both the children are present
		{
			node *p;
			p = findminvalue(root->right); //Finding min and then substituting it
			root->data = p->data;
			root->right = removebst(root->right, p->data); //For deleting that node call
		}
	}
	return root; //Return statement for making NULL
}

void bst::mirrorimage(node *root)
{
	node *temp;
	node *p = root;
	if (root == NULL)
		return;
	else
	{
		temp = p->right;	  //Storin right in temp
		p->right = p->left;   //Making right as left
		p->left = temp;		  //Making left as right
		mirrorimage(p->left); //Calling recurssively
		mirrorimage(p->right);
	}
}

void bst::preordertrav(node *root)	//Preorder traversal
{

	if (root == NULL)
	{
		return;
	}
	else if (root != NULL)
	{
		cout << root->data << " ";
		preordertrav(root->left);
		preordertrav(root->right);
	}
}

void bst::levelwise(node *root)
{
	queue<node *> q;
	if (root == NULL)
		cout << "Tree is Empty !";
	else
	{
		q.enqueue(root);	 //Enqueuing root
		while (!q.IsEmpty())
		{
			node *T = q.dequeue();
			cout << T->data << " ";
			if (T->left != NULL)
				q.enqueue(T->left);
			if (T->right != NULL)
				q.enqueue(T->right);
		}
	}
}

void bst::display(node *root, int space)
{
	if (root == NULL)
		return;

	else
	{
		space += 6;
		display(root->right, space);

		cout << "\n\n";
		for (int i = 0; i < space; i++)
			cout << " ";
		cout << root->data;
		display(root->left, space);
	}
}
