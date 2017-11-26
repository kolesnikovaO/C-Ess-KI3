
#include "stdafx.h"
#include <regex>
#include <iostream>
#include <string>
using namespace std;

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) {
		return false;
	}
	
};
class MinLengthValidator :public StringValidator {
private:
	int min;
public:
	MinLengthValidator(int i) {
		min = i;
	}
	bool isValid(string input) {
		return input.length() >= min;
	}
};
class MaxLengthValidator :public StringValidator {
private:
	int max;
public:
	MaxLengthValidator(int i) {
		max = i;
	}
	bool isValid(string input) {
		return input.length() <= max;
	}
};

class PatternValidator :public StringValidator {
private:
	int max;
	regex *digit;
public:
	PatternValidator(string i) {
		i=regex_replace(i, *(new regex("D")), string("\\d"));
		
		i=regex_replace(i, *(new regex("[a-ce-z]")), string("[a-ce-zB-Z]"));
		i=regex_replace(i, *(new regex("A")), string("[a-zA-Z]"));

	i=regex_replace(i, *(new regex("\\?")), string("."));
		i=regex_replace(i, *(new regex("[^\\?\\s\\d\\w\\\\]")), string("\\[^\\?\\s\\d\\w\\\\]"));
		digit = new regex(i);
		cout << i << endl;
	}
	bool isValid(string input) {
		return regex_match(input,*digit);
	}
};

void printValid(StringValidator *validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator->isValid(input) ? "valid" : "invalid")<<endl;
}
int main()
{
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(&min, "hello");
	printValid(&min, "welcome");
	cout << endl;
	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(&max, "hello");
	printValid(&max, "welcome");
	cout << endl;
	cout << "PatternValidator" << endl;
	PatternValidator digit("D");
	printValid(&digit, "2");
	printValid(&digit, "valid and invalid ones");
	cout << endl;
	return 0;
}
