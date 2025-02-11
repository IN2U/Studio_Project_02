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

double Button::getButtonMinPosX() const
{
	return ButtonMinPosX;
}

double Button::getButtonMaxPosX() const
{
	return ButtonMaxPosX;
}

double Button::getButton1MinPosY() const
{
	return ButtonMinPosY[0];
}

double Button::getButton1MaxPosY() const
{
	return ButtonMaxPosY[0];
}

double Button::getButton2MinPosY() const
{
	return ButtonMinPosY[1];
}

double Button::getButton2MaxPosY() const
{
	return ButtonMaxPosY[1];
}

double Button::getButton3MinPosY() const
{
	return ButtonMinPosY[2];
}

double Button::getButton3MaxPosY() const
{
	return ButtonMaxPosY[2];
}

double Button::getButton4MinPosY() const
{
	return ButtonMinPosY[3];
}

double Button::getButton4MaxPosY() const
{
	return ButtonMaxPosY[3];
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

	ButtonMinPosX = double(window->getWidth() / 20) * (double)7;
	ButtonMaxPosX = double(window->getWidth() / 20 * (double)13);

	ButtonMinPosY[0] = double(window->getHeight() / 8) * (double)3;
	ButtonMaxPosY[0] = double(window->getHeight() / 20) * (double)9;

	ButtonMinPosY[1] = double(window->getHeight() / 40) * (double)19;
	ButtonMaxPosY[1] = double(window->getHeight() / 20) * (double)11;

	ButtonMinPosY[2] = double(window->getHeight() / 40) * (double)23;
	ButtonMaxPosY[2] = double(window->getHeight() / 20) * (double)13;

	ButtonMinPosY[3] = double(window->getHeight() / 60) * (double)43;
	ButtonMaxPosY[3] = double(window->getHeight() / 60) * (double)47;
}