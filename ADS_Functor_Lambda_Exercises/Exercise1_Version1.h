#pragma once
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//Version 1 - quick and dirty
void print(int value) {
	cout << value << endl;
}

void Functor_Exercise1_Version1()
{
	//	list<int> co2List = { 456, 471, 432, 400, 319, 307, 311 };
	list<int> co2List = { 1, 2, 3, 4, 5 };

	//average
	double sum = 0;
	for (auto value : co2List) {
		sum += value;
	}

	//standard deviation
	double average = sum / co2List.size();
	double sumSquares = 0;
	for (auto value : co2List) {
		sumSquares += pow(value - average, 2);
	}
	double stdDev = sqrt(sumSquares / co2List.size());

	//list of all within 10%
	list<int> outList;
	double upper = 1.1 * average;
	double lower = 0.9 * average;

	for (auto value : co2List) {
		if (lower <= value && value <= upper)
			outList.push_back(value);
	}

	//any_of, none_of, for_each
	for_each(outList.begin(), outList.end(), print);
}