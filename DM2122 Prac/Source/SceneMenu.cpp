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

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");

	InitShaderUniforms();

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);

	glUseProgram(m_programID);

	InitMeshList();
}

void SceneMenu::Update(double dt)
{
	if (Application::IsKeyPressed(MK_LBUTTON))
	{
		Cursor* mouse = Cursor::getInstance();
		Button* button = Button::getInstance();

		//PLAY
		if (mouse->getMXPos() > button->getMenuMinPosX() && mouse->getMXPos() < button->getMenuMaxPosX()
			&& mouse->getMYPos() < button->getMenuPlayMaxPosY() && mouse->getMYPos() > button->getMenuPlayMinPosY())
		{
			//SceneManager* scene = SceneManager::getInstance();
			//scene->SetNextScene(1);
			SceneManager::getInstance()->SetNextScene(1);
		}
		//OPTIONS
		else if (mouse->getMXPos() > button->getMenuMinPosX()&& mouse->getMXPos() < button->getMenuMaxPosX() 
			&& mouse->getMYPos() < button->getMenuOptionsMaxPosY() && mouse->getMYPos() > button->getMenuOptionsMinPosY())
		{

		}
		//QUIT
		else if (mouse->getMXPos() > button->getMenuMinPosX()&& mouse->getMXPos() < button->getMenuMaxPosX() 
			&& mouse->getMYPos() < button->getMenuQuitMaxPosY() && mouse->getMYPos() > button->getMenuQuitMinPosY())
		{
			SceneManager::getInstance()->SetNextScene(-1);
		}
	}
}

void SceneMenu::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderMeshOnScreen(meshList[MENU_SCREEN], 40, 30, 80, 60);
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