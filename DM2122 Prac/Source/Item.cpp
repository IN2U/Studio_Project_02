#include "Item.h"

Item::Item()
{
	itemID = 0;
	next = nullptr;
}
Item::Item(int data, string name, float price)
{
	itemID = data;
	this->name = name;
	itemPrice = price;
	next = nullptr;
}

Item::~Item()
{

}

Item* Item::ReturnNext()
{
	return this->next;
}

int Item::ReturnID()
{
	return itemID;
}

string Item::ReturnName()
{
	return name;
}

float Item::ReturnPrice()
{
	return itemPrice;
}

void Item::AssignNext(Item* node)
{
	this->next = node;
}

Item* Item::GetNext()
{
	return next;
}

