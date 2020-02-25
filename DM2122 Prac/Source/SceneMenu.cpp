#include "SceneMenu.h"
#include "Application.h"

#include "GL\glew.h"
#include "MeshBuilder.h"
#include "LoadTGA.h"
#include "shader.hpp"
#include <Mtx44.h>
#include "SceneManager.h"
#include "SceneText.h"

#include "Cursor.h"
#include "ButtonPos.h"

SceneMenu::SceneMenu()
{
	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}
}

SceneMenu::~SceneMenu()
{
}

void SceneMenu::Init()
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");

	InitShaderUniforms();

	glUseProgram(m_programID);

	InitMeshList();
}

void SceneMenu::Update(double dt)
{
	if (Application::IsKeyPressed(MK_LBUTTON))
	{
		Cursor* mouse = Cursor::getInstance();
		Button* button = Button::getInstance();

		SceneManager* scene = SceneManager::getInstance();

		//PLAY
		if (mouse->getMXPos() > button->getMenuMinPosX() && mouse->getMXPos() < button->getMenuMaxPosX()
			&& mouse->getMYPos() < button->getMenuPlayMaxPosY() && mouse->getMYPos() > button->getMenuPlayMinPosY())
		{
			scene->SetNextScene(1);
		}
		//OPTIONS
		else if (mouse->getMXPos() > button->getMenuMinPosX()&& mouse->getMXPos() < button->getMenuMaxPosX() 
			&& mouse->getMYPos() < button->getMenuOptionsMaxPosY() && mouse->getMYPos() > button->getMenuOptionsMinPosY())
		{
			scene->SetNextScene(2);
		}
		//QUIT
		else if (mouse->getMXPos() > button->getMenuMinPosX()&& mouse->getMXPos() < button->getMenuMaxPosX() 
			&& mouse->getMYPos() < button->getMenuQuitMaxPosY() && mouse->getMYPos() > button->getMenuQuitMinPosY())
		{
			scene->SetNextScene(-1);
		}
	}
}

void SceneMenu::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderMeshOnScreen(meshList[MENU_SCREEN], 40, 30, 80, 60);

	RenderMeshOnScreen(meshList[BUTTON], 40.f, 35.f, 24.f, 4.5f);
	RenderMeshOnScreen(meshList[BUTTON], 40.f, 29.f, 24.f, 4.5f);
	RenderMeshOnScreen(meshList[BUTTON], 40.f, 23.f, 24.f, 4.5f);

	RenderTextOnScreen(meshList[TEXT], "Play", Color(0, 0, 0), 3.f, 11.6f, 11.25f);
	RenderTextOnScreen(meshList[TEXT], "Options", Color(0, 0, 0), 3.f, 10.f, 9.25f);
	RenderTextOnScreen(meshList[TEXT], "Quit", Color(0, 0, 0), 3.f, 11.6f, 7.25f);
}

void SceneMenu::Exit()
{
	// Cleanup here
	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		if (meshList[i] != NULL)
			delete meshList[i];
	}
	// Cleanup VBO here
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}