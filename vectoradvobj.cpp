#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class money {
	int value, amount;
public:
	money(int v = 10, int a = 1) :value(v), amount(a) {}
	int Value() {
		return value;
	}
	int Amount() {
		return amount;
	}
};
bool Check(vector<money> &ATM, int a1) {
	for (size_t i = ATM.size() - 1; i > 0; i--)
	{
		for (size_t j = 0; j <= ATM[i].Amount() + 1; j++)
		{
			if (a1 <= ATM[i].Value()*j) {
				if (a1 == ATM[i].Value()*j) {
					return true;
				}
				a1 -= ATM[i].Value()*(j - 1);
				break;
			}
			if (j == ATM[i].Amount() && a1 > ATM[i].Value()*j) {
				a1 -= ATM[i].Value()*j;
				break;
			}

		}
	}
	return false;
}
int main()
{
	vector<money> ATM = { money(10,5),money(20,6) ,money(50,3) ,money(100,4) ,money(200,5) };
	stringstream ss;
	string inel;
	int a1, a2;
	getline(cin, inel);
	ss << inel;
	ss >> a1;
	ss >> a2;
	if (a1 % 10 != 0) {
		cout << "Incorrect amount of money. ";
	}
	else
	{
		if (Check(ATM, a1))
			cout << "Enough money. ";
		else
			cout << "Not enough money. ";
	}
	if (a2 % 10 != 0) {
		cout << "Incorrect amount of money. ";
	}
	else {
		if (Check(ATM, a2))
			cout << "Enough money. ";
		else
			cout << "Not enough money. ";
	}




	return 0;
}
