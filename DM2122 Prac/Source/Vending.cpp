#include "Vending.h"

Vending::Vending()
{
	FillMachine();

	goingToBuyItem = false;
	itemBought = false;
	buttonTrigger = 0;
	somethingHappened = false;
}

Vending::~Vending()
{
	for (int i = 0; i < 10; ++i)
	{
		if (machineItems.at(i) != nullptr)
			delete machineItems.at(i);
	}
}

bool Vending::BuyItem(int choice)
{
	//machineItems.at(choice)->Print();
	if (choice >= 0 && choice <= 5)
	{
		if (!machineItems.at(choice)->IsEmpty())
		{
			machineItems.at(choice)->RemoveItem();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void Vending::PrintAvailability(int choice)
{
	machineItems.at(choice)->Print();
}

std::string Vending::ReturnItemName(int ID)
{
	if (ID > int(machineItems.size()))
		return "INVALID";
	else
		return machineItems.at(ID)->Name();

}

float Vending::ReturnItemPrice(int ID)
{
	if (ID > int(machineItems.size()))
		return 0.f;
	else
		return machineItems.at(ID)->Price();
}

bool Vending::ItemAvailable(int ID)
{
	if (machineItems.at(ID)->IsEmpty())
		return false;
	else
		return true;
}