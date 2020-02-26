#pragma once

#include "Scene.h"

class SceneMenu : public Scene
{
private:
	enum GEOMETRY_TYPE
	{
		MENU_SCREEN,
		BUTTON,
		TEXT,
		NUM_GEOMETRY,
	};

	Mesh* meshList[NUM_GEOMETRY];

	virtual void InitMeshList() override;
public:
	SceneMenu();
	~SceneMenu();

	virtual void Init() override;
	virtual void Update(double dt) override;
	virtual void Render() override;
	virtual void Exit() override;
};