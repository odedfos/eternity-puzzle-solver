#ifndef __STRATEGIES_H__
#define __STRATEGIES_H__

#include "Piece.h"
#include "Board.h"

extern Piece **g_PIECES;
extern Board* g_BOARD;

class Strategies
{
public:
	Strategies(void);
	~Strategies(void);

	static void placeCornersRandom();
	static void placeFrameRandom();
	static void placeCenterRandom();
	
	static void placeCenter();
	static void placeCorners();
	static void placeFrame();
	static void placeKnownPiece();
};

#endif

