#ifndef PLAY_H
#define PLAY_H

#define FALSE 0
#define TRUE 1
#define NA 2

typedef struct XO {
    char p1;
    char bot;
} XO;

typedef struct Coord {
    int x;
    int y;
} Coord;

typedef struct Square {
    char xo;
    int index;
} Square;


int getLevel();
XO chooseXO();
void playEasy(XO p, Square b[3][3]);
int won(char p, Square b[3][3]);
Coord botEasyTurn(XO p, Square b[3][3]);
void botHardTurn(XO p, Square b[3][3], int i, int c[8], Coord w[8][3]);
void botExtremeTurn(XO p, Square b[3][3], int i, int c[8], Coord w[8][3]);////////////////////remains
void playerTurn(XO p, Square b[3][3]);
int spotEmpty(XO p, int ind, Square b[3][3]);
void fillWins(Coord w[8][3]);
void addCoord(Coord last, int c[8]);

#endif /* PLAY_H */

