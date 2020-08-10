#include<iostream>
#include"Game.h"
#include<time.h>
using namespace std;

int main()
{
	srand((unsigned) time(NULL));

	Game G1("Omar ahmed",25,30);

	G1.Runsimulation();

	system("pause");
	

	return 0;
}