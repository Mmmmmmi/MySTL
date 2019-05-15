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

};


template<class T>
class AVLTree
{

};

template<class T>
class RedBlackTree
{

};