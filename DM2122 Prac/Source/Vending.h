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

	bool somethingHappened;

	const int BASE_ITEM_PRICE = 1000;

	enum ITEMS
	{
		NUM_START,
		SODA,
		POTATO_CHIPS,
		CHOCOLATE,
		NOODLES,
		HOTDOG,
		PEANUTS,
		SAKE,
		BEER,
		ICE_CREAM,
		CANDY,
		COFFEE,
		PIZZA,
		BURGER,
		NUM_ITEMS,
	};

	struct itemInfo
	{
		string name;
		int price;
	};

public:
	Vending();
	~Vending();

	void FillMachine();

	bool BuyItem(int choice);

	void PrintAvailability(int choice);

	std::string ReturnItemName(int ID);
	int ReturnItemPrice(int ID);

	bool ItemAvailable(int ID);

	void CheckInput();
	void UpdateVending();

	//getters
	string GetItemChosen();
	string GetItemIssued();

	//setters
	void SetToDefault();

	Item* GetItem(int ID);

	bool BuyingItem();
	bool ItemIsBought();

	bool SomethingHappened();

	bool CheckIfValidInput(int ID);

};

#endif