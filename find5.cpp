#include <string>
#include <iostream>

using namespace std;

int main() {
	string password; 
	getline(cin, password);

	bool validLength = true, containsUpper = false, containsLower = false, containsDigit = false, containsSymbol = false;

	if (password.length() > 8 || password.length() < 8)
	{
		cout << "The password must be 8 characters long" << endl;
		validLength = false;
	}

	for (int i = 0; i < password.length(); i++) {

		if (!containsLower) {
			if (password[i] >= 'a' && password[i] <= 'z')
				containsLower = true;
		}
		if (!containsUpper) {
			if (password[i] >= 'A' && password[i] <= 'Z')
				containsUpper = true;
		}
		if (!containsSymbol) {
			if ((password[i] >= '#' && password[i] <= '+') || (password[i] >= '<' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '^'))
				containsSymbol = true;
		}
		if (!containsDigit) {
			if (password[i] >= '0' && password[i] <= '9')
				containsDigit = true;
		}
		if (containsLower && containsUpper && containsDigit && containsSymbol) break;
	}

	if (!containsLower) cout << "The password must have at least one lower case letter" << endl;
	if (!containsUpper) cout << "The password must have at least one upper case letter" << endl;
	if (!containsSymbol) cout << "The password must have at least one special character" << endl;
	if (!containsDigit) cout << "The password must have at least one digit " << endl;
	
	if (validLength && containsLower && containsUpper && containsSymbol && containsDigit)
		cout << "The password is valid" << endl;

	
	return 0;
}
