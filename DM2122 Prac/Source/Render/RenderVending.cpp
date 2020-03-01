#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderVendingMachine()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* vending;

	vending = Objects->AddObject("vending", meshList[GEO_VENDING], true);
	vending->Transform('T', -40.f, 0.f, -10.f);
	vending->Transform(90.f, 0.f, 1.f, 0.f);

	Objects->getLib().push_back(vending);
}