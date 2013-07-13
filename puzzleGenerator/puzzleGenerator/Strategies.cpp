#include "Strategies.h"

Strategies::Strategies(void)
{
}

Strategies::~Strategies(void)
{
}

void Manager::placeCornersRandom()
{
	g_BOARD->m_Loc[0][0] = findMatch(m_CornersVec, TD, NONE, NONE, TD);
	g_BOARD->m_Loc[0][15] = findMatch(m_CornersVec, TD, TD, NONE, NONE);
	g_BOARD->m_Loc[15][0] = findMatch(m_CornersVec, NONE, NONE, TD, TD);
	g_BOARD->m_Loc[15][15] = findMatch(m_CornersVec, NONE, TD, TD, NONE);
}

void Manager::placeFrameRandom()
{
	for (int i = 1; i < 15; i++)
	{
		g_BOARD->m_Loc[0][i] = findMatch(m_FrameVec, TD, NONE, NONE, NONE);
		g_BOARD->m_Loc[i][15] = findMatch(m_FrameVec, NONE, TD, NONE, NONE);
		g_BOARD->m_Loc[15][i] = findMatch(m_FrameVec, NONE, NONE, TD, NONE);
		g_BOARD->m_Loc[i][0] = findMatch(m_FrameVec, NONE, NONE, NONE, TD);
	}
}

void Manager::placeCenterRandom()
{
	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 15; j++)
			g_BOARD->m_Loc[i][j] = findMatchRandom(m_CenterPiecesVec, NONE, NONE, NONE, NONE);
}

void Manager::placeCenterSnail() //start at location[7][8], go clockwise.
{
	int i = 8;
	int j = 7;
	int stepSize = 0;
	while (i != 15 && j != 15)
	{
		stepSize++;
		for (int step = 0; step < stepSize; step++)	//up
		{
			i--;
			g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
		}
		for (int step = 0; step < stepSize; step++)	//right
		{
			j++;
			g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
		}
		stepSize++;
		for (int step = 0; step < stepSize; step++)	//down
		{
			i++;
			if (i > 15)
				return;
			g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
		}
		for (int step = 0; step < stepSize; step++)	//left
		{
			j--;
			g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
		}
	}
}

void Manager::placeReverseSnail()
{
	int i = 14;
	int j = 1;
	int stepSize = 14;
	g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
	while (stepSize > 0)
	{
		stepSize--;
		for (int step = 0; step < stepSize; step++)	//up
		{
			i--;
			g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
		}
		for (int step = 0; step < stepSize; step++)	//right
		{
			j++;
			g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
		}
		stepSize--;
		for (int step = 0; step < stepSize; step++)	//down
		{
			i++;
			g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
		}
		for (int step = 0; step < stepSize; step++)	//left
		{
			j--;
			g_BOARD->m_Loc[i][j] = findMatch(m_CenterPiecesVec, i, j);
		}
	}
}

