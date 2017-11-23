#include <string>
#include <iostream>

using namespace std;

int main()
{
	string sentence;
	getline(cin, sentence);

	int asteriks = 0, underline = 0, prevAsteriksPos = 0, prevUnderlinePos = 0;
	string word = "";


	for (int i = 0; i < sentence.length(); i++) {

		if (sentence[i] == '*') {
			if (asteriks == 1) {
					for (int j = 0; j < word.length(); j++) {
					if (sentence[i - word.length() + j] >= 'a' && sentence[i - word.length() + j] <= 'z')
						sentence[i - word.length() + j] = sentence[i - word.length() + j] - 'a' + 'A';
				}
				sentence.replace(i, 1, "&");
				sentence.replace(i - word.length() - 1, 1, "&");
				asteriks = 0;
				word = "";
			}
			else {
				if (underline == 1) {
					sentence.replace(prevUnderlinePos, 1, "&");
					underline = 0;
					word = "";
				}
				asteriks++;
				prevAsteriksPos = i;
			}
		}

		if (sentence[i] == '_') {
			if (underline == 1) {
				
				int counter = 1;
				for (int j = 0; j < word.length(); j++) {
					if (j == word.length() - 1) break;
					sentence.insert(prevUnderlinePos + 1 + counter, " ");
					counter += 2;
				}
				i += word.length() - 1;

				sentence.replace(i, 1, " ");
				sentence.replace(prevUnderlinePos, 1, " ");
				underline = 0;
				word = "";
			}
			else {
				if (asteriks == 1) {
					sentence.replace(prevAsteriksPos, 1, "&");
					asteriks = 0;
					word = "";
				}
				underline++;
				prevUnderlinePos = i;
			}
		}

		if (sentence[i] != '*' && sentence[i] != '_') {
			if (asteriks == 1 || underline == 1) word += sentence[i];
		}

		if (i == sentence.length() - 1) {
			if (asteriks == 1) sentence.replace(prevAsteriksPos, 1, "&");
			else if (underline == 1) sentence.replace(prevUnderlinePos, 1, "&");
		}

	}


	int find = sentence.find('&');
	while (find != string::npos) {
		sentence.replace(find, 1, "");
		find = sentence.find('&');
	}

	
	cout << sentence << "\n";
return 0;
}
