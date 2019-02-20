/*
 * LL.h
 *
 *  Created on: 26-Dec-2018
 *      Author: ml-07
 */

#ifndef LL_H_
#define LL_H_

struct Node
{
	int data;
	Node *next;
};

class LL
{


	Node *head;

	public:
		LL();
		virtual ~LL();
		Node* create(Node*);
		Node* getnode(Node*);
		void display(Node*);
		Node* insert(Node*,int);
		Node* Delete(Node*,int);
};

#endif /* LL_H_ */
