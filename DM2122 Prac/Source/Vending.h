#ifndef VENDING_H
#define VENDING_H

#include "CLinkList.h"

class Vending
{
private:
	vector<CLinkList*> machineItems;

public:
	Vending();
	~Vending();

	void FillMachine();

	bool BuyItem(int choice);

	void PrintAvailability(int choice);

	std::string ReturnItemName(int ID);
	float ReturnItemPrice(int ID);

	bool ItemAvailable(int ID);
};

#endif