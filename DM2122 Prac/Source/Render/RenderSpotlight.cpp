#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderSpotlight()
{
	// Car 1
	modelStack.PushMatrix();
	modelStack.Translate(Car1X + dFromCarCentre * float(cos(angle * 0.01745329251)), 10, CarZ + dFromCarCentre * float(sin(angle * 0.01745329251)));
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(Car1X - dFromCarCentre * float(cos(angle * 0.01745329251)), 10, CarZ - dFromCarCentre * float(sin(angle * 0.01745329251)));
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], false);
	modelStack.PopMatrix();
	// ~Car1

	// Car 2
	modelStack.PushMatrix();
	modelStack.Translate(Car2X + dFromCarCentre * float(cos(angle * 0.01745329251)), 10, CarZ + dFromCarCentre * float(sin(angle * 0.01745329251)));
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(Car2X - dFromCarCentre * float(cos(angle * 0.01745329251)), 10, CarZ - dFromCarCentre * float(sin(angle * 0.01745329251)));
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], false);
	modelStack.PopMatrix();
	// ~Car2

	// Car 3
	modelStack.PushMatrix();
	modelStack.Translate(Car3X + dFromCarCentre * float(cos(angle * 0.01745329251)), 10, CarZ + dFromCarCentre * float(sin(angle * 0.01745329251)));
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(Car3X - dFromCarCentre * float(cos(angle * 0.01745329251)), 10, CarZ - dFromCarCentre * float(sin(angle * 0.01745329251)));
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], false);
	modelStack.PopMatrix();
	// ~Car3

	// Car 4
	modelStack.PushMatrix();
	modelStack.Translate(Car4X + dFromCarCentre * float(cos(angle * 0.01745329251)), 10, CarZ + dFromCarCentre * float(sin(angle * 0.01745329251)));
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(Car4X - dFromCarCentre * float(cos(angle * 0.01745329251)), 10, CarZ - dFromCarCentre * float(sin(angle * 0.01745329251)));
	modelStack.Rotate(180.f, 0.f, 0.f, 1.f);
	modelStack.Scale(0.1f, 0.1f, 0.1f);
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], false);
	modelStack.PopMatrix();
	// ~Car4
}