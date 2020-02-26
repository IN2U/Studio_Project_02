#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
}

Window::~Window()
{
}

int Window::getWidth() const
{
	return width;
}

int Window::getHeight() const
{
	return height;
}

Window* Window::instance = nullptr;

// Updates width and height
void Window::getWindowSize(GLFWwindow* m_window)
{
	glfwGetWindowSize(m_window, &width, &height);
}

Window* Window::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Window;
	}
	return instance;
}
