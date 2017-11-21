#include <iostream>
#include <string>

using namespace std;

int main(void) {
	
	bool ispangram = true;
	char uniqueCharacters[26]{ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int timesUsed[26]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	string sentence;
	cout << "Input a string: ";
	getline(cin, sentence);

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 'a' && sentence[i] <= 'z') 
			timesUsed[sentence[i] - 97]++;
		else if (sentence[i] >= 'A' - 32 && sentence[i] <= 'Z' - 32)
			timesUsed[sentence[i] - 65]++;
	}

	for (int i = 0; i < sizeof(uniqueCharacters) / sizeof(uniqueCharacters[0]); i++) {
		if (timesUsed[i] == 0) {
			ispangram = false;
			break;
		}
	}
	if (ispangram) cout << "Pangram" << endl;
	else cout << "Not pangram" << endl;

	for (int i = 0; i < sizeof(uniqueCharacters) / sizeof(uniqueCharacters[0]); i++)
		cout << uniqueCharacters[i] << "-" << timesUsed[i] << endl;

	
	return 0;
}
