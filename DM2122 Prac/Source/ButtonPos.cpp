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

double Button::getOptionsMinPosX() const
{
	return OptionsMinPosX;
}

double Button::getOptionsMaxPosX() const
{
	return OptionsMaxPosX;
}

double Button::getOptionsControlsMinPosY() const
{
	return OptionsMinPosY[0];
}

double Button::getOptionsControlsMaxPosY() const
{
	return OptionsMaxPosY[0];
}

double Button::getOptionsAudioMinPosY() const
{
	return OptionsMinPosY[1];
}

double Button::getOptionsAudioMaxPosY() const
{
	return OptionsMaxPosY[1];
}

double Button::getOptionsBackMinPosY() const
{
	return OptionsMinPosY[2];
}

double Button::getOptionsBackMaxPosY() const
{
	return OptionsMaxPosY[2];
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

	// Play, Options, Quit
	MenuMinPosX = double(window->getWidth() / 20) * (double)7;
	MenuMaxPosX = double(window->getWidth() / 20 * (double)13);

	//225 270 285 330 345 390
	MenuMinPosY[0] = double(window->getHeight() / 8) * (double)3;
	MenuMaxPosY[0] = double(window->getHeight() / 20) * (double)9;

	MenuMinPosY[1] = double(window->getHeight() / 40) * (double)19;
	MenuMaxPosY[1] = double(window->getHeight() / 20) * (double)11;

	MenuMinPosY[2] = double(window->getHeight() / 40) * (double)23;
	MenuMaxPosY[2] = double(window->getHeight() / 20) * (double)13;

	// Controls, Audio, Back
	OptionsMinPosX = double(window->getWidth() / 20) * (double)7;
	OptionsMaxPosX = double(window->getWidth() / 20 * (double)13);

	// 270 285 330 345 390
	OptionsMinPosY[0] = double(window->getHeight() / 8) * (double)3;
	OptionsMaxPosY[0] = double(window->getHeight() / 20) * (double)9;

	OptionsMinPosY[1] = double(window->getHeight() / 40) * (double)19;
	OptionsMaxPosY[1] = double(window->getHeight() / 20) * (double)11;

	OptionsMinPosY[2] = double(window->getHeight() / 40) * (double)23;
	OptionsMaxPosY[2] = double(window->getHeight() / 20) * (double)13;
}