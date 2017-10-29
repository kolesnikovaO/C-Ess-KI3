#include <iostream>

using namespace std;
int main(void) {
int year;

cout << "Enter a year : ";
cin >> year;

if ((year % 4== 0) || (year % 100 == 0) || (year % 400 ==0)) {
cout << "IT'S LEAP YEAR";}
else 
cout << "COMMON"; 
return 0;
}
