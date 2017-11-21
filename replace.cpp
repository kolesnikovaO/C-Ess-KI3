#include <string>
#include <iostream>

using namespace std;

int main()
{
	string sentence;
	getline(cin, sentence);
	
	string word1 = "", word2 = "";
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ') {
			if (word2 == word1) {
				sentence.erase(i - word2.length(), word2.length() + 1);
			}
			word1 = word2;
			word2 = "";
		}
		else word2 += sentence[i];
	}

	cout << sentence << "\n";

	
	return 0;
}
