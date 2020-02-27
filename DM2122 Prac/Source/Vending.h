#ifndef VENDING_H
#define VENDING_H

#include "ItemManager.h"


class Vending
{
private:
	vector<ItemManager*> machineItems;

	string itemChosen;
	string itemIssued;

	bool goingToBuyItem;
	bool itemBought;

	int buttonTrigger;

	bool somethingHappened = true;

public:
	Vending();
	~Vending();

	void FillMachine();

	bool BuyItem(int choice);

	void PrintAvailability(int choice);

	std::string ReturnItemName(int ID);
	float ReturnItemPrice(int ID);

	bool ItemAvailable(int ID);

	void CheckInput();
	void UpdateVending();

	//getters
	string GetItemChosen();
	string GetItemIssued();

	Item* GetItem(int ID);

	bool BuyingItem();
	bool ItemIsBought();

	bool SomethingHappened();

};

#endif