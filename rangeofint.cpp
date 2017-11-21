#include <iostream>

using namespace std;

int main(void) {

	int n;
	cout << "Input a number: ";
	cin >> n;

	long long result = 0;
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	cout << result << endl;

	
	return 0;
}

