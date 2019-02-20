#include <iostream>
#include "pqueue.h"
using namespace std;

template <class T>
queue<T>::queue()
{
	front = NULL;
	rear = NULL;
}

template <class T>
queue<T>::~queue()
{
}

template <class T>
int queue<T>::isEmpty()
{
	if (front == NULL)
		return (1);
	else
		return (0);
}

template <class T>
void queue<T>::enqueue(T d, int p)
{
	node *prev;
	struct node *key = new node;
	struct node *temp2 = front;

	key->data = d;
	key->prior = p;
	key->next = NULL;

	if (front == NULL)
	{
		front = key;
		rear = key;
	}
	else
	{
		int flag=0;
		while (temp2 != NULL && key->prior <= temp2->prior)
		{
			flag=1;
			prev=temp2;
			temp2=temp2->next;
		}
		if(flag==1)
		{
			prev->next=key;
			key->next=temp2;
		}
		else
		{
			key->next=temp2;
			front=key;
		}		
	}
	temp2=front;
	while(temp2->next!=NULL)
	temp2=temp2->next;
	rear=temp2;
}

template <class T>
T queue<T>::dqueue()
{
	if (front == NULL)
		cout << "\nEMPTY QUEUE\n";
	else
	{
		struct node *temp1 = front;
		T temp2 = front->data;
		front = temp1->next;
		delete (temp1);
		return (temp2);
	}
}

template <class T>
void queue<T>::display()
{
	struct node *temp = front;
	cout << "\nPATIENT NAME\t\tPATIENT NO.\t\tDISEASE PRIORITY\n\n";
	if (temp == NULL)
		cout << "\n\t\tEMPTY QUEUE\n";
	else
	{
		while (temp != NULL)
		{
			cout << temp->data.name << "\t\t\t" << temp->data.phone << "\t\t\t" << temp->data.pr << "\n";
			temp = temp->next;
		}
	}
}
