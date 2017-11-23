#include <string>
#include <iostream>

using namespace std;

int main()
{
	string values;
	getline(cin, values);
	string templ;
	getline(cin, templ);

	string name = "", value = "";
	bool nameWasRead = false;


	for (int i = 0; i < values.length(); i++) {

		if (values[i] == ',') {
			int findName = templ.find("[" + name + "]");
			while (findName != string::npos) {
				templ.replace(findName, name.length() + 2, value);
				findName = templ.find("[" + name + "]");
			}
			nameWasRead = false;
			name = "";
			value = "";
		}
		else {
			if (nameWasRead) {
				value += values[i];
			}
			else {
				if (values[i] == '=') nameWasRead = true;
				else name += values[i];
			}
		}
		if (i + 1 == values.length()) {
			int findName = templ.find("[" + name + "]");
			while (findName != string::npos) {
				templ.replace(findName, name.length() + 2, value);
				findName = templ.find("[" + name + "]");
			}
		}

	}


	cout << templ << "\n";

	
	return 0;
}
