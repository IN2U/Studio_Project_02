#include "Inventory.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{
	if (instance != nullptr)
		delete instance;
}

Inventory* Inventory::instance = nullptr;

Inventory* Inventory::GetInstance()
{
	if (instance == nullptr) {
		instance = new Inventory;
	}
	return instance;
}

bool Inventory::AddItemIntoInventory(Item* newItem)
{
	if (itemInventory.size() <= 5) {
		itemInventory.push_back(newItem);
		return true;
	}
	else {
		return false;
	}
}

void Inventory::RemoveItemFromInventory(int ID)
{
	if (!itemInventory.empty())
		itemInventory.erase(itemInventory.begin() + ID - 1);
}

void Inventory::UseItem(int ID)
{
	if (!itemInventory.empty())
		itemInventory.erase(itemInventory.begin() + ID - 1);
}

bool Inventory::isEmpty()
{
	if (itemInventory.empty())
		return true;
	else
		return false;
}