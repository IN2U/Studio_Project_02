#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderNPC()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* npc;

	for (int i = 0; i < 2; ++i)
	{
		npc = Objects->AddObject("NPC", meshList[GEO_NPC], true);
		npc->Transform('T', 36.f - 20.f * (float)i, 2.f, -20.f);
		Objects->getLib().push_back(npc);
	}

	for (int i = 0; i < 2; ++i)
	{
		npc = Objects->AddObject("NPC", meshList[GEO_NPC], true);
		npc->Transform('T', -36.f + 20.f * (float)i, 2.f, -20.f);
		Objects->getLib().push_back(npc);
	}
}