#include "Board.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

char* itoa( int value, char* result, int base );

Board::Board(void)
{
	m_Matches = 0;
	m_MissingPieces = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			m_Loc[i][j] = new Square(g_PIECES[NO_PIECE], i, j);
}

Board::~Board(void)
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			delete m_Loc[i][j];
}


bool fileExists(const std::string& fileName)
{
	std::fstream fin;
	fin.open(fileName.c_str(),std::ios::in);
	if( fin.is_open() )
	{
		fin.close();
		return true;
	}
	fin.close();
	return false;
}

char* Board::writeBoardToFile(char *filename)
{
	string name = filename;
	string tryName = "";
	int fileIndex = 1;
	char indexBuf[10];
	itoa(fileIndex, indexBuf, 10);
	tryName = name + indexBuf + ".lay";
	while (fileExists(tryName))
	{
		fileIndex++;
		itoa(fileIndex, indexBuf, 10);
		tryName = name + indexBuf + ".lay";
	}
	name = tryName;

	ofstream myfile;
	myfile.open(name.c_str());
	
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			char id [10];
			char rotation [10];
			if (j > 0)
			{
				myfile << "\t";
			}
			itoa(getPiece(i, j)->getID(), id, 10);
			itoa(getPiece(i, j)->getRotation(), rotation, 10);
			myfile << id;
			myfile << "\t";
			myfile << rotation;
		}
		myfile << "\n";
	}
	char matches [10];
	char missing [10];
	itoa(m_Matches, matches, 10);
	itoa(m_MissingPieces, missing, 10);
	myfile << "Matches: ";
	myfile << matches;
	myfile << "\nMissingPieces: ";
	myfile << missing;
	myfile << "\n";
	myfile.close();
	printf("Writing to: %s\n", name.c_str());
	return ""; //name.c_str();
}

//void Board::placePiece(int i, int j, Piece* p)
//{
//	m_Loc[i][j] = p;
//}

void Board::clearBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			setPiece(g_PIECES[NO_PIECE], i, j);
	m_MissingPieces = 0;
	m_Matches = 0;
}

void Board::setPiece(Piece *p, int row, int col)
{
	m_Loc[row][col]->m_Piece = p;
}
Piece* Board::getPiece(int row, int col)
{
	return m_Loc[row][col]->m_Piece;
}

void Board::evaluateMatches()
{
	m_Matches = 0;
	m_MissingPieces = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (getPiece(i,j) == g_PIECES[NO_PIECE])
			{
				m_MissingPieces++;
				continue;
			}
			if (j > 0)
			{
				if (getPiece(i,j-1)->getRight() == getPiece(i,j)->getLeft())
					m_Matches++;
			}
			if (i > 0)
			{
				if (getPiece(i-1,j)->getBottom() == getPiece(i,j)->getTop())
					m_Matches++;
			}
		}
	}
}

char* itoa( int value, char* result, int base ) {
	// check that the base if valid
	if (base < 2 || base > 16) { *result = 0; return result; }

	char* out = result;
	int quotient = value;

	do {
		*out = "0123456789abcdef"[ std::abs( quotient % base ) ];
		++out;
		quotient /= base;
	} while ( quotient );

	// Only apply negative sign for base 10
	if ( value < 0 && base == 10) *out++ = '-';

	std::reverse( result, out );
	*out = 0;
	return result;
}


