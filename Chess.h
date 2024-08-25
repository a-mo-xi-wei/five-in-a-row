#pragma once
#include<graphics.h>
#include<vector>
using namespace std;

//��ʾ����λ��
struct ChessPos {
	ChessPos(int r = 0, int c = 0) :row(r), col(c) {}
	int row;
	int col;
};

typedef enum {
	CHESS_WHITE = -1,//����
	CHESS_BLACK = 1
}chess_kind_t;

class Chess
{
public:
	Chess(int gradeSize, int marginX, int marginY, float chessSize);

	// ���̵ĳ�ʼ�����������̵�ͼƬ��Դ����ʼ�����̵��������
	void init();

	// �ж���ָ������(x,y)λ�ã��Ƿ�����Ч���
	// �������Ч���������Ч�����λ��(�У��У������ڲ���pos��
	bool clickBoard(int x, int y, ChessPos* pos);

	// �����̵�ָ��λ�ã�pos��, ���ӣ�kind��
	void chessDown(ChessPos* pos, chess_kind_t kind);

	// ��ȡ���̵Ĵ�С��13�ߡ�15�ߡ�19�ߣ�
	int getGradeSize();

	// ��ȡָ��λ���Ǻ��壬���ǰ��壬���ǿհ�
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);

	// �ж�����Ƿ����
	bool checkOver();
	bool checkWin();

private:
	// ���̳ߴ�
	int gradeSize;
	float margin_x;//49;
	int margin_y;// 49;
	float chessSize; //���Ӵ�С�����̷����С��

	IMAGE chessBlackImg;
	IMAGE chessWhiteImg;

	// �洢��ǰ��Ϸ���̺����ӵ����,�հ�Ϊ0������1������-1
	vector<vector<int>> chessMap;

	// ��ʾ���巽, true:���巽  false: AI ���巽��AI����
	bool playerFlag;
	void updateGameMap(ChessPos* pos);
	ChessPos lastPos; //�������λ��, Chess��private���ݳ�Ա
};

