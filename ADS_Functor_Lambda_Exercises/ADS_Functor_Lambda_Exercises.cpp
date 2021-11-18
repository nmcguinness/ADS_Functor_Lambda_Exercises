#include <iostream>
#include <list>
using namespace std;

void Functor_Exercise1();
void Functor_Exercise2();
void Lambda_Exercise1();
void Lambda_Exercise2();

int main()
{
	cout << "Functor_Exercise1" << endl;
	Functor_Exercise1();

	cout << "Functor_Exercise2" << endl;
	Functor_Exercise2();

	cout << "Lambda_Exercise1" << endl;
	Lambda_Exercise1();

	cout << "Lambda_Exercise2" << endl;
	Lambda_Exercise2();
}

/*
Given the monthly CO2 readings from a city,
write the code to perform the following:

- Calculate the average CO2.
- Calculate the standard deviation for all the values that year.
- Return a list of all values within 10% of the average.

list<int> co2List = {456, 471, 432, 400, 319, 307, 311};

Use any C++ technique(s) that you have learned.
Avoid using the STL and try to think of your own solution.
*/

void Functor_Exercise1()
{
	list<int> co2List = { 456, 471, 432, 400, 319, 307, 311 };
}

void Functor_Exercise2()
{
}

void Lambda_Exercise1()
{
}

void Lambda_Exercise2()
{
}