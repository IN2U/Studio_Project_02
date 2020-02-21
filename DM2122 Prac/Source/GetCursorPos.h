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

	double getMXPos() const;
	double getMYPos() const;

	static Cursor* getInstance();

	void getCursorPos(GLFWwindow* m_window);
};