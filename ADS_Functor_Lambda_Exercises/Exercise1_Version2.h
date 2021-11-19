#pragma once
#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <exception>
#include <sstream>
using namespace std;

//of course, if we want to keep this data together we can just sub-divide the code from Version 1 in to methods so lets do something more interesting
struct Stats {
	double sum, average, stdDev;
};

class Accumulator {
public:

	int doSomething() const { return 1; }

	//pure virtual function which means any inheriting class MUST provide a body for this function
	virtual void reset() {
	}
};

/// @brief Demos a functor inside an accumulator class which accumulates statistical data on ints passed by iterating through a data structure contains ints.
class StatisticsAccumulator {
private:
	int count;
	double sum;

public:

	StatisticsAccumulator() : sum(0), count(0) {
	}

	//functor (overloads () operator) and also a unary function
	void operator()(int value) {
		sum += value;
		count++;
	}

	int getCount() const { return this->count; }
	double getSum() const { return this->sum; }
	double getAverage() const { return this->sum / this->count; }

	/// @brief Converts selected fields to string
	/// @return string
	/// @see https://www.cplusplus.com/reference/sstream/stringstream/stringstream/
	string toString() const {
		stringstream strStream;

		//performing string concatenation which is costly because...strings are immutable...replace
		strStream << "["
			<< this->count << ","
			<< this->sum
			<< ","
			<< getAverage()
			<< "]";

		//using a stringstream prevent performance loss incurred when using string concatenation (e.g. "[" + this->count + "," + ...)
		return strStream.str();
	}
};

/// @brief Demos a functor inside an accumulator class which accumulates statistical data on ints passed by iterating through a data structure contains ints.
class StdDevAccumulator {
private:
	int count;
	double average;
	double sumSquares;

public:

	StdDevAccumulator(double average, int count) : average(average), count(count) {
		sumSquares = 0;
	};

	//functor (overloads () operator) and also a unary function
	void operator()(int value) {
		sumSquares += pow(value - average, 2);
	}

	double getStdDev() const { return sqrt(sumSquares / count); }
};

/// @brief Demos a functor inside a filter class which filters data on ints passed by iterating through a data structure contains ints.
class WithinRangeFilter {
private:
	double average;
	double percentageAsFraction;
	double lower, upper;
	list<int> filteredList;

public:
	WithinRangeFilter(double average, double percentageAsFraction) : average(average), percentageAsFraction(percentageAsFraction) {
		if (percentageAsFraction < 0 || percentageAsFraction > 1)
			throw std::invalid_argument("percentageAsFraction must be in range [0,1]");

		upper = (1 + percentageAsFraction) * average;
		lower = (1 - percentageAsFraction) * average;
	};

	void operator()(int value) {
		if (lower <= value && value <= upper)
			filteredList.push_back(value);
	}

	list<int> getFilteredList() const { return this->filteredList; }
};

void Functor_Exercise1_Version2()
{
	list<int> co2List = { 1, 2, 3, 4, 5 };

	//average
	StatisticsAccumulator statsAcc;
	for (auto value : co2List) {
		statsAcc(value);
	}
	cout << statsAcc.toString() << endl;

	//std deviation
	StdDevAccumulator stdDevAcc(statsAcc.getAverage(), statsAcc.getCount());
	for (auto value : co2List) {
		stdDevAcc(value);
	}
	cout << stdDevAcc.getStdDev() << endl;

	////list of all within 10%
	WithinRangeFilter rangeFilter(statsAcc.getAverage(), 0.1);
	for (auto value : co2List) {
		rangeFilter(value);
	}

	//any_of, none_of, for_each
	auto filteredList = rangeFilter.getFilteredList();
	for_each(filteredList.begin(), filteredList.end(), print);

	//here's an advanced demo of how we could store our accumulators for re-use in our code
	//NON-EXAMINABLE CONTENT FOLLOWS...
	Accumulator average;
	Accumulator stdDev;
	map<string, Accumulator> accumulatorLookup;
	accumulatorLookup["averageAcc"] = average;
	accumulatorLookup["stdDevAcc"] = stdDev;
	auto acc = accumulatorLookup["averageAcc"];
	acc.reset();
	acc.doSomething();
}
