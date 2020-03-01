#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderTurntable()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* turntable;

	turntable = Objects->AddObject("Turntable1", meshList[GEO_TURNTABLE], true);
	turntable->Transform('T', Car1X, 0.f, CarZ);
	turntable->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(turntable);

	turntable = Objects->AddObject("Turntable2", meshList[GEO_TURNTABLE], true);
	turntable->Transform('T', Car2X, 0.f, CarZ);
	turntable->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(turntable);

	turntable = Objects->AddObject("Turntable3", meshList[GEO_TURNTABLE], true);
	turntable->Transform('T', Car3X, 0.f, CarZ);
	turntable->Transform(anglex, 0.f, 1.f, 0.f);
	Objects->getLib().push_back(turntable);
}