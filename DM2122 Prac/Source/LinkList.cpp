#include "LinkList.h"
#include <iostream>

LinkList::LinkList()
{
	head = nullptr;
}

LinkList::LinkList(int ID, string name, float price)
{
	head = nullptr;
	for (int i = 0; i < ITEM_AMOUNT; ++i)
	{
		this->AddItem(ID, name, price);
	}
}

LinkList::~LinkList()
{
	while (!IsEmpty())
		RemoveItem();

}

void LinkList::AddItem(int data, string name, float price)
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

void LinkList::RemoveItem()
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


void LinkList::Print()
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

std::string LinkList::Name()
{
	return head->ReturnName();
}

float LinkList::Price()
{
	return head->ReturnPrice();
}

bool LinkList::IsEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

bool LinkList::IsLastNode()
{
	if (head->GetNext() == nullptr)
		return true;
	else
		return false;
}
