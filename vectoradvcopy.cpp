#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector <string> ip_table{ "127.0.0.1", "192.168.0.1", "192.168.1.100", "255.255.255.255" };
	//your code
	vector<string> copy(ip_table);
	int show_ip_count;
	cin >> show_ip_count;
	if (show_ip_count > copy.size())
		cout << "Too big - value must be smaller than or equal to vector size." << endl;
	else {
		for (size_t i = 0; i < show_ip_count; i++)
		{
			cout << copy[i] << " ";
		}
	}
	return 0;
}
