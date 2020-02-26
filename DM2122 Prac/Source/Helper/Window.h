#pragma once

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

class Window
{
private:
	// GLFW window width and height
	int width;
	int height;

	static Window* instance;

	Window();
public:
	~Window();

	int getWidth() const;
	int getHeight() const;

	// Gets current window size
	void getWindowSize(GLFWwindow* m_window);

	static Window* getInstance();
};