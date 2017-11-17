#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
	if (num == 1) return false;
	if (num == 2 || num == 3 || num == 5 || num == 7) return true;
	for (int i = 2; i <= 9; i++) {
		if (!(num % i)) return false;
	}
	return true;
}

int main(void) {
	for (int i = 0; i <= 21; i++)
		if (isPrime(i))
			cout << i << " ";
	cout << endl;
	
	return 0;
}
