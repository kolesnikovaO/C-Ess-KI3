#include <iostream>

using namespace std;

int main(void) {

	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);

	int *p1 = vector;
	int smallest = *p1;
	for (int i = 0; i < n; i++) {
		if (smallest > *p1) smallest = *p1;
		p1++;
	}

	cout << smallest << endl;

	
	return 0;
}
