#ifndef BTREE_H_
#define BTREE_H_

struct bnode
{
	char data;
	bnode *left;
	bnode *right;
};

class btree
{
	bnode *root;
  public:
	//bnode *root;

	btree();
	virtual ~btree();

	bnode *maketree(char);
	bnode *getroot();
	bool isOperand(char);
	bool isOperator(char);

	void create_exptree_post();

	void dispinorder(bnode *root);
	void disppreorder(bnode *root);
	void disppostorder(bnode *root);

	void dispInorderNonRec();
	void dispPreorderNonRec();
	void disppostorderNonRec();
};

#endif /* BTREE_H_ */
