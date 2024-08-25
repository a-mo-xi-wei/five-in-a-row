#include "ChessGame.h"

ChessGame::ChessGame(Man* man, AI* ai, Chess* chess)
{
	this->man = man;
	this->ai = ai;
	this->chess = chess;

	ai->init(chess);
	man->init(chess);
};

void ChessGame::play()
{
	chess->init();
	while (1) {
		//先由棋手走
		man->go();
		if (chess->checkOver()) {
			chess->init();;
			continue;
		}
		//由AI走
		ai->go();
		if (chess->checkOver()) {
			chess->init();
			continue;
		}
	}
}