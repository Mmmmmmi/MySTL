#pragma once


template<class T>
struct Tree_Node
{
	typedef Tree_Node<T> Node;
	typedef Tree_Node<T>* PNode;

	T _data;
	PNode _leftChild;
	PNode _rightChild;
	PNode _patent;
};



template<class T>
class BinarySearchTree 
{
	typedef Tree_Node<T> Node;
	typedef Tree_Node<T>* PNode;
	typedef T& reference;
	typedef BinarySearchTree<T> Self;
public:
	BinarySearchTree()
		:_head(nullptr)
	{}

	void Destroy()
	{
		_Destroy(_head);
		_head = nullptr;
	}

	~BinarySearchTree()
	{
		Destroy();
	}


private:
	void _Destroy(PNode root)
	{
		if (root != nullptr)
		{
			_Destroy(root->_leftChild);
			_Destroy(root->_rightChild);
			delete root;
		}
	}

	PNode _head;
};


template<class T>
class AVLTree
{
	typedef Tree_Node<T> Node;
	typedef Tree_Node<T>* PNode;
public:

private:
	PNode _head;
};

template<class T>
class RedBlackTree
{
	typedef Tree_Node<T> Node;
	typedef Tree_Node<T>* PNode;
public:

private:
	PNode _head;
};
