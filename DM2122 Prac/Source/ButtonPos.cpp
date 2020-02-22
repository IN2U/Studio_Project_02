#include "ButtonPos.h"
#include "Window.h"

Button::Button()
{
	updateButtonPos();
}

Button::~Button()
{
	//HELP ME
}

double Button::getMenuMinPosX() const
{
	return MenuMinPosX;
}

double Button::getMenuMaxPosX() const
{
	return MenuMaxPosX;
}

double Button::getMenuPlayMinPosY() const
{
	return MenuMinPosY[0];
}

double Button::getMenuPlayMaxPosY() const
{
	return MenuMaxPosY[0];
}

double Button::getMenuOptionsMinPosY() const
{
	return MenuMinPosY[1];
}

double Button::getMenuOptionsMaxPosY() const
{
	return MenuMaxPosY[1];
}

double Button::getMenuQuitMinPosY() const
{
	return MenuMinPosY[2];
}

double Button::getMenuQuitMaxPosY() const
{
	return MenuMaxPosY[2];
}

Button* Button::instance = nullptr;

Button* Button::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Button;
	}
	return instance;
}

void Button::updateButtonPos()
{
	Window* window = Window::getInstance();

	MenuMinPosX = double(window->getWidth() / 160) * (double)69;
	MenuMaxPosX = double(window->getWidth() / 16 * (double)9);

	MenuMinPosY[0] = double(window->getHeight() / 20) * (double)9;
	MenuMaxPosY[0] = double(window->getHeight() / 40) * (double)21;

	MenuMinPosY[1] = double(window->getHeight() / 40) * (double)23;
	MenuMaxPosY[1] = double(window->getHeight() / 20) * (double)13;

	MenuMinPosY[2] = double(window->getHeight() / 120) * (double)83;
	MenuMaxPosY[2] = double(window->getHeight() / 30) * (double)23;
}