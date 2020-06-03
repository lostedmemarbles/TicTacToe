#ifndef SQUARE_H
#define SQUARE_H
#include "play.h"

void resetBoard(Square b[3][3]);
void printBoard(Square b[3][3]);
int up(Coord c, Square b[3][3], char check);
int down(Coord c, Square b[3][3], char check);
int left(Coord c, Square b[3][3], char check);
int right(Coord c, Square b[3][3], char check);
int upleft(Coord c, Square b[3][3], char check);
int upright(Coord c, Square b[3][3], char check);
int downleft(Coord c, Square b[3][3], char check);
int downright(Coord c, Square b[3][3], char check);

#endif /* SQUARE_H */

