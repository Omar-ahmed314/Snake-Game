#include "Food.h"
#include<iostream>

Food::Food(int x, int y)
{
	width=this->x = rand() % (x - 1) + 1;
	length=this->y = rand() % (y - 1) + 1;
}
bool Food::Is_Food(int x, int y)
{
	if (this->x == x && this->y == y)
		return true;
	else
		return false;
}
void Food::Change_pos()
{
	this->x = rand() % (width ) + 1;
	this->y = rand() % (length ) + 1;
}
int Food::Get_x()
{
	return x;
}
int Food::Get_y()
{
	return y;
}