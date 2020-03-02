#pragma once

#include "Scene.h"

class SceneMenu : public Scene
{
private:
	enum GEOMETRY_TYPE
	{
		MENU_SCREEN,
		CONTROLS_SCREEN,
		BUTTON,
		TEXT,
		NUM_GEOMETRY,
	};

	Mesh* meshList[NUM_GEOMETRY];

	// Debounce
	double sceneTime;
	double debounceTime;

	// Menu states
	const int MAIN_MENU;
	const int OPTIONS_MENU;
	const int CONTROLS_MENU;

	int menuCurrentState;

	virtual void InitMeshList() override;
public:
	SceneMenu();
	~SceneMenu();

	virtual void Init() override;
	virtual void Update(double dt) override;
	virtual void Render() override;
	virtual void Exit() override;
};