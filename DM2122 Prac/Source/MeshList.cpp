#include "SceneText.h"
#include "SceneMenu.h"
#include "SceneOptions.h"
#include "MeshBuilder.h"
#include "../../glew/include/GL/glew.h"
#include "LoadTGA.h"

void SceneMenu::InitMeshList()
{
	meshList[MENU_SCREEN] = MeshBuilder::GenerateQuad("Menu_Screen", Color(1, 1, 1), 1.f, 1.f);
	meshList[MENU_SCREEN]->textureID = LoadTGA("Image//menu-screen.tga");

	meshList[BUTTON] = MeshBuilder::GenerateQuad("Button", Color(0.4, 0.4, 0.4), 1.f, 1.f);

	meshList[TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[TEXT]->textureID = LoadTGA("Image//arial-rounded-mt-bold.tga");
}

void SceneOptions::InitMeshList()
{
	meshList[OPTIONS_SCREEN] = MeshBuilder::GenerateQuad("Options_Screen", Color(1, 1, 1), 1.f, 1.f);
	meshList[OPTIONS_SCREEN]->textureID = LoadTGA("Image//options-screen.tga");

	meshList[BUTTON] = MeshBuilder::GenerateQuad("Button", Color(0.4, 0.4, 0.4), 1.f, 1.f);

	meshList[TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[TEXT]->textureID = LoadTGA("Image//arial-rounded-mt-bold.tga");
}

void SceneText::InitMeshList()
{
	//DAY SKYBOX
	meshList[SKYBOX_LEFT_DAY] = MeshBuilder::GenerateQuad("sb_left_day", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_LEFT_DAY]->textureID = LoadTGA("Image//sb_left_day.tga");

	meshList[SKYBOX_RIGHT_DAY] = MeshBuilder::GenerateQuad("sb_right_day", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_RIGHT_DAY]->textureID = LoadTGA("Image//sb_right_day.tga");

	meshList[SKYBOX_TOP_DAY] = MeshBuilder::GenerateQuad("sb_top_day", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_TOP_DAY]->textureID = LoadTGA("Image//sb_top_day.tga");

	meshList[SKYBOX_BOTTOM_DAY] = MeshBuilder::GenerateQuad("sb_bottom_day", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_BOTTOM_DAY]->textureID = LoadTGA("Image//sb_bottom_day.tga");

	meshList[SKYBOX_FRONT_DAY] = MeshBuilder::GenerateQuad("sb_front_day", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_FRONT_DAY]->textureID = LoadTGA("Image//sb_front_day.tga");

	meshList[SKYBOX_BACK_DAY] = MeshBuilder::GenerateQuad("sb_back_day", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_BACK_DAY]->textureID = LoadTGA("Image//sb_back_day.tga");
	//~

	//NIGHT SKYBOX
	meshList[SKYBOX_LEFT_NIGHT] = MeshBuilder::GenerateQuad("sb_left_night", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_LEFT_NIGHT]->textureID = LoadTGA("Image//sb_left_night.tga");

	meshList[SKYBOX_RIGHT_NIGHT] = MeshBuilder::GenerateQuad("sb_right_night", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_RIGHT_NIGHT]->textureID = LoadTGA("Image//sb_right_night.tga");

	meshList[SKYBOX_TOP_NIGHT] = MeshBuilder::GenerateQuad("sb_top_night", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_TOP_NIGHT]->textureID = LoadTGA("Image//sb_top_night.tga");

	meshList[SKYBOX_BOTTOM_NIGHT] = MeshBuilder::GenerateQuad("sb_bottom_night", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_BOTTOM_NIGHT]->textureID = LoadTGA("Image//sb_bottom_night.tga");

	meshList[SKYBOX_FRONT_NIGHT] = MeshBuilder::GenerateQuad("sb_front_night", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_FRONT_NIGHT]->textureID = LoadTGA("Image//sb_front_night.tga");

	meshList[SKYBOX_BACK_NIGHT] = MeshBuilder::GenerateQuad("sb_back_night", Color(1, 1, 1), 1.f, 1.f);
	meshList[SKYBOX_BACK_NIGHT]->textureID = LoadTGA("Image//sb_back_night.tga");
	//~
	
	meshList[GEO_SUN] = MeshBuilder::GenerateSphere("sun", Color(1.f, 1.f, 1.f), 9, 36, 1.f);

	meshList[PLAYER_POINTER] = MeshBuilder::GenerateQuad("pointer", Color(1, 1, 1), 1.f, 1.f);
	meshList[PLAYER_POINTER]->textureID = LoadTGA("Image//arrow_pointer.tga");

	meshList[MINIMAP_BORDER] = MeshBuilder::GenerateQuad("minimap_border", Color(1, 1, 1), 1.f, 1.f);
	meshList[MINIMAP_BORDER]->textureID = LoadTGA("Image//minimap_border.tga");

	meshList[GEO_CHAR] = MeshBuilder::GenerateQuad("char", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_CHAR]->textureID = LoadTGA("Image//char.tga");

	meshList[GEO_DICE] = MeshBuilder::GenerateOBJ("Dice", "OBJ//doorman.obj");
	meshList[GEO_DICE]->textureID = LoadTGA("Image//doorman.tga");

	meshList[GEO_LIGHTSPHERE] = MeshBuilder::GenerateSphere("lightBall", Color(1.f, 1.f, 1.f), 9, 36, 1.f);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");
}