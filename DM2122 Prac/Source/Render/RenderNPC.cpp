#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderNPC()
{
	ObjectManager* Objects = ObjectManager::getInstance();
	Object* temp;
	temp = Objects->AddObject("NPC1", meshList[GEO_NPC], true);
	temp->Transform('T',16.f, 0.f, -20.f);
	temp->AddHitbox(Vector3(0, 2.5, 0), Vector3(0.5, 3, 0.5));
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("ARM", meshList[GEO_ARM], true, "NPC1");
	temp->Transform('T',-0.55f, 4.7f, 0.f);
	temp->Transform(anglea1, 1, 0, 0);
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("FARM", meshList[GEO_FARM], true, "NPC1");
	temp->Transform('T', -0.25f, -1.0f, 0.15f);
	temp->Transform(angleb1, 1, 0, 0);
	temp->Transform(anglec1, 0, 1, 0);
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("NPC2", meshList[GEO_NPC], true);
	temp->Transform('T', 36.f, 0.f, -20.f);
	temp->AddHitbox(Vector3(0, 2.5, 0), Vector3(0.5, 3, 0.5));
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("ARM", meshList[GEO_ARM], true, "NPC2");
	temp->Transform('T', -0.55f, 4.7f, 0.f);
	temp->Transform(anglea2, 1, 0, 0);
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("FARM", meshList[GEO_FARM], true, "NPC2");
	temp->Transform('T', -0.25f, -1.0f, 0.15f);
	temp->Transform(angleb2, 1, 0, 0);
	temp->Transform(anglec2, 0, 1, 0);
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("NPC3", meshList[GEO_NPC], true);
	temp->Transform('T', -16.f, 0.f, -20.f);
	temp->AddHitbox(Vector3(0, 2.5, 0), Vector3(0.5, 3, 0.5));
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("ARM", meshList[GEO_ARM], true, "NPC3");
	temp->Transform('T', -0.55f, 4.7f, 0.f);
	temp->Transform(anglea3, 1, 0, 0);
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("FARM", meshList[GEO_FARM], true, "NPC3");
	temp->Transform('T', -0.25f, -1.0f, 0.15f);
	temp->Transform(angleb3, 1, 0, 0);
	temp->Transform(anglec3, 0, 1, 0);
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("NPC4", meshList[GEO_NPC], true);
	temp->Transform('T', -36.f, 0.f, -20.f);
	temp->AddHitbox(Vector3(0, 2.5, 0), Vector3(0.5, 3, 0.5));
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("ARM", meshList[GEO_ARM], true, "NPC4");
	temp->Transform('T', -0.55f, 4.7f, 0.f);
	temp->Transform(anglea4, 1, 0, 0);
	Objects->getLib().push_back(temp);

	temp = Objects->AddObject("FARM", meshList[GEO_FARM], true, "NPC4");
	temp->Transform('T', -0.25f, -1.0f, 0.15f);
	temp->Transform(angleb4, 1, 0, 0);
	temp->Transform(anglec4, 0, 1, 0);
	Objects->getLib().push_back(temp);

}