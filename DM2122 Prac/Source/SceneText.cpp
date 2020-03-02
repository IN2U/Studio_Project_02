#include "SceneText.h"
#include "Application.h"
#include "GL/glew.h"
#include "ObjectManager.h"
#include "Mesh_Generation/MeshBuilder.h"
#include "Currency.h"
#include "Vending.h"
#include "NPC.h"
#include "Inventory.h"
#include "shader.hpp"
#include "Utility.h"

#include "Texture_Mapping/LoadTGA.h"

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

SceneText::SceneText() : dFromCarCentre(2),  Car1X(30.f), Car2X(10.f), Car3X(-10.f) , Car4X(-30.f), CarZ(-20.f),
meshList{ 
NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, NULL, NULL }
{
	gameTime = 0.0f;
	bounceTime = 0.0f;
	somethingHappened = false;

	vendingMenuAppear = false;
	vendingID = 0;

	NPCID = 0;

	sunAngle = 0.f;
	spotlightAngle = 0.f;

	anglex = 0.f;

	anglea1 = 0.f;
	angleb1 = 0.f;
	anglec1 = 0.f;

	anglea2 = 0.f;
	angleb2 = 0.f;
	anglec2 = 0.f;

	anglea3 = 0.f;
	angleb3 = 0.f;
	anglec3 = 0.f;

	anglea4 = 0.f;
	angleb4 = 0.f;
	anglec4 = 0.f;

	carRotate = true;
	clickL1 = false;
	clickL2 = false;
	clickL3 = false;
	clickL4 = false;
	clickv = false;
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

	camera.Init(Vector3(0, 6, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));

	Objects = ObjectManager::getInstance();

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

	if (Application::IsKeyPressed(0x35))
	{
		renderHitBox = true;
	}

	if (eUIState == NPC_UI)
	{
		npc[NPCUI].UpdateNPC();
		somethingHappened = npc[NPCUI].SomethingHappened();
	}
	else if (eUIState == VENDING_UI)
	{
		vending[vendingID].UpdateVending();
		somethingHappened = vending[vendingID].SomethingHappened();
	}
	else if (eUIState == INVENTORY_UI)
	{
		inventory->UpdateInventory();
		somethingHappened = inventory->SomethingHappened();
	}

	if (Application::IsKeyPressed('F'))
	{
		if (eUIState != INVENTORY_UI) {
			eUIState = INVENTORY_UI;
			somethingHappened = true;
		}
		else {
			eUIState = DEFAULT_UI;
			somethingHappened = true;
		}
	}

	if (camera.position.z >= -11 && camera.position.z <= -9 && camera.position.x < -37)
	{
		clickv = true;
	}
	if (clickv == true)
	{
		if (eUIState == VENDING_UI)
		{
			if (vendingMenuAppear == false)
			{
				vendingMenuAppear = true;

			}
		}
		else
		{
			eUIState = VENDING_UI;
		}
	}
	if (camera.position.x > -35 && vendingMenuAppear == true)
	{
		clickv = false;
		vendingMenuAppear = false;
	}

	// Phone
	if (Application::IsKeyPressed('C'))
	{
		if (phoneUse == false)
		{
			phoneUse = true;
			somethingHappened = true;
		}

		else
		{
			phoneUse = false;
			somethingHappened = true;
		}
	}

	SceneManager* scene = SceneManager::getInstance();

	if (Application::IsKeyPressed('M'))
	{
		scene->SetNextScene(STATE::TIC_TAC_TOE_SCENE);
	}

	// Open options
	if (Application::IsKeyPressed(VK_ESCAPE))
	{
			scene->SetNextScene(STATE::MENU_SCENE);
	}

	RevolveSun(dt);
	UpdateSpotlights(dt);

	currency->AddCurrency(int(currency->ReturnRegeneration() * dt));
	currency->SortAndUpdateCurrency();

	camera.Update(dt, Objects);
	CalculateFrameRate();

	if (somethingHappened) {
		bounceTime = gameTime + 0.2;
	}

	if (carRotate == true)
	{
		anglex += (float)(0.5);
	}

	if (camera.position.x > 15 && camera.position.x < 17 && camera.position.z <= -17)
	{
		NPCID = 1;
		npc[NPCID].SetToDefaultTipState();
		clickL1 = true;
	}
	if (clickL1 == true)
	{
		if (eUIState == DEFAULT_UI || eUIState == VENDING_UI || eUIState == INVENTORY_UI) {
			eUIState = NPC_UI;
			somethingHappened = true;
		}
		anglea1 -= (float)(1.5);
		angleb1 -= (float)(5.5);
		anglec1 += (float)(4.5);
	}
	if (anglea1 <= -30)
	{
		clickL1 = false;
	}
	if (clickL1 == false && anglea1 < 0)
	{

		anglea1 += (float)(1.5);
		angleb1 += (float)(5.5);
		anglec1 -= (float)(4.5);
	}

	if (camera.position.x > 35 && camera.position.x < 37 && camera.position.z <= -17)
	{
		NPCID = 0;
		npc[NPCID].SetToDefaultTipState();
		clickL2 = true;
	}
	if (clickL2 == true)
	{
		if (eUIState == DEFAULT_UI || eUIState == VENDING_UI || eUIState == INVENTORY_UI) {
			eUIState = NPC_UI;
			somethingHappened = true;
		}

		anglea2 -= (float)(1.5);
		angleb2 -= (float)(5.5);
		anglec2 += (float)(4.5);
	}
	if (anglea2 <= -30)
	{
		clickL2 = false;
	}
	if (clickL2 == false && anglea2 < 0)
	{
		anglea2 += (float)(1.5);
		angleb2 += (float)(5.5);
		anglec2 -= (float)(4.5);
	}

	if (camera.position.x > -17 && camera.position.x < -15 && camera.position.z <= -17)
	{
		NPCID = 2;
		npc[NPCID].SetToDefaultTipState();
		clickL3 = true;
	}
	if (clickL3 == true)
	{
		if (eUIState == DEFAULT_UI || eUIState == VENDING_UI || eUIState == INVENTORY_UI) {
			eUIState = NPC_UI;
			somethingHappened = true;
		}
		anglea3 -= (float)(1.5);
		angleb3 -= (float)(5.5);
		anglec3 += (float)(4.5);
	}
	if (anglea3 <= -30)
	{
		clickL3 = false;
	}
	if (clickL3 == false && anglea3 < 0)
	{
		anglea3 += (float)(1.5);
		angleb3 += (float)(5.5);
		anglec3 -= (float)(4.5);
	}

	if (camera.position.x > -37 && camera.position.x < -35 && camera.position.z <= -17)
	{
		NPCID = 3;
		npc[NPCID].SetToDefaultTipState();
		clickL4 = true;
	}
	if (clickL4 == true)
	{
		if (eUIState == DEFAULT_UI || eUIState == VENDING_UI || eUIState == INVENTORY_UI) {
			eUIState = NPC_UI;
			somethingHappened = true;
		}
		anglea4 -= (float)(1.5);
		angleb4 -= (float)(5.5);
		anglec4 += (float)(4.5);
	}
	if (anglea4 <= -30)
	{
		clickL4 = false;
	}
	if (clickL4 == false && anglea4 < 0)
	{
		anglea4 += (float)(1.5);
		angleb4 += (float)(5.5);
		anglec4 -= (float)(4.5);
	}

	if (camera.position.z > -17 && eUIState == NPC_UI)
	{
		eUIState = DEFAULT_UI;
		somethingHappened = true;
	}

	if (Application::IsKeyPressed(VK_F1)) {
		scene->SetNextScene(3,1);
	}
	if (Application::IsKeyPressed(VK_F2)) {
		scene->SetNextScene(3,2);
	}
	if (Application::IsKeyPressed(VK_F3)) {
		scene->SetNextScene(3,3);
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
	for (int i = 0; i < 10; ++i)
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

	Objects->Update();
	Object* temp;

	RenderSun();

	temp = Objects->AddObject("RaceTrack", meshList[GEO_RACE_TRACK], true);
	Objects->getLib().push_back(temp);

	RenderFloor();

	RenderNPC();

	RenderSpotlight();

	RenderCar();

	RenderTurntable();

	RenderBuilding();


	RenderVendingMachine();

	temp = Objects->AddObject("User", meshList[GEO_USER], true);
	temp->Transform('T', camera.position.x, camera.position.y, camera.position.z);
	Objects->getLib().push_back(temp);
	Objects->getObject("User")->AddHitbox(Vector3(0, 0, 0), Vector3(2, 3, 2));

	if (phoneUse == true)
	{
		RenderPhone();
	}

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
	case NPC_UI: RenderNPCUI(npc[NPCUI]);
		break;
	case VENDING_UI: RenderVendingUI(vendingID);
		break;
	case INVENTORY_UI: RenderInventoryUI();
		break;
	}

	if (renderHitBox == true) {
		RenderHitbox(Objects);
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

void SceneText::RenderHitbox(ObjectManager*& Objects) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int i = 0; i < Objects->getLib().size(); i++) {
		for (int j = 0; j < Objects->getLib()[i]->getHitboxLib().size(); j++) {
			modelStack.PushMatrix();
			Objects->getLib()[i]->Render(modelStack);
			Vector3 temp = Objects->getLib()[i]->getHitboxLib()[j]->getDisplacement();
			modelStack.Translate(temp.x, temp.y, temp.z);
			if (Objects->getLib()[i]->getHitboxLib()[j]->getDegrees() != 0) {
				temp = Objects->getLib()[i]->getHitboxLib()[j]->getRotate();
				modelStack.Rotate(Objects->getLib()[i]->getHitboxLib()[j]->getDegrees(), temp.x, temp.y, temp.z);
			}
			temp = Objects->getLib()[i]->getHitboxLib()[j]->getDimensions();
			Mesh* temp2 = MeshBuilder::GenerateCuboid("Hitbox", Color(0, 1, 0), temp.x * 2, temp.y * 2, temp.z * 2);
			RenderMesh(temp2, false);
			modelStack.PopMatrix();
		}
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
