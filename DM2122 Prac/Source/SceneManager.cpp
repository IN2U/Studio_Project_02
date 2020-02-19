#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager() {
	currSceneID = 0;
	nextSceneID = 0;
}

SceneManager::~SceneManager() {
	for (int i = 0; i < sceneLib.size(); i++) {
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
}

void SceneManager::Update(double ElapsedTime) {

	sceneLib[currSceneID]->Update(ElapsedTime);
	sceneLib[currSceneID]->Render();
}

void SceneManager::ChangeScene() {

	currSceneID = nextSceneID;
	if (currSceneID == 0) {
		nextSceneID = 0;
	}
	else {
		nextSceneID = 0;
	}
}