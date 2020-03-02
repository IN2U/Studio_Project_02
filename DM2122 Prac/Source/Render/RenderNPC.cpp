#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderNPC()
{
	modelStack.PushMatrix();
	modelStack.Translate(16.f, 0.9f, -20.f);
	RenderMesh(meshList[GEO_NPC], true);

	modelStack.PushMatrix();
	modelStack.Translate(-0.55f, 4.7f, 0.f);
	modelStack.Rotate(anglea1, 1, 0, 0);
	RenderMesh(meshList[GEO_ARM], true);

	modelStack.PushMatrix();
	modelStack.Translate(-0.25f, -1.0f, 0.15f);
	modelStack.Rotate(angleb1, 1, 0, 0);
	modelStack.Rotate(anglec1, 0, 1, 0);
	RenderMesh(meshList[GEO_FARM], true);
	modelStack.PopMatrix();

	modelStack.PopMatrix();

	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(36.f, 0.9f, -20.f);
	RenderMesh(meshList[GEO_NPC], true);

	modelStack.PushMatrix();
	modelStack.Translate(-0.55f, 4.7f, 0.f);
	modelStack.Rotate(anglea2, 1, 0, 0);
	RenderMesh(meshList[GEO_ARM], true);

	modelStack.PushMatrix();
	modelStack.Translate(-0.25f, -1.0f, 0.15f);
	modelStack.Rotate(angleb2, 1, 0, 0);
	modelStack.Rotate(anglec2, 0, 1, 0);
	RenderMesh(meshList[GEO_FARM], true);
	modelStack.PopMatrix();

	modelStack.PopMatrix();

	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-16.f, 0.9f, -20.f);
	RenderMesh(meshList[GEO_NPC], true);
	modelStack.PushMatrix();
	modelStack.Translate(-0.55f, 4.7f, 0.f);
	modelStack.Rotate(anglea3, 1, 0, 0);
	RenderMesh(meshList[GEO_ARM], true);

	modelStack.PushMatrix();
	modelStack.Translate(-0.25f, -1.0f, 0.15f);
	modelStack.Rotate(angleb3, 1, 0, 0);
	modelStack.Rotate(anglec3, 0, 1, 0);
	RenderMesh(meshList[GEO_FARM], true);
	modelStack.PopMatrix();

	modelStack.PopMatrix();

	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-36.f, 0.9f, -20.f);
	RenderMesh(meshList[GEO_NPC], true);
	modelStack.PushMatrix();
	modelStack.Translate(-0.55f, 4.7f, 0.f);
	modelStack.Rotate(anglea4, 1, 0, 0);
	RenderMesh(meshList[GEO_ARM], true);

	modelStack.PushMatrix();
	modelStack.Translate(-0.25f, -1.0f, 0.15f);
	modelStack.Rotate(angleb4, 1, 0, 0);
	modelStack.Rotate(anglec4, 0, 1, 0);
	RenderMesh(meshList[GEO_FARM], true);
	modelStack.PopMatrix();

	modelStack.PopMatrix();

	modelStack.PopMatrix();
}