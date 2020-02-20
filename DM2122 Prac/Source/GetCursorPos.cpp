#include "GetCursorPos.h"
#include "Application.h"

Cursor::Cursor()
{
	mXPos = 0;
	mYPos = 0;
}

Cursor::~Cursor()
{
	// HELP ME
}

double Cursor::getMXPos()
{
	return mXPos;
}

double Cursor::getMYPos()
{
	return mYPos;
}

Cursor* Cursor::instance = nullptr;

Cursor* Cursor::getInstance() 
{
	if (instance == nullptr) 
	{
		instance = new Cursor;
	}
	return instance;
}

void Cursor::getCursorPos(GLFWwindow* m_window)
{
	// Stores cursor pos in mXPos & mYPos
	glfwGetCursorPos(m_window, &mXPos, &mYPos);
}