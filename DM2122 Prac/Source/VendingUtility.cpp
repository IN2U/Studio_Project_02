#include "SceneText.h"
#include "Vending.h"
#include "Application.h"

void SceneText::CheckInput()
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
	
	else if (Application::IsKeyPressed(VK_RETURN))
	{
		buttonTrigger++;
		somethingHappened = true;
	}

}

void SceneText::UpdateVending()
{
	if (buttonTrigger >= 2)
		goingToBuyItem = true;

	if (!goingToBuyItem)
	{
		CheckInput();
	}

	else if (goingToBuyItem)
	{
		if (Application::IsKeyPressed('Y'))
		{
			vending[0].BuyItem(std::stoi(itemChosen));
			itemIssued = vending[0].ReturnItemName(std::stoi(itemChosen));

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