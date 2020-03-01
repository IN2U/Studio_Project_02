#include "../SceneText.h"
#include "../Helper/Window.h"
#include "../ObjectManager.h"

void SceneText::RenderMinimap()
{
	// Sets the viewport for minimap
	glViewport(0, GLint(Window::getInstance()->getHeight() / 1.25), Window::getInstance()->getWidth() / 5, Window::getInstance()->getHeight() / 5);

	viewStack_mini.LoadIdentity();
	viewStack_mini.LookAt(minimapCamera.position.x, minimapCamera.position.y, minimapCamera.position.z, minimapCamera.target.x, minimapCamera.target.y, minimapCamera.target.z, minimapCamera.up.x, minimapCamera.up.y, minimapCamera.up.z);
	modelStack_mini.LoadIdentity();

	ObjectManager* Objects = ObjectManager::getInstance();
	Objects->Update();
	Object* mini;

	mini = Objects->AddObject("minimap_border", meshList[MINIMAP_BORDER], false);
	mini->Transform(90.f, -1.f, 0.f, 0.f);
	mini->Transform('S', 10.f, 1.f, 10.f);
	Objects->getLib().push_back(mini);

	mini = Objects->AddObject("RaceTrack", meshList[GEO_RACE_TRACK], false);
	mini->Transform('T', 0.f, 0.f, 2.f);
	mini->Transform('S', 0.1f, 0.1f, 0.1f);
	Objects->getLib().push_back(mini);

	mini = Objects->AddObject("Building", meshList[BUILDING], true);
	mini->Transform('T', -2.5f, 0.f, -22.5f);
	mini->Transform(90.f, 0.f, -1.f, 0.f);
	mini->Transform('S', 0.1f, 0.1f, 0.05f);
	Objects->getLib().push_back(mini);

	mini = Objects->AddObject("Car1", meshList[FORD_GT], true);
	mini->Transform('T', 10.5f, 0.f, 0.f);
	mini->Transform('S', 0.1f, 0.1f, 0.1f);
	Objects->getLib().push_back(mini);

	mini= Objects->AddObject("Car2", meshList[FENYR], true);
	mini->Transform('T', 0.f, 0.f, 0.f);
	mini->Transform('S', 0.1f, 0.1f, 0.1f);
	Objects->getLib().push_back(mini);

	mini= Objects->AddObject("Car3", meshList[LAMBORGHINI], true);
	mini->Transform('T', -10.5f, 0.f, 0.f);
	mini->Transform('S', 0.1f, 0.1f, 0.1f);
	Objects->getLib().push_back(mini);


	for (unsigned int i = 0; i < Objects->getLib().size(); i++) {
		modelStack_mini.PushMatrix();
		Objects->getLib()[i]->Render(modelStack_mini);
		RenderMiniMesh(Objects->getLib()[i]->getMesh());
		modelStack_mini.PopMatrix();
	}
}


