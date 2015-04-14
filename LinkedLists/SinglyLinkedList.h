#include <cstddef>

template <typename T>
class Node {
	
public:
	T data_;
	Node<T> *next_;

	Node(T data) {
		data_ = data;
		next_ = NULL;
	}

	// Insert given node after this node
	Node* insertAfter(T data) {
		Node<T> *next = new Node<T>(data);
		Node<T> *temp = next_;
		next_ = next;
		next->next_ = temp;
		return next;
	}

	// Append input node to tail
	Node* appendToTail(T data) {
		Node<T> *tail = new Node<T>(data);
		Node<T> *previous = this;
		Node<T> *curr = next_;
		while(curr != NULL)
		{
			previous = curr;
			curr = curr->next_;
		}
		previous->next_ = tail;
		return tail;
	}

	// Deletes first node found after this node with given data
	bool deleteFirstNode(T data) {
		Node<T> *previous = NULL;
		Node<T> *curr = this;
		bool deleted = false;
		while(curr != NULL)
		{
			if(curr->data_ == data)
			{
				previous->next_ = curr->next_;
				delete curr;
				curr = previous->next_;
				deleted = true;
			}
			previous = curr;
			curr = curr->next_;
		}
		return deleted;
	}
};

