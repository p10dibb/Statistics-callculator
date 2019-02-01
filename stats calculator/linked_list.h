#include "header.h"

class Node {

public:
	Node();
	~Node();
	double get_value();
	void set_value(double v);

	Node* get_pPre();
	Node* get_pNext();

	void set_pPre(Node* pre);
	void set_pNext(Node* next);

private:
	double value;
	Node* pNext;
	Node* pPre;
};

class list {

public:
	list();
	~list();

	Node* makeNode(double v);

	void insert(double v);
	
	void insert_inorder(double v);

	void erase_all();

	double get_pos(int p);

	int get_size();

	Node* getHead();


private:
	void set_size();
	
	Node* pHead;
	Node* pTail;
	int size;



};