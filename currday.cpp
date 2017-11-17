#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ctime>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

Date today(void) {
	time_t t = time(NULL);
	tm tl = *localtime(&t);
	Date date;
	date.year = tl.tm_year + 1900;
	date.month = tl.tm_mon + 1;
	date.day = tl.tm_mday;
	return date;
}

int main(void) {

	Date t = today();
	cout << t.year << "-" << t.month << "-" << t.day << endl;

	
	return 0;
}
