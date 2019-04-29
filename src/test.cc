#include <iostream>
#include <vector>
using namespace std;

#include "Vector.hpp"
#include "List.hpp"

Vector<int> funv()
{
	return Vector<int>{ 1, 2, 3, 4, 5, 6, 7 };
}

List<int> funl();

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	v.erase(v.cbegin());
	cout << *(v.begin());
	return 0;
}