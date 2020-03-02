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
	int tipsID = 0;
	std::vector<std::string> dialogue;
	std::vector<std::string> tips;
	Quest* NPCQuest;

	bool questActive;
	bool goingToGiveTip;

	bool somethingHappened;

public:
	NPC();
	~NPC();

	std::string ReturnDialogue();
	std::string ReturnTips();
	float ReturnReward();

	void SelectRandomDialogue();
	void SelectRandomTip();

	bool QuestCompleted();

	void StartQuest();
	void FinishQuest();

	void CheckInput();
	void UpdateNPC();

	bool QuestIsActive();
	bool SomethingHappened();

	bool QuestRequirementMet();

	bool IsGoingToGiveTip();
	void SetToDefaultTipState();

	Quest* ReturnQuest();
};

#endif