#ifndef LINKLIST_H
#define LINKLIST_H

constexpr auto ITEM_AMOUNT = 5;

#include "Item.h"

#include <vector>

class LinkList
{
private:
	Item* head;

public:
	LinkList();
	LinkList(int ID, string name, float price);
	~LinkList();

	void AddItem(int data, string name, float price);
	void RemoveItem();
	void Print();

	std::string Name();
	float Price();

	bool IsEmpty();
	bool IsLastNode();
};

#endif