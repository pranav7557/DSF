/*
 * Stack.cpp
 *
 *  Created on: 26-Dec-2018
 *      Author: ml-07
 */

#include "Stack.h"
#include<iostream>
using namespace std;

Stack::Stack()
{
	head=NULL;
}

Stack::~Stack()
{

}

int Stack::isEmpty()
{
	if(head==NULL)
		return 1;
	return 0;
}

void Stack::push()
{
	int x;
	cin>>x;
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		temp->next=head;
		head=temp;
	}
}

int Stack::pop()
{
	node *temp=head;
	int x=temp->data;
	cout<<x<<"\t";
	head=head->next;

}
void Stack::display()
{
	node *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cout<<"\t"<<temp->next;
	}
}
