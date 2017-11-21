#include <iostream>
#include <string>

using namespace std;

string ChechIPAddress(string ip) {

	int numberOfPoints = 0;
	for (int i = 0; i < ip.length(); i++) {
		if (ip[i] == 46) numberOfPoints++;
		else if (ip[i] < 48 || ip[i] > 57)
			return "Only digits and dots allowed";
	}
	if (numberOfPoints > 3) return "Too many parts";
	if (numberOfPoints < 3) return "Incorect parts count";

	int find1 = ip.find('.');
	int find2 = ip.find('.', ip.find('.') + 1);
	int find3 = ip.find('.', ip.find('.', ip.find('.') + 1) + 1);

	string ip1 = ip.substr(0, find1);
	string ip2 = ip.substr(find1 + 1, find2 - find1 - 1);
	string ip3 = ip.substr(find2 + 1, find3 - find2 - 1);
	string ip4 = ip.substr(find3 + 1, ip.length() - find3 - 1);
	if (ip1.length() > 3 || ip2.length() > 3 || ip3.length() > 3 || ip4.length() > 3)
		return "Too many characters in a part";

	if (atoi(ip1.c_str()) > 255 || atoi(ip2.c_str()) > 255 || atoi(ip3.c_str()) > 255 || atoi(ip4.c_str()) > 255)
		return "Too big a value of a part";

	return "Correct IP";
}

int main(void) {

	string ip;
	cout << "Input IP: " << endl;
	cin >> ip;

	cout << ChechIPAddress(ip) << endl;

	
	return 0;
}

