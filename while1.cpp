#include <iostream>

using namespace std;
int main(void) {
int c0;
int count = 0;
cin >> c0;
while (c0!=1){
count += 1;
if (c0>0){
c0 /= 2;}
else if (c0%2){
c0 = 3 * c0 +1;}
cout << c0<< endl;}
cout << count;
return 0;
}

