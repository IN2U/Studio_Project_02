#include "SceneManager.h"
#include "Global_Constants/GAME_STATES.h"

SceneManager::SceneManager() {
	currSceneID = STATE::MENU_SCENE;
	nextSceneID = STATE::MENU_SCENE;
	fromGame = false;
	carSelect = 0;
}

SceneManager::~SceneManager() {
	for (unsigned int i = 0; i < sceneLib.size(); i++) {
		delete sceneLib[i];
	}
}

SceneManager* SceneManager::instance = nullptr;

SceneManager* SceneManager::getInstance() {
	if (instance == nullptr) {
		instance = new SceneManager;
	}
	return instance;
}

Scene* SceneManager::GetCurrScene() {

	return sceneLib[currSceneID];
}


void SceneManager::AddScene(Scene* scene) {

	sceneLib.push_back(scene);
}

void SceneManager::SetNextScene(int sceneID) {

	nextSceneID = sceneID;
	carSelect = 0;
}

void SceneManager::SetNextScene(int sceneID, int carSelect) {
	nextSceneID = sceneID;
	this->carSelect = carSelect;
}

int SceneManager::getCurrentSceneID() const
{
	return currSceneID;
}

int SceneManager::getNextSceneID() const
{
	return nextSceneID;
}

void SceneManager::Update(double ElapsedTime) {

	sceneLib[currSceneID]->Update(ElapsedTime);
	sceneLib[currSceneID]->Render();
}

void SceneManager::SetGameScene()
{
	SceneManager* scene = SceneManager::getInstance();
	scene->SetNextScene(STATE::GAME_SCENE);
}


void SceneManager::ChangeScene() {

	currSceneID = nextSceneID;
}

int SceneManager::getCarSelect() {
	return carSelect;
}