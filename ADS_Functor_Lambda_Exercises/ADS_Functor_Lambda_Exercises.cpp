/*****************************************************************//**
 * \file   ADS_Functor_Lambda_Exercises.cpp
 * \brief  Selected solutions to two exercises to examine the usefulness
 *	       of functors and lambdas *
 * \author NMCG
 * \date   November 2021
 *********************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include "Exercise1_Version1.h"
#include "Exercise1_Version2.h"

using namespace std;

void Functor_Exercise2();
void Lambda_Exercise1();
void Lambda_Exercise2();

int main()
{
	/*cout << "Functor_Exercise1_Version1 - Simple method with all code contained within..." << endl;
	Functor_Exercise1_Version1();

	cout << "Functor_Exercise1_Version2 - Using functors to create resuable accumulators and filters..." << endl;
	Functor_Exercise1_Version2();*/

	//cout << "Functor_Exercise2" << endl;
	//Functor_Exercise2();

	cout << "Lambda_Exercise1" << endl;
	Lambda_Exercise1();

	//cout << "Lambda_Exercise2" << endl;
	//Lambda_Exercise2();
}

#pragma region Functors

/*
Given the monthly CO2 readings from a city, write the code to perform the following:

1. Calculate the average CO2.
2. Calculate the standard deviation for all the values that year.
3. Return a list of all values within 10% of the average.

list<int> co2List = {456, 471, 432, 400, 319, 307, 311};

Use any C++ technique(s) that you have learned.
Avoid using the STL and try to think of your own solution.
*/

/*
You work for a popular bank and are tasked with identifying fraudulent
deposits related to money laundering. You have been provided with the
last 10 deposits for a specific bank account.

A deposit record is in the following form:

- DepositRecord (id{string}, amount{double})

1. Write the code to search through a list of 10 deposits and return
   a list of all deposits where the deposit amount is X% above the average.
2. Write the code to compare this list of 10 deposits to 10 deposits
   made in the previous month. The code should return true if the deposits
   are roughly identical in size. The definition of "roughly" is if each deposit
   from the new list is +/- X% larger/smaller than the deposit in the same position
   in the earlier list.

   For example your code will compare the first deposit in the old list

   {id1234, 5000.00}

   with the first deposit in the new list

   {id1234, 15000.00} //new deposit is 3x larger! Fraud/laundering?

Use any C++ technique(s) that you have learned.
Avoid using the STL and try to think of your own solution.
*/

struct DepositRecord {
public:
	string id;
	double amount;
	DepositRecord(string id, double amount) : id(id), amount(amount) {};
	//add whatever additional operators (e.g. == <, >) and methods (getters) that you need here
};

void Functor_Exercise2()
{
	list<DepositRecord> depositListDec2021
		= { DepositRecord("id1234", 500) /*add more....*/ };

	//add your code here...
}

#pragma endregion

#pragma region Lambdas

void doSomething(list<int> list, function<void(int)> func) {
	for (int value : list)
		func(value);
}

void Lambda_Exercise1()
{
	list<int> co2List = { 1, 2, 3, 4, 5 };

	//we can either use a pre-existing/pre-defined function e.g. print
	for_each(co2List.begin(), co2List.end(), print);

	//or we can dynamically insert a anonymous function at the point where we want to use it
	auto printLambda = [](int value) { cout << value << endl; };
	for_each(co2List.begin(), co2List.end(), printLambda);

	//here's the same code using an inlined lambda (i.e. not stores in any variable e.g. printLambda)
	for_each(co2List.begin(), co2List.end(), [](int value)
		{
			cout << value << endl;
		}
	);

	//here's the same code (yet again!) except this time we explicitly define the data type of the lambda (i.e. printLambdaNoAuto)
	function<void(int)> printLambdaNoAuto = [](int value) { cout << value << endl; };
	for_each(co2List.begin(), co2List.end(), printLambdaNoAuto);

	//using the explicit definition of the print lambda we can now define a function that takes that lambda
	doSomething(co2List, printLambdaNoAuto);

	//now that we have a function (doSomething) that can accept functions we can even inline the lambda when we call the method
	doSomething(co2List, [](int value) { cout << sqrt(value) << endl; });
}

void Lambda_Exercise2()
{
}

#pragma endregion