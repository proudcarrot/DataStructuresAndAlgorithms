#ifndef BINARYTREE
#define BINARYTREE

#include <cstddef> // for NULL keyword

template <typename T>
struct BTNode {
	BTNode(T data) 
		: data_(data), left_(NULL), right_(NULL)
	{

	}

	T data_;
	BTNode* left_;
	BTNode* right_;
};

#endif // BINARYTREE
