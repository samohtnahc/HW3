#include "D_LinkedList.h"

/***************************************
constructor
to initialize sentinal node to tail 
pointer and set count to 0
****************************************/
List::List()
{
	tail = new Node;	//get space for sentinal node
	tail->next = tail; //set next pointer to point to itself
	tail->prev = tail; //set previous pointer to point to itself
	count = 0;			 //set count to 0
}


/***************************************
Push function
get data and push it into the list
****************************************/
void List::push(int num)
{
	Node *newNode = new Node; //get space for new node
	newNode->digit = num;		// set new node to contain the data

	//link the new node into the list
	newNode->prev = tail;		
	newNode->next = tail->next;
	tail->next->prev = newNode;
	tail->next = newNode;
	
	tail = newNode;			//set tail to point to the new node
	count++;				//add the number of elements
}

void List::pushB(int num)
{
	Node *newNode = new Node; //get space for new node
	newNode->digit = num;		// set new node to contain the data

	//link the new node into the list
	newNode->next = tail->next->next;
	newNode->prev = tail->next;
	tail->next->next->prev = newNode;
	tail->next->next = newNode;
	if (count == 0)
		tail = newNode;		
	count++;				//add the number of elements
}

int List::pop()
{
	Node *last = tail;
	int val = last->digit;
	last->prev->next = last->next;
	last->next->prev = last->prev;
	tail = last->prev;
	delete last;
	count--;
	return val;
}
/***************************************
getNode function
****************************************
bool List::getNode(int &num, int &index)
{
	if (index < count)
	{
		num = 0;
		return false;
	}

	Node *curr = tail;
	for (int i = 0; i < index; i++)
	{
		curr = curr->prev;
	}
	num = curr->digit;
	return true;
}*/

/***************************************
getCount function
return the number of elements in the list
****************************************/
int List::getCount()
{
	return count;
}


/***************************************
getSum function
this function take two lists of digits,
and the digits of the two lists and push
them into a new list.
****************************************/

void List::getSum(List & val1, List & val2)
{
	int d1, d2,carry = 0; //variables for the digits and the carry value
	Node *curr1; 
	Node *curr2;
	curr1 = val1.tail;
	curr2 = val2.tail;
	while (curr1 != val1.tail->next || curr2 != val2.tail->next || carry != 0)
	{
		if (curr1 == val1.tail->next)
			d1 = 0; //set d1 value to 0 if the list ended
		else
		{
			d1 = curr1->digit;
			curr1 = curr1->prev; //used to move through the list
		}
		
		if (curr2 == val2.tail->next)
			d2 = 0;
		else
		{
			d2 = curr2->digit;
			curr2 = curr2->prev;
		}
		
		if (d1 + d2 + carry>= 10)
		{
			pushB(d1 + d2 - 10 + carry); //push the sum of the two digits + the value they carrided)

			carry = 1;
		}
		else
		{
			pushB(d1 + d2 + carry);
			carry = 0;
		}
		
	}
}

void List::getProduct(List & val1, List & val2)
{
	int d1, d2,carry = 0, level; //variables for the digits and the carry value
	Node *curr1;
	List lv1;
	Node *curr2;
	curr1 = val1.tail;
	curr2 = val2.tail;
	while (curr1 != val1.tail->next || curr2 != val2.tail->next || carry != 0)
	{
		List lv2;
		if (curr1 == val1.tail->next)
			d1 = 0; //set d1 value to 0 if the list ended
		else
		{
			d1 = curr1->digit;
			while (curr2 != val2.tail->next)
			{
				if (curr2 == val1.tail->next)
					d1 = 0; //set d1 value to 0 if the list ended
				else
				{
					d2 = curr2->digit;
					curr2 = curr2->prev;
				}
			if(d1 * d2 > 10)
			{

			}
			curr1 = curr1->prev;
			//used to move through the list
		 }
		}
		
	}
}


void List::getLargest(List & val1, List & val2, List * & addrLargest)
{	Node *curr1;
	Node *curr2;
	List l1, l2;
	curr1 = val1.tail;
	curr2 = val2.tail;
	addrLargest = &val2;
	if(val1.count==val2.count)
	{
		if(val1.tail->next->next>val2.tail->next->next)
			addrLargest = &val1;
	}
	else if(val1.count>val2.count)
	{
		addrLargest = &val1;
	}

	/*
	while (curr1 != val1.tail->next || curr2 != val2.tail->next)
	{
		if (curr1 == val1.tail->next)
			l1.push(0);
		else
		{
			l1.push(curr1->digit);
			curr1 = curr1->prev;
		}

		if (curr2 == val2.tail->next)
			l2.push(0);
		else
		{
			l2.push(curr2->digit);
			curr2 = curr2->prev;
		}

	}

	curr1 = l1.tail;
	curr2 = l2.tail;
	bool success = false;
	while (!success)
	{
		if (curr1->digit>curr2->digit)
		{
			largest = &val1;
			success = true;
		}
		else if (curr2->digit>curr1->digit)
		{
			largest = &val2;
			success = true;
		}
		else
		{
			curr1 = curr1->prev;
			curr2 = curr2->prev;
		}
	}
	*/
}

void List::printF()
{
	Node *curr = tail->next->next;
	while (curr != tail->next)
	{
		cout << curr->digit;
		curr = curr->next;
	}
}

void List::printB()
{
	Node *curr = tail;
	while (curr != tail->next)
	{
		cout << curr->digit;
		curr = curr->prev;
	}
}



List::~List()
{
	Node *nodePtr;
	Node *nextNode;
	Node *headNode;
	headNode = tail->next->next;
	nodePtr = tail->next->next;

	while (nodePtr != headNode)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	delete nodePtr;
}
	
