#include <iostream>

using namespace std;

bool isLeap(int year) {
	if (year % 4 != 0) return false;
	if (year % 100 != 0) return true;
	if (year % 400 != 0) return false;
	return true;
}
int monthLength(int year, int month) {
	if (month == 2) {
		if (isLeap(year)) return 29;
		else return 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	if (month <= 12) return 31;
	return 0;
}

int main(void) {
	for (int yr = 2000; yr < 2002; yr++) {
		for (int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr, mo) << " ";
		cout << endl;
	}
	
	return 0;
}
