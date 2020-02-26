#pragma once

#include "Scene.h"

class SceneOptions : public Scene
{
private:
	enum GEOMETRY_TYPE
	{
		OPTIONS_SCREEN,
		IN_GAME_OPTIONS_SCREEN,
		BUTTON,
		TEXT,
		NUM_GEOMETRY,
	};

	Mesh* meshList[NUM_GEOMETRY];

	virtual void InitMeshList() override;
public:
	SceneOptions();
	~SceneOptions();

	virtual void Init() override;
	virtual void Update(double dt) override;
	virtual void Render() override;
	virtual void Exit() override;
};