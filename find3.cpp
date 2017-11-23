#include <string>
#include <iostream>

using namespace std;

int main()
{
	string pattern;
	getline(cin, pattern);
	string sentence;
	getline(cin, sentence);

	bool hasDigits = false, hasAAA = false, normalWord = false, hasSymbols = false, hasQuestions = false;


	for (int i = 0; i < pattern.length(); i++) {

		if (pattern[i] >= 'a' && pattern[i] <= 'z') {
			normalWord = true;
			break;
		}
		if (pattern[i] == '?') hasQuestions = true;

		if (pattern[i] == 'D') hasDigits = true;

		if (pattern[i] == 'A') hasAAA = true;

		if ((pattern[i] >= '!' && pattern[i] <= '/') || (pattern[i] >= ':' && pattern[i] <= '@') || (pattern[i] >= '[' && pattern[i] <= '\''))
			hasSymbols = true;
	}

	if (normalWord) {
		 
	}
	else if (hasQuestions && !hasAAA && !hasDigits && !hasSymbols) {

	}
	else if (hasAAA && !hasDigits && !hasSymbols) {

	}
	else if (!hasAAA && hasDigits && !hasSymbols) {

	}
	else if (!hasAAA && !hasDigits && hasSymbols) {

	}
	else if (hasAAA && hasDigits && !hasSymbols) {

	}
	else if (hasAAA && !hasDigits && hasSymbols) {

	}
	else if (hasAAA && hasDigits && hasSymbols) {

	}
	else if (hasAAA && hasDigits && hasSymbols) {

	}


	cout << sentence << "\n";

	
	return 0;
}
