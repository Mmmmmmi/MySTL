#pragma once

template<class T>
class Vector
{
	typedef T* Iterator;					//普通迭代器
	typedef const T* Const_Iterator;		//const迭代器

public:
	//vector部分
	Vector()
		:_first(nullptr)
		,_last(nullptr)
		,_end(nullptr)
	{}

	vector()
		:_
	{}

	//迭代器部分
private:
	Iterator _first;	//指向 第一个元素
	Iterator _last;		//指向最后一个元素
	Iterator _end;		//指向空间的结尾
};