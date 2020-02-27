#include "NPC.h"

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
}

NPC::~NPC()
{

}

std::string NPC::ReturnDialogue()
{
	srand(time(NULL));
	return dialogue.at(dialogueID);
}

std::string NPC::ReturnTips()
{
	srand(time(NULL));
	return tips.at(tipsID);
}

Quest NPC::ReturnQuest()
{
	return NPCQuest;
}

float NPC::ReturnReward()
{
	return NPCQuest.ReturnReward();
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
	questActive = true;
}

void NPC::FinishQuest()
{
	questActive = false;
}

bool NPC::QuestIsActive()
{
	return questActive;
}

