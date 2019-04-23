#include <iostream>
#include <vector>
using namespace std;

#include "Vector.hpp"

Vector<int> fun()
{
	return Vector<int>{ 1, 2, 3, 4, 5, 6, 7 };
}

int main()
{
#if 0
	Vector<int> v1;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	Vector<int> v2(3, 5);
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	Vector<int> v3(v2);

	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	Vector<int> v4(5);
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	int p[] = { 1, 2, 3, 4, 5 };
	Vector<int> v5(p, p + sizeof(p) / sizeof(p[0] - 1));
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;

	Vector<int> v6 = { 1, 2, 3, 4, 5, 6 };
	for (auto e : v6)
	{
		cout << e << " ";
	}
	cout << endl;

	Vector<int>&& v7(fun());
	cout << v7.begin() << endl;
	for (auto e : v7)
	{
		cout << e << " ";
	}
	cout << endl;

	Vector<int>&& v8 = []() {return Vector<int>{1, 2, 3, 4, 5}; }();
	for (auto e : v8)
	{
		cout << e << " ";
	}
	cout << endl;

#endif


#if 0
	Vector<int> v(0);
	vector<int> v1;
	v1.resize(10);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.shrink_to_fit();
	cout << v1.capacity() << endl;
	v1.resize(25);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
#endif

	vector<int> v1{ 1, 2, 3, 4, 5, 6, 7 };
	for (auto it = v1.begin(); it != v1.end(); )
	{
		if (*it % 2 == 0) {
			it = v1.erase(it);
		}
		else {
			++it;
		}
	}
	v1.erase(v1.cbegin());
	for (auto e : v1)
	{
		cout << e  << " ";
	}

	cout << endl;

	//Vector<int> v2{ 1, 2, 3, 4, 5, 6, 7 };
	//for (auto it = v2.begin(); it != v2.end(); )
	//{
	//	if (*it % 2 == 0) {
	//		it = v2.erase(it);
	//	}
	//	else {
	//		++it;
	//	}
	//}
	//for (auto e : v2)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	return 0;
}