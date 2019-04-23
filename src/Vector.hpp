#pragma once

#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <initializer_list>

template<class T>
class Vector
{
	typedef size_t size_type;
	typedef T* iterator;					//普通迭代器
	typedef const T* const_iterator;		//const迭代器
	typedef T& reference;					//引用
	typedef const T& const_reference;		//常引用

public:
	////////////////////
	//Constructs

	Vector()
		:_first(nullptr)
		, _last(nullptr)
		, _end(nullptr)
	{}

	Vector(size_t count, const T& value = T())
		:_first(nullptr)
		, _last(nullptr)
		, _end(nullptr)
	{
		if (count > 0)
		{
			_first = new T[count];
			_last = _first + count;
			_end = _first + count;
			for (size_t i = 0; i < count; ++i)
			{
				_first[i] = value;
			}
		}
	}

	template<class InputIterator>
	Vector(InputIterator first, InputIterator last)
	{
		assert(first <= last);
		size_t size = last - first;
		_first = new T[size];
		memcpy(_first, first, sizeof(T) * size);
		_last = _first + size;
		_end = _first + size;
	}

	Vector(const Vector<T> & other)
		:Vector(other._first, other._last)
	{}

	Vector(const std::initializer_list<T> init)
		:_first(new T[init.size()])
		, _last(_first)
		, _end(_first + init.size())
	{
		for (auto e : init)
		{
			*(_last++) = e;
		}
	}

	Vector(Vector<T> && other)
		:_first(move(other._first))
		, _last(move(other._last))
		, _end(move(other._end))
	{
		other._first = other._last = other._end = nullptr;
	}

	////////////////////////
	//Destructs

	~Vector()
	{
		if (_first != nullptr)
		{
			delete[] _first;
			_first = nullptr;
			_last = nullptr;
			_end = nullptr;
		}
	}

	////////////////////////
	//Iterator

	iterator begin()
	{
		return _first;
	}

	iterator end()
	{
		return _last;
	}

	iterator rbegin()
	{
		return _last;
	}

	iterator rend()
	{
		return _first;
	}

	const_iterator cbegin() const
	{
		return _first;
	}

	const_iterator cend() const
	{
		return _last;
	}

	const_iterator crbegin() const
	{
		return _last;
	}

	const_iterator crend() const
	{
		return _first;
	}

	////////////////////////
	//Element access

	reference operator[](size_t pos)
	{
		assert(pos < this.size());
		return _first[pos];
	}

	const_reference operator[](size_t pos) const
	{
		assert(pos < this.size());
		return _first[pos];
	}

	reference front()
	{
		assert(this.size() > 0);
		return *_first;
	}

	const_reference front() const
	{
		assert(this.size() > 0);
		return *_first;
	}

	reference back()
	{
		assert(this.back() > 0);
		return *(_last - 1);
	}

	const_reference back() const
	{
		assert(this.size() > 0);
		return *(_last - 1);
	}

	T* data()
	{
		return _first;
	}

	T* data() const
	{
		return _first;
	}

	/////////////////////
	//Capacity
	bool empty() const
	{
		return _first == _last;
	}

	size_t size() const
	{
		return _last - _first;
	}

	void reserve(size_t new_cap)
	{
		//可以扩容 但是不能变小
		if (new_cap > capacity())
		{
			size_t count = size();
			T* temp = new T[new_cap];

			if (_first)
			{
				for (size_t i = 0; i < count; i++)
				{
					temp[i] = _first[i];
				}
				delete[] _first;
			}

			_first = temp;
			_last = _first + count;
			_end = _first + new_cap;
		}
	}

	size_t capacity() const
	{
		return _end - _first;
	}

	/////////////////////
	//Modifiers

	void clear()
	{
		_last = _first;
	}

	void resize(size_t count, const T & value = T())
	{
		size_t oldSize = size();
		if (count <= oldSize())
		{
			_last = _first + count;
		}
		else
		{
			size_t oldCapacity = capacity();
			if (oldCapacity < count)
			{
				reserve(count);
			}
			for (size_t i = oldCapacity; i < count; ++i)
			{
				*(_last++) = value;
			}
		}
	}

	void swap(Vector & other)
	{
		T* temp = nullptr;
		temp = this._first;
		this->_first = other._first;
		other._first = temp;

		temp = this._last;
		this->_last = other._last;
		other._last = temp;

		temp = this._end;
		this->_end = other._end;
		other._end = temp;

	}

	void push_back(const T & value)
	{
		if (size() == capacity())
		{
			reserve(2 * capacity + 3);
		}
		*(_last++) = value;
	}

	void pop_back()
	{
		if (size() > 0)
		{
			--_last;
		}
	}

	iterator erase(iterator pos)
	{
		if (pos + 1 != _last)
		{
			for (iterator it = pos + 1; it != _last; ++it)
			{
				*(it - 1) = *it;
			}
		}
		pop_back();
		return pos;
	}

	//iterator erase(const_iterator pos);

	iterator erase(iterator first, iterator last)
	{
		if (last != _last)
		{
			while (last < _last)
			{
				*(first++) = *(last++);
			}
		}
		_last = first;
		return first;
	}

	//iterator erase(const_iterator first, const_iterator last);

	iterator insert(iterator pos, const T & value);
	
	//iterator insert(const_iterator pos, const T & value);
	
	//iterator insert(const_iterator pos, T && value);
	
	void insert(iterator pos, size_type count, const T & value);
	
	//iterator insert(const_iterator pos, size_type count, const T & value);
	
	template< class InputIt >
	void insert(iterator pos, InputIt first, InputIt last);
	
	//template< class InputIt >
	//iterator insert(const_iterator pos, InputIt first, InputIt last);
	
	//iterator insert(const_iterator pos, std::initializer_list<T> ilist);


private:

	iterator _first;	//指向 第一个元素
	iterator _last;		//指向最后一个元素
	iterator _end;		//指向空间的结尾
};