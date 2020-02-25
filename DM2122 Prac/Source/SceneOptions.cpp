#include "SceneOptions.h"
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

SceneOptions::SceneOptions()
{
	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}
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
		if (mouse->getMXPos() > button->getOptionsMinPosX() && mouse->getMXPos() < button->getOptionsMaxPosX()
			&& mouse->getMYPos() < button->getOptionsControlsMaxPosY() && mouse->getMYPos() > button->getOptionsControlsMinPosY())
		{

		}
		// AUDIO
		else if (mouse->getMXPos() > button->getOptionsMinPosX() && mouse->getMXPos() < button->getOptionsMaxPosX()
			&& mouse->getMYPos() < button->getOptionsAudioMaxPosY() && mouse->getMYPos() > button->getOptionsAudioMinPosY())
		{

		}
		// BACK
		else if (mouse->getMXPos() > button->getOptionsMinPosX() && mouse->getMXPos() < button->getOptionsMaxPosX()
			&& mouse->getMYPos() < button->getOptionsBackMaxPosY() && mouse->getMYPos() > button->getOptionsBackMinPosY())
		{
			scene->SetNextScene(0);
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

	RenderMeshOnScreen(meshList[OPTIONS_SCREEN], 40, 30, 80, 60);

	RenderMeshOnScreen(meshList[BUTTON], 40.f, 35.f, 24.f, 4.5f);
	RenderMeshOnScreen(meshList[BUTTON], 40.f, 29.f, 24.f, 4.5f);
	RenderMeshOnScreen(meshList[BUTTON], 40.f, 23.f, 24.f, 4.5f);

	RenderTextOnScreen(meshList[TEXT], "Controls", Color(0, 0, 0), 3.f, 9.6f, 11.25f);
	RenderTextOnScreen(meshList[TEXT], "Audio", Color(0, 0, 0), 3.f, 11.2f, 9.25f);
	RenderTextOnScreen(meshList[TEXT], "Back", Color(0, 0, 0), 3.f, 11.5f, 7.25f);
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