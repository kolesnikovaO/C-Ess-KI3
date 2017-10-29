#include <iostream>

using namespace std;

int main(void) {

int value1, value2;
float result1 , result2;

cin >> value1;
cin >> value2;

result1 = 1.0 / (float)value1;
result2 = 1.0 / (float)value2;

cout << (result1==result2 ? "EQUAL" : "NOT EQUAL") << endl;
return 0;
}
