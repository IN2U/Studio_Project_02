#include "SceneOptions.h"
#include "Application.h"
#include "GL\glew.h"
#include "MeshBuilder.h"
#include "LoadTGA.h"
#include "shader.hpp"
#include <Mtx44.h>
#include "SceneManager.h"
#include "SceneText.h"

#include "Helper/ButtonPos.h"
#include "Helper/Cursor.h"

#include "Global_Constants/TEXT_BUTTON.h"
#include "Global_Constants/GAME_STATES.h"

SceneOptions::SceneOptions() : meshList{ NULL, NULL, NULL, NULL }
{
}

SceneOptions::~SceneOptions()
{
}

void SceneOptions::Init()
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

void SceneOptions::Update(double dt)
{
	if (Application::IsKeyPressed(MK_LBUTTON))
	{
		Cursor* mouse = Cursor::getInstance();
		Button* button = Button::getInstance();

		SceneManager* scene = SceneManager::getInstance();

		// CONTROLS
		if (mouse->getMXPos() > button->getButtonMinPosX() && mouse->getMXPos() < button->getButtonMaxPosX()
			&& mouse->getMYPos() < button->getButton1MaxPosY() && mouse->getMYPos() > button->getButton1MinPosY())
		{

		}
		// AUDIO
		else if (mouse->getMXPos() > button->getButtonMinPosX() && mouse->getMXPos() < button->getButtonMaxPosX()
			&& mouse->getMYPos() < button->getButton2MaxPosY() && mouse->getMYPos() > button->getButton2MinPosY())
		{

		}
		// BACK
		else if (mouse->getMXPos() > button->getButtonMinPosX() && mouse->getMXPos() < button->getButtonMaxPosX()
			&& mouse->getMYPos() < button->getButton3MaxPosY() && mouse->getMYPos() > button->getButton3MinPosY())
		{
			scene->SetNextScene(STATE::MENU_SCENE);
		}
	}

	//  options
	//if (Application::IsKeyPressed(VK_ESCAPE))
	//{
	//	SceneManager* scene = SceneManager::getInstance();
	//	scene->SetNextScene(1);
	//}
}

void SceneOptions::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderMeshOnScreen(meshList[OPTIONS_SCREEN], TxtB::CENTRE_OF_SCREEN_X, 30, 80, 60);

	RenderMeshOnScreen(meshList[BUTTON], TxtB::CENTRE_OF_SCREEN_X, 35.f, TxtB::BUTTON_SIZE_X, TxtB::BUTTON_SIZE_Y);
	RenderMeshOnScreen(meshList[BUTTON], TxtB::CENTRE_OF_SCREEN_X, 29.f, TxtB::BUTTON_SIZE_X, TxtB::BUTTON_SIZE_Y);
	RenderMeshOnScreen(meshList[BUTTON], TxtB::CENTRE_OF_SCREEN_X, 23.f, TxtB::BUTTON_SIZE_X, TxtB::BUTTON_SIZE_Y);

	RenderTextOnScreen(meshList[TEXT], "Controls",	Color(TxtB::TEXT_COLOR, TxtB::TEXT_COLOR, TxtB::TEXT_COLOR), TxtB::TEXT_SIZE, 9.6f, TxtB::TEXT_DISTANCE_Y);
	RenderTextOnScreen(meshList[TEXT], "Audio",		Color(TxtB::TEXT_COLOR, TxtB::TEXT_COLOR, TxtB::TEXT_COLOR), TxtB::TEXT_SIZE, 11.2f, TxtB::TEXT_DISTANCE_Y - 2);
	RenderTextOnScreen(meshList[TEXT], "Back",		Color(TxtB::TEXT_COLOR, TxtB::TEXT_COLOR, TxtB::TEXT_COLOR), TxtB::TEXT_SIZE, 11.5f, TxtB::TEXT_DISTANCE_Y - 4);
}

void SceneOptions::Exit()
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