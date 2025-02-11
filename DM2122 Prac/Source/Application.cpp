//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

//Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>

#include "Application.h"
#include "SceneManager.h"
#include "SceneMenu.h"
#include "SceneText.h"
#include "TicTacToe/TicTacToe.h"
#include "race.h"

#include "Helper/Cursor.h"
#include "Helper/ButtonPos.h"
#include "Helper/Window.h"

#include "Global_Constants/GAME_STATES.h"

GLFWwindow* m_window;
const unsigned char FPS = 60; // FPS of this game
const unsigned int frameTime = 1000 / FPS; // time for each frame

//Define an error callback
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

//Define the key input callback
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void resize_callback(GLFWwindow* window, int w, int h)
{
	//update opengl new window size
	glViewport(0, 0, w, h);
}

bool Application::IsKeyPressed(unsigned short key)
{
	return ((GetAsyncKeyState(key) & 0x8001) != 0);
}

Application::Application()
{
}

Application::~Application()
{
}

void Application::Init()
{
	//Set the error callback
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Set the GLFW window creation hints - these are optional
	glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 

	//Create a window and create its OpenGL context
	m_window = glfwCreateWindow(Window::getInstance()->getWidth(), Window::getInstance()->getHeight(), "Motor Show 2077", NULL, NULL);

	glfwSetCursorPos(m_window, 450, 430);// 470

	//If the window couldn't be created
	if (!m_window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//This function makes the context of the specified window current on the calling thread. 
	glfwMakeContextCurrent(m_window);

	//Sets the key callback
	//glfwSetKeyCallback(m_window, key_callback);

	glewExperimental = true; // Needed for core profile
	//Initialize GLEW
	GLenum err = glewInit();

	//If GLEW hasn't initialized
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		//return -1;
	}

	glfwSetWindowSizeCallback(m_window, resize_callback);
}

void Application::Run()
{
	//Main Loop
	SceneManager* scene = SceneManager::getInstance();

	scene->AddScene(new SceneMenu); // 0
	scene->AddScene(new SceneText); // 1
	scene->AddScene(new TicTacToe); // 2
	scene->AddScene(new SceneRace);

	scene->GetCurrScene()->Init();

	m_timer.startTimer();    // Start timer to calculate how long it takes to render this frame

	while (!glfwWindowShouldClose(m_window) && scene->getInstance()->getNextSceneID() != STATE::EXIT_SCENE)
	{
		// When esc is pressed while in main game scene, render menu scene without exiting game scene
		if (scene->getCurrentSceneID() == STATE::GAME_SCENE && scene->getNextSceneID() == STATE::MENU_SCENE)
		{
			scene->fromGame = true;
			scene->ChangeScene();
		}
		// When back is pressed from options screen in game scene, exit menu scene
		else if (scene->getNextSceneID() == STATE::GAME_SCENE && scene->fromGame == true)
		{
			scene->ChangeScene();
		}
		// When quit is pressed from Tic Tac Toe screen, go back to game scene
		else if (scene->getNextSceneID() == STATE::GAME_SCENE && scene->getCurrentSceneID() == STATE::TIC_TAC_TOE_SCENE)
		{
			scene->ChangeScene();
		}
		// Checks if next scene has been set to something else
		else if (scene->getCurrentSceneID() != scene->getNextSceneID())
		{
			//scene->GetCurrScene()->Exit();
			scene->ChangeScene();
			scene->GetCurrScene()->Init();
		}

		// Gets window size
		Window::getInstance()->getWindowSize(m_window);

		// Updates buttons position
		Button::getInstance()->updateButtonPos();

		// Gets cursor position
		Cursor::getInstance()->getCursorPos(m_window);

		scene->Update(m_timer.getElapsedTime());

		//Swap buffers
		glfwSwapBuffers(m_window);
		//Get and organize events, like keyboard and mouse input, window resizing, etc...
		glfwPollEvents();
		m_timer.waitUntil(frameTime);       // Frame rate limiter. Limits each frame to a specified time in ms.   

	} // Check if the window had been closed or quit game has been pressed

	scene->GetCurrScene()->Exit();
	delete scene;
}

void Application::Exit()
{
	//Close OpenGL window and terminate GLFW
	glfwDestroyWindow(m_window);
	//Finalize and clean up GLFW
	glfwTerminate();
}
