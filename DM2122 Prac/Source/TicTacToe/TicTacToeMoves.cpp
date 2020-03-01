#include "TicTacToe.h"
#include "../Application.h"

#include "../Helper/Cursor.h"
#include "../Helper/Window.h"

void TicTacToe::Human_Move()
{
	if (Application::IsKeyPressed(MK_LBUTTON))
	{
		// To get cursor pos
		Cursor* mouse = Cursor::getInstance();

		// To get window size
		Window* window = Window::getInstance();

		int row;
		int column;

		// Finds position of click and clamps it to 0 - 2
		if (mouse->getMXPos() < double(window->getWidth() / 3))
			column = 0;
		else if (mouse->getMXPos() < (double)window->getWidth() / 3 * (double)2)
			column = 1;
		else
			column = 2;

		if (mouse->getMYPos() < double(window->getHeight() / 3))
			row = 0;
		else if (mouse->getMYPos() < (double)window->getHeight() / 3 * (double)2)
			row = 1;
		else
			row = 2;

		// Allows input
		validInput = true;

		// If cell is empty, changes the number to 1
		if (board[column][row] == NO_VAL)
		{
			board[column][row] = PLAYER_VAL;

			// Change turn
			turn = CPU_PLAYER;
		}
		else
		{
			validInput = false;
		}

		// Checks if player won
		if (isWinner(HUMAN_PLAYER) == true)
		{
			winner = PLAYER_VAL;
		}

		clicked = true;
	}
}

void TicTacToe::CPU_Move()
{
	AiMove cpuMove = minimax(board);
	board[cpuMove.row][cpuMove.column] = CPU_VAL;

	// Checks if player won
	if (isWinner(CPU_PLAYER) == true)
	{
		winner = CPU_VAL;
	}

	// Change turn
	turn = HUMAN_PLAYER;
}

bool TicTacToe::isWinner(PLAYER_TYPE player)
{
	int playerType;

	if (player == HUMAN_PLAYER)
		playerType = PLAYER_VAL;
	else
		playerType = CPU_VAL;

	// Check horizontal cells from left to right
	for (int i = 0; i < 3; ++i)
	{
		if (board[i][0] == playerType && board[i][1] == playerType && board[i][2] == playerType)
		{
			return true;
		}
	}

	// Check vertical cells from top to bottom
	for (int i = 0; i < 3; ++i)
	{
		if (board[0][i] == playerType && board[1][i] == playerType && board[2][i] == playerType)
		{
			return true;
		}
	}

	// Check diagonal cells from top left to bottom right
	if (board[0][0] == playerType && board[1][1] == playerType && board[2][2] == playerType)
	{
		return true;
	}

	// Check diagonal cells from top right to bottom left
	if (board[0][2] == playerType && board[1][1] == playerType && board[2][0] == playerType)
	{
		return true;
	}

	return false;
}

TicTacToe::AiMove TicTacToe::minimax(int board[3][3])
{
	// arbitrary value
	int bestMoveScore = 100;

	// Searches for an empty cell
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i][j] == NO_VAL)
			{
				// Temporarily set that cell to CPU_VAL 
				board[i][j] = CPU_VAL;

				// Checks the score when CPU_VAL is placed the there
				// If game is not over when it is placed there, set another empty cell to PLAYER_VAL
				// If game is over by then, returns a -10 score
				int tempMoveScore = maxSearch(board);

				// Compares current bestMoveScore with the bestMoveScore from maxSearch()
				// Switches current bestMoveScore with tempMoveScore if tempMoveScore is lower for next loop 
				if (tempMoveScore <= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
					bestMove.row = i;
					bestMove.column = j;
				}

				// Reset that cell to empty value
				board[i][j] = NO_VAL;
			}
		}
	}

	return bestMove;
}

int TicTacToe::maxSearch(int board[3][3])
{
	// Go back to minimax if game is over when CPU_VAL is placed in that empty cell with the score
	if (gameOver() == true)
	{
		return score();
	}

	AiMove bestMove;

	int bestMoveScore = -10000;

	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal value. 
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i][j] == NO_VAL)
			{
				// Temporarily set that cell to PLAYER_VAL 
				board[i][j] = PLAYER_VAL;

				// Checks the score when PLAYER_VAL is placed there
				// Call minSearch recursively and choose the minimum value 
				int tempMoveScore = minSearch(board);

				if (tempMoveScore >= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
					bestMove.row = i;
					bestMove.column = j;
				}

				// Reset that cell to empty value
				board[i][j] = NO_VAL;
			}
		}
	}

	return bestMoveScore;
}

int TicTacToe::minSearch(int board[3][3])
{
	// Go back to maxSearch if game is over when PLAYER_VAL is placed in that empty cell with the score
	if (gameOver())
	{
		return score();
	}

	AiMove bestMove;

	int bestMoveScore = 10000;

	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal value. 
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i][j] == NO_VAL)
			{
				// Temporarily set that cell to CPU_VAL
				board[i][j] = CPU_VAL;

				// Tests if game will be over if CPU_VAL is placed there and returns the score
				// Call maxSearch recursively and choose the maximum value 
				int tempMove = maxSearch(board);

				if (tempMove <= bestMoveScore)
				{
					bestMoveScore = tempMove;
					bestMove.row = i;
					bestMove.column = j;
				}

				// Reset that cell to empty value
				board[i][j] = NO_VAL;
			}
		}
	}

	return bestMoveScore;
}

bool TicTacToe::gameOver()
{
	if (isWinner(HUMAN_PLAYER))
	{
		return true;
	}
	else if (isWinner(CPU_PLAYER))
	{
		return true;
	}

	bool emptySpace = false;

	// Checks each row if there are empty spaces
	for (int i = 0; i < 3; ++i)
	{
		if (board[i][0] == NO_VAL || board[i][1] == NO_VAL || board[i][2] == NO_VAL)
			emptySpace = true;
	}

	// Returns true if there are no empty space
	// Returns false if there are empty spaces
	return !emptySpace;
}

int TicTacToe::score()
{
	if (isWinner(HUMAN_PLAYER))
	{
		return 10;
	}
	else if (isWinner(CPU_PLAYER))
	{
		return -10;
	}
	return 0;
}

void TicTacToe::isTie()
{
	// Resets count
	int emptySpaceCount = 9;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i][j] != NO_VAL)
			{
				emptySpaceCount -= 1;
			}
		}
	}

	// When all cells are taken
	if (emptySpaceCount == 0)
	{
		winner = NO_VAL;
	}
}