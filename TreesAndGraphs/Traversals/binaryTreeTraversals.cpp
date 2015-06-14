#include "binaryTreeTraversals.h"
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

template <typename N, typename V>
N* BTTraversal::depthFirstSearch(N* head, const V& value) {
	if(head == NULL) return NULL;

	std::stack<N*> opOrder;
	opOrder.push(head);
	int count = 0;

	while(!opOrder.empty()) {
		N* node = opOrder.top();
		++count;
		if(node->data_ == value) {
			cout << "Looked at " << count << " nodes." << endl;
			return node;
		}

		opOrder.pop();
		if(node->right_ != NULL) opOrder.push(node->right_);
		if(node->left_ != NULL) opOrder.push(node->left_);
	}

	cout << "Looked at all " << count << " nodes." << endl;
	return NULL;
}

template <typename N, typename V>
N* BTTraversal::breadthFirstSearch(N* head, const V& value) {
	if(head == NULL) return NULL;
	
	std::queue<N*> opOrder;
	opOrder.push(head);
	int count = 0;

	while(!opOrder.empty()) {
		N* node = opOrder.front();
		++count;
		if(node->data_ == value) {
			cout << "Looked at " << count << " nodes." << endl;
			return node;
		}

		opOrder.pop();
		if(node->left_ != NULL) opOrder.push(node->left_);
		if(node->right_ != NULL) opOrder.push(node->right_);
	}

	cout << "Looked at all " << count << " nodes." << endl;
	return NULL;
}

template BTNode<int>* BTTraversal::depthFirstSearch<BTNode<int>, int>(BTNode<int>*, const int&);

template BTNode<int>* BTTraversal::breadthFirstSearch<BTNode<int>, int>(BTNode<int>*, const int&);
