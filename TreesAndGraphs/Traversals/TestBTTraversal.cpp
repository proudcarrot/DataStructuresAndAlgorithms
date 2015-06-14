#include "../binaryTree.h"
#include "binaryTreeTraversals.h"
#include <iostream>

using namespace std;

void checkIfInTreeD(BTNode<int>* head, int& val)
{
	BTNode<int>* nodeWithVal = BTTraversal::depthFirstSearch<BTNode<int>, int>(head, val);

	if(nodeWithVal == NULL)
	{
		cout << "Tree does not have node with value: " << val << endl;
	}
	else
	{
		cout << "Tree has value: " << val << " : " << nodeWithVal->data_ << endl;
	}
}

void checkIfInTreeB(BTNode<int>* head, int& val)
{
	BTNode<int>* nodeWithVal = BTTraversal::breadthFirstSearch<BTNode<int>, int>(head, val);

	if(nodeWithVal == NULL)
	{
		cout << "Tree does not have node with value: " << val << endl;
	}
	else
	{
		cout << "Tree has value: " << val << " : " << nodeWithVal->data_ << endl;
	}
}

int main() {
	BTNode<int>* node = new BTNode<int>(5);


	cout << "Depth First Search" << endl;

	int val = 5;
	checkIfInTreeD(node, val);

	node->left_ = new BTNode<int>(4);
	node->right_ = new BTNode<int>(8);
	node->left_->right_ = new BTNode<int>(114);
	node->right_->right_ = new BTNode<int>(45);

	val = 144;
	checkIfInTreeD(node, val);

	val = 114;
	checkIfInTreeD(node, val);

	cout << "Breadth First Search" << endl;

	val = 5;
	checkIfInTreeB(node, val);

	val = 144;
	checkIfInTreeB(node, val);

	val = 114;
	checkIfInTreeB(node, val);

	cout << "Depth first and Breadth first NULL checking" << endl;

	checkIfInTreeD(NULL, val);
	checkIfInTreeB(NULL, val);

}
