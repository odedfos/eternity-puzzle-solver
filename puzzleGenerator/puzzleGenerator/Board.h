#ifndef ___BOARD_H__
#define ___BOARD_H__

#include "Piece.h"

using namespace std;

#define BOARD_SIZE 16

typedef struct Square
{
	Piece *m_Piece;
	int Row, Col;
	Square(Piece* p, int row, int col)
		: m_Piece(p), Row(row), Col(col)
	{}
}Square;

extern Piece **g_PIECES;

class Board
{
public:
	Square* m_Loc[BOARD_SIZE][BOARD_SIZE];
	int m_Matches;
	int m_MissingPieces;
	int m_NoMatch;

public:
	Board(void);
	~Board(void);
	void placePiece(int i, int j, Piece* p);
	char* writeBoardToFile(char *filename);
	void clearBoard();
	void evaluateMatches();
	void setPiece(Piece *p, int row, int col);
	Piece* getPiece(int row, int col);

};

#endif


