
## Make file for the words demonstration.

COMPILER=gcc -g
C_PLUS=g++ -g
COMP=$(COMPILER) -o $@ -c
TARGET1=puz
LIBS=
OBJS=Main.o Board.o Manager.o Piece.o PieceLoader.o
.SUFFIXES: no_suffiexes

project : $(TARGET1)

$(TARGET1): Main.cpp $(OBJS)
	$(C_PLUS)   -o  $(TARGET1) $(OBJS) $(LIBS) -Wno-deprecated
Manager.o: Manager.h Manager.cpp
	$(COMPILER) -D_REENTRANT -o Manager.o -c Manager.cpp -Wno-deprecated
Board.o:	Board.h Board.cpp
	$(C_PLUS) -D_REENTRANT -o Board.o -c Board.cpp -Wno-deprecated
Piece.o:  Piece.h Piece.cpp
	$(C_PLUS) -D_REENTRANT -o Piece.o -c Piece.cpp -Wno-deprecated
PieceLoader.o:	PieceLoader.h PieceLoader.cpp
	$(C_PLUS) -D_REENTRANT -o PieceLoader.o -c PieceLoader.cpp -Wno-deprecated


clean : 
	rm -f *.o project