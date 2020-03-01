#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderCar()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* car;

	car = Objects->AddObject("Car1", meshList[FORD_GT], true);
	car->Transform('T', Car1X, 0.f, CarZ);
	car->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(car);

	car = Objects->AddObject("Car2", meshList[FENYR], true);
	car->Transform('T', Car2X, 0.f, CarZ);
	car->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(car);

	car = Objects->AddObject("Car3", meshList[LAMBORGHINI], true);
	car->Transform('T', Car3X, 0.f, CarZ);
	car->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(car);
}