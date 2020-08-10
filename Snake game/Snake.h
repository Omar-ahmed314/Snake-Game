#pragma once
#include"enum.h"
#include<conio.h>
#include<vector>

#include<utility>
using namespace std;
class Snake
{
private:
	int x;
	int y;
	int x_tail;
	int y_tail;
	int speed;
	int length;
	
	vector<pair<int,int>>t;
	direction d;
public:
	Snake();
	bool Is_tail(int& x, int& y);
	bool Is_snake(int& x, int &y);
	bool Is_touched();
	void Set_x(const int &x);
	void Set_y(const int &y);
	int Get_x();
	int Get_y();
	void Set_dir(const direction);
	void Read_key();
	void Change_dir();
	void Increase_length();
	void Shift_tail();
};

