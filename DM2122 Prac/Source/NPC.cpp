#include "NPC.h"
#include "Currency.h"
#include "Inventory.h"

NPC::NPC()
{
	std::string temp;
	temp = "Hello there.";
	dialogue.push_back(temp);

	temp = "The cars look amazing today.";
	dialogue.push_back(temp);

	temp = "Good day.";
	dialogue.push_back(temp);

	temp = "Want to go for a test drive?";
	dialogue.push_back(temp);

	temp = "How can I help you?";
	dialogue.push_back(temp);

	temp = "You can approach any vending machine to buy items.";
	tips.push_back(temp);

	temp = "Try to explore the area, you might find easter eggs!";
	tips.push_back(temp);

	questActive = false;
	goingToGiveTip = false;

	somethingHappened = false;

	NPCQuest = nullptr;
}

NPC::~NPC()
{

}

std::string NPC::ReturnDialogue()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	return dialogue.at(dialogueID);
}

std::string NPC::ReturnTips()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	return tips.at(tipsID);
}

Quest* NPC::ReturnQuest()
{
	return NPCQuest;
}

float NPC::ReturnReward()
{
	if (questActive) {
		return NPCQuest->ReturnReward();
	}
	else {
		return 0.f;
	}
}

void NPC::SelectRandomDialogue()
{
	dialogueID = rand() % dialogue.size();
}

void NPC::SelectRandomTip()
{
	tipsID = rand() % tips.size();
}

bool NPC::QuestCompleted()
{
	return false;
}

void NPC::StartQuest()
{
	NPCQuest = new Quest();
	questActive = true;
}

void NPC::FinishQuest()
{
	if (QuestRequirementMet())
	{
		Currency* currency3 = Currency::GetInstance();
		currency3->AddCurrency(int(NPCQuest->ReturnReward()));
		delete NPCQuest;
		questActive = false;
	}
}

bool NPC::QuestIsActive()
{
	return questActive;
}

bool NPC::IsGoingToGiveTip()
{
	return goingToGiveTip;
}

void NPC::SetToDefaultTipState()
{
	goingToGiveTip = false;
}

bool NPC::QuestRequirementMet()
{
	if (NPCQuest != nullptr)
	{
		if (NPCQuest->ReturnTypeOfQuest() == 0) //drive a car
		{
			return true;
		}
		else if (NPCQuest->ReturnTypeOfQuest() == 1) //own item from vending machine
		{
			Inventory* inventory3 = Inventory::GetInstance();
			if (inventory3->isEmpty())
			{
				return false;
			}
			else
				return true;
		}
		else if (NPCQuest->ReturnTypeOfQuest() == 2) // customise car once
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
