#pragma once
#include <iostream>


template<class T>
struct List_Node
{
	List_Node(const T& value = T())
		:_value(value)
		, _prev(nullptr)
		, _next(nullptr)
	{}
	T _value;
	List_Node<T>* _prev;
	List_Node<T>* _next;
};

template<class T>
class List_Iterator
{

private:

};



template<class T>
class List
{
	typedef List_Node<T> Node;
	typedef List_Node<T>* PNode;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef List_Iterator<T> iterator;
	typedef const List_Iterator<T> const_iterator;

public:
	//////////////////
	//Constructor
	List();

	explicit List(size_type count, const T& value = T());

	//template< class InputIt >
	//List(InputIt first, InputIt last);

	//List(const List& other);

	//List(List&& other);

	//List(std::initializer_list<T> init);

	/////////////////
	//Destructor
	~List();

	////////////////
	//Element access
	reference front();
	const_reference front() const;

	reference back();
	const_reference back() const;

	////////////////
	//Iterators
	iterator begin();
	iterator end();

	const_iterator cbegin();
	const_iterator cend();

	iterator rbegin();
	iterator rend();

	const_iterator crbegin();
	const_iterator crend();

	////////////////////
	//Capacity
	bool empty() const;

	size_type size() const;

	////////////////////
	//Modifiers
	void clear();

	void push_back(const T& value);

	void push_back(T&& value);

	void pop_back();

	void push_front(const T& value);

	void push_front(T&& value);

	void pop_front();

	void resize(size_type count, const T& value = T());


	iterator insert(iterator pos, const T& value);

	//iterator insert(const_iterator pos, const T& value);
	//iterator insert(const_iterator pos, T&& value);

	void insert(iterator pos, size_type count, const T& value);
	
	//iterator insert(const_iterator pos, size_type count, const T& value);
	
	template< class InputIt >
	void insert(iterator pos, InputIt first, InputIt last);
	
	//template< class InputIt >
	//iterator insert(const_iterator pos, InputIt first, InputIt last);
	//iterator insert(const_iterator pos, std::initializer_list<T> ilist);

	iterator erase(iterator pos);
	//iterator erase(const_iterator pos);
	
	iterator erase(iterator first, iterator last);
	//iterator erase(const_iterator first, const_iterator last);

private:

	void _create_head();
	
	PNode _head;
};


template<class T>
void List<T>::_create_head()
{
	_head = new Node();
	_head->_next = _head;
	_head->_prev = _head;
}


template<class T>
List<T>::List()
{
	_create_head();
}

template<class T>
List<T>::List(size_type count, const T& value)
{
	_create_head();
	while (count--)
	{
		List<T>::PNode newNode = new List<T>::Node(value);
		newNode->_prev = _head->_prev;
		_head->_prev->_next = newNode;
		_head->_prev = newNode;
	}
	_head->_prev->_next = _head;
}

template<class T>
List<T>::~List()
{
	clear();
	delete _head;
	_head = nullptr;
}

template<class T>
void List<T>::clear()
{
	List<T>::PNode del = _head->_next;
	while (del != _head)
	{
		_head->_next = del->_next;
		delete del;
		del = _head->_next;
	}
	_head->_prev = _head;
}

template<class T>
typename List<T>::reference List<T>::front()
{
	return const_cast<T&>(static_cast<const List<T>*>(this)->front());
}

template<class T>
typename List<T>::const_reference List<T>::front() const
{
	return _head->_next->_value;
}

template<class T>
typename List<T>::reference List<T>::back()
{
	return const_cast<T&>(static_cast<const List<T>*>(this)->back());
}

template<class T>
typename List<T>::const_reference List<T>::back() const
{
	return _head->_prev->_value;
}

