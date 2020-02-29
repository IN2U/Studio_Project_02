#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderNPC()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* npc;

	npc = Objects->AddObject("NPC", meshList[GEO_NPC], true);
	npc->Transform('T', 5.f, 2.f, 0.f);
	npc->Transform('S', 1.f, 1.f, 1.f);
	Objects->getLib().push_back(npc);
}