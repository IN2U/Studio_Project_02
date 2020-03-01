#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderCar()
{
	//ObjectManager* Objects = ObjectManager::getInstance();
	//Object* car;

	//car = Objects->AddObject("Car1", meshList[FORD_GT], true);
	//car->Transform('T', Car1X, 0.f, CarZ);
	//Objects->getLib().push_back(car);

	//car = Objects->AddObject("Car2", meshList[FENYR], true);
	//car->Transform('T', Car2X, 0.f, CarZ);
	//Objects->getLib().push_back(car);

	//car = Objects->AddObject("Car3", meshList[LAMBORGHINI], true);
	//car->Transform('T', Car3X, 0.f, CarZ);
	//Objects->getLib().push_back(car);

	modelStack.PushMatrix();
	modelStack.Translate(10.f, 0.f, -20.f);
	modelStack.Rotate(anglex, 0, 1, 0);
	RenderMesh(meshList[FORD_GT], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-10.f, 0.f, -20.f);
	modelStack.Rotate(anglex, 0, 1, 0);
	RenderMesh(meshList[FENYR], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-30.f, 0.f, -20.f);
	modelStack.Rotate(anglex, 0, 1, 0);
	RenderMesh(meshList[LAMBORGHINI], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(10.f, 0.f, -20.f);
	modelStack.Rotate(anglex, 0, 1, 0);
	RenderMesh(meshList[GEO_TURNTABLE], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-10.f, 0.f, -20.f);
	modelStack.Rotate(anglex, 0, 1, 0);
	RenderMesh(meshList[GEO_TURNTABLE], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-30.f, 0.f, -20.f);
	modelStack.Rotate(anglex, 0, 1, 0);
	RenderMesh(meshList[GEO_TURNTABLE], true);
	modelStack.PopMatrix();
}