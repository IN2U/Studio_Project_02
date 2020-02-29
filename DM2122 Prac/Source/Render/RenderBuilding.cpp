#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderBuilding()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* building;

	building = Objects->AddObject("Building", meshList[BUILDING], true);
	building->Transform('T', 0.f, -2.f, -50.f);
	building->Transform(90.f, 0.f, -1.f, 0.f);
	building->Transform('S', 2.f, 1.f, 1.f);
	Objects->getLib().push_back(building);
}