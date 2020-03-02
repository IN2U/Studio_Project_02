#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderFloor()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* floor;

	floor = Objects->AddObject("Floor", meshList[GEO_FLOOR], true);
	floor->Transform('T', 0.f, 1.f, 0.f);
	floor->Transform(-90.f, 1.f, 0.f, 0.f);
	floor->Transform('S', 200.f, 1.f, 200.f);
	Objects->getLib().push_back(floor);
}