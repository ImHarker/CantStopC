#ifndef _HARKERH_		//protectes from multiple including...
#define _HARKERH_		//... needs an #endif at bottom
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include "lab.h"


//Terminal size
#define COLS 236
#define ROWS 62

//Player struct
typedef struct PLAYER {
	char name[21];
	int col2[3], col3[5], col4[7], col5[9], col6[11], col7[13], col8[11], col9[9], col10[7], col11[5], col12[3];
	int current[3];
	int playerN;
	int score;
	int nSubTurns;
}player;

//Board struct
typedef struct BOARD {
	int isFull[11];
	int nTurns;
}board;

//Credits
#define COPY_CHAR 169
#define CREDITS "Gustavo Santos - al70800"
#define CREDITS1 "  Vasco Teixeira - al74107"
#define CREDITS2 "  Universidade de Tras-os-Montes e Alto Douro"

void menu(void);
void how2(void);


void game(void);

void playAI(board *cantStop);

char* getPlayerName(void);

void init(board *cantStop, player *p, player *AI);
void askContinue(board* cantStop, player* p);


void draw(player p, player AI);
void drawBoard(void);
void drawPlayerList(player p, player AI);
void drawTempMarkers(int n, player* p);
void drawPermMarkers(int n, player* p);
void sideMenuClear(int n);
void drawDices(int dice1, int dice2, int dice3, int dice4);

void logic(int gameOver, board *cantStop, player *p, player *AI);
void checkCols(board *cantStop, player *p);
void genDice(int* dice1, int* dice2, int* dice3, int* dice4);
void input(int dice1, int dice2, int dice3, int dice4, board *cantStop, player *p);
int  canPlay(player *p, board *cantStop, int a1, int a2, int b1, int b2, int c1, int c2);
void play(player* p, board* cantStop, int a1, int a2, int b1, int b2, int c1, int c2);
void movePlayer(int n, player *p);
void setPerm(player* p);

#endif