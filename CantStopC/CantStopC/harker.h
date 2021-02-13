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
	int nSubTurns;
	int playerN;
	int score;
	int current[3];
	int col2[3], col3[5], col4[7], col5[9], col6[11], col7[13], col8[11], col9[9], col10[7], col11[5], col12[3];
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

void playAI(board *cantStop, player *AI, int* dice1, int* dice2, int* dice3, int* dice4);

char* getPlayerName(void);

void init(board *cantStop, player *p, player *AI);
void askContinue(board* cantStop, player* p);


void draw(player p, player AI);
void drawBoard(void);
void drawPlayerList(player p, player AI);
void drawTempMarkers(int n, player* p);
void drawPermMarkers(int n, player* p);
void sideMenuClear(int n);
void drawDice(int dice1, int dice2, int dice3, int dice4);
void drawCombo(int a1, int a2, int b1, int b2, int c1, int c2);
void drawWinner(player p, player p2);

void logic(board *cantStop, player *p, player *AI);
void checkCols(board *cantStop, player *p);
void genDice(int* dice1, int* dice2, int* dice3, int* dice4);
void input(int dice1, int dice2, int dice3, int dice4, board *cantStop, player *p);
int  canPlay(int *matrix, int a1, int a2, int b1, int b2, int c1, int c2);
void play(player* p, board* cantStop, int a1, int a2, int b1, int b2, int c1, int c2);
void movePlayer(int n, player *p);
void setPerm(player* p);
void genComboMatrix(int* matrix, player* p, board* cantStop, int a1, int a2, int b1, int b2, int c1, int c2);
void addToCurrent(player* p, int move);
void resetProgress(player* p);
void extremeMove(player* p, int a, int b);
void calculateRating(player* AI, int* currentRating, int* currentMove, int col1, int col2);
void makeMoveAI(player* AI, board* cantStop, int* bestMove);

void gameOverChecker(int* gameOver, player p, player AI);

void saveGame(player p, board cantStop);
int savePlayer(FILE* fptr, player p);
int loadPlayer(FILE* fptr, player* p);

#endif