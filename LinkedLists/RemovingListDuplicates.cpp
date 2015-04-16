#include <iostream>
#include "SinglyLinkedList.h"
#include <vector>
#include <set>

using namespace std;

// Remove duplicates from list without changing the order
// O(n) time
// O(n) space
template <typename T>
vector<T> removeListDuplicates(Node<T> *head)
{
	vector<T> removedData;
	if(head == NULL)
		return removedData;

	set<T> seenData;
	Node<T> *prev = NULL;
	Node<T> *curr = head;

	while(curr != NULL)
	{
		if(seenData.find(curr->data_) != seenData.end())
		{
			prev->next_ = curr->next_;
			removedData.push_back(curr->data_);
			delete curr;
			curr = prev->next_;
		}
		else
		{
			seenData.insert(curr->data_);
			prev = curr;
			curr = curr->next_;
		}
	}
	return removedData;
}

// Brute force inplace removal of duplicates without changing order
// O(n2) time
// O(1) space
template <typename T>
vector<T> removeListDuplicatesBrute(Node<T> *head)
{
	vector<T> removedData;
	Node<T> *original = head;

	while(original != NULL)
	{
		Node<T> *prev = original;
		Node<T> *curr = original->next_;

		while(curr != NULL)
		{
			if(original->data_ == curr->data_)
			{
				prev->next_ = curr->next_;
				removedData.push_back(curr->data_);
				delete curr;
				curr = prev->next_;
			}
			else
			{
				prev = curr;
				curr = curr->next_;
			}
		}
		original = original->next_;
	}
	return removedData;
}

void testRemoveListDuplicates()
{
	// First removal
	cout << "First removal" << endl;
	Node<int> *head = new Node<int>(4);
	head->insertAfter(2);
	head->appendToTail(3);
	head->appendToTail(4);
	head->appendToTail(2);
	head->appendToTail(5);
	head->appendToTail(1);
	head->appendToTail(11);
	head->appendToTail(1);
	head->appendToTail(1);

	head->printList();

	vector<int> removed = removeListDuplicates(head);

	cout << "List after duplicates removed" << endl;
	head->printList();
	cout << "Duplicates Removed" << endl;
	for(auto& i: removed)
	{
		cout << i << ",";
	}
	cout << endl;
}

void testRemoveListDuplicatesBrute()
{
	// Brute force removal
	cout << "Brute force removal" << endl;
	Node<int> *headb = new Node<int>(4);
	headb->appendToTail(4);
	headb->appendToTail(4);
	headb->appendToTail(4);
	headb->insertAfter(2);
	headb->appendToTail(3);
	headb->appendToTail(4);
	headb->appendToTail(20);
	headb->appendToTail(5);
	headb->appendToTail(1);
	headb->appendToTail(1);
	headb->appendToTail(1);
	headb->appendToTail(1);

	headb->printList();

	vector<int> removedb = removeListDuplicatesBrute(headb);

	cout << "List after duplicates removed" << endl;
	headb->printList();
	cout << "Duplicates Removed" << endl;
	for(auto& i: removedb)
	{
		cout << i << ",";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	testRemoveListDuplicates();
	testRemoveListDuplicatesBrute();
}