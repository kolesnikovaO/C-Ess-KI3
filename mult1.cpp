#include <iostream>

using namespace std;

int main(void) {
double rez = 1;
int n, i;
cout << "Number: ";
cin >> n;
for(i = 0; i < n ; i++){
if( n == 0) {
cout <<0;
return 0;}
else {
rez *= 2;
}}
cout.precision(20);
cout << 1./rez;
return 0;
}
