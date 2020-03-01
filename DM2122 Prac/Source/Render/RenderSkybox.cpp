#include "../SceneText.h"

void SceneText::RenderSkybox()
{
	modelStack.PushMatrix();
	modelStack.Translate(-50.f, 20.f, 0.f);
	modelStack.Scale(102.f, 102.f, 102.f);
	modelStack.Rotate(90.f, 0.f, 1.f, 0.f);

	if (light[1].position.y > 0)
		RenderMesh(meshList[SKYBOX_RIGHT_DAY], false);
	else
		RenderMesh(meshList[SKYBOX_RIGHT_NIGHT], false);

	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(50.f, 20.f, 0.f);
	modelStack.Scale(102.f, 102.f, 102.f);
	modelStack.Rotate(-90.f, 0.f, 1.f, 0.f);

	if (light[1].position.y > 0)
		RenderMesh(meshList[SKYBOX_LEFT_DAY], false);
	else
		RenderMesh(meshList[SKYBOX_LEFT_NIGHT], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.f, 70.f, 0.f);
	modelStack.Scale(102.f, 102.f, 102.f);
	modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
	modelStack.PushMatrix();
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);

	if (light[1].position.y > 0)
		RenderMesh(meshList[SKYBOX_TOP_DAY], false);
	else
		RenderMesh(meshList[SKYBOX_TOP_NIGHT], false);

	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.f, -30.f, 0.f);
	modelStack.Scale(102.f, 102.f, 102.f);
	modelStack.Rotate(-90.f, 1.f, 0.f, 0.f);

	if (light[1].position.y > 0)
		RenderMesh(meshList[SKYBOX_BOTTOM_DAY], false);
	else
		RenderMesh(meshList[SKYBOX_BOTTOM_NIGHT], false);

	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.f, 20.f, -50.f);
	modelStack.Scale(102.f, 102.f, 102.f);

	if (light[1].position.y > 0)
		RenderMesh(meshList[SKYBOX_FRONT_DAY], false);
	else
		RenderMesh(meshList[SKYBOX_FRONT_NIGHT], false);

	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.f, 20.f, 50.f);
	modelStack.Scale(102.f, 102.f, 102.f);
	modelStack.Rotate(180.f, 0.f, 1.f, 0.f);

	if (light[1].position.y > 0)
		RenderMesh(meshList[SKYBOX_BACK_DAY], false);
	else
		RenderMesh(meshList[SKYBOX_BACK_NIGHT], false);

	modelStack.PopMatrix();
}