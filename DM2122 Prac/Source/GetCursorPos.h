#pragma once

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

class Cursor
{
private:
	Cursor();
	static Cursor* instance;
	double mXPos, mYPos;
public:
	~Cursor();
	static Cursor* getInstance();

	double getMXPos();
	double getMYPos();

	void getCursorPos(GLFWwindow* m_window);
};