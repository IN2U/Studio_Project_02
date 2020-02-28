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
	if (Application::IsKeyPressed('6'))
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
}

void Vending::UpdateVending()
{
	somethingHappened = false;

	if (buttonTrigger >= 2) {
		goingToBuyItem = true;
	}

	if (!goingToBuyItem)
	{
		CheckInput();
	}

	else if (goingToBuyItem)
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

string Vending::GetItemChosen()
{
	return itemChosen;
}

string Vending::GetItemIssued()
{
	return itemIssued;
}

Item* Vending::GetItem(int ID)
{
	return machineItems.at(ID)->GetItem();
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
