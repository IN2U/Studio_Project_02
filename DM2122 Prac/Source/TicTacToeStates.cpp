#include "TicTacToe.h"
#include "Application.h"
#include "SceneManager.h"

#include "Helper/ButtonPos.h"
#include "Helper/Cursor.h"

#include "Global_Constants/GAME_STATES.h"

void TicTacToe::startState()
{
	if (Application::IsKeyPressed(MK_LBUTTON))
	{
		// To get cursor pos
		Cursor* mouse = Cursor::getInstance();

		// To get buttons pos
		Button* button = Button::getInstance();

		SceneManager* scene = SceneManager::getInstance();

		// PLAYER START
		if (mouse->getMXPos() > button->getButtonMinPosX() && mouse->getMXPos() < button->getButtonMaxPosX()
			&& mouse->getMYPos() < button->getButton1MaxPosY() && mouse->getMYPos() > button->getButton1MinPosY())
		{
			turn = HUMAN_PLAYER;
			gameCurrentState = GAME_STATE;
		}
		// CPU START
		else if (mouse->getMXPos() > button->getButtonMinPosX() && mouse->getMXPos() < button->getButtonMaxPosX()
			&& mouse->getMYPos() < button->getButton2MaxPosY() && mouse->getMYPos() > button->getButton2MinPosY())
		{
			turn = CPU_PLAYER;
			gameCurrentState = GAME_STATE;
		}
		// QUIT
		else if (mouse->getMXPos() > button->getButtonMinPosX() && mouse->getMXPos() < button->getButtonMaxPosX()
			&& mouse->getMYPos() < button->getButton3MaxPosY() && mouse->getMYPos() > button->getButton3MinPosY())
		{
			scene->SetNextScene(STATE::GAME_SCENE);
		}

		clicked = true;
	}
}

void TicTacToe::gameState()
{
	// If winner is still undecided
	if (winner == INVALID_VAL)
	{
		isTie();

		if (turn == HUMAN_PLAYER)
		{
			Human_Move();
		}
		else if (turn == CPU_PLAYER)
		{
			CPU_Move();
		}
	}
	else
	{
		gameCurrentState = END_STATE;
	}
}

void TicTacToe::endState()
{
	if (Application::IsKeyPressed(MK_LBUTTON))
	{
		// To get cursor pos
		Cursor* mouse = Cursor::getInstance();

		// To get buttons pos
		Button* button = Button::getInstance();

		SceneManager* scene = SceneManager::getInstance();

		// Restart
		if (mouse->getMXPos() > button->getButtonMinPosX() && mouse->getMXPos() < button->getButtonMaxPosX()
			&& mouse->getMYPos() < button->getButton1MaxPosY() && mouse->getMYPos() > button->getButton1MinPosY())
		{
			//if (scene->getCurrentSceneID() == 3)
			//	scene->SetNextScene(4);
			//else
			//	scene->SetNextScene(3);
		}
		// Exit game
		else if (mouse->getMXPos() > button->getButtonMinPosX() && mouse->getMXPos() < button->getButtonMaxPosX()
			&& mouse->getMYPos() < button->getButton2MaxPosY() && mouse->getMYPos() > button->getButton2MinPosY())
		{
			scene->SetNextScene(STATE::GAME_SCENE);
		}

		clicked = true;
	}
}
