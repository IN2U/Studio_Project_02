#ifndef SCENE_H
#define SCENE_H

#include "UNIFORM_TYPE.h"

class Scene
{
public:
	Scene() {}
	~Scene() {}

	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;

	virtual void InitMeshList() = 0;

	void InitShaderUniforms();

	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
};

#endif