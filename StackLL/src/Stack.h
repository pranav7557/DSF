/*
 * Stack.h
 *
 *  Created on: 26-Dec-2018
 *      Author: ml-07
 */

#ifndef STACK_H_
#define STACK_H_
#define MAX 100

class Stack
{
	struct node
	{
		int data;
		node *next;
	};

	node *head;

	public:
		Stack();
		virtual ~Stack();
		void push();
		int pop();
		int isEmpty();
		void display();
};

#endif /* STACK_H_ */
