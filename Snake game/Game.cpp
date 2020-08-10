#include "Game.h"
#include<iostream>
#include<cstring>
using namespace std;

Game::Game(const char*p,int l, int w)
{
	strcpy_s(player_name, p);

		s = new Snake;
		f = new Food(w, l);
		length = l;
		width = w;
		Game_over = false;
		s->Set_x(width/2);
		s->Set_y(length/2);
		score = 0;

}
void Game::Runsimulation()
{
	while (!Is_end())
	{
		s->Read_key();
		s->Change_dir();


		for (int i = 0; i <= length; i++)
		{
			for (int j = 0; j <= width; j++)
			{
				if (i == 0 || i == length)
					cout << '#';
				else if (j == 0 || j == width)
					cout << '#';
				else if (s->Is_snake(j, i))
					cout << 'O';
				else if (s->Is_tail(j, i))
					cout << 'o';
				else if (f->Is_Food(j, i))
					cout << 'F';
				else
					cout << ' ';



			}
			cout << endl;
		}
		// Printing the score of the player

		cout << endl << endl;
		cout << " The Score : " << score;

		// Check if it's game over or not
		if (s->Is_touched())
			Game_over = true;




		// Detect and change the position of the food
		if (s->Get_x() == f->Get_x() && s->Get_y() == f->Get_y())
		{
			f->Change_pos();
			s->Increase_length();
			score += 10;
			cout << '\a';
		}
		// Shift the tail vector
		s->Shift_tail();
		// change the direction of the snake with the close of boarderes
		if (s->Get_x() == 0)
			s->Set_x(width);
		else if (s->Get_x() == width)
			s->Set_x(0);
		else if (s->Get_y() == 0)
			s->Set_y(length);
		else if (s->Get_y() == length)
			s->Set_y(0);
		system("cls");


	}
	PrintEnd_game();
}

bool Game::Is_end()
{
	return Game_over;
}
void Game::PrintEnd_game()
{
	cout << "GAME OVER" << endl;
	cout << "YOUR SCORE IS : " << score << endl;

}
