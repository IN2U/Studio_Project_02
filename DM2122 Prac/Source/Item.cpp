#include "Item.h"
#include <time.h>

Item::Item()
{
	itemID = 0;
	next = nullptr;
	itemPrice = 0;
	itemEffect = "NIL";
	itemEffectID = 0;
}
Item::Item(int data, string name, float price)
{
	itemID = data;
	this->name = name;
	itemPrice = price;
	next = nullptr;
	itemEffect = "NIL";
	itemEffectID = 0;

	/*srand(time(NULL));
	randomItemEffect = rand() % NUM_EFFECT;

	switch (randomItemEffect)
	{
	case FAST_CURRENCY_REGEN:
		itemEffect = "REGEN";

	case ADD_CURRENCY:
		itemEffect = "CURRENCY";
	}*/
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

void Item::SetItemEffect(string eff)
{
	itemEffect = eff;
}

string Item::ReturnItemEffect()
{
	return itemEffect;
}

void Item::SetItemEffectID(int ID)
{
	itemEffectID = ID;
}

int Item::ReturnItemEffectID()
{
	return itemEffectID;
}

int Item::ReturnListOfItemEffects()
{
	return NUM_EFFECT;
}

void Item::AssignNext(Item* node)
{
	this->next = node;
}

Item* Item::GetNext()
{
	return next;
}

