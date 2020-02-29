#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"
#include <vector>

class SceneManager
{
private:

	static SceneManager* instance;
	SceneManager();
	std::vector< Scene* > sceneLib;
	int currSceneID;
	int nextSceneID;

public:

	~SceneManager();
	static SceneManager* getInstance();
	Scene* GetCurrScene();
	void ChangeScene();
	void AddScene(Scene* scene);
	void SetNextScene(int sceneID);

	int getCurrentSceneID() const;
	int getNextSceneID() const;
	void Update(double ElapsedTime);
	bool fromGame;

	void SetGameScene();
};

#endif
