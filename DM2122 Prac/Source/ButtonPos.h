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
	static Button* getInstance();

	int getWWidth();
	int getWHeight();

	double getMenuMinPosX();
	double getMenuMaxPosX();

	double getMenuPlayMinPosY();
	double getMenuPlayMaxPosY();

	double getMenuOptionsMinPosY();
	double getMenuOptionsMaxPosY();

	double getMenuQuitMinPosY();
	double getMenuQuitMaxPosY();

	void getWindowSize(GLFWwindow* m_window);
	void setWidthHeight();
};