#include "ItemManager.h"
#include <iostream>

ItemManager::ItemManager()
{
	head = nullptr;
}

ItemManager::ItemManager(int ID, string name, float price)
{
	head = nullptr;
	for (int i = 0; i < ITEM_AMOUNT; ++i)
	{
		this->AddItem(ID, name, price);
	}
}

ItemManager::~ItemManager()
{
	while (!IsEmpty())
		RemoveItem();

}

void ItemManager::AddItem(int data, string name, float price)
{
	Item* tmp;
	tmp = new Item(data, name, price);

	if (head == nullptr)
	{
		// LL is empty
		head = tmp;
	}
	else
	{
		//LL not empty
		//transversing
		Item* current;
		current = head;
		while (current->ReturnNext() != nullptr)
		{
			current = current->ReturnNext();
		}
		//current is pting to last node
		current->AssignNext(tmp);
	}
}

void ItemManager::RemoveItem()
{
	Item* tmp = head;
	if (!IsEmpty())
	{
		head = tmp->GetNext();
		delete tmp;
	}
	else
		/*cout << "STOCK EMPTY" << endl*/;
}


void ItemManager::Print()
{
	Item* current;
	current = head;

	if (head == nullptr)
	{
		std::cout << "This item has run out of stock." << std::endl;
	}
	else
	{
		while (current != nullptr)
		{
			cout << current->ReturnName() << " " << current->ReturnID() << endl;
			current = current->ReturnNext();
		}
	}

}

std::string ItemManager::Name()
{
	return head->ReturnName();
}

float ItemManager::Price()
{
	return head->ReturnPrice();
}

bool ItemManager::IsEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

bool ItemManager::IsLastNode()
{
	if (head->GetNext() == nullptr)
		return true;
	else
		return false;
}

Item* ItemManager::GetItem()
{
	return head;
}
