#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CItem
{
private:
	int itemID;
	string name;
	float itemPrice;
	CItem* next;

public:
	CItem();
	CItem(int ID, string name, float price);
	~CItem();

	CItem* ReturnNext();
	int ReturnID();
	string ReturnName();
	float ReturnPrice();

	void AssignNext(CItem* node);

	CItem* GetNext();

};

