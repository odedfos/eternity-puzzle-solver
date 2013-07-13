#include "stdio.h"
#include "Piece.h"
#include "Board.h"
#include "Manager.h"
#include <ctime>

Piece **g_PIECES;
Board* g_BOARD;
int g_NoMatchLimit = 35;

int main(int argc, char *argv[])
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
		if (sessionNum % 1000 == 0)
			printf("%d..", sessionNum);
		manager->resetPuzzle();
		manager->fillPuzzle();
		g_BOARD->evaluateMatches();
		missingPieces = g_BOARD->m_MissingPieces;
		if (missingPieces < minMissing)
		{
			printf("\nFound %d matches, and %d missing pieces.\n", g_BOARD->m_Matches, g_BOARD->m_MissingPieces);
			if (argc < 2)
				g_BOARD->writeBoardToFile("puzz");
			else
				g_BOARD->writeBoardToFile(argv[1]);
			minMissing = missingPieces;
			printf("new Min: %d\n", minMissing);
		}
	}
}

