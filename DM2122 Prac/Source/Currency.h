#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>

#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Currency
{
private:
	int totalCurrency;
	std::string sortedCurrency;
	std::string adjustedCurrency;

	Currency();
	~Currency();
	static Currency* instance;

public:
	int ReturnCurrency();
	std::string ReturnSortedCurrency();
	std::string ReturnAdjustedCurrency();

	void SortAndUpdateCurrency();

	static Currency* GetInstance();

	bool AddCurrency(int amount);
	bool DeductCurrency(int amount);
};

#endif