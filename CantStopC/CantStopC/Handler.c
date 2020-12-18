#include "harker.h"

void init(board *cantStop, player *p, player *AI) {
	int i;
	//INIT BOARD
	//init isFull[]
	for (i = 0; i < 11; i++)
		cantStop->isFull[i] = false;
	//init nTurns
	cantStop->nTurns = 0;

	//INIT PLAYER

	//init col7[]
	for (i = 0; i < 13; i++)
		p->col7[i] = false;
	//init col2[] col12[]
	for (i = 0; i < 3; i++) {
		p->col2[i] = false;
		p->col12[i] = false;
	}
	//init col3[] col11[]
	for (i = 0; i < 5; i++) {
		p->col3[i] = false;
		p->col11[i] = false;
	}
	//init col4[] col10[]
	for (i = 0; i < 7; i++) {
		p->col4[i] = false;
		p->col10[i] = false;
	}
	//init col5[] col9[]
	for (i = 0; i < 9; i++) {
		p->col5[i] = false;
		p->col9[i] = false;
	}
	//init col6[] col8[]
	for (i = 0; i < 11; i++) {
		p->col6[i] = false;
		p->col8[i] = false;
	}

	//init current[]
	for (i = 0; i < 3; i++)
		p->current[i] = 0;
	//init playerN
	p->playerN = rand()%2 + 1;					//random first player
	//init playerName
	strcpy(p->name, getPlayerName());

	//init score
	p->score = 0;

	//init nSubTurns
	p->nSubTurns = 0;
	//INIT AI

	//init col7[]
	for (i = 0; i < 13; i++)
		AI->col7[i] = false;
	//init col2[] col12[]
	for (i = 0; i < 3; i++) {
		AI->col2[i] = false;
		AI->col12[i] = false;
	}
	//init col3[] col11[]
	for (i = 0; i < 5; i++) {
		AI->col3[i] = false;
		AI->col11[i] = false;
	}
	//init col4[] col10[]
	for (i = 0; i < 7; i++) {
		AI->col4[i] = false;
		AI->col10[i] = false;
	}
	//init col5[] col9[]
	for (i = 0; i < 9; i++) {
		AI->col5[i] = false;
		AI->col9[i] = false;
	}
	//init col6[] col8[]
	for (i = 0; i < 11; i++) {
		AI->col6[i] = false;
		AI->col8[i] = false;
	}

	//init current[]
	for (i = 0; i < 3; i++)
		AI->current[i] = 0;
	//init playerN
	if (p->playerN == 1) {
		AI->playerN = 2;
	}
	else {
		AI->playerN = 1;
	}
	//init name[]
	strcpy(AI->name, "AI");

	//init score
	AI->score = 0;

	//init nSubTurns
	AI->nSubTurns = 0;
}

char* getPlayerName(void) {
	char name[21] = "A Nameless Human?";
	fseek(stdin, 0, SEEK_END); //clear stdin buffer
	printf("Insert your name: ");
	(void)scanf("%20[^\n]s", name);
	fseek(stdin, 0, SEEK_END);
	return name;
}

void sideMenuClear(int n) {
	int i;
	for (i = n; i < 15; i++) {
		gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + i);
		printf("                                                    ");
	}
}