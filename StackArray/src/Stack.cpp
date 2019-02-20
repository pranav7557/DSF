/*
 * Stack.cpp
 *
 *  Created on: 21-Dec-2018
 *      Author: ml-07
 */

#include<iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub
	top=-1;
}

template <class T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
}

template <class T>
int Stack<T>::isEmpty()
{
	if(top==-1)
		return 1;
	return 0;
}

template <class T>
int Stack<T>::isFull()
{
	if(top==MAX)
		return 1;
	return 0;
}

template <class T>
void Stack<T>::push()
{
	T temp;
	if(!isFull())
	{
		cin>>temp;
		top+=1;
		data[top]=temp;
	}
	else
		cout<<"\nStack is Full!!\n";
}

template <class T>
T Stack<T>::pop()
{
	T x;
	if(!isEmpty())
	{
		x=data[top];
		top-=1;
		return x;
	}
	else
		return -1;
}

template <class T>
void Stack<T>::display()
{
	for(int i=0;i<=top;i++)
	{
		cout<<"\t"<<data[i];
	}
}
