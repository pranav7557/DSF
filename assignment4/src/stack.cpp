#include "stack.h"
#include <iostream>
using namespace std;

template <class T>
Stack<T>::Stack()
{
	head = NULL;
}

template <class T>
Stack<T>::~Stack()
{
}

template <class T>
int Stack<T>::isEmpty()
{
	if (head == NULL)
		return 1;
	return 0;
}

template <class T>
void Stack<T>::push(T x)
{
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	if (head == NULL)
		head = temp;
	else
	{
		temp->next = head;
		head = temp;
	}
}

template <class T>
T Stack<T>::pop()
{
	node *temp = head;
	head = head->next;
	T x;
	x = temp->data;
	delete temp;
	return x;
}

template <class T>
T Stack<T>::top_data()
{
	return (head->data);
}

template <class T>
void Stack<T>::display()
{
	node *temp;
	for (temp = head; temp != NULL; temp = temp->next)
	{
		cout << "\t" << temp->next;
	}
}
