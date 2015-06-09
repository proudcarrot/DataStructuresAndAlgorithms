#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

// Assumptions :
// 1. kth to last is 0 indexed so 0th to last is the last, 1st to last
// is the one before the last, and so on
// 2. If k is greater than the sie of the list -1 will return a null 
// pointer
template <typename T>
Node<T>* kthToLastElement(Node<T>* head, int k)
{
	if(!head) return NULL;

	Node<T>* kToLast = head;
	for(int i=0; i<k; ++i, head = head->next_)
	{
		if(!head->next_) return NULL;
	}
	while(head->next_)
	{
		kToLast = kToLast->next_;
		head = head->next_;
	}

	return kToLast;
}

int main()
{
	Node<int>* head = new Node<int>(0);
	head->appendToTail(1);
	head->appendToTail(2);
	head->appendToTail(3);
	head->appendToTail(4);
	head->appendToTail(5);
	head->appendToTail(6);

	cout << "List: " << endl;
	head->printList();

	Node<int>* zeroth = kthToLastElement(head, 0);
	cout << "Zeroth to last: " << zeroth->data_ << endl;

	Node<int>* first = kthToLastElement(head, 1);
	cout << "First to last: " << first->data_ << endl;

	Node<int>* sixth = kthToLastElement(head, 6);
	cout << "Sixth to last: " << sixth->data_ << endl;

	Node<int>* seventh = kthToLastElement(head, 7);
	cout << "Seventh to last: ";
	if(!seventh)
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << seventh->data_ << endl;
	}

	while(head)
	{
		Node<int>* temp = head;
		head = head->next_;
		delete temp;
	}
	
	Node<int>* none = kthToLastElement(head, 7);
	cout << "Null node: ";
	if(!none)
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << none->data_ << endl;
	}
}