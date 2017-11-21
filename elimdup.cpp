#include <string>
#include <iostream>

using namespace std;

int main()
{
	string sentence;
	getline(cin, sentence);

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ') {
			if (sentence[i + 1] == ' ') {
				sentence.replace(i, 1, "");
				i--;
			}
		}
	}

	cout << sentence << "\n";

	return 0;
}
