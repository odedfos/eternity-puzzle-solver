#include "Manager.h"
#include <cstdlib>
#include <algorithm>
#include <ctime> 

Manager::Manager()
{
	m_CornersVec = new vector<Piece*>();
	m_FrameVec = new vector<Piece*>();
	m_CenterPiecesVec = new vector<Piece*>();
	m_AllPiecesVec = new vector<Piece*>();
	m_RowIndexes = new vector<int>();
	m_ColIndexes = new vector<int>();
	resetPuzzle();
}

Manager::~Manager(void)
{
	delete m_CornersVec;
	delete m_FrameVec;
	delete m_CenterPiecesVec;
	delete m_AllPiecesVec;
	delete m_RowIndexes;
	delete m_ColIndexes;
}

void Manager::fillPuzzle()
{
	placeKnownPiece();

	placeCorners();
	placeMinMatches();
	//placeFrame();
	//placeCenter();
	//placeCenterSnail();
	//placeReverseSnail();

}

void Manager::resetPuzzle()
{
	g_BOARD->clearBoard();
	m_CornersVec->clear();
	m_FrameVec->clear();
	m_CenterPiecesVec->clear();
	m_AllPiecesVec->clear();
	m_RowIndexes->clear();
	m_ColIndexes->clear();
	for (int i = 1; i <= 4; i++)
		m_CornersVec->push_back(g_PIECES[i]);
	for (int i = 5; i <= 60; i++)
		m_FrameVec->push_back(g_PIECES[i]);
	for (int i = 61; i <= 256; i++)
		m_CenterPiecesVec->push_back(g_PIECES[i]);
	for (int i = 1; i <= 256; i++)
		m_AllPiecesVec->push_back(g_PIECES[i]);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		m_RowIndexes->push_back(i);
		m_ColIndexes->push_back(i);
	}
	random_shuffle(m_RowIndexes->begin(), m_RowIndexes->end());
	random_shuffle(m_ColIndexes->begin(), m_ColIndexes->end());
	random_shuffle(m_CornersVec->begin(), m_CornersVec->end());
	random_shuffle(m_FrameVec->begin(), m_FrameVec->end());
	random_shuffle(m_CenterPiecesVec->begin(), m_CenterPiecesVec->end());
	random_shuffle(m_AllPiecesVec->begin(), m_AllPiecesVec->end());
}

void Manager::mutateVector(vector<void*>* vec)
{
	if (vec->size() <= 1)
		return;
	void* element = NULL;
	int randIndex = rand();
	if (randIndex % 2 == 0)
	{
		element = vec->front();
		vec->erase(vec->begin());
	}
	else
	{
		element = vec->back();
		vec->pop_back();
	}
	vec->insert(vec->begin() + (randIndex % vec->size()), element);
}

void Manager::placeCorners()
{
	g_BOARD->m_Loc[0][0]->m_Piece = findMatch(m_CornersVec, 0, 0); 
	g_BOARD->m_Loc[0][15]->m_Piece = findMatch(m_CornersVec, 0, 15);
	g_BOARD->m_Loc[15][0]->m_Piece = findMatch(m_CornersVec,15, 0);
	g_BOARD->m_Loc[15][15]->m_Piece = findMatch(m_CornersVec, 15, 15);
}

void Manager::placeFrame()
{
	for (int i = 1; i < 15; i++)
	{
		g_BOARD->m_Loc[0][i]->m_Piece = findMatch(m_FrameVec, 0, i);
		g_BOARD->m_Loc[i][15]->m_Piece = findMatch(m_FrameVec, i, 15);
		g_BOARD->m_Loc[15][i]->m_Piece = findMatch(m_FrameVec, 15, i);
		g_BOARD->m_Loc[i][0]->m_Piece = findMatch(m_FrameVec, i, 0);
	}
}

void Manager::placeKnownPiece()
{
	Piece* p139 = NULL;
	for (unsigned int i = 0; i < m_CenterPiecesVec->size(); i++)
	{
		if (m_CenterPiecesVec->at(i)->getID() == 139 && g_BOARD->getPiece(8, 7) == g_PIECES[NO_PIECE])
		{
			p139 = m_CenterPiecesVec->at(i);
			m_CenterPiecesVec->erase(m_CenterPiecesVec->begin() + i);
			p139->setRotation(2);
			g_BOARD->setPiece(p139, 8, 7);
			return;
		}
	}
}

void Manager::placeCenter()
{
	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 15; j++)
			g_BOARD->setPiece(findMatch(m_CenterPiecesVec, i, j), i, j);
}

Piece* Manager::findMatchRandom(vector<Piece*> *pieceVec, Shape top, Shape right, Shape bottom, Shape left)
{
	int index = rand() % pieceVec->size();
	int rotation = rand() % 4;
	Piece* res = pieceVec->at(index);
	res->setRotation(rotation);
	pieceVec->erase(pieceVec->begin() + index);
	return res;
}

Piece* Manager::findMatch(vector<Piece*> *pieceVec, Shape top, Shape right, Shape bottom, Shape left)
{
	Piece* res = NULL;
	//random_shuffle(pieceVec->begin(), pieceVec->end());
	mutateVector((vector<void*>*)pieceVec);
	vector <Piece*>::iterator iter;
	for (iter = pieceVec->begin(); iter != pieceVec->end(); iter++)
	{
		res = *iter;
		if (res->tryToMatchPiece(top, right, bottom, left))
		{
			pieceVec->erase(iter);
			return res;
		}
	}
	return g_PIECES[NO_PIECE];
}

Piece* Manager::findMatch(vector<Piece*> *pieceVec, int i, int j)
{
	if (g_BOARD->getPiece(i, j) != g_PIECES[NO_PIECE]) //piece has been set
		return g_BOARD->getPiece(i, j);				//return the piece.
	//Shape* rest = getShapeRestrictions(i, j);
	Shape rest[4];
	getShapeRestrictions(rest, i, j);
	Piece* p = findMatch(pieceVec, rest[TOP], rest[RIGHT], rest[BOTTOM], rest[LEFT]);
	//delete rest;
	return p;
}

Piece* Manager::findMatch(int i, int j)
{
	vector<Piece*>* pieceVec = getCorrectPieceVector(i, j);
	return findMatch(pieceVec, i, j);
}

Piece* Manager::findMatchWithMaxNeighbors(int row, int col)
{
	vector<Piece*>* pieceVec = getCorrectPieceVector(row, col);
	Piece* maxNeighborsPiece = g_PIECES[NO_PIECE];
	Piece* p = NULL;
	int maxFromAllMins = 0;
	Shape rest[4];
	getShapeRestrictions(rest, row, col);
	vector <Piece*>::iterator iter = pieceVec->begin();
	vector <Piece*>::iterator iterEnd = pieceVec->end();
	
	while (iter != iterEnd && maxFromAllMins < 10)
	{
		p = *iter;
		if (p->tryToMatchPiece(rest[TOP], rest[RIGHT], rest[BOTTOM], rest[LEFT]))
		{
			g_BOARD->setPiece(p, row, col);
			vector <Piece*>::iterator tempIter = iter;
			iter++;
			//pieceVec->erase(tempIter);
			int top = getNumOfMatches(row - 1, col);
			int right = getNumOfMatches(row, col + 1);
			int bottom = getNumOfMatches(row + 1, col);
			int left = getNumOfMatches(row, col - 1);
			int Min = min(min(top, right), min(bottom, left));
			if (Min > maxFromAllMins)
			{
				maxFromAllMins = Min;
				maxNeighborsPiece = p;
			}
			//removePieceFromBoard(row, col);
		}
		else
			iter++;
	}
	return maxNeighborsPiece;
}

vector<Piece*>* Manager::getCorrectPieceVector(int i, int j)
{
	if (i == 0 || j == 0 || i == 15 || j == 15)
	{
		if ((i == 0 && (j == 0 || j == 15)) ||
			(i == 15 && (j == 0 || j == 15)))
			return m_CornersVec;
		else
			return m_FrameVec;
	}
	return m_CenterPiecesVec;
}

int Manager::getPosWithLeastMatches(int* iOut, int* jOut)
{
	int iMin = INT_MAX;
	int jMin = INT_MAX;
	int minMatches = INT_MAX;
	int matches = 0;
	//random_shuffle(m_RowIndexes->begin(), m_RowIndexes->end());
	//random_shuffle(m_ColIndexes->begin(), m_ColIndexes->end());
	mutateVector((vector<void*>*)m_RowIndexes);
	mutateVector((vector<void*>*)m_ColIndexes);
	vector<int>::iterator rowIter, colIter;
	for (rowIter = m_RowIndexes->begin(); rowIter != m_RowIndexes->end(); rowIter++)
	{
		for (colIter = m_ColIndexes->begin(); colIter != m_ColIndexes->end(); colIter++)
		{
			int i = *rowIter;
			int j = *colIter;
			matches = getNumOfMatches(i, j);
			if (matches > 0 && matches < minMatches)
			{
				minMatches = matches;
				*iOut = i;
				*jOut = j;
				if (minMatches == 1)
					return minMatches;		//no smaller num of matches possible
			}
			//else if (matches == 0)
			//	tryToRecoverNoMatch(i, j);
		}
	}
	return minMatches;
}

void Manager::getShapeRestrictions(Shape* restrictions, int i, int j)
{
	//Shape* restrictions = (Shape*) malloc(4 * sizeof(Shape));
	restrictions[TOP] = TD;	//edge
	restrictions[RIGHT] = TD;
	restrictions[BOTTOM] = TD;
	restrictions[LEFT] = TD;
	if (i > 0)
		restrictions[TOP] = g_BOARD->getPiece(i-1, j)->getBottom();
	if (j < BOARD_SIZE - 1)
		restrictions[RIGHT] = g_BOARD->getPiece(i, j+1)->getLeft();
	if (i < BOARD_SIZE - 1)
		restrictions[BOTTOM] = g_BOARD->getPiece(i+1, j)->getTop();
	if (j > 0)
		restrictions[LEFT] = g_BOARD->getPiece(i, j-1)->getRight();
	//return restrictions;
}

int Manager::getNumOfMatches(int i, int j)
{
	if (i < 0 || i > 15 || j < 0 || j > 15)
		return -1;
	if (g_BOARD->getPiece(i, j) != g_PIECES[NO_PIECE]) //piece has been set
		return -1;
	//Shape* rest = getShapeRestrictions(i, j);
	Shape rest[4];
	getShapeRestrictions(rest, i, j);
	if (rest[TOP] == NONE &&
		rest[RIGHT] == NONE &&
		rest[BOTTOM] == NONE &&
		rest[LEFT] == NONE)		//all pieces match here, doesn't interest us a t the moment.
		return -1;
	Piece* p = NULL;
	int matches = 0;
	vector<Piece*>* pieceVec = getCorrectPieceVector(i, j);
	vector <Piece*>::iterator iter;
	
	for (iter = pieceVec->begin(); iter != pieceVec->end(); iter++)
	{
		p = *iter;
		if (p->tryToMatchPiece(rest[TOP], rest[RIGHT], rest[BOTTOM], rest[LEFT]))
		{
			matches++;
			if (matches > 10)
				return matches;
		}
	}
	//delete rest;
	return matches;
}

void Manager::placeMinMatches()
{
	int* row = (int*)malloc(sizeof(void*));
	int* col = (int*)malloc(sizeof(void*));
	int matches = 1;
	int piecesPlaced = 0;

	while (matches > 0 && matches < INT_MAX)
	{
		matches = getPosWithLeastMatches(row, col);
		g_BOARD->m_Loc[*row][*col]->m_Piece = findMatch(*row, *col);
		//g_BOARD->m_Loc[*row][*col]->m_Piece = findMatchWithMaxNeighbors(*row, *col);
		piecesPlaced++;
		//if (piecesPlaced % 50 == 0)
		//	g_BOARD->writeBoardToFile("C:\\Documents and Settings\\IBM\\Desktop\\Puzzle\\test");
	}
	delete row;
	delete col;
}

void Manager::removePieceFromBoard(int row, int col)
{
	Piece *p = g_BOARD->getPiece(row, col);
	if (p == g_PIECES[NO_PIECE])
		return;
	vector<Piece*>* pieceVec = getCorrectPieceVector(row, col);
	g_BOARD->setPiece(g_PIECES[NO_PIECE], row, col);
	pieceVec->insert(pieceVec->begin(), p);
	return;
}

