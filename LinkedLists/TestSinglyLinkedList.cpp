#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	Node<int> *head = new Node<int>(3);
	head->insertAfter(4);
	head->insertAfter(5);
	head->appendToTail(1);
	head->appendToTail(19);
	Node<int> *temp = head;
	cout << "After Inserts" << endl;
	temp->printList();
	
	head->deleteFirstNode(10);
	head->deleteFirstNode(5);
	cout << "After Deletion" << endl;
	temp = head;
	temp->printList();
}