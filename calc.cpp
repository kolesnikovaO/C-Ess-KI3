#include <iostream>

using namespace std;

int main(void) {

	int chosenValue;
	double a, b, result = 0;
	bool notExit = true;
	
	while (notExit) {
		cout << "MENU:" << endl << "0 - exit" << endl << "1 - addition" << endl << "2 - substraction" << endl;
		cout << "3 - multiplication" << endl << "4 - division" << endl << "Your choice?" << endl;
		cin >> chosenValue;
		if (chosenValue < 1 || chosenValue > 4) notExit = false;
		else {
			cout << "Input 2 numbers: " << endl;
			cin >> a >> b;

			switch (chosenValue)
			{
			case 1:
				result = a + b;
				break;
			case 2:
				result = a - b;
				break;
			case 3:
				result = a * b;
				break;
			default:
				result = a / b;
				break;
			}

			cout << "Result: " << result << endl << endl;
		}
	}

	return 0;
}
