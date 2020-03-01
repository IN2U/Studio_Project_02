#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderPhone()
{
	Object* phone;
	ObjectManager* Objects = ObjectManager::getInstance();

	phone = Objects->AddObject("Phone", meshList[GEO_PHONE], true);
	phone->Transform('T', camera.position.x + 1, camera.position.y, camera.position.z - 2.5);
	phone->Transform(40.f, 1.f, 0.f, 0.f);
	phone->Transform('S', 0.5f, 0.5f, 0.5f);
	Objects->getLib().push_back(phone);
}
