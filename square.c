#include <stdio.h>
#include <stdlib.h>
#include "square.h"
#include "play.h"

void resetBoard(Square b[3][3]) {
    int i, j, c = 1;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            b[i][j].index = c;
            b[i][j].xo = 0x5f;
            c++;
        }
    }
}
void printBoard(Square b[3][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%4d", b[i][j].index);
        }
        printf("\t");
        for(j = 0; j < 3; j++) {
            printf("%4c", b[i][j].xo);
        }
        printf("\n\n");
    }
}
int up(Coord c, Square b[3][3], char check) {
        int i = c.x-1;
        if(i < 0)
            return NA;
        if(b[i][c.y].xo == check)
            return TRUE;
        return FALSE;
    }
int down(Coord c, Square b[3][3], char check) {
        int i = c.x+1;
        if(i > 2)
            return NA;
        if(b[i][c.y].xo == check)
            return TRUE;
        return FALSE;
    }
int left(Coord c, Square b[3][3], char check) {
        int i = c.y-1;
        if(i < 0)
            return NA;
        if(b[c.x][i].xo == check)
            return TRUE;
        return FALSE;
    }
int right(Coord c, Square b[3][3], char check) {
        int i = c.y+1;
        if(i > 2)
            return NA;
        if(b[c.x][i].xo == check)
            return TRUE;
        return FALSE;
    }
int upleft(Coord c, Square b[3][3], char check) {
        int i = c.x-1;
        int j = c.y-1;
        if(i < 0 || j < 0)
            return NA;
        if(b[i][j].xo == check)
            return TRUE;
        return FALSE;
    }
int upright(Coord c, Square b[3][3], char check) {
        int i = c.x-1;
        int j = c.y+1;
        if(i < 0 || j > 2)
            return NA;
        if(b[i][j].xo == check)
            return TRUE;
        return FALSE;
    }
int downleft(Coord c, Square b[3][3], char check) {
        int i = c.x+1;
        int j = c.y-1;
        if(i > 2 || j < 0)
            return NA;
        if(b[i][j].xo == check)
            return TRUE;
        return FALSE;
    }
int downright(Coord c, Square b[3][3], char check) {
        int i = c.x+1;
        int j = c.y+1;
        if(i > 2 || j > 2)
            return NA;
        if(b[i][j].xo == check)
            return TRUE;
        return FALSE;
    }