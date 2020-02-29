#include "Currency.h"

Currency::Currency()
{
	totalCurrency = 300000;  // Set to any value for starting currency
	sortedCurrency = "";     // Set to nothing at the start
	adjustedCurrency = "";   // Set to nothing at the start
	regeneration = 100.0;
}

Currency::~Currency()
{
	if (instance != nullptr)
		delete instance;
}

// Set currency instance to 0 to create singleton
Currency* Currency::instance = nullptr;

Currency* Currency::GetInstance()
{
	if (instance == nullptr) {
		instance = new Currency;
	}
	return instance;
}

std::string Currency::ReturnSortedCurrency()
{
	return sortedCurrency;  // Sorted currency is after changing it to decimal places
}

std::string Currency::ReturnAdjustedCurrency()
{
	return adjustedCurrency; // Adjusted currency is after changing it to 4 significant figures
}

int Currency::ReturnCurrency()
{
	return totalCurrency;
}

void Currency::SortAndUpdateCurrency()
{
	//std::string stringCurrency = returnCurrency();

	switch (std::to_string(totalCurrency).length())
	{
	case 4:
	case 5:
	case 6:
	{
		sortedCurrency = std::to_string(float(totalCurrency) / 1000);
		adjustedCurrency = "";
		for (int i = 0; i < 5; ++i) // We just need the first 5 characters to be displayed (inclusive of decimal dot)
		{
			adjustedCurrency += sortedCurrency.at(i);
		}
		adjustedCurrency += "K";
		break;
	} // If thousands

	case 7:
	case 8:
	case 9:
	{
		sortedCurrency = std::to_string(float(totalCurrency) / 1000000);
		adjustedCurrency = "";
		for (int i = 0; i < 5; ++i) // We just need the first 5 characters to be displayed (inclusive of decimal dot)
		{
			adjustedCurrency += sortedCurrency.at(i);
		}
		adjustedCurrency += "M";
		break;
	}// If millions

	default:
		adjustedCurrency = std::to_string(totalCurrency);
	}
}

bool Currency::AddCurrency(int amount)
{
	totalCurrency += amount;
	return true;
}

bool Currency::DeductCurrency(int amount)
{
	if (totalCurrency > amount)
		totalCurrency -= amount;
	else
		return false;
}

double Currency::ReturnRegeneration()
{
	return regeneration;
}

void Currency::SetRegeneration(double newRegen)
{
	regeneration = newRegen;
}
