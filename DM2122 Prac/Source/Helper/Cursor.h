#pragma once

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

class Cursor
{
private:
	double mXPos;
	double mYPos;
	static Cursor* instance;
	Cursor();
public:
	~Cursor();

	double getMXPos() const;
	double getMYPos() const;

	// Gets current cursor xy coordinates
	void getCursorPos(GLFWwindow* m_window);

	static Cursor* getInstance();
};