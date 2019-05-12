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

template<class T, class Ref, class Ptr>
struct List_Iterator
{
	typedef List_Node<T> Node;
	typedef List_Node<T>* PNode;
	typedef List_Iterator<T, Ref, Ptr> Self;

	List_Iterator(PNode pNode = nullptr)
		:_ptr(pNode)
	{}

	List_Iterator(const Self& x)
		:_ptr(x._ptr)
	{}

	Ref operator*() const
	{
		return _ptr->_value;
	}

	Ptr operator->() const
	{
		return &(operator*());
	}

	
	Self& operator++()
	{
		_ptr = _ptr->_next;
		return *this;
	}


	Self operator++(int)
	{
		Self temp(*this);
		_ptr = _ptr->_next;
		return temp;
	}

	Self& operator--()
	{
		_ptr = _ptr->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		_ptr = _ptr->_prev;
		return temp;
	}

	bool operator==(const Self& s) const
	{
		return this->_ptr == s._ptr;
	}

	bool operator!=(const Self& s) const
	{
		return this->_ptr != s._ptr;
	}

	PNode _ptr;
};


template<class T, class Ref, class Ptr, class Iterator>
struct List_Iterator_Reverse
{
	typedef List_Node<T> Node;
	typedef List_Node<T>* PNode;
	typedef List_Iterator_Reverse<T, Ref, Ptr, Iterator> Self;

	List_Iterator_Reverse(PNode pNode = nullptr)
		:_it(pNode)
	{}

	List_Iterator_Reverse(Iterator it)
		:_it(it)
	{}


	List_Iterator_Reverse(const Self& x)
		:_it(x._it)
	{}

	Ref operator*() const
	{
		Iterator temp(_it);
		--temp;
		return *temp;
	}

	Ptr operator->() const
	{
		return &(operator*());
	}


	Self& operator++()
	{
		--_it;
		return *this;
	}


	Self operator++(int)
	{
		Self temp(*this);
		--_it;
		return temp;
	}

	Self& operator--()
	{
		++_it;
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		++_it;
		return temp;
	}

	bool operator==(const Self& s) const
	{
		return this->_it == s._it;
	}

	bool operator!=(const Self& s) const
	{
		return this->_it != s._it;
	}

	Iterator _it;
};

template<class T>
class List
{
	typedef List_Node<T> Node;
	typedef List_Node<T>* PNode;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef List_Iterator<T, T&, T*> iterator;
	typedef List_Iterator<T, const T&, const T*> const_iterator;
	typedef List_Iterator_Reverse<T, T&, T*, iterator> reverse_iterator;
	typedef List_Iterator_Reverse<T, const T&, const T*, const_iterator> const_reverse_iterator;

public:
	//////////////////
	//Constructor
	List();

	explicit List(size_type count, const T& value = T());

	template< class InputIt >
	List(InputIt first, InputIt last);

	explicit List(const List& other);

	//List(List&& other);

	List(std::initializer_list<T> init);

	/////////////////
	//Destructor
	~List();

	////////////////

	List& operator=(const List& other);
	//list& operator=(std::initializer_list<T> ilist);

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

	const_iterator cbegin() const;
	const_iterator cend() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;

	////////////////////
	//Capacity
	bool empty() const;

	size_type size() const;

	////////////////////
	//Modifiers
	void clear();

	void push_back(const T& value);

	//void push_back(T&& value);

	void pop_back();

	void push_front(const T& value);

	//void push_front(T&& value);

	void pop_front();

	void resize(size_type count, const T& value = T());

	iterator insert(iterator pos, const T& value);

	//iterator insert(const_iterator pos, const T& value);
	//iterator insert(const_iterator pos, T&& value);

	void insert(iterator pos, size_type count, const T& value);
	
	//iterator insert(const_iterator pos, size_type count, const T& value);
	
	template<class InputIt>
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
		PNode newNode = new Node(value);
		newNode->_prev = _head->_prev;
		_head->_prev->_next = newNode;
		_head->_prev = newNode;
	}
	_head->_prev->_next = _head;
}

template<class T>
template<class InputIt>
List<T>::List(InputIt first, InputIt last)
	:List()
{
	while (first != last)
	{
		push_back(*first);
		++first;
	}
}

template<class T>
List<T>::List(const List& other)
	:List()
{
	List<T> temp(other.cbegin(), other.cend());
	swap(temp._head, this->_head);
}

template<class T>
List<T>::List(std::initializer_list<T> init)
	:List()
{
	for (const auto& e : init)
	{
		push_back(e);
	}
}


template<class T>
List<T>::~List()
{
	clear();
	delete _head;
	_head = nullptr;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (&other != this) 
	{
		List<T> temp(other);
		swap(temp._head, this->_head);
	}
	return *this;
}

template<class T>
typename List<T>::reference List<T>::front()
{
	return const_cast<T&>(static_cast<const List<T>>(*this).front());
}

template<class T>
typename List<T>::const_reference List<T>::front() const
{
	return _head->_next->_value;
}

template<class T>
typename List<T>::reference List<T>::back()
{
	return const_cast<T&>(static_cast<const List<T>>(*this).back());
}

template<class T>
typename List<T>::const_reference List<T>::back() const
{
	return _head->_prev->_value;
}

template<class T>
typename List<T>::iterator List<T>::begin()
{
	return iterator(_head->_next);
}

template<class T>
typename List<T>::iterator List<T>::end()
{
	return iterator(_head);
}

template<class T>						
typename List<T>::const_iterator List<T>::cbegin() const
{
	return const_iterator(_head->_next);
}

template<class T>
typename List<T>::const_iterator List<T>::cend() const
{
	return const_iterator(_head);
}

template<class T>
typename List<T>::reverse_iterator  List<T>::rbegin()
{
	return reverse_iterator(end());
}

template<class T>
typename List<T>::reverse_iterator  List<T>::rend()
{
	return reverse_iterator(begin());
}

template<class T>
typename List<T>::const_reverse_iterator  List<T>::crbegin() const
{
	return const_reverse_iterator(cend());
}

template<class T>
typename List<T>::const_reverse_iterator  List<T>::crend() const
{
	return const_reverse_iterator(cbegin());
}

template<class T>
bool List<T>::empty() const
{
	return this->begin() == this->end();
}

template<class T>
typename List<T>::size_type List<T>::size() const
{
	size_type count = 0;
	PNode pcur = _head;
	while (pcur != _head)
	{
		count++;
		pcur = pcur->_next;
	}
	return count;
}

template<class T>
void List<T>::clear()
{
	PNode del = _head->_next;
	while (del != _head)
	{
		_head->_next = del->_next;
		delete del;
		del = _head->_next;
	}
	_head->_prev = _head;
}

template<class T>
void List<T>::push_back(const T& value)
{
	insert(end(), value);
}


template<class T>
void List<T>::pop_back()
{
	erase(--end());
}

template<class T>
void List<T>::push_front(const T& value)
{
	insert(begin(), value);
}

//void push_front(T&& value);

template<class T>
void List<T>::pop_front()
{
	erase(--begin());
}

template<class T>
void List<T>::resize(size_type count, const T& value)
{
	size_type oldCount = size();
	if (count > oldCount)
	{
		while (oldCount < count) 
		{
			push_back(value);
			++oldCount;
		}
	}
	else
	{
		while (oldCount > count)
		{
			pop_back(value);
			--oldCount;
		}
	}
}

template<class T>
typename List<T>::iterator List<T>::insert(iterator pos, const T& value)
{
	PNode newNode = new Node(value);
	PNode pcur = pos._ptr;
	newNode->_prev = pcur->_prev;
	newNode->_next = pcur;
	pcur->_prev->_next = newNode;
	pcur->_prev = newNode;
	return iterator(newNode);
}

//iterator insert(const_iterator pos, const T& value);
//iterator insert(const_iterator pos, T&& value);

template<class T>
void List<T>::insert(iterator pos, size_type count, const T& value)
{
	while (count--)
	{
		insert(pos, value);
	}
}

//iterator insert(const_iterator pos, size_type count, const T& value);

template<class T>
template<class InputIt>
void List<T>::insert(iterator pos, typename InputIt first, typename InputIt last)
{
	while (first != last)
	{
		insert(pos, *first);
		++first;
	}
}

//template< class InputIt >
//iterator insert(const_iterator pos, InputIt first, InputIt last);
//iterator insert(const_iterator pos, std::initializer_list<T> ilist);

template<class T>
typename List<T>::iterator List<T>::erase(iterator pos)
{
	PNode del = pos._ptr;
	PNode prev = del->_prev;
	PNode next = del->_next;
	prev->_next = next;
	next->_prev = prev;
	return next;
}

//iterator erase(const_iterator pos);

template<class T>
typename List<T>::iterator List<T>::erase(iterator first, iterator last)
{
	while (first != last)
	{
		erase(first++);
	}
}

//iterator erase(const_iterator first, const_iterator last);

