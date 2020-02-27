#include "Quest.h"

Quest::Quest()
{
	srand(time(NULL));
	typeOfQuest = rand() % 3;
	if (typeOfQuest == 0) {
		questRequirement = "Drive a car at least once.";
		questReward = 10000.f;
	}
	else if (typeOfQuest == 1) {
		questRequirement = "Own an item from the vending machine.";
		questReward = 5000.f;
	}
	else {
		questRequirement = "Customise your car at least once.";
		questReward = 10000.f;
	}
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

int Quest::ReturnTypeOfQuest()
{
	return typeOfQuest;
}

