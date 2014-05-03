#ifndef D_LINKEDLIST
#define D_LINKEDLIST

#include <iostream>
using namespace std;

class List
{
private:
	struct Node
	{
		int digit;
		Node *next;
		Node *prev;
	};

	Node *tail;
	int count;

public:
	List();
	void push (int);
	void pushB(int);
	int pop();
	int	getCount();
	int List::getHeadvalue();
	void getSum(List &, List &);
	void getProduct(List &, List &);
	void getLargest(List &, List &, List *&);
	void printF();
	void printB();
	~List();
};


#endif 