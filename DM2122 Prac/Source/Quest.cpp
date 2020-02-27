#include "Quest.h"

Quest::Quest()
{
	srand(time(NULL));
	typeOfQuest = rand() % 3;
	if (typeOfQuest == 0){
		questRequirement = "Drive a car once.";
		questReward = 10000.f;
	}
	else if (typeOfQuest == 1) {
		questRequirement = "Buy an item at the vending machine.";
		questReward = 5000.f;
	}
	else {
		questRequirement = "Customise your car once.";
		questReward = 10000.f;
	}

	questActive = false;
}

Quest::~Quest()
{

}

std::string Quest::ReturnRequirement()
{
	return questRequirement;
}

float Quest::ReturnReward()
{
	return questReward;
}

bool Quest::QuestActive()
{
	return questActive;
}

void Quest::SetToStartQuest()
{
	questActive = true;
}

void Quest::SetToCompleteQuest()
{
	questActive = false;
	questRequirement = "You already completed my quest!";
	questReward = 0;
}
