#include "stdio.h"
#include "Piece.h"
#include "Board.h"
#include "Manager.h"
#include <ctime>

Piece **g_PIECES;
Board* g_BOARD;

int main()
{
	srand((unsigned)time(0));
	int minMissing = 50;
	int missingPieces = 0;
	int sessionNum = 0;
	g_PIECES = Piece::PieceGenerator();
	g_BOARD = new Board();
	Manager *manager = new Manager();
	printf("Initializing puzzle generator...\n");
	while (true)
	{
		sessionNum++;
		printf("%d..", sessionNum);
		manager->resetPuzzle();
		manager->fillPuzzle();
		g_BOARD->evaluateMatches();
		missingPieces = g_BOARD->m_MissingPieces;
		if (missingPieces < minMissing)
		{
			printf("\nFound %d matches, and %d missing pieces.\n", g_BOARD->m_Matches, g_BOARD->m_MissingPieces);
			g_BOARD->writeBoardToFile("results/puzz");
			minMissing = missingPieces;
			printf("new Min: %d\n", minMissing);
		}
	}
	getchar();
}

