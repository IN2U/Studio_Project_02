#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

constexpr auto ITEM_AMOUNT = 5;

#include "Item.h"

#include <vector>

class ItemManager
{
private:
	Item* head;

public:
	ItemManager();
	ItemManager(int ID, string name, int price);
	~ItemManager();

	void AddItem(int data, string name, int price);
	void RemoveItem();
	void Print();

	std::string Name();
	int Price();

	bool IsEmpty();
	bool IsLastNode();

	Item* GetItem();
};

#endif