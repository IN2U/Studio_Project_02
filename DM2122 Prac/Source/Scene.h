#ifndef SCENE_H
#define SCENE_H

#include "UNIFORM_TYPE.h"
#include <MatrixStack.h>
#include "Mesh_Generation/Mesh.h"

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

	unsigned m_vertexArrayID;

	MS modelStack, viewStack, projectionStack;

	void InitShaderUniforms();

	void RenderMesh(Mesh* mesh, bool enableLight);
	void RenderMeshOnScreen(Mesh* mesh, float x, float y, float sizex, float sizey);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);

	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];
};

#endif