#include "SceneText.h"
#include "Application.h"
#include "GL/glew.h"
#include "ObjectManager.h"
#include "Currency.h"
#include "Vending.h"
#include "NPC.h"
#include "Inventory.h"
#include "shader.hpp"
#include "Utility.h"

#include "Texture_Mapping/LoadTGA.h";

#include "Helper/Cursor.h"
#include "Helper/Window.h"

#include "Global_Constants/GAME_STATES.h"

#include "SceneManager.h"

#define ROT_LIMIT 45.f;
#define SCALE_LIMIT 5.f;
#define LSPEED 10.f

Currency* currency = Currency::GetInstance();

Inventory* inventory = Inventory::GetInstance();

UISTATE eUIState = DEFAULT_UI;

SceneText::SceneText()
{
	gameTime = 0.0f;
	bounceTime = 0.0f;
	somethingHappened = false;

	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}
}

SceneText::~SceneText()
{
}

void SceneText::Init()
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);
	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	camera.Init(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));

	// Top-down view for minimap
	minimapCamera.Init(Vector3(0, 10, 0), Vector3(0, 0, 0), Vector3(0, 0, -1));

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);
	// For minimap
	projectionStack_mini.LoadMatrix(projection);
	
	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");

	InitShaderUniforms();
	
	InitLightShaderUniforms();

	glUseProgram(m_programID);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);

	InitLightSettings();

	InitMeshList();

	gameTime = 0;

	currency->SortAndUpdateCurrency();
}

void SceneText::Update(double dt)
{
	somethingHappened = false;

	gameTime += dt;

	if (bounceTime > gameTime) {
		return;
	}

	if (Application::IsKeyPressed(0x31))
	{
		glDisable(GL_CULL_FACE);
	}
	else if (Application::IsKeyPressed(0x32))
	{
		glEnable(GL_CULL_FACE);
	}
	else if (Application::IsKeyPressed(0x33))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else if (Application::IsKeyPressed(0x34))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else if (Application::IsKeyPressed(0x35))
	{
		renderHitBox = true;
	}
	
	if (Application::IsKeyPressed('I'))
		light[0].position.z -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('K'))
		light[0].position.z += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('J'))
		light[0].position.x -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('L'))
		light[0].position.x += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('O'))
		light[0].position.y -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('P'))
		light[0].position.y += (float)(LSPEED * dt);

	if (Application::IsKeyPressed('Q'))
	{
		//to do: switch light type to POINT and pass the information to
		light[0].type = Light::LIGHT_POINT;
	}
	else if (Application::IsKeyPressed('W'))
	{
		//to do: switch light type to DIRECTIONAL and pass the
		light[0].type = Light::LIGHT_DIRECTIONAL;
	}
	else if (Application::IsKeyPressed('E'))
	{
		//to do: switch light type to SPOT and pass the information to
		light[0].type = Light::LIGHT_SPOT;
	}

	// Open options
	if (Application::IsKeyPressed(VK_ESCAPE))
	{
		SceneManager* scene = SceneManager::getInstance();
		scene->SetNextScene(STATE::MENU_SCENE);
	}

	// Updates sun pos
	sun.revolve(dt);

	// Updates sunlight pos
	light[1].position.Set(sun.getX(), sun.getY(), sun.getZ());

	// Night
	if (sun.getAngle() > 180)
	{
		light[1].power = 0;
		glUniform1f(m_parameters[U_LIGHT_SUN_POWER], light[1].power);
	}
	// Morning
	else if (sun.getAngle() < 90)
	{
		light[1].power += sun.getIntensity();
		glUniform1f(m_parameters[U_LIGHT_SUN_POWER], light[1].power);
	}
	// Afternoon
	else if (sun.getAngle() > 90)
	{
		light[1].power -= sun.getIntensity();
		glUniform1f(m_parameters[U_LIGHT_SUN_POWER], light[1].power);
	}

	if (eUIState == NPC_UI)
	{
		npc[0].UpdateNPC();
		somethingHappened = npc[0].SomethingHappened();
	}
	else if (eUIState == VENDING_UI)
	{
		vending[0].UpdateVending();
		somethingHappened = vending[0].SomethingHappened();
	}
	else if (eUIState == INVENTORY_UI)
	{
		inventory->UpdateInventory();
		somethingHappened = inventory->SomethingHappened();
	}

	if (Application::IsKeyPressed('B'))
	{
		if (eUIState == DEFAULT_UI) {
			eUIState = NPC_UI;
			somethingHappened = true;
		}
		else {
			eUIState = DEFAULT_UI;
			somethingHappened = true;
		}
	}

	if (Application::IsKeyPressed('V'))
	{
		eUIState = VENDING_UI;
	}

	if (Application::IsKeyPressed('F'))
	{
		//inventory->PrintInventory();
		eUIState = INVENTORY_UI;
	}

	currency->AddCurrency(100 * dt);
	currency->SortAndUpdateCurrency();

	camera.Update(dt);
	CalculateFrameRate();

	if (somethingHappened) {
		bounceTime = gameTime + 0.125;
	}
}

void SceneText::Render()
{
	//Clear color & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Sets the viewport for main scene
	glViewport(0, 0, Window::getInstance()->getWidth(), Window::getInstance()->getHeight());

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();

	// Pass light info to shader
	for (int i = 0; i < 3; ++i)
	{
		// passing the light direction if it is a direction light	
		if (light[i].type == Light::LIGHT_DIRECTIONAL)
		{
			Vector3 lightDir(light[i].position.x, light[i].position.y, light[i].position.z);
			Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
			glUniform3fv(m_parameters[7 + i * 11], 1, &lightDirection_cameraspace.x);
		}
		// if it is spot light, pass in position and direction 
		else if (light[i].type == Light::LIGHT_SPOT)
		{
			Position lightPosition_cameraspace = viewStack.Top() * light[i].position;
			glUniform3fv(m_parameters[7 + i * 11], 1, &lightPosition_cameraspace.x);
			Vector3 spotDirection_cameraspace = viewStack.Top() * light[i].spotDirection;
			glUniform3fv(m_parameters[14 + i * 11], 1, &spotDirection_cameraspace.x);
		}
		else
		{
			// default is point light (only position since point light is 360 degrees)
			Position lightPosition_cameraspace = viewStack.Top() * light[i].position;
			glUniform3fv(m_parameters[7 + i * 11], 1, &lightPosition_cameraspace.x);
		}
	}

	RenderSkybox();

	ObjectManager* Objects = ObjectManager::getInstance();
	Objects->Update();
	Object* temp;
	
	temp = Objects->AddObject("Sun", meshList[GEO_SUN], false);
	temp->Transform('T', sun.getX(), sun.getY(), sun.getZ());
	temp->Transform('S', 0.5f, 0.5f, 0.5f);
	Objects->getLib().push_back(temp);

	/*temp = Objects->AddObject("One_1", meshList[ONE_1], true);
	Objects->getLib().push_back(temp);*/

	RenderNPC();
	RenderSpotlight();

	modelStack.PushMatrix();
	modelStack.Translate(-4.5f, 1.25f, 0.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_LIGHTSPHERE], false);
	modelStack.PopMatrix();

	// RenderMesh
	for (unsigned int i = 0; i < Objects->getLib().size(); i++) {
		modelStack.PushMatrix();
		Objects->getLib()[i]->Render(modelStack);
		RenderMesh(Objects->getLib()[i]->getMesh(), Objects->getLib()[i]->getLight());
		modelStack.PopMatrix();
	}

	switch (eUIState)
	{
	case DEFAULT_UI: RenderUI();
		break;
	case NPC_UI: RenderNPCUI(npc[0]);
		break;
	case VENDING_UI: RenderVendingUI();
		break;
	case INVENTORY_UI: RenderInventoryUI();
		break;
	}

	RenderMinimap();

	glViewport(0, 0, Window::getInstance()->getWidth(), Window::getInstance()->getHeight());
}

void SceneText::Exit()
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

void SceneText::CalculateFrameRate()
{
	static float framesPerSecond = 0.0f;
	static int fps;
	static float lastTime = 0.0f;
	float currentTime = GetTickCount64() * 0.001f;
	++framesPerSecond;
	//printf("Current Frames Per Second: %d\n\n", fps);
	if (currentTime - lastTime > 1.0f)
	{
		lastTime = currentTime;
		fps = (int)framesPerSecond;
		framesPerSecond = 0;
	}
}
