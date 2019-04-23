#pragma once

template<class T>
class List_Node
{
public:
	List_Node(const T& value = T())
		:_value(value)
		,_prev(nullptr)
		,_next(nullptr)
	{}
private:
	T _value;
	List_Node<T>* _prev;
	List_Node<T>* _next;
};


template<class T>
class List
{
	typedef List_Node<T> Node;
	typedef List_Node<T*> PNode;
public:
	List();
private:
	PNode _head;
};