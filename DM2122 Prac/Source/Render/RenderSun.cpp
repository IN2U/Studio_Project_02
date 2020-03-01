#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderSun()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* sun;

	sun = Objects->AddObject("Sun", meshList[GEO_SUN], false);
	sun->Transform('T', light[1].position.x, light[1].position.y, light[1].position.z);
	sun->Transform('S', 0.5f, 0.5f, 0.5f);
	Objects->getLib().push_back(sun);
}