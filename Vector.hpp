#pragma once

#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <initializer_list>

template<class T>
class Vector
{
	typedef T* iterator;					//普通迭代器
	typedef const T* const_iterator;		//const迭代器
	typedef T& reference;					//引用
	typedef const T& const_reference;		//常引用

public:
	////////////////////
	//Constructs

	Vector()
		:_first(nullptr)
		,_last(nullptr)
		,_end(nullptr)
	{}

	Vector(size_t count, const T& value = T())
		:_first(nullptr)
		,_last(nullptr)
		,_end(nullptr)
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

	Vector(const iterator& first, const iterator& last)
	{
		assert(first <= last);
		size_t size = last - first;
		_first = new T[size];
		memcpy(_first, first, sizeof(T) * size);
		_last = _first + size;
		_end = _first + size;
	}

	Vector(const Vector<T>& other)
		:Vector(other._first, other._last)
	{}

	Vector(const std::initializer_list<T> init)
		:_first(new T[init.size()])
		,_last(_first)
		, _end(_first + init.size())
	{
		cout << _first << endl;
		for (auto e : init)
		{
			*(_last++) = e;
		}
	}

	Vector(Vector<T>&& other)
		:_first(move(other._first))
		,_last(move(other._last))
		,_end(move(other._end))
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

	void resize(size_type count, const T& value = T())
	{
		size_t oldSize = size();
		if (count <= oldSize())
		{
			_last = _first + count;
		}
		else
		{
			T* temp = new T[count];
		}
	}

private:

	iterator _first;	//指向 第一个元素
	iterator _last;		//指向最后一个元素
	iterator _end;		//指向空间的结尾
};