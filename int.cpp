#include <iostream>

using namespace std;

int main(void) {
float pi = 3.14159265359;
float x,y,up, down;

cout << "Enter value for x: ";
cin >> x;

up = (x * x) /( pi * pi* ( x * x + 1. / 2.));
down = 1. + ((x * x) /( pi * pi) * (x * x - 1. / 2.) *(x * x - 1. / 2.));
y = up * down;
cout << "y = " << y;
return 0;
}
