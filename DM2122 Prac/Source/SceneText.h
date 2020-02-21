#ifndef SCENETEXT_H
#define SCENETEXT_H

#include "Scene.h"
#include "Mesh.h"
#include "Camera2.h"
#include "Light.h"
#include <MatrixStack.h>
#include "Sun.h"


class SceneText : public Scene
{
private:
	enum GEOMETRY_TYPE
	{
		GEO_AXES = 0,

		SKYBOX_LEFT_DAY, 
		SKYBOX_RIGHT_DAY,
		SKYBOX_TOP_DAY,
		SKYBOX_BOTTOM_DAY,
		SKYBOX_FRONT_DAY,
		SKYBOX_BACK_DAY,

		SKYBOX_LEFT_NIGHT,
		SKYBOX_RIGHT_NIGHT,
		SKYBOX_TOP_NIGHT,
		SKYBOX_BOTTOM_NIGHT,
		SKYBOX_FRONT_NIGHT,
		SKYBOX_BACK_NIGHT,

		GEO_SUN,
		GEO_CHAR,
		GEO_DICE,
		GEO_LIGHTSPHERE,
		GEO_TEXT,
		GEO_VENDING_MENU,
		NUM_GEOMETRY,
	}; 

	unsigned m_vertexArrayID;

	Mesh* meshList[NUM_GEOMETRY];

	MS modelStack, viewStack, projectionStack;

	Light light[2];

	bool renderHitBox;

	Camera2 camera;
	
	void RenderMesh(Mesh* mesh, bool enableLight);
	void RenderSkybox();

	void RenderText(Mesh* mesh, std::string text, Color color, float size, float x, float y, float z);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderMeshOnScreen(Mesh* mesh, float x, float y, float sizex, float sizey);
	
	void InitLightShaderUniforms();
	void InitLightSettings();

	virtual void InitMeshList() override;

	void CalculateFrameRate();


	Sun sun;
	//void updateSunlight();

public:
	SceneText();
	~SceneText();

	virtual void Init() override;
	virtual void Update(double dt) override;
	virtual void Render() override;
	virtual void Exit() override;
};

#endif