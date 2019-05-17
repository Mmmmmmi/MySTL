#include <iostream>
#include <vector>
#include <list>
using namespace std;

//#include "Vector.hpp"
//#include "List.hpp"

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
	return 0;
}
