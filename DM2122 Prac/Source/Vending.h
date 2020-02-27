#ifndef VENDING_H
#define VENDING_H

#include "LinkList.h"

class Vending
{
private:
	vector<LinkList*> machineItems;

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