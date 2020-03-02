#include "race.h"
#include "GL\glew.h"
#include "Application.h"
#include <Mtx44.h>
#include "shader.hpp"
#include "Mesh_Generation/MeshBuilder.h"
#include "Utility.h"
#include "Texture_Mapping/LoadTGA.h"
#include "SceneManager.h"

#define ROT_LIMIT 45.f;
#define SCALE_LIMIT 5.f;
#define LSPEED 10.f

SceneRace::SceneRace()
{
	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}
}

SceneRace::~SceneRace()
{
}

void SceneRace::Init()
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	renderHitbox = false;

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);
	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	camera.Init(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));
	Objects = ObjectManager::getInstance();

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);

	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");


	InitShaderUniforms();

	glUseProgram(m_programID);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);

	InitLightSettings();

	InitMeshList(1);
}

void SceneRace::Init(int Car)
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	renderHitbox = false;

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);
	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	camera.Init(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0));
	Objects = ObjectManager::getInstance();

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);

	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");


	InitShaderUniforms();

	glUseProgram(m_programID);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);

	InitLightSettings();

	InitMeshList(Car);
}

void SceneRace::Update(double dt)
{
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
		renderHitbox = false;
	}
	else if (Application::IsKeyPressed(0x36))
	{
		renderHitbox = true;
	}

	if (Application::IsKeyPressed(VK_F2))
	{
		//to do: switch light type to POINT and pass the information to
		light[0].type = Light::LIGHT_POINT;
	}
	else if (Application::IsKeyPressed(VK_F3))
	{
		//to do: switch light type to DIRECTIONAL and pass the
		light[0].type = Light::LIGHT_DIRECTIONAL;
	}
	else if (Application::IsKeyPressed(VK_F4))
	{
		//to do: switch light type to SPOT and pass the information to
		light[0].type = Light::LIGHT_SPOT;
	}
	//camera.Update(dt, Car->getPos(), Car->getRotation());
	camera.Update(dt, Car->getPos(), Car->getRotation());

	CalculateFrameRate();
	carControls(dt, Car);
	Car->Update(dt, Objects);
}

void SceneRace::Render()
{
	//Clear color & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();

	// passing the light direction if it is a direction light	
	if (light[0].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(light[0].position.x, light[0].position.y, light[0].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
	}
	// if it is spot light, pass in position and direction 
	else if (light[0].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		// default is point light (only position since point light is 360 degrees)
		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	}

	RenderSkybox();

	Objects->Update();
	Object* temp;

	temp = Objects->AddObject("Light", meshList[GEO_LIGHTSPHERE], false);
	temp->Transform('T', light[0].position.x, light[0].position.y, light[0].position.z);
	Objects->getLib().push_back(temp);
	Vector3 temp1 = Vector3(0, 0, 0);
	Vector3 temp2 = Vector3(1, 1, 1);
	Objects->getObject("Light")->AddHitbox(temp1, temp2);

	temp = Objects->AddObject("Track", meshList[GEO_TRACK], true);
	temp->Transform('T', 0, -5, 18.5);
	temp->Transform('S', 2.5, 2.5, 2.5);
	temp->AddHitbox(Vector3(11.9, 0.5, -2), Vector3(0.2, 0.5, 12));
	temp->AddHitbox(Vector3(9.4, 0.5, -2), Vector3(0.2, 0.5, 10));
	temp->AddHitbox(Vector3(-11, 0.5, 7), Vector3(0.2, 0.5, 6));
	temp->AddHitbox(Vector3(-8.2, 0.5, 5), Vector3(0.4, 0.5, 4));
	temp->AddHitbox(Vector3(-12.3, 0.5, -17), Vector3(0.2, 0.5, 6));
	temp->AddHitbox(Vector3(-9.8, 0.5, -17), Vector3(0.2, 0.5, 6));
	temp->AddHitbox(Vector3(-10, 0.5, -4.8), Vector3(2, 0.5, 2.1));
	temp->AddHitbox(Vector3(-5.5, 0.5, -4.8), Vector3(0.2, 0.5, 2.1));
	temp->AddHitbox(Vector3(7, 0.5, -14.2), Vector3(1, 0.5, 0.2));
	temp->AddHitbox(Vector3(8, 0.5, -17), Vector3(1, 0.5, 0.2));
	temp->AddHitbox(Vector3(9, 0.5, -13.2), Vector3(1, 0.5, 0.2), -55.f, Vector3(0, 1, 0));
	temp->AddHitbox(Vector3(11, 0.5, -15.7), Vector3(1, 0.5, 0.2), -45.f, Vector3(0, 1, 0));
	temp->AddHitbox(Vector3(1.8, 0.5, -22.1), Vector3(6., 0.5, 0.2), -54.f, Vector3(0,1,0));
	temp->AddHitbox(Vector3(1, 0.5, -18.8), Vector3(7, 0.5, 0.2), -54.f, Vector3(0, 1, 0));
	temp->AddHitbox(Vector3(-6, 0.5, -27.4), Vector3(5, 0.5, 0.2));
	temp->AddHitbox(Vector3(-6, 0.5, -24.8), Vector3(2.5, 0.5, 0.2));
	temp->AddHitbox(Vector3(7, 0.5, 11.5), Vector3(5, 0.5, 0.2));
	temp->AddHitbox(Vector3(6, 0.5, 8.5), Vector3(2.5, 0.5, 0.2));
	temp->AddHitbox(Vector3(-2.5, 0.5, 8.2), Vector3(1.5, 0.5, 0.2));
	temp->AddHitbox(Vector3(-2.5, 0.5, 6.2), Vector3(3, 0.5, 0.2));
	temp->AddHitbox(Vector3(1, 0.5, 10), Vector3(1, 0.5, 0.2), -55.f, Vector3(0, 1, 0));
	temp->AddHitbox(Vector3(2, 0.5, 7), Vector3(1, 0.5, 0.2), -45.f, Vector3(0, 1, 0));
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("Car", meshList[GEO_CAR], true);
	temp->Transform('S', 0.2, 0.2, 0.2);
	temp->Transform('T', Car->getPos().x, Car->getPos().y, Car->getPos().z);
	Objects->getLib().push_back(temp);
	Objects->getObject("Car")->AddHitbox(Vector3(0, 0, 0), Vector3(2.5, 1.5, 6));


	// RenderMesh
	for (int i = 0; i < Objects->getLib().size(); i++) {
		modelStack.PushMatrix();
		Objects->getLib()[i]->Render(modelStack);
		if (Objects->getLib()[i]->getID() == "Car") {
			modelStack.Rotate(Car->getRotation());
		}
		RenderMesh(Objects->getLib()[i]->getMesh(), Objects->getLib()[i]->getLight());
		modelStack.PopMatrix();
	}

	if (renderHitbox == true) {
		RenderHitbox(Objects);
	}

}

void SceneRace::Exit()
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

void SceneRace::RenderMesh(Mesh* mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	modelView = viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);


	if (enableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}

	if (mesh->textureID > 0) {
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else {
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}
	mesh->Render(); //this line should only be called once in the whole function

	if (mesh->textureID > 0) glBindTexture(GL_TEXTURE_2D, 0);
}

void SceneRace::CalculateFrameRate()
{
	static float framesPerSecond = 0.0f;
	static int fps;
	static float lastTime = 0.0f;
	float currentTime = GetTickCount() * 0.001f;
	++framesPerSecond;
	printf("Current Frames Per Second: %d\n\n", fps);
	if (currentTime - lastTime > 1.0f)
	{
		lastTime = currentTime;
		fps = (int)framesPerSecond;
		framesPerSecond = 0;
	}
}

void SceneRace::RenderHitbox(ObjectManager*& Objects) {
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

void SceneRace::RenderText(Mesh* mesh, std::string text, Color color, float size, float x, float y, float z) {

	if (!mesh || mesh->textureID <= 0) { return; }

	modelStack.PushMatrix();
	modelStack.LoadIdentity();
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, z);
	glDisable(GL_DEPTH_TEST);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for (unsigned i = 0; i < text.length(); ++i) {
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0);
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);

	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	glEnable(GL_DEPTH_TEST);
}

void SceneRace::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if (!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);

	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for (unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();

	glEnable(GL_DEPTH_TEST);
}