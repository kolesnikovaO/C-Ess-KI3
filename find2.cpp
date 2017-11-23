#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string word1, word2;
	cin >> word1 >> word2;

	bool useSameLetters = true;

	if (word1.length() == word2.length()) {

		for (int i = 0; i < word1.length(); i++) {
			for (int j = 0; j < word2.length(); j++) {
				if (word1[i] == word2[j]) break;
				if (j == word2.length() - 1) useSameLetters = false;
			}
			if (!useSameLetters) break;
		}

	}
	else useSameLetters = false;

	if (useSameLetters) cout << "antagrams" << endl;
	else cout << "not anagrams" << endl;

	
	return 0;
}
