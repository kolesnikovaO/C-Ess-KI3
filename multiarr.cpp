#include <iostream>
#include <iomanip>

using namespace std;

float AvarageGrade(int *pointer, int length) {
	float sumOfElem = 0;
	for (int i = 0; i < length; i++) {
		sumOfElem += *pointer;
		pointer += 1;
	}
	return sumOfElem / length;
}

void PrintArrayElements(int *pointer, int length) {
	for (int i = 0; i < length; i++) {
		cout << *pointer << " ";
		pointer += 1;
	}
}

int main(void) {

	int numberOfCurses;
	cout << "Number of curses: ";
	cin >> numberOfCurses;

	int **coursesAndGrades = new int*[numberOfCurses];
	int *numberOfGradesInCourse = new int[numberOfCurses];

	for (int i = 0; i < numberOfCurses; i++) {
		cin >> numberOfGradesInCourse[i];
		coursesAndGrades[i] = new int[numberOfGradesInCourse[i]];
		for (int j = 0; j < numberOfGradesInCourse[i]; j++) {
			cin >> coursesAndGrades[i][j];
		}
	}

	cout << fixed << setprecision(2);
	float average = 0, averagesSum = 0;
	for (int i = 0; i < numberOfCurses; i++) {
		cout << "Course " << i + 1 << ": ";
		average = AvarageGrade(coursesAndGrades[i], numberOfGradesInCourse[i]);
		averagesSum += average;
		cout << "final " << average << ", ";
		cout << "grades: ";
		PrintArrayElements(coursesAndGrades[i], numberOfGradesInCourse[i]);
		cout << endl;
	}
	cout << "Overall final " << averagesSum / numberOfCurses << endl;

	
	return 0;
}
