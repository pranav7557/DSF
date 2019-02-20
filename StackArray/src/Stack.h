/*
 * Stack.h
 *
 *  Created on: 21-Dec-2018
 *      Author: ml-07
 */

#ifndef STACK_H_
#define STACK_H_
#define MAX 100

template <class T>
class Stack
{
	int top;
	T data[MAX];

	public:
		Stack();
		virtual ~Stack();
		void push();
		T pop();
		int isEmpty();
		int isFull();
		void display();
};

#endif /* STACK_H_ */
