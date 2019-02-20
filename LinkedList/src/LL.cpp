/*
 * LL.cpp
 *
 *  Created on: 26-Dec-2018
 *      Author: ml-07
 */

#include "LL.h"
#include<iostream>
using namespace std;

LL::LL()
{
	head=NULL;
}

LL::~LL()
{

}

Node* LL::create(Node *head)
{
	Node* temp=NULL;
	Node* node=NULL;
	int flag=1;

	while(flag==1)           //Condition to input the data
	{
		node=getnode(node);
		cout<<"\nEnter the value\n";
		cin>>node->data;
		//printf("\n");

		if(head==NULL)
		{
			head=node;
			temp=head;
		}
		else
		{
			temp->next=node;
			temp=node;
		}
		//display(head);
		cout<<"\nDo you want to continue?\n0.NO\n1.YES\n\n";
		cin>>flag;         //Checking the while condition
		}
		return (head);
}

Node* LL::getnode(Node *node1)
{
	node1=new Node;    //Dynamic allocation
	return (node1);
}

void LL::display(Node* head)   //Function to display
{
	cout<<"\n";
	while(head!=NULL)     //Checking upto the last address
	{
		cout<<head->data<<"head->data";
		head=head->next;
	}
	cout<<"NULL";
	cout<<"\n";
}

Node* LL::insert(Node* head,int n)   //Function to insert at the given position
{
	Node* node=NULL;
	int i;
	node=getnode(node);
	cout<<"\nPlease enter the value\n";
	cin>>node->data;
	node->next=NULL;
	if(n==1)    //When n=1
	{
		node->next=head;
		head=node;
	}

	Node* temp;
	temp=head;

	for(i=0;i<(n-2);i++)
	{
		temp=temp->next;
	}
	node->next=temp->next;
	temp->next=node;

	return (head);
}

Node* LL::Delete(Node* head,int n)  //Function to delete the node
{
	int i;
	struct Node* node=NULL;
	struct Node* temp=head;

	if(n==1)
	{
		head=temp->next;
		delete(temp);
	}

	for(i=0;i<(n-2);i++)
	{
		temp=temp->next;
	}

	node=temp->next;
	temp->next=node->next;
	delete(node);
	return (head);
}













