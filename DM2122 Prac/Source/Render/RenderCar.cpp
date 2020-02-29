#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderCar()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* car;

	car = Objects->AddObject("Car", meshList[FORD_GT], true);
	car->Transform('T', 10.f, 0.f, -20.f);
	Objects->getLib().push_back(car);

	car = Objects->AddObject("Car", meshList[FENYR], true);
	car->Transform('T', -10.f, 0.f, -20.f);
	Objects->getLib().push_back(car);

	car = Objects->AddObject("Car", meshList[LAMBORGHINI], true);
	car->Transform('T', -30.f, 0.f, -20.f);
	Objects->getLib().push_back(car);
}