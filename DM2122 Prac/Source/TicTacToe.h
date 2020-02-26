#pragma once

#include "Scene.h"

class TicTacToe : public Scene
{
private:
	enum PLAYER_TYPE
	{
		HUMAN_PLAYER,
		CPU_PLAYER
	};

	enum GEOMETRY_TYPE
	{
		ENDING_SCREEN,
		BUTTON,
		GRID,
		TEXT,
		NUM_GEOMETRY,
	};

	struct AiMove
	{
		int row;
		int column;
		AiMove() : row(0), column(0) {}
	};

	AiMove bestMove;

	// Player indicators
	const int INVALID_VAL;
	const int NO_VAL;
	const int PLAYER_VAL;
	const int CPU_VAL;

	// "X" "O" properties
	const float MARK_COLOR;
	const float MARK_SIZE;
	const float MARK_X;
	const float MARK_Y;

	int board[3][3];
	int turn;
	int winner;
	bool validInput;

	// Debounce
	double sceneTime;
	double debounceTime;
	bool clicked;

	// Human turn to move
	void Human_Move();

	// CPU turn to move
	void CPU_Move();

	// Checks if game is tied
	void isTie();

	// Checks if a player won
	bool isWinner(PLAYER_TYPE player);

	// Minimax algorithm, tries every single possible move player can make and assigns a score to each one and use the best score
	// Returns the coord of best move
	// Failed attempt
	AiMove minimax(int board[3][3]);

	// Predicts the next move of cpu player, chooses the move with the highest possible score
	int maxSearch(int board[3][3]);

	// Predicts the next move of human player, chooses the move with the least possible score
	int minSearch(int board[3][3]);
	
	// Returns true if a winner has been found or there are no empty spaces
	bool gameOver();
	 
	// Returns 10 for human win, -10 for cpu win, 0 for draw
	int score();

	Mesh* meshList[NUM_GEOMETRY];

	virtual void InitMeshList() override;
public:
	TicTacToe();
	~TicTacToe();

	virtual void Init() override;
	virtual void Update(double dt) override;
	virtual void Render() override;
	virtual void Exit() override;
};