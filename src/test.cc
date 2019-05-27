#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
using namespace std;

//#include "Vector.hpp"
//#include "List.hpp"
#include "Tree.hpp"

#if 0
Vector<int> funv()
{
	return Vector<int>{ 1, 2, 3, 4, 5, 6, 7 };
}
#endif

int main()
{
#if 0
	vector<int> v{ 1, 2, 3, 4, 5 };
	cout << v.size() << v.capacity() << endl;
	v.resize(10);
	cout << v.size() << v.capacity() << endl;
	v.reserve(7);
	cout << v.size() << v.capacity() << endl;

#endif
	

#if 0
	List<int> l1{ 1, 2, 3, 4, 5 };
	for (auto e : l1)
	{
		cout << e << endl;
	}

	for (auto e = l1.crbegin(); e != l1.crend(); ++e)
	{
		cout << *e << endl;
	}

#endif



#if 1

	BinarySearchTree<int> bst;
    bst.Insert(8);
    bst.Insert(1);
    bst.Insert(9);
    bst.Insert(10);
    bst.Insert(2);
    bst.Insert(6);
    bst.Insert(3);
    bst.Insert(2);
    bst.Insert(5);
    bst.Insert(4);
    bst.Insert(5);
    bst.InOrder();
    bst.Erase(1);
    bst.Erase(6);
    bst.Erase(4);
    bst.Erase(8);
    bst.Erase(2);
    bst.Erase(3);
    bst.Erase(5);
    bst.Erase(9);
    bst.Erase(10);
    bst.Insert(9);
    bst.Insert(10);
    bst.Insert(2);
    bst.Insert(6);
    bst.Insert(3);
    bst.InOrder();

#endif

	return 0;
}
