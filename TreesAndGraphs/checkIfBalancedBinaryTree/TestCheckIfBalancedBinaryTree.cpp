#include "../binaryTree.h" // for BTNode
#include "checkIfBalancedBinaryTree.h" // for checkIfBalancedBinaryTree
#include <iostream> // for cout, endl

int main()
{
	std::cout << "NULL Head" << std::endl;
	std::cout << BinaryTreeUtils::isBinaryTreeBalanced<int>(NULL) << std::endl;
	
	BTNode<int> *head = new BTNode<int>(0);
	std::cout << "Tree with head only: " << std::endl;
	std::cout << BinaryTreeUtils::isBinaryTreeBalanced<int>(head) << std::endl;

	head->left_ = new BTNode<int>(1);
	head->right_ = new BTNode<int>(1);
	head->right_->right_ = new BTNode<int>(2);
	head->left_->left_ = new BTNode<int>(2);

	std::cout << "Tree with a left and right and each with 1 child" << std::endl;
	std::cout << BinaryTreeUtils::isBinaryTreeBalanced<int>(head) << std::endl;

	head->left_->left_->left_ = new BTNode<int>(3);
	head->right_->right_->right_ = new BTNode<int>(3);

	std::cout << "Tree with each of previous tree's children with 1 child" << std::endl;
	std::cout << BinaryTreeUtils::isBinaryTreeBalanced<int>(head) << std::endl;

	// The following tree
	// 0		 o
	//  	   /   \
	// 1	  o     o
	//  	 / \     \
	// 2	o   o     o
	//     /    	 / \
	// 3  o 		o	o

	head->left_->right_ = new BTNode<int>(2);
	head->right_->right_->left_ = new BTNode<int>(3);

	std::cout << "Tree as layed out in comments" << std::endl;
	std::cout << BinaryTreeUtils::isBinaryTreeBalanced<int>(head) << std::endl;

	// The following tree
	// 0		 o
	//  	   /   \
	// 1	  o     o
	//  	 / \   / \
	// 2	o   o o   o
	//     /    	 / \
	// 3  o 		o	o

	head->right_->left_ = new BTNode<int>(2);

	std::cout << "Tree as layed out in comments" << std::endl;
	std::cout << BinaryTreeUtils::isBinaryTreeBalanced<int>(head) << std::endl;
}
