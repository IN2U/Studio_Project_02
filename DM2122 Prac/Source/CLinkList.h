#ifndef CLINKLIST_H
#define CLINKLIST_H

constexpr auto ITEM_AMOUNT = 5;

#include "CItem.h"

#include <vector>

class CLinkList
{
private:
	CItem* head;

public:
	CLinkList();
	CLinkList(int ID, string name, float price);
	~CLinkList();

	void AddItem(int data, string name, float price);
	void RemoveItem();
	void Print();

	std::string Name();
	float Price();

	bool IsEmpty();
	bool IsLastNode();
};

#endif