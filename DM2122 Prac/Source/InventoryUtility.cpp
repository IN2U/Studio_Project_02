#include "Application.h"
#include "Inventory.h"
#include "Application.h"

void Inventory::CheckInput()
{
	if (Application::IsKeyPressed('1'))
	{
		UseItem(1);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('2'))
	{
		UseItem(2);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('3'))
	{
		UseItem(3);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('4'))
	{
		UseItem(4);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('5'))
	{
		UseItem(5);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('6'))
	{
		UseItem(6);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('7'))
	{
		UseItem(7);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('8'))
	{
		UseItem(8);
		somethingHappened = true;
	}
	if (Application::IsKeyPressed('9'))
	{
		UseItem(9);
		somethingHappened = true;
	}

}

void Inventory::UpdateInventory()
{
	somethingHappened = false;

	CheckInput();
}

bool Inventory::SomethingHappened()
{
	return somethingHappened;
}

