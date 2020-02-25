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
}

NPC::~NPC()
{

}

std::string NPC::ReturnDialogue()
{
	srand(time(NULL));
	return dialogue.at(dialogueID);
}

std::string NPC::ReturnQuest()
{
	return NPCQuest.ReturnRequirement();
}

float NPC::ReturnReward()
{
	return NPCQuest.ReturnReward();
}

void NPC::SelectRandomDialogue()
{
	dialogueID = rand() % dialogue.size();
}

bool NPC::CheckQuestIssued()
{
	return false;
}

bool NPC::CheckQuestActive()
{
	return NPCQuest.QuestActive();
}

void NPC::CompleteQuest()
{
	NPCQuest.SetToCompleteQuest();
}
