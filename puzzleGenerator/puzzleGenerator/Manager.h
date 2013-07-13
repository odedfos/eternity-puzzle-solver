#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "Piece.h"
#include "Board.h"
#include <vector>

using namespace std;

extern Piece **g_PIECES;
extern Board* g_BOARD;
extern int g_NoMatchLimit;

class Manager
{
private:
	Piece **m_Pieces;
	vector<int> m_RandomVec;
	vector <Piece*> *m_CornersVec;
	vector <Piece*> *m_FrameVec;
	vector <Piece*> *m_CenterPiecesVec;
	vector <Piece*> *m_AllPiecesVec;
	vector <int> *m_RowIndexes;
	vector <int> *m_ColIndexes;

public:
	Manager(void);
	~Manager(void);

	void fillPuzzle();

	void placeCornersRandom();
	void placeFrameRandom();
	void placeCenterRandom();
	
	void placeCenter();
	void placeCorners();
	void placeFrame();
	void placeKnownPiece();

	void placeMinMatches();

	void resetPuzzle();
	Piece *findMatchRandom(vector<Piece*> *pieceVec, Shape top, Shape right, Shape bottom, Shape left);
	Piece *findMatch(vector<Piece*> *pieceVec, Shape top, Shape right, Shape bottom, Shape left);
	Piece *findMatch(vector<Piece*> *pieceVec, int i, int j);
	Piece *findMatch(int i, int j);
	Piece *findMatchWithMaxNeighbors(int row, int col);
	void getShapeRestrictions(Shape* restrictions, int i, int j);
	int getPosWithLeastMatches(int& iOut, int& jOut);  //return matches
	int getNumOfMatches(int i, int j);
	vector<Piece*>* getCorrectPieceVector(int i, int j);
	void mutateVector(vector<void*>* vec);
	void removePieceFromBoard(int row, int col);
};

#endif


