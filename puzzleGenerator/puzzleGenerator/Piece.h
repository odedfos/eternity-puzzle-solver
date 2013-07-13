#ifndef ___PIECE_H__
#define ___PIECE_H__

#include "stdio.h"
#include <vector>

#define NO_PIECE 0

using namespace std;

enum Shape {NONE, CY, CH, CD, SY, SB, SP, QB, QG, AB, AH, AO, BY, BH, BO, PD, PP, PB, TD, FY, OD, WB, JB, KO};
enum Direction {TOP, RIGHT, BOTTOM, LEFT};

class Piece
{
private:
	int m_ID;
	vector<Shape> m_ShapeVec;
	int m_Rotation;
	
public:
	Piece(int id, Shape top, Shape right, Shape bottom, Shape left);
	~Piece(void);
	int getID() {return m_ID;}
	int getRotation() {return m_Rotation;}
	void setRotation(int rot) {m_Rotation = rot;}
	void rotateRight();
	void printPiece();
	Shape getTop();
	Shape getRight();
	Shape getBottom();
	Shape getLeft();
	bool tryToMatchPiece(Shape top, Shape right, Shape bottom, Shape left);

	static Piece** PieceGenerator();

};

#endif
