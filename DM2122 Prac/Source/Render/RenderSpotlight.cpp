#include "../SceneText.h"
#include "../ObjectManager.h"

void SceneText::RenderSpotlight()
{
	modelStack.PushMatrix();
	modelStack.Translate(25.f, 0.f, -15.f);
	modelStack.Scale(0.5f, 0.5f, 0.5f);
	RenderSpotlightStand();

	modelStack.PushMatrix();
	modelStack.Translate(-0.6f, -0.05f, -0.04f);
	RenderSpotlightJointPoint();

	modelStack.PushMatrix();
	modelStack.Translate(0.6f, 0.2f, 0.05f);
	RenderSpotlightJoint();

	modelStack.PushMatrix();
	RenderSpotlightHead();

	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
		modelStack.Translate(5.f, 0.f, -15.f);
		modelStack.Scale(0.5f, 0.5f, 0.5f);
		RenderSpotlightStand();

		modelStack.PushMatrix();
			modelStack.Translate(-0.6f, -0.05f, -0.04f);
			RenderSpotlightJointPoint();
				
				modelStack.PushMatrix();
				modelStack.Translate(0.6f, 0.2f, 0.05f);
				RenderSpotlightJoint();

				modelStack.PushMatrix();
				RenderSpotlightHead();

			modelStack.PopMatrix();
			modelStack.PopMatrix();
		modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-5.f, 0.f, -15.f);
	modelStack.Scale(0.5f, 0.5f, 0.5f);
	RenderSpotlightStand();

	modelStack.PushMatrix();
	modelStack.Translate(-0.6f, -0.05f, -0.04f);
	modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
	RenderSpotlightJointPoint();

	modelStack.PushMatrix();
	modelStack.Translate(0.6f, 0.2f, 0.05f);
	RenderSpotlightJoint();

	modelStack.PushMatrix();
	RenderSpotlightHead();

	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-25.f, 0.f, -15.f);
	modelStack.Scale(0.5f, 0.5f, 0.5f);
	RenderSpotlightStand();

	modelStack.PushMatrix();
	modelStack.Translate(-0.6f, -0.05f, -0.04f);
	modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
	RenderSpotlightJointPoint();

	modelStack.PushMatrix();
	modelStack.Translate(0.6f, 0.2f, 0.05f);
	RenderSpotlightJoint();

	modelStack.PushMatrix();
	RenderSpotlightHead();

	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}

void SceneText::RenderSpotlightStand()
{
	modelStack.PushMatrix();
	RenderMesh(meshList[GEO_SPOTLIGHT_STAND], true);
	modelStack.PopMatrix();
}

void SceneText::RenderSpotlightJointPoint()
{
	modelStack.PushMatrix();
	modelStack.Scale(0.03f, 0.03f, 0.03f);
	RenderMesh(meshList[GEO_LIGHTSPHERE], false);
	modelStack.PopMatrix();
}

void SceneText::RenderSpotlightJoint()
{
	modelStack.PushMatrix();
	RenderMesh(meshList[GEO_SPOTLIGHT_JOINT], true);
	modelStack.PopMatrix();
}

void SceneText::RenderSpotlightHead()
{
	modelStack.PushMatrix();
	RenderMesh(meshList[GEO_SPOTLIGHT_HEAD], true);
	modelStack.PopMatrix();
}