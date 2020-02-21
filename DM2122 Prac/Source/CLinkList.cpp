#include "CLinkList.h"
#include <iostream>

CLinkList::CLinkList()
{
	head = nullptr;
}

CLinkList::CLinkList(int ID, string name, float price)
{
	head = nullptr;
	for (int i = 0; i < ITEM_AMOUNT; ++i)
	{
		this->AddItem(ID, name, price);
	}
}

CLinkList::~CLinkList()
{
	while (!IsEmpty())
		RemoveItem();

}

void CLinkList::AddItem(int data, string name, float price)
{
	CItem* tmp;
	tmp = new CItem(data, name, price);

	if (head == nullptr)
	{
		// LL is empty
		head = tmp;
	}
	else
	{
		//LL not empty
		//transversing
		CItem* current;
		current = head;
		while (current->ReturnNext() != nullptr)
		{
			current = current->ReturnNext();
		}
		//current is pting to last node
		current->AssignNext(tmp);
	}
}

void CLinkList::RemoveItem()
{
	CItem* tmp = head;
	if (!IsEmpty())
	{
		head = tmp->GetNext();
		delete tmp;
	}
	else
		/*cout << "STOCK EMPTY" << endl*/;
}


void CLinkList::Print()
{
	CItem* current;
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

std::string CLinkList::Name()
{
	return head->ReturnName();
}

float CLinkList::Price()
{
	return head->ReturnPrice();
}

bool CLinkList::IsEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

bool CLinkList::IsLastNode()
{
	if (head->GetNext() == nullptr)
		return true;
	else
		return false;
}
