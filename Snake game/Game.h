#pragma once
#include"Snake.h"
#include"Food.h"

class Game
{
	char player_name[25];
	Snake* s;
	Food* f;
	int score;
	int length;
	int width;
	bool Game_over;
public:
	Game(const char*,int=10,int=10);
	void Set_Snake(Snake* s);
	void Set_Food(Food* f);
	void PrintEnd_game();
	void Set_boarders(int l, int w);
	void Runsimulation();
	bool Is_end();

};

