#include "TicTacToe.h"
#include "GL\glew.h"
#include "../shader.hpp"
#include "../Application.h"
#include "../SceneManager.h"

#include "../Global_Constants/TEXT_BUTTON.h"

TicTacToe::TicTacToe() : INVALID_VAL(-1), NO_VAL(0), PLAYER_VAL(1), CPU_VAL(2),
MARK_COLOR(0.f), MARK_SIZE(8.f), MARK_X(1.4f), MARK_Y(5.75f),
board{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
meshList{ NULL, NULL, NULL, NULL, NULL },
START_STATE(0), GAME_STATE(1), END_STATE(2), gameCurrentState(START_STATE)
{
	turn = HUMAN_PLAYER;
	winner = INVALID_VAL;
	validInput = true;

	sceneTime = 0.0;
	debounceTime = 0.0;
	clicked = false;

	bestMove.row = -1;
	bestMove.column = -1;
}

TicTacToe::~TicTacToe()
{
}

void TicTacToe::Init()
{
	glClearColor(0, 0, 0, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");

	InitShaderUniforms();

	glUseProgram(m_programID);

	InitMeshList();

	sceneTime = 0.0;
}

void TicTacToe::Update(double dt)
{
	sceneTime += dt;

	clicked = false;

	if (debounceTime > sceneTime)
		return;

	if (gameCurrentState == START_STATE)
	{
		startState();
	}
	else if (gameCurrentState == GAME_STATE)
	{
		gameState();
	}
	else if (gameCurrentState == END_STATE)
	{
		endState();
	}

	if (clicked)
	{
		debounceTime = sceneTime + 0.15;
	}
}

void TicTacToe::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (gameCurrentState == START_STATE)
	{
		RenderMeshOnScreen(meshList[STARTING_SCREEN], TxtB::CENTRE_OF_SCREEN_X, 30, 80, 60);

		RenderMeshOnScreen(meshList[BUTTON], TxtB::CENTRE_OF_SCREEN_X, 35.f, TxtB::BUTTON_SIZE_X + 11.5f, TxtB::BUTTON_SIZE_Y);
		RenderMeshOnScreen(meshList[BUTTON], TxtB::CENTRE_OF_SCREEN_X, 29.f, TxtB::BUTTON_SIZE_X + 11.5f, TxtB::BUTTON_SIZE_Y);
		RenderMeshOnScreen(meshList[BUTTON], TxtB::CENTRE_OF_SCREEN_X, 23.f, TxtB::BUTTON_SIZE_X + 11.5f, TxtB::BUTTON_SIZE_Y);

		RenderTextOnScreen(meshList[TEXT], "Player start", Color(TxtB::TEXT_COLOR, TxtB::TEXT_COLOR, TxtB::TEXT_COLOR), TxtB::TEXT_SIZE, 7.8f, TxtB::TEXT_DISTANCE_Y);
		RenderTextOnScreen(meshList[TEXT], "CPU start", Color(TxtB::TEXT_COLOR, TxtB::TEXT_COLOR, TxtB::TEXT_COLOR), TxtB::TEXT_SIZE, 9.1f, TxtB::TEXT_DISTANCE_Y - 2);
		RenderTextOnScreen(meshList[TEXT], "Quit", Color(TxtB::TEXT_COLOR, TxtB::TEXT_COLOR, TxtB::TEXT_COLOR), TxtB::TEXT_SIZE, 11.6f, TxtB::TEXT_DISTANCE_Y - 4);
	}
	else
	{
		RenderMeshOnScreen(meshList[GRID], TxtB::CENTRE_OF_SCREEN_X, 30, 80, 60);

		// Draws 'X' or 'O' at respective player's cell
		for (int row = 0; row < 3; ++row)
		{
			for (int column = 0; column < 3; ++column)
			{
				if (board[column][row] == PLAYER_VAL)
				{
					RenderTextOnScreen(meshList[TEXT], "X", Color(MARK_COLOR, MARK_COLOR, MARK_COLOR), MARK_SIZE, MARK_X + float(column * 3 + 0.35 * column), MARK_Y - float(row * 2 + 0.45 * row));
				}
				else if (board[column][row] == CPU_VAL)
				{
					RenderTextOnScreen(meshList[TEXT], "O", Color(MARK_COLOR, MARK_COLOR, MARK_COLOR), MARK_SIZE, MARK_X + float(column * 3 + 0.35 * column), MARK_Y - float(row * 2 + 0.45 * row));
				}
			}
		}

		// When clicked on a used cell
		if (validInput == false)
		{
			RenderTextOnScreen(meshList[TEXT], "Invalid input", Color(1.f, 0.f, 0.f), 6.f, 0.5f, 1.8f);
		}

		// When game is over
		if (winner != INVALID_VAL)
		{
			if (winner == NO_VAL)
			{
				RenderTextOnScreen(meshList[TEXT], "Tie", Color(0.314f, 0.863f, 0.392f), 7.f, 4.4f, 1.8f);
			}
			else if (winner == PLAYER_VAL)
			{
				RenderTextOnScreen(meshList[TEXT], "Player Wins", Color(0.314f, 0.863f, 0.392f), 7.f, 0.5f, 1.8f);
			}
			else if (winner == CPU_VAL)
			{
				RenderTextOnScreen(meshList[TEXT], "CPU Wins", Color(0.314f, 0.863f, 0.392f), 7.f, 1.8f, 1.8f);
			}

			RenderMeshOnScreen(meshList[ENDING_SCREEN], TxtB::CENTRE_OF_SCREEN_X, 30, 80, 60);

			RenderMeshOnScreen(meshList[BUTTON], TxtB::CENTRE_OF_SCREEN_X, 35.f, TxtB::BUTTON_SIZE_X, TxtB::BUTTON_SIZE_Y);
			RenderMeshOnScreen(meshList[BUTTON], TxtB::CENTRE_OF_SCREEN_X, 29.f, TxtB::BUTTON_SIZE_X, TxtB::BUTTON_SIZE_Y);

			RenderTextOnScreen(meshList[TEXT], "Restart", Color(TxtB::TEXT_COLOR, TxtB::TEXT_COLOR, TxtB::TEXT_COLOR), TxtB::TEXT_SIZE, 10.1f, TxtB::TEXT_DISTANCE_Y);
			RenderTextOnScreen(meshList[TEXT], "Exit", Color(TxtB::TEXT_COLOR, TxtB::TEXT_COLOR, TxtB::TEXT_COLOR), TxtB::TEXT_SIZE, 11.6f, TxtB::TEXT_DISTANCE_Y - 2);
		}
	}
}

void TicTacToe::Exit()
{
	// Cleanup here
	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		if (meshList[i] != NULL)
			delete meshList[i];
	}
	// Cleanup VBO here
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}