#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;
int main()
{
	vector <float> v(5);
	float user_number, sum = 0;
	cin >> user_number;
	v[0] = user_number;
	v[1] = user_number + 5;
	v[2] = user_number + 0.5;
	v[3] = user_number + 2.3;
	v[4] = user_number + 4.7;
	
	for (size_t i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	cout << "sum: " << sum << " avg: " << sum / v.size();
	//your code
	return 0;
}
