#include<iostream>
using namespace std;
#include"ChessGame.h"

int main() {
	Man man;
	Chess chess(13, 44, 43, 67.4);
	AI ai;
	ChessGame game(&man, &ai, &chess);
	game.play();
	system("pause");
	return 0;
}