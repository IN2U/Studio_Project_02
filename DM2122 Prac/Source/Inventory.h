#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory
{
private:
	// Anyone can add more vectors of various items, eg your class of car keys
	// CItem are the items in the vending machine
	std::vector<Item*> itemInventory;

	Inventory();
	~Inventory();

	static Inventory* instance;
public:
	static Inventory* GetInstance();

	// Adding of items
	bool AddItemIntoInventory(Item* newItem);

	//removal of items
	void RemoveItemFromInventory(int ID); // Discard, means the user does not get the effect of the item
	void UseItem(int ID); // Use, means the user gets the benefit of the used item

	void PrintInventory();
};

#endif