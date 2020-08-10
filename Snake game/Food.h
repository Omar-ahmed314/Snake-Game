#pragma once
class Food
{
private:
	int x;
	int y;
	int length;
	int width;
public:
	Food(int, int);
	bool Is_Food(int , int );
	int Get_x();
	int Get_y();
	void Change_pos();
};

