#pragma once

template<class T>
class Vector
{
	typedef T* Iterator;					//��ͨ������
	typedef const T* Const_Iterator;		//const������

public:
	//vector����
	Vector()
		:_first(nullptr)
		,_last(nullptr)
		,_end(nullptr)
	{}

	vector()
		:_
	{}

	//����������
private:
	Iterator _first;	//ָ�� ��һ��Ԫ��
	Iterator _last;		//ָ�����һ��Ԫ��
	Iterator _end;		//ָ��ռ�Ľ�β
};