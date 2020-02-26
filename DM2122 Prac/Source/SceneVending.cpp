#include "SceneVending.h"
#include "GL\glew.h"
#include "shader.hpp"
#include "Application.h"
#include "Helper/Window.h"
#include "SceneManager.h"
#include "Global_Constants/GAME_STATES.h"
#include "Global_Constants/TEXT_BUTTON.h"

#define ROT_LIMIT 45.f;
#define SCALE_LIMIT 5.f;
#define LSPEED 10.f

Currency* currency2 = Currency::GetInstance();

//Inventory* inventory2 = Inventory::GetInstance();

SceneVending::SceneVending()
{
	gameTime = 0.0f;
	bounceTime = 0.0f;
	buttonTrigger = 0;
	somethingHappened = false;
	goingToBuyItem = false;
	itemBought = false;
	itemChosen = "";
	itemIssued = "";
	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}
}

SceneVending::~SceneVending()
{

}

void SceneVending::Init()
{
	glClearColor(0.f, 0.f, 0.f, 0.f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");

	InitShaderUniforms();

	glUseProgram(m_programID);

	InitMeshList();

	gameTime = 0;

	gameTime = 0;

	//currency->SortAndUpdateCurrency();
}

void SceneVending::Update(double dt)
{
	somethingHappened = false;

	gameTime += dt;

	if (bounceTime > gameTime) {
		return;
	}

	if (buttonTrigger >= 2)
	{
		goingToBuyItem = true;
	}

	if (goingToBuyItem == false)
	{
		checkInput();
	}

	if (goingToBuyItem)
	{
		if (Application::IsKeyPressed('Y'))
		{
			//inventory2->AddItemIntoInventory(vending.returnItem(std::stoi(itemChosen)));
			vending.BuyItem(std::stoi(itemChosen));
			itemIssued = vending.ReturnItemName(std::stoi(itemChosen));
			itemChosen = "";
			buttonTrigger = 0;
			somethingHappened = true;
			goingToBuyItem = false;
			itemBought = true;
		}
		if (Application::IsKeyPressed('N'))
		{
			itemChosen = "";
			buttonTrigger = 0;
			somethingHappened = true;
			goingToBuyItem = false;
		}
	}

	if (Application::IsKeyPressed('G'))
	{
		//inventory2->PrintInventory();
	}
	currency2->AddCurrency(100 * dt);
	currency2->SortAndUpdateCurrency();

	if (somethingHappened) {
		bounceTime = gameTime + 0.5;
	}
}

void SceneVending::Render()
{
	//Clear color & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderTextOnScreen(meshList[VENDING_TEXT], currency2->ReturnAdjustedCurrency(), Color(0, 1, 0), 4, 13, 13);
	RenderMeshOnScreen(meshList[GEO_VENDING], TxtB::CENTRE_OF_SCREEN_X, 30, 40, 40);

	if (!goingToBuyItem) {
		RenderTextOnScreen(meshList[VENDING_TEXT], "What would you like to buy?", Color(0, 1, 0), 2.5f, 3.f, 2.f);
		RenderTextOnScreen(meshList[VENDING_TEXT], itemChosen, Color(0, 1, 0), 3.f, 1.f, 5.f);
	}
	
	if (goingToBuyItem)
		RenderTextOnScreen(meshList[VENDING_TEXT], "Buy item " + itemChosen + " ?(Y/N)", Color(0, 1, 0), 2.5f, 2.2f, 2.f);

	if (itemBought) {
		RenderTextOnScreen(meshList[VENDING_TEXT], "Item " + itemIssued + " bought.", Color(0, 1, 0), 2.3f, 2.2f, 22.f);
	}
}

void SceneVending::Exit()
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



void SceneVending::checkInput()
{
	if (Application::IsKeyPressed('1')) {
		itemChosen += "1";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('2')) {
		itemChosen += "2";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('3')) {
		itemChosen += "3";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('4')) {
		itemChosen += "4";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('5')) {
		itemChosen += "5";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('6')) {
		itemChosen += "6";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('7')) {
		itemChosen += "7";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('8')) {
		itemChosen += "8";
		buttonTrigger++;
		somethingHappened = true;
	}
	else if (Application::IsKeyPressed('9')) {
		itemChosen += "9";
		buttonTrigger++;
		somethingHappened = true;
	}
	if (Application::IsKeyPressed(VK_RETURN)) {
		buttonTrigger++;
		somethingHappened = true;
	}
}