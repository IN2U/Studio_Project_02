#ifndef QUEST_H
#define QUEST_H

#include <string>
#include <time.h>

class Quest
{
private:
	int typeOfQuest;
	std::string questRequirement;
	float questReward;

	bool questActive;

public:
	Quest();
	~Quest();

	std::string ReturnRequirement();
	float ReturnReward();

	bool QuestActive();

	void SetToStartQuest();
	void SetToCompleteQuest();
};

#endif