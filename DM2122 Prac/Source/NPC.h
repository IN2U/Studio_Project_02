#ifndef NPC_H
#define NPC_H

#include <time.h>
#include <string>
#include <vector>
#include "Quest.h"

class NPC
{
private:
	int dialogueID = 0;
	std::vector<std::string> dialogue;
	Quest NPCQuest;



public:
	NPC();
	~NPC();

	std::string ReturnDialogue();
	std::string ReturnQuest();
	float ReturnReward();

	bool CheckQuestActive();
	void CompleteQuest();
	void SelectRandomDialogue();

	void StartQuest();
	

	
};

#endif