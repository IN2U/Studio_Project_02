#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item
{
private:
	int itemID;
	string name;
	float itemPrice;
	Item* next;

public:
	Item();
	Item(int ID, string name, float price);
	~Item();

	Item* ReturnNext();
	int ReturnID();
	string ReturnName();
	float ReturnPrice();

	void AssignNext(Item* node);

	Item* GetNext();

};

#endif