#include <stdio.h>
#include <stdlib.h>
#include "play.h"
#include "square.h"

int getLevel() {
    char chlvl[2] = "";
    int lvl;
    while(1) {
        printf("%s\n%20s\n%20s\n","Choose your level", "1. Easy", "2. Hard");
        fgets(chlvl, sizeof(chlvl), stdin);
        while ((getchar()) != '\n');
        lvl = atoi(chlvl);
        if(lvl == 1 || lvl == 2)
            return lvl;
        printf("%s\n%20s\n\n", "That is not an option.", "Try again.");
        }
}
XO chooseXO() {
    char choice[2];
    XO r;
    while(1) {
        printf("Would you like to be Xs or Os?\n");
        fgets(choice, sizeof(choice), stdin);
        while ((getchar()) != '\n');
        if(choice[0] == 'X' || choice[0] == 'x') {
            r.p1 = 'X';
            r.bot = 'O';
            return r;
        }
        if(choice[0] == 'O' || choice[0] == 'o') {
            r.p1 = 'O';
            r.bot = 'X';
            return r;
        }
        printf("%s\n%20s\n\n", "That is not an option.", "Try again.");
   }
}
int won(char p, Square b[3][3]) {
        int i, j;
        Coord c;
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                if(i == 1 || j == 1) {
                    c.x = i;
                    c.y = j;
                    if(b[i][j].xo == p) {
                        if(up(c, b, p) == TRUE) {
                            if(down(c, b, p) == TRUE)
                                return TRUE;
                        }
                        if(upleft(c, b, p) == TRUE) {
                            if(downright(c, b, p) == TRUE)
                                return TRUE;
                        }
                        if(right(c, b, p) == TRUE) {
                            if(left(c, b, p) == TRUE)
                                return TRUE;
                        }
                        if(upright(c, b, p) == TRUE) {
                            if(downleft(c, b, p) == TRUE)
                                return TRUE;
                        }
                    }
                }
            }
        }
        return FALSE;
    } 
int genRand() {
        int num;
        num = rand() % 4;
        return num;
    }
void addCoord(Coord last, int c[8]) {
        switch(last.x) {
        case 0:
            c[0]++;
            if(last.y == 2)
                c[7]++;
            break;
        case 1:
            c[1]++;
            if(last.y == 1)
                c[7]++;
            break;
        case 2:
            c[2]++;
            if(last.y == 0)
                c[7]++;
            break;
    }
    switch(last.y) {
        case 0:
            c[3]++;
            break;
        case 1:
            c[4]++;
            break;
        case 2:
            c[5]++;
            break;
    }
    if(last.x == last.y)
        c[6]++;
}
void botHardTurn(XO p, Square b[3][3], int first, int c[8], Coord w[8][3]) {
    Coord last;
    int i, most = -1, mostInd;
    printf("Bot's turn!\n");
    if(first == 0) {
        last = botEasyTurn(p, b);
        addCoord(last, c);
        return;
    }
    while(1) {
        most = -1;
        for(i = 0; i < 8; i++) {
            if(c[i] > most) {
                most = c[i];
                mostInd = i;
            }
        }
        for(i = 0; i < 3; i++) {
            if(b[w[mostInd][i].x][w[mostInd][i].y].xo == p.p1)
                c[mostInd] = 0;
        }
        for(i = 0; i < 3; i++) {
            if(b[w[mostInd][i].x][w[mostInd][i].y].xo == 0x5f) {
                b[w[mostInd][i].x][w[mostInd][i].y].xo = p.bot;
                addCoord(w[mostInd][i], c);
                printBoard(b);
                return;
            }
        }
    }
}
Coord botEasyTurn(XO p, Square b[3][3]) {
    time_t t;
    srand((unsigned) time(&t));
        if(b[1][1].xo == 0x5f) {
            b[1][1].xo = p.bot;
            return;
        }
        while(1) {
            int i = genRand();
            int j = genRand();
            if(b[i][j].xo == 0x5f) {
                b[i][j].xo = p.bot;
                printBoard(b);
                return;
            }
        }
    }
void fillWins(Coord w[8][3]) {
    int i, j;
    int put[8][6] = {{0,0,0,1,0,2}, {1,0,1,1,1,2}, {2,0,2,1,2,2}, 
                    {0,0,1,0,2,0}, {0,1,1,1,2,1}, {0,2,1,2,2,2}, 
                    {0,0,1,1,2,2}, {0,2,1,1,2,0}};
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 3; j++) {
            w[i][j].x = put[i][j*2];
            w[i][j].y = put[i][(j*2)+1];
        }
    }
}

void play(XO p, Square b[3][3], int lvl) {
    Coord wins[8][3];
    int i;
    fillWins(wins);
    int combos[8];
    if(lvl == 2) {
        for(i = 0; i < 8; i++) {
            combos[i] = 0;
        }
    }
    int pw = 0, bw = 0;
    i = 0;
    printf("X's go first!\n");
    if(p.p1 == 'X') {
        playerTurn(p, b);
    }
    while(!pw && !bw) {
        if(i % 2 == 0) {
            if(lvl == 1) {
                printf("Bot's turn!\n");
                botEasyTurn(p, b);
            }
            else
                botHardTurn(p, b, i, combos, wins);
        }
        else
            playerTurn(p, b);
        i++;
        pw = won(p.p1, b);
        bw = won(p.bot, b);
    }
    if(pw == TRUE) {
        printBoard(b);
        printf("YOU WON!\n");
        exit(0);
    }
    else {
        printBoard(b);
        printf("YOU LOST!\n");
        exit(0);
    }
}
int spotEmpty(XO p, int ind, Square b[3][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(b[i][j].index == ind) {
                if(b[i][j].xo == 0x5f) {
                    b[i][j].xo = p.p1;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}
void playerTurn(XO p, Square b[3][3]) {
    char get[2];
    int ind = -1;
    while(1) {
        printf("Your turn!\n");
        printf("Where would you like to play your turn?\n");
        printBoard(b);
        fgets(get, sizeof(get), stdin);
        while ((getchar()) != '\n');
        ind = atoi(get);
        if(ind > 9 || ind < 1) {
            printf("%s\n%20s\n\n", "That is not an option.", "Try again.");
            continue;
        }
        if(!spotEmpty(p, ind, b)) {
            printf("%s\n%20s\n\n", "That spot is taken.", "Try again.");
            continue;
        }
        else {
            return;
        }
    }
}