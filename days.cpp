#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool isLeap(int year) {
	if (year % 4 != 0) return false;
	if (year % 100 != 0) return true;
	if (year % 400 != 0) return false;
	return true;
}
int monthLength(int year, int month) {
	if (month > 12) return 0;
	if (month == 2) {
		if (isLeap(year)) return 29;
		else return 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
}
int dayOfYear(Date date) {
	for (int i = 1; i < date.month; i++) {
		date.day += monthLength(date.year, i);
	}
	return date.day;
}
int daysBetween(Date d1, Date d2) {
	int days = 0;
	if (d1.year > d2.year || d1.year == d2.year && d1.month > d2.month || d1.year == d2.year && d1.month == d2.month && d1.day > d2.day) return -1;
	for (int i = d1.year; i < d2.year; i++) {
		if (isLeap(i)) days += 366;
		else days += 365;
	}
	days = days + dayOfYear(d2) - dayOfYear(d1);
	return days;
}

int main(void) {
	Date since, till;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> till.year >> till.month >> till.day;
	cout << daysBetween(since, till) << endl;
	
	return 0;
}
