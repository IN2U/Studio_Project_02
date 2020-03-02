#include "race.h"
#include "Mesh_Generation/MeshBuilder.h"
#include "../../glew/include/GL/glew.h"
#include "Texture_Mapping/LoadTGA.h"

void SceneRace::InitMeshList(int Car)
{
	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_LEFT]->textureID = LoadTGA("Image//left.tga");

	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//right.tga");

	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_TOP]->textureID = LoadTGA("Image//top.tga");

	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//bottom.tga");

	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_FRONT]->textureID = LoadTGA("Image//front.tga");

	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BACK]->textureID = LoadTGA("Image//back.tga");

	meshList[GEO_LIGHTSPHERE] = MeshBuilder::GenerateSphere("lightBall", Color(1.f, 1.f, 1.f), 9, 36, 1.f);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");

	switch (Car) {
	case 1:
		meshList[GEO_CAR] = MeshBuilder::GenerateOBJ("Ford_GT", "OBJ//ford_gt.obj");
		meshList[GEO_CAR]->textureID = LoadTGA("Image//ford_gt.tga");
		break;
	case 2:
		meshList[GEO_CAR] = MeshBuilder::GenerateOBJ("Fenyr", "OBJ//fenyr.obj");
		meshList[GEO_CAR]->textureID = LoadTGA("Image//fenyr.tga");
		break;
	case 3:
		meshList[GEO_CAR] = MeshBuilder::GenerateOBJ("Lamborghini", "OBJ//Lamborghini.obj");
		meshList[GEO_CAR]->textureID = LoadTGA("Image//Lamborghini.tga");
		break;
	}

	meshList[GEO_TRACK] = MeshBuilder::GenerateOBJ("Track", "OBJ//racetrack.obj");
	meshList[GEO_TRACK]->textureID = LoadTGA("Image//track.tga");
}

void SceneRace::InitMeshList()
{
	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_LEFT]->textureID = LoadTGA("Image//left.tga");

	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//right.tga");

	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_TOP]->textureID = LoadTGA("Image//top.tga");

	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//bottom.tga");

	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_FRONT]->textureID = LoadTGA("Image//front.tga");

	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BACK]->textureID = LoadTGA("Image//back.tga");

	meshList[GEO_LIGHTSPHERE] = MeshBuilder::GenerateSphere("lightBall", Color(1.f, 1.f, 1.f), 9, 36, 1.f);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");


	meshList[GEO_CAR] = MeshBuilder::GenerateOBJ("Ford_GT", "OBJ//ford_gt.obj");
	meshList[GEO_CAR]->textureID = LoadTGA("Image//ford_gt.tga");


	meshList[GEO_TRACK] = MeshBuilder::GenerateOBJ("Track", "OBJ//racetrack.obj");
	meshList[GEO_TRACK]->textureID = LoadTGA("Image//track.tga");
}