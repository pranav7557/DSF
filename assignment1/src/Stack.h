#ifndef STACK_H_
#define STACK_H_

template <class T>
class Stack
{
	struct node
	{
		T data;
		node *next;
	};

	node *head;

	public:

		T top_data();
		Stack();
		virtual ~Stack();
		void push(T);
		T pop();
		int isEmpty();
		void display();
};

#endif /* STACK_H_ */
