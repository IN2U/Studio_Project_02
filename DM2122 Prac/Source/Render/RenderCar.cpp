#include "../SceneText.h"

void SceneText::RenderCar()
{
	modelStack.PushMatrix();
	modelStack.Translate(10.f, 0.f, -20.f);
	RenderMesh(meshList[FORD_GT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-10.f, 0.f, -20.f);
	RenderMesh(meshList[FENYR], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-30.f, 0.f, -20.f);
	RenderMesh(meshList[LAMBORGHINI], true);
	modelStack.PopMatrix();
}