#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class FarmAnimal {
public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption();
	// ...
private:
	double water_consumption;
};
FarmAnimal::FarmAnimal(double water_consumption) {
	this->water_consumption = water_consumption;
}
double FarmAnimal::getWaterConsumption() {
	return water_consumption;
}
class ConsumptionAccumulator
{
public:
	ConsumptionAccumulator();
	double getTotalConsumption();
	void addConsumption(FarmAnimal animal);
private:
	double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator() :
	total_consumption(0)
{
}
double ConsumptionAccumulator::getTotalConsumption()
{
	return total_consumption;
}
void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
	total_consumption += animal.getWaterConsumption();
}
int main()
{
	ConsumptionAccumulator accumulator;
	string line, an;
	float wei;
	while (true)
	{
		stringstream ss;
		getline(cin, line);
		ss << line;
		ss >> an;
		ss >> wei;
		
		if (an == "sheep") {
			FarmAnimal sh(1.1*(wei / 10));
			accumulator.addConsumption(sh);
		}
		else
			if (an == "horse") {
				FarmAnimal sh(6.8*(wei / 100));
				accumulator.addConsumption(sh);
			}
			else
				if (an == "cow") {
					FarmAnimal sh(8.6*(wei / 100));
					accumulator.addConsumption(sh);
				}
				else
					break;
		an = "";
	}

	// read user input
	// create appropriate objects and add them to the accumulator
	cout << accumulator.getTotalConsumption();
	return 0;
}
