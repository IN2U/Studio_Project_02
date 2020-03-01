#include "SceneText.h"
#include "Vending.h"
#include "Application.h"
#include "Inventory.h"
#include "Currency.h"

Inventory* inventory2 = Inventory::GetInstance();

Currency* currency2 = Currency::GetInstance();

void Vending::CheckInput()
{
	if (Application::IsKeyPressed('1'))
	{
		itemChosen += "1";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('2'))
	{
		itemChosen += "2";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('3'))
	{
		itemChosen += "3";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('4'))
	{
		itemChosen += "4";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('5'))
	{
		itemChosen += "5";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('6'))
	{
		itemChosen += "6";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('7'))
	{
		itemChosen += "7";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('8'))
	{
		itemChosen += "8";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('9'))
	{
		itemChosen += "9";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('0'))
	{
		itemChosen += "0";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed(VK_RETURN))
	{
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed(VK_BACK))
	{
		buttonTrigger--;
		itemChosen = itemChosen.substr(0, itemChosen.size() - 1);
		somethingHappened = true;
	}
}


void Vending::UpdateVending()
{
	somethingHappened = false;

	if (buttonTrigger >= 2) 
	{
		goingToBuyItem = true;
	}

	if (!goingToBuyItem)
	{
		CheckInput();
	}

	else if (goingToBuyItem)
	{
		itemBought = false;
		if (CheckIfValidInput(std::stoi((itemChosen)) == true))
		{
			if (Application::IsKeyPressed('Y'))
			{
				this->BuyItem(std::stoi(itemChosen));
				inventory2->AddItemIntoInventory(this->GetItem(std::stoi(itemChosen)));
				currency2->DeductCurrency(this->ReturnItemPrice(std::stoi(itemChosen)));
				itemIssued = this->ReturnItemName(std::stoi(itemChosen));
				itemChosen = "";
				buttonTrigger = 0;
				itemBought = true;
				goingToBuyItem = false;
				somethingHappened = true;
			}
			else if (Application::IsKeyPressed('N'))
			{
				itemChosen = "";
				itemIssued = "";
				buttonTrigger = 0;
				goingToBuyItem = false;
				somethingHappened = true;
			}
		
		}
	}
}

string Vending::GetItemChosen()
{
	return itemChosen;
}

string Vending::GetItemIssued()
{
	return itemIssued;
}

void Vending::SetToDefault()
{
	goingToBuyItem = false;
	itemBought = false;
	buttonTrigger = 0;
	somethingHappened = false;

	itemChosen = "";
	itemIssued = "";
}

Item* Vending::GetItem(int ID)
{
	if (ID > int(machineItems.size())) {
		return NULL;
	}
	else if (ID <= int(machineItems.size())) {
		return machineItems.at(ID)->GetItem();
	}
	else {
		return NULL;
	}
}

bool Vending::BuyingItem()
{
	return goingToBuyItem;
}

bool Vending::ItemIsBought()
{
	return itemBought;
}

bool Vending::SomethingHappened()
{
	return somethingHappened;
}

bool Vending::CheckIfValidInput(int ID)
{
	if (ID < int(machineItems.size())) {
		return true;
	}
	else {
		return false;
	}
}

void Vending::FillMachine()
{
	itemInfo tempItem;

	for (int i = 0; i < NUM_ITEMS; ++i)
	{
		switch (i)
		{
		case 1:
			tempItem = { "Soda", BASE_ITEM_PRICE };
			break;
		case 2:
			tempItem = { "Potato Chips", BASE_ITEM_PRICE * 2 };
			break;
		case 3:
			tempItem = { "Chocolate", BASE_ITEM_PRICE / 2 };
			break;
		case 4:
			tempItem = { "Noodles", BASE_ITEM_PRICE * 3 };
			break;
		case 5:
			tempItem = { "Hot Dog", BASE_ITEM_PRICE };
			break;
		case 6:
			tempItem = { "Peanuts", BASE_ITEM_PRICE / 2 };
			break;
		case 7:
			tempItem = { "Sake", BASE_ITEM_PRICE * 5 };
			break;
		case 8:
			tempItem = { "Beer", BASE_ITEM_PRICE * 2 };
			break;
		case 9:
			tempItem = { "Ice Cream", (BASE_ITEM_PRICE / 10) * 8 };
			break;
		case 10:
			tempItem = { "Candy", (BASE_ITEM_PRICE / 10) * 3 };
			break;
		case 11:
			tempItem = { "Coffee", (BASE_ITEM_PRICE / 10) * 8 };
			break;
		case 12:
			tempItem = { "Pizza", BASE_ITEM_PRICE * 3 };
			break;
		case 13:
			tempItem = { "Burger", BASE_ITEM_PRICE * 2 };
			break;
		}

		ItemManager* newManager = new ItemManager(i, tempItem.name, tempItem.price);
		machineItems.push_back(newManager);
	}

}