#pragma once

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

class Window
{
private:
	int width;
	int height;

	Window();

	static Window* instance;
public:
	~Window();

	int getWidth() const;
	int getHeight() const;

	void getWindowSize(GLFWwindow* m_window);

	static Window* getInstance();
};