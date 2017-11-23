#include <string>
#include <iostream>

using namespace std;

int main()
{
	string from;
	getline(cin, from);
	string to;
	getline(cin, to);
	string sentence;
	getline(cin, sentence);

	int find1 = sentence.find(from);
	if (find1 != string::npos)
		sentence.replace(find1, from.length(), to);

	cout << sentence << "\n";

	
	return 0;
}
