#include "SceneText.h"
#include "NPC.h"
#include "Application.h"

#include "Currency.h"

void NPC::CheckInput()
{
	if (Application::IsKeyPressed('1'))
	{
		SelectRandomDialogue();
		goingToGiveTip = true;
		somethingHappened = true;
	}

	else if (!questActive)
	{
		if (Application::IsKeyPressed('2'))
		{
			StartQuest();
			somethingHappened = true;
		}
	}
	else if (questActive)
	{
		if (Application::IsKeyPressed('2'))
		{
			if (QuestRequirementMet())
			{
				FinishQuest();
				somethingHappened = true;
			}
			else
			{
				somethingHappened = true;
			}
		}
	}

}

void NPC::UpdateNPC()
{
	somethingHappened = false;
	CheckInput();

	if (tipsID != -1)
	{
		goingToGiveTip = true;
	}
	else if (tipsID == -1)
	{
		goingToGiveTip = false;
	}
}

bool NPC::SomethingHappened()
{
	return somethingHappened;
}