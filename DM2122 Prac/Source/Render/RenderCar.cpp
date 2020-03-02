#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderCar()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* car;

	car = Objects->AddObject("Car1", meshList[FORD_GT], true);
	car->Transform('T', Car1X, 1.f, CarZ);
	car->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(car);
	Objects->getObject("Car1")->AddHitbox(Vector3(0,0,0),Vector3(2.5,1,5));

	car = Objects->AddObject("Car2", meshList[FENYR], true);
	car->Transform('T', Car2X, 1.f, CarZ);
	car->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(car);
	Objects->getObject("Car2")->AddHitbox(Vector3(0, 0, 0), Vector3(2.5, 1, 5));

	car = Objects->AddObject("Car3", meshList[LAMBORGHINI], true);
	car->Transform('T', Car3X, 1.f, CarZ);
	car->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(car);
	Objects->getObject("Car3")->AddHitbox(Vector3(0, 0, 0), Vector3(2.5, 1, 5));
}