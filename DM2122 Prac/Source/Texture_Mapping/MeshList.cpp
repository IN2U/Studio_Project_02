#include "../SceneText.h"
#include "../SceneMenu.h"
#include "../TicTacToe.h"
#include "../SceneVending.h"
#include "../Mesh_Generation/MeshBuilder.h"
#include "../../../glew/include/GL/glew.h"
#include "LoadTGA.h"


void SceneMenu::InitMeshList()
{
	meshList[MENU_SCREEN] = MeshBuilder::GenerateQuad("Menu_Screen", Color(1, 1, 1), 1.f, 1.f);
	meshList[MENU_SCREEN]->textureID = LoadTGA("Image//menu-screen.tga");

	meshList[BUTTON] = MeshBuilder::GenerateQuad("Button", Color(0.4f, 0.4f, 0.4f), 1.f, 1.f);

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

	meshList[TEXT_BORDER] = MeshBuilder::GenerateQuad("text_border", Color(0, 1, 0), 1.f, 1.f);
	meshList[TEXT_BORDER]->textureID = LoadTGA("Image//TextBorder.tga");

	meshList[GEO_LIGHTSPHERE] = MeshBuilder::GenerateSphere("lightBall", Color(1.f, 1.f, 1.f), 9, 36, 1.f);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//calibri.tga");

	meshList[GEO_NPC] = MeshBuilder::GenerateOBJ("NPC", "OBJ//NPC.obj");
	meshList[GEO_NPC]->textureID = LoadTGA("Image//silver.tga");

	meshList[GEO_SPOTLIGHT_STAND] = MeshBuilder::GenerateOBJ("Spotlight", "OBJ//Lamp_stand.obj");
	meshList[GEO_SPOTLIGHT_STAND]->textureID = LoadTGA("Image/silver.tga");

	meshList[GEO_SPOTLIGHT_JOINT] = MeshBuilder::GenerateOBJ("Spotlight", "OBJ//Lamp_joint.obj");
	meshList[GEO_SPOTLIGHT_JOINT]->textureID = LoadTGA("Image//silver.tga");

	meshList[GEO_SPOTLIGHT_HEAD] = MeshBuilder::GenerateOBJ("Spotlight", "OBJ//Lamp_head.obj");
	meshList[GEO_SPOTLIGHT_HEAD]->textureID = LoadTGA("Image//silver.tga");

	//Vehicles
	/*meshList[FORD_GT] = MeshBuilder::GenerateOBJ("Ford_GT", "OBJ//ford_gt.obj");
	meshList[FORD_GT]->textureID = LoadTGA("Image//ford_gt.tga");

	meshList[FENYR] = MeshBuilder::GenerateOBJ("Fenyr", "OBJ//fenyr.obj");
	meshList[FENYR]->textureID = LoadTGA("Image//fenyr.tga");

	meshList[LAMBORGHINI] = MeshBuilder::GenerateOBJ("Lamborghini", "OBJ//Lamborghini.obj");
	meshList[LAMBORGHINI]->textureID = LoadTGA("Image//Lamborghini.tga");*/

	//meshList[ONE_1] = MeshBuilder::GenerateOBJ("One_1", "OBJ//one_1.obj");

	//Food icons
	meshList[HAMBURGER] = MeshBuilder::GenerateQuad("hamburger", Color(0, 1, 0), 1.f, 1.f);
	meshList[HAMBURGER]->textureID = LoadTGA("Image//hamburger.tga");

	meshList[STEAK] = MeshBuilder::GenerateQuad("steak", Color(0, 1, 0), 1.f, 1.f);
	meshList[STEAK]->textureID = LoadTGA("Image//steak.tga");

	//UI Icons
	meshList[BUTTON_W] = MeshBuilder::GenerateQuad("ButtonW_White", Color(0, 0, 0), 1.f, 1.f);
	meshList[BUTTON_W]->textureID = LoadTGA("Image//W_WHITE.tga");

	meshList[BUTTON_A] = MeshBuilder::GenerateQuad("ButtonA_White", Color(0, 0, 0), 1.f, 1.f);
	meshList[BUTTON_A]->textureID = LoadTGA("Image//A_WHITE.tga");

	meshList[BUTTON_S] = MeshBuilder::GenerateQuad("ButtonS_White", Color(0, 0, 0), 1.f, 1.f);
	meshList[BUTTON_S]->textureID = LoadTGA("Image//S_WHITE.tga");

	meshList[BUTTON_D] = MeshBuilder::GenerateQuad("ButtonD_White", Color(0, 0, 0), 1.f, 1.f);
	meshList[BUTTON_D]->textureID = LoadTGA("Image//D_WHITE.tga");

	meshList[BUTTON_W_HIGHLIGHT] = MeshBuilder::GenerateQuad("ButtonW_Red", Color(0, 0, 0), 1.f, 1.f);
	meshList[BUTTON_W_HIGHLIGHT]->textureID = LoadTGA("Image//W_RED.tga");

	meshList[BUTTON_A_HIGHLIGHT] = MeshBuilder::GenerateQuad("ButtonA_Red", Color(0, 0, 0), 1.f, 1.f);
	meshList[BUTTON_A_HIGHLIGHT]->textureID = LoadTGA("Image//A_RED.tga");

	meshList[BUTTON_S_HIGHLIGHT] = MeshBuilder::GenerateQuad("ButtonS_Red", Color(0, 0, 0), 1.f, 1.f);
	meshList[BUTTON_S_HIGHLIGHT]->textureID = LoadTGA("Image//S_RED.tga");

	meshList[BUTTON_D_HIGHLIGHT] = MeshBuilder::GenerateQuad("ButtonD_Red", Color(0, 0, 0), 1.f, 1.f);
	meshList[BUTTON_D_HIGHLIGHT]->textureID = LoadTGA("Image//D_RED.tga");

	meshList[L_MOUSE] = MeshBuilder::GenerateQuad("LeftMouseButton_White", Color(0, 1, 0), 1.f, 1.f);
	meshList[L_MOUSE]->textureID = LoadTGA("Image//L_MOUSE_WHITE.tga");

	meshList[L_MOUSE_HIGHLIGHT] = MeshBuilder::GenerateQuad("LeftMouseButton_Red", Color(0, 1, 0), 1.f, 1.f);
	meshList[L_MOUSE_HIGHLIGHT]->textureID = LoadTGA("Image//L_MOUSE_RED.tga");

>>>>>>> 24a22a27ee71c6727f98c7913845fb570df554ac
}

void TicTacToe::InitMeshList()
{
	meshList[STARTING_SCREEN] = MeshBuilder::GenerateQuad("Starting_screen", Color(1, 1, 1), 1.f, 1.f);
	meshList[STARTING_SCREEN]->textureID = LoadTGA("Image//tic-tac-toe-grid.tga");

	meshList[ENDING_SCREEN] = MeshBuilder::GenerateQuad("Ending_screen", Color(1, 1, 1), 1.f, 1.f);
	meshList[ENDING_SCREEN]->textureID = LoadTGA("Image//game-over-screen.tga");

	meshList[BUTTON] = MeshBuilder::GenerateQuad("Button", Color(0.4f, 0.4f, 0.4f), 1.f, 1.f);

	meshList[GRID] = MeshBuilder::GenerateQuad("Grid", Color(1, 1, 1), 1.f, 1.f);
	meshList[GRID]->textureID = LoadTGA("Image//tic-tac-toe-grid.tga");

	meshList[TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[TEXT]->textureID = LoadTGA("Image//arial-rounded-mt-bold.tga");
}
