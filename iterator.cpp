#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2;
	//your code
	int max_value;
	cin >> max_value;
	if (max_value % 2 != 0)
		max_value++;
	for (int i = 1; i <= max_value; i += 2) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
		for (auto j = v2.begin(); j != v2.end(); j++) {
			cout << *i + *j << " ";
		}
	for (vector<int>::reverse_iterator i = v1.rbegin(); i != v1.rend(); i++)
		for (auto j = v2.rbegin(); j != v2.rend(); j++) {
			cout << *i + *j << " ";
		}
	return 0;
}
