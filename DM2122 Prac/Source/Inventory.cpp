#include "Inventory.h"
#include "Application.h"

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
	if (!itemInventory.empty() && itemInventory.at(ID - 1) != nullptr)
		itemInventory.erase(itemInventory.begin() + ID - 1);
}

void Inventory::UseItem(int ID)
{
	if (!itemInventory.empty() && itemInventory.at(ID) != nullptr)
		itemInventory.erase(itemInventory.begin() + ID - 1);
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
	for (int i = 0; i < itemInventory.size(); ++i)
	{
		std::cout << itemInventory.at(i)->ReturnName() << std::endl;
	}
}

std::vector<Item*> Inventory::ReturnInventory()
{
	return itemInventory;
}

void Inventory::CheckInput()
{
	if (Application::IsKeyPressed('1'))
	{
		RemoveItemFromInventory(1);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('2'))
	{
		RemoveItemFromInventory(2);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('3'))
	{
		RemoveItemFromInventory(3);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('4'))
	{
		RemoveItemFromInventory(4);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('5'))
	{
		RemoveItemFromInventory(5);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('6'))
	{
		RemoveItemFromInventory(6);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('7'))
	{
		RemoveItemFromInventory(7);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('8'))
	{
		RemoveItemFromInventory(8);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('9'))
	{
		RemoveItemFromInventory(9);
		somethingHappened = true;
	}

}

void Inventory::UpdateInventory()
{
	somethingHappened = false;

	CheckInput();
}

bool Inventory::SomethingHappened()
{
	return somethingHappened;
}