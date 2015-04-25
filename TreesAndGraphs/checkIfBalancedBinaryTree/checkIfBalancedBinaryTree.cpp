#include "checkIfBalancedBinaryTree.h" // for function isBinaryTreeBalanced
#include <utility> // for pairs
#include <algorithm> // for min and max
#include <iostream> //for cout, endl

// Function to check if a binary tree is balanced.
// In this case the definition of balanced is that 
// the heights of the two subtrees of any node never
// differ by more than one. 

using namespace std;

template <typename T>
pair<int,int> nodeHelper(int depth, BTNode<T> *node)
{
	pair<int,int> L = make_pair(depth,depth);
	pair<int,int> R = make_pair(depth,depth);

	if(node->left_ != NULL)
	{
		L = nodeHelper(depth+1, node->left_);
	}
	if(node->right_ != NULL)
	{
		R = nodeHelper(depth+1, node->right_);
	}

	return make_pair(min(L.first, R.first),max(L.second,R.second));
}

template <typename T>
bool BinaryTreeUtils::isBinaryTreeBalanced(BTNode<T> *head)
{
	if(head == NULL)
	{
		return true;
	}
	
	pair<int,int> minAndMaxDepth = nodeHelper(0,head);

	cout << "Min depth: " << minAndMaxDepth.first << endl;
	cout << "Max depth: " << minAndMaxDepth.second << endl;

	if(minAndMaxDepth.second - minAndMaxDepth.first > 1)
	{
		return false;
	}

	return true;
}

template bool BinaryTreeUtils::isBinaryTreeBalanced<int>(BTNode<int> *head);
