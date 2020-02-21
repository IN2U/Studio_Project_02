#include "CItem.h"

CItem::CItem()
{
	itemID = 0;
	next = nullptr;
}
CItem::CItem(int data, string name, float price)
{
	itemID = data;
	this->name = name;
	itemPrice = price;
	next = nullptr;
}

CItem::~CItem()
{

}

CItem* CItem::ReturnNext()
{
	return this->next;
}

int CItem::ReturnID()
{
	return itemID;
}

string CItem::ReturnName()
{
	return name;
}

float CItem::ReturnPrice()
{
	return itemPrice;
}

void CItem::AssignNext(CItem* node)
{
	this->next = node;
}

CItem* CItem::GetNext()
{
	return next;
}

