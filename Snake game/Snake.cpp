#include "Snake.h"
Snake::Snake()
{
	length = 0;
	speed = 1;
}

bool Snake::Is_snake(int& x, int &y)
{
	if (this->x == x && this->y == y)
		return true;
	else
		return false;

}

void Snake::Set_x(const int &x)
{
	this->x = x;
}

void Snake::Set_y(const int& y)
{
	this->y = y;
}


void Snake::Set_dir(const direction d)
{
	this->d = d;
}


void Snake::Read_key()
{
	if (_kbhit())
	{
		int c = _getch();
		switch (c)
		{
		case 72:
			d = UP;
			break;
		case 80:
			d = DOWN;
			break;
		case 75:
			d = LEFT;
			break;
		case 77:
			d = RIGHT;
			break;
		}
	}
	else
		return;
}

void Snake::Change_dir()
{
	switch (this->d)
	{
	case UP:
		y-=1*speed;
		
		break;
	case DOWN:
		y+=1*speed;
		
		break;
	case LEFT:
		x-=1*speed;
		
		break;
	case RIGHT:
		x+=1*speed;
		
		break;
	}
}
int Snake::Get_x()
{
	return x;
}
int Snake::Get_y()
{
	return y;
}
bool Snake::Is_tail(int& x, int& y)
{
	auto it = t.begin();
	for (; it != t.end(); it++)
		if (it->first == x && it->second == y)
			return true;
	return false;


}
void Snake::Increase_length()
{
	if (length == 0)
	{
		t.push_back({ x,y });
	}
	else
	{
		t.push_back(t[length-1]);
	}
	length++;
}
void Snake::Shift_tail()
{
	if (length != 0)
	{
		for (int i = length - 2; i >= 0; i--)
		{
			t[i + 1] = t[i];
		}
		t[0] = { x,y };
	}
}
bool Snake::Is_touched()
{
	if (length != 0)
	{
		auto it = t.begin();
		for (; it != t.end(); it++)
		{
			if (it->first==x&&it->second==y)
				return true;
		}
	}
	else
		return false;
}