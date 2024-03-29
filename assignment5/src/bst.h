#ifndef BST_H_
#define BST_H_

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class bst
{
	node *root;
  public:

	bst();
	node *getroot();
	node *maketree(int);
	node *findminvalue(node *);
	void preordertrav(node *);
	void insert(node *, int);
	void display(node *, int);
	void searchbst(node *, int);
	node *removebst(node *, int);
	void mirrorimage(node *);
	void levelwise(node *);
	virtual ~bst();
};

#endif /* BST_H_ */
