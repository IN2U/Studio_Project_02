#pragma once

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

class Button
{
private:
	Button();

	int wWidth;
	int wHeight;

	double MenuMinPosX;
	double MenuMaxPosX;
	double MenuMinPosY[3];
	double MenuMaxPosY[3];

	static Button* instance;
public:
	~Button();

	int getWWidth();
	int getWHeight();

	double getMenuMinPosX() const;
	double getMenuMaxPosX() const;

	double getMenuPlayMinPosY() const;
	double getMenuPlayMaxPosY() const;

	double getMenuOptionsMinPosY() const;
	double getMenuOptionsMaxPosY() const;

	double getMenuQuitMinPosY() const;
	double getMenuQuitMaxPosY() const;

	static Button* getInstance();

	void getWindowSize(GLFWwindow* m_window);
	void setWidthHeight();
};