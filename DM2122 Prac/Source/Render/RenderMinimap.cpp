#include "../SceneText.h"
#include "../Helper/Window.h"
#include "../ObjectManager.h"

void SceneText::RenderMinimap()
{
	// Sets the viewport for minimap
	glViewport(0, 0, Window::getInstance()->getWidth() / 5, Window::getInstance()->getHeight() / 5);

	viewStack_mini.LoadIdentity();
	viewStack_mini.LookAt(minimapCamera.position.x, minimapCamera.position.y, minimapCamera.position.z, minimapCamera.target.x, minimapCamera.target.y, minimapCamera.target.z, minimapCamera.up.x, minimapCamera.up.y, minimapCamera.up.z);
	modelStack_mini.LoadIdentity();

	// Plan: change character to a arrow pointer
	ObjectManager* Objects = ObjectManager::getInstance();
	Objects->Update();

	Object* mini;

	mini = Objects->AddObject("minimap_border", meshList[MINIMAP_BORDER], false);
	mini->Transform(90.f, -1.f, 0.f, 0.f);
	mini->Transform('S', 10.f, 1.f, 10.f);
	Objects->getLib().push_back(mini);

	mini = Objects->AddObject("pointer", meshList[PLAYER_POINTER], false);
	mini->Transform('T', 0.f, 0.1f, 0.f);
	mini->Transform(90.f, -1.f, 0.f, 0.f);
	Objects->getLib().push_back(mini);

	for (unsigned int i = 0; i < Objects->getLib().size(); i++) {
		modelStack_mini.PushMatrix();
		Objects->getLib()[i]->Render(modelStack_mini);
		RenderMiniMesh(Objects->getLib()[i]->getMesh());
		modelStack_mini.PopMatrix();
	}
}


