#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "square.h"
#include "play.h"
//#include <iostream>


int main(int argc, char** argv) {
    int lvl;
    XO p;
    char p1, bot;
    Square board[3][3];
    printf("%30s", "Tic-Tac-Toe\n\n");
    resetBoard(board);
    printBoard(board);
    lvl = getLevel();
    p = chooseXO();
    play(p, board, lvl);
    return (EXIT_SUCCESS);
}

