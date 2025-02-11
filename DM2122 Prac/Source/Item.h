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
	int itemPrice;
	Item* next;

	int itemEffectID;
	string itemEffect;
	enum ItemEffects
	{
		FAST_CURRENCY_REGEN,
		ADD_CURRENCY,
		FILLER,
		NUM_EFFECT,
	};

	ItemEffects e_ItemEffects;
public:
	Item();
	Item(int ID, string name, int price);
	~Item();

	Item* ReturnNext();
	int ReturnID();
	string ReturnName();
	int ReturnPrice();

	void SetItemEffect(string eff);
	string ReturnItemEffect();
	void SetItemEffectID(int ID);
	int ReturnItemEffectID();

	int ReturnListOfItemEffects();

	void AssignNext(Item* node);

	Item* GetNext();

};

#endif