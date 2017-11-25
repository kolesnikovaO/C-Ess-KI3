include "stdafx.h"
#include <iostream>
#include <string>

class Point2D
{
public:
	Point2D(double x, double y);
	std::string ToString();
	double DistanceTo(Point2D that);
	double GetX();
	double GetY();
private:
	double x;
	double y;
};

class Line2D {
public:
	Line2D(double slope, double yIntercept);
	Line2D(Point2D pointA, Point2D pointB);
	std::string ToString();

private:
	double slope;
	double yIntercept;
};

Line2D::Line2D(double slope, double yIntercept)
{
	this->slope = slope;
	this->yIntercept = yIntercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	this->slope = (pointB.GetY() - pointA.GetY()) / (pointB.GetX() - pointA.GetX());
	this->yIntercept = pointA.GetY() - 
		((pointB.GetY() - pointA.GetY()) / (pointB.GetX() - pointA.GetX())) * pointA.GetX();
}

std::string Line2D::ToString()
{
	return "y = " + std::to_string(this->slope) + "x + " + std::to_string(this->yIntercept);
}

double Point2D::GetX()
{
	return this->x;
}

double Point2D::GetY()
{
	return this->y;
}

std::string Point2D::ToString()
{
	return "x1: " + std::to_string(this->x) +
		" x2: " + std::to_string(this->y);
}

Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point2D::DistanceTo(Point2D that)
{
	return std::sqrt(std::pow(this->x - that.x, 2) + std::pow(this->y - that.y, 2));
}

std::string RemoveExtraSpaces(std::string str)
{
	int index = 0;

	// starting from index 'cause there are no reason
	// to check befour found spaces again
	while ((index = str.find("  "), index) != -1)
		str = str.replace(index, 2, " ");

	return str;
}

std::string* Split(std::string str)
{
	int index;
	std::string* splited = new std::string[2];

	// if user entered without spaces but with comma
	if ((index = str.find(',')) != -1)
		str.replace(index, 1, " ");

	// if user entered with comma and lot's of spaces
	str = RemoveExtraSpaces(str);

	splited[0] = str.substr(0, str.find(' '));
	splited[1] = str.substr(str.find(' ') + 1);

	return splited;
}

int main(void)
{
	std::string input;
	std::string* splitedString;

	std::cout << "Enter first point coordinates (x, y): ";
	std::getline(std::cin, input);

	splitedString = Split(input);
	Point2D point1(std::stod(splitedString[0]), std::stod(splitedString[1]));

	std::cout << "Enter second point coordinates (x, y): ";
	std::getline(std::cin, input);

	splitedString = Split(input);
	Point2D point2(std::stod(splitedString[0]), std::stod(splitedString[1]));

	Line2D line(point1, point2);

	std::cout << line.ToString() << std::endl;

	return 0;
}
