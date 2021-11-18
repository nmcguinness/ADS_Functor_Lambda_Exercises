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
Given the monthly CO2 readings from a city, write the code to perform the following:

1. Calculate the average CO2.
2. Calculate the standard deviation for all the values that year.
3. Return a list of all values within 10% of the average.

list<int> co2List = {456, 471, 432, 400, 319, 307, 311};

Use any C++ technique(s) that you have learned.
Avoid using the STL and try to think of your own solution.
*/
void Functor_Exercise1()
{
	list<int> co2List = { 456, 471, 432, 400, 319, 307, 311 };

	//add your code here...
}

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

void Lambda_Exercise1()
{
}

void Lambda_Exercise2()
{
}