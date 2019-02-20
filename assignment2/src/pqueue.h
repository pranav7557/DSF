
#ifndef PQUEUE_H_
#define PQUEUE_H_
#include <string.h>

template <class T>
class queue
{
  public:
	struct node
	{
		T data;
		int prior;
		struct node *next;
	};

	struct node *front;
	struct node *rear;

  public:
	void enqueue(T, int);
	T dqueue();
	int isEmpty();
	void display();
	queue();
	virtual ~queue();
};

#endif /* PQUEUE_H_ */
