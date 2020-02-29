#include "Inventory.h"
#include "Currency.h"
#include "Application.h"
#include <time.h>

Inventory::Inventory()
{
	somethingHappened = false;
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
	if (!itemInventory.empty() && itemInventory.at(ID - 1) != nullptr) {
		//std::cout << itemInventory.at(ID - 1)->ReturnItemEffect() << std::endl;
		itemInventory.erase(itemInventory.begin() + ID - 1);
	}
}

void Inventory::UseItem(int ID)
{
	srand((time)(NULL));
	itemInventory.at(ID - 1)->SetItemEffectID(rand() % itemInventory.at(ID - 1)->ReturnListOfItemEffects());
	Currency* currency = Currency::GetInstance();
	switch (itemInventory.at(ID - 1)->ReturnItemEffectID())
	{
	case 0:
		itemInventory.at(ID - 1)->SetItemEffect("REGEN");
		currency->SetRegeneration(currency->ReturnRegeneration() + 100.0);
		break;
	case 1:
		itemInventory.at(ID - 1)->SetItemEffect("CURRENCY");
		currency->AddCurrency(1000);
		break;
	case 2:
		itemInventory.at(ID - 1)->SetItemEffect("BOOST");
		currency->AddCurrency(10000);
		break;
	}

	if (!itemInventory.empty() && itemInventory.at(ID - 1) != nullptr) {
		std::cout << itemInventory.at(ID - 1)->ReturnItemEffect() << std::endl;
		itemInventory.erase(itemInventory.begin() + ID - 1);
	}
}

bool Inventory::isEmpty()
{
	if (itemInventory.empty())
		return true;
	else
		return false;
}

void Inventory::PrintInventory()
{
	for (int i = 0; i < itemInventory.size(); ++i){
		std::cout << itemInventory.at(i)->ReturnName() << std::endl;
	}
}

std::vector<Item*> Inventory::ReturnInventory()
{
	return itemInventory;
}