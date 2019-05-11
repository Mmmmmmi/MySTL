#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "Vector.hpp"
#include "List.hpp"

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
	v.erase(v.cbegin());
	cout << *(v.begin());
#endif

	//const List<int> l(5, 6);
	//cout << l.front() << endl;
	//List<int> l1(2, 3);
	//cout << l1.front() << endl;
	//l1.front() = 1;

	list<int> l{1, 2, 3, 4, 5};
	cout << l.front() << " " << l.back() << endl;
	return 0;
}