#include <iostream>

using namespace std;
int main(void) {
int year, mounth, day;

cout << "Enter year, mounth,day!" << endl;
cin >> year;
cin >> mounth;
cin >> day;
mounth -= 2;
if (mounth < 0) {mounth +=12; year -= 1;
mounth *=83./32.;
mounth += day+year + year/4. - year/100. + year / 400.;
cout << mounth % 7;}
else{
mounth *= 83. / 32.;
mounth += day + year +year/4. - year/ 100. +year /400.;
cout << mounth % 7;}

return 0;
}
