#include "./Source/SceneText.h"
#include "./Source/ObjectManager.h"

void SceneText::RenderPhone()
{
	Object* phone;
	ObjectManager* Objects = ObjectManager::getInstance();

	phone = Objects->AddObject("Phone", meshList[GEO_PHONE], true);
	phone->Transform('T', camera.position.x - 2, camera.position.y, camera.position.z - 5);
	Objects->getLib().push_back(phone);
}
