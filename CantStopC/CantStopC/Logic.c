#include "harker.h"


void logic(int gameOver, board *cantStop, player *p, player *AI) {
	int dice1, dice2, dice3, dice4;
	genDice(&dice1, &dice2, &dice3, &dice4);
	if ((cantStop->nTurns % 2 == 0 && p->playerN == 1) || (cantStop->nTurns % 2 != 0 && p->playerN == 2)) {
		input(dice1, dice2, dice3, dice4, cantStop, p);
	}
	else {
		playAI(cantStop);
	
	}

}

void playAI(board *cantStop) {
	system("pause");
	cantStop->nTurns++;
}

void checkCols(board* cantStop, player* p) {
	int i;
	for (i = 2; i < 13; i++) {
		if (i <= 7) {
		switch (i) {
		case 2:
			if (p->col2[2 * i - 2] == 2 && cantStop->isFull[0] == false) {
				p->score++;
				cantStop->isFull[0] = true;
			}
			break;
		case 3:
			if (p->col3[2 * i - 2] == 2 && cantStop->isFull[1] == false) {
				p->score++;
				cantStop->isFull[1] = true;
			}
			break;
		case 4:
			if (p->col4[2 * i - 2] == 2 && cantStop->isFull[2] == false) {
				p->score++;
				cantStop->isFull[2] = true;
			}
			break;
		case 5:
			if (p->col5[2 * i - 2] == 2 && cantStop->isFull[3] == false) {
				p->score++;
				cantStop->isFull[3] = true;
			}
			break;
		case 6:
			if (p->col6[2 * i - 2] == 2 && cantStop->isFull[4] == false) {
				p->score++;
				cantStop->isFull[4] = true;
			}
			break;
		case 7:
			if (p->col7[2 * i - 2] == 2 && cantStop->isFull[5] == false) {
				p->score++;
				cantStop->isFull[5] = true;
			}
			break;
		}
	}
		if (i > 7) {
			switch (i) {
			case 8:
				if (p->col8[2 * (i - (i - 7) * 2) - 2] == 2 && cantStop->isFull[6] == false) {
					p->score++;
					cantStop->isFull[6] = true;
				}
				break;
			case 9:
				if (p->col9[2 * (i - (i - 7) * 2) - 2] == 2 && cantStop->isFull[7] == false) {
					p->score++;
					cantStop->isFull[7] = true;
				}
				break;
			case 10:
				if (p->col10[2 * (i - (i - 7) * 2) - 2] == 2 && cantStop->isFull[8] == false) {
					p->score++;
					cantStop->isFull[8] = true;
				}
				break;
			case 11:
				if (p->col11[2 * (i - (i - 7) * 2) - 2] == 2 && cantStop->isFull[9] == false) {
					p->score++;
					cantStop->isFull[9] = true;
				}
				break;
			case 12:
				if (p->col12[2 * (i - (i - 7) * 2) - 2] == 2 && cantStop->isFull[10] == false) {
					p->score++;
					cantStop->isFull[10] = true;
				}
				break;
			}
		}

	}
}
void genDice(int *dice1, int* dice2, int* dice3, int* dice4) {
	*dice1 = rand() % 6 + 1;
	*dice2 = rand() % 6 + 1;
	*dice3 = rand() % 6 + 1;
	*dice4 = rand() % 6 + 1;
}

void input(int dice1, int dice2, int dice3, int dice4, board *cantStop, player *p) {
	int a1,a2, b1,b2, c1,c2;
	a1 = dice1 + dice2;
	a2 = dice3 + dice4;

	b1 = dice1 + dice3;
	b2 = dice2 + dice4;

	c1 = dice1 + dice4;
	c2 = dice2 + dice3;
	sideMenuClear(0);
	drawDices(dice1, dice2, dice3, dice4);
	//printf("Dice1: %d, Dice2: %d, Dice3: %d, Dice4: %d", dice1, dice2, dice3, dice4);//debug
	gotoxy(20, ROWS / 2 + 1);
	printf("DEBUG:");
	gotoxy(20, ROWS / 2 + 2);
	printf("Can play: %i", canPlay(p, cantStop, a1, a2, b1, b2, c1, c2)); // debug
	play(p, cantStop, a1, a2, b1, b2, c1, c2);

}
int canPlay(player *p,board *cantStop, int a1, int a2, int b1, int b2, int c1, int c2){
	int i;

	for (i = 0; i < 3; i++) {
		if  ((p->current[i] == 0 && (cantStop->isFull[a1-2] == false || cantStop->isFull[a2 - 2] == false || cantStop->isFull[b1 - 2] == false || cantStop->isFull[b2 - 2] == false || cantStop->isFull[c1 - 2] == false || cantStop->isFull[c2 - 2] == false))	||
			(p->current[i] == a1 && cantStop->isFull[a1-2] == false) ||
			(p->current[i] == a2 && cantStop->isFull[a2-2] == false) ||
			(p->current[i] == b1 && cantStop->isFull[b1-2] == false) ||
			(p->current[i] == b2 && cantStop->isFull[b2-2] == false) ||
			(p->current[i] == c1 && cantStop->isFull[c1-2] == false) ||
			(p->current[i] == c2 && cantStop->isFull[c2-2] == false))
			return true;
	}
	return false;
}
void play(player* p, board* cantStop, int a1, int a2, int b1, int b2, int c1, int c2) {
	char combination = '0';
	char opt = '0';
	if (canPlay(p, cantStop, a1, a2, b1, b2, c1, c2)) {
		if ( p->current[1] == 0
				&& cantStop->isFull[a1 - 2] == false
				&& cantStop->isFull[a2 - 2] == false
				&& cantStop->isFull[b1 - 2] == false
				&& cantStop->isFull[b2 - 2] == false
				&& cantStop->isFull[c1 - 2] == false
				&& cantStop->isFull[c2 - 2] == false) {										//No temp markers or 1 marker and no cols full
			sideMenuClear(4);
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 2);
			printf("Combinations:");
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 4);
			printf("A: %i and %i", a1, a2);
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 5);
			printf("B: %i and %i",b1, b2);
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 6);
			printf("C: %i and %i",c1, c2);
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 8);
			printf("Choose one combination A, B or C to play");
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 9);
			fseek(stdin, 0, SEEK_END);
			(void)scanf(" %c", &combination);
			combination = tolower(combination);

			switch (combination)
			{
			case 'a':
				movePlayer(a1, p);
				movePlayer(a2, p);
				p->nSubTurns++;
				break;
			case 'b':
				movePlayer(b1, p);
				movePlayer(b2, p);
				p->nSubTurns++;
				break;
			case 'c':
				movePlayer(c1, p);
				movePlayer(c2, p);
				p->nSubTurns++;
				break;
			default:
				play(p, cantStop, a1, a2, b1, b2, c1, c2);
				break;
			}
		}
	}else {
		printf("\nNo possible moves! You lost all the progress made in this round!\n");							//A & B & C IMPOSSIBLE	
	}
}
void movePlayer(int n, player *p) {
	int i;
	int hasChanged = 0;								//flag
	if (n <= 7) {									//n col < or = 7
		for (i = 0; i <= 2 * n - 2; i++) {
			switch (n) {
			case 2:
				if (p->col2[i] == 0) {				//if there is no marker
					p->col2[i] = 1;					//place temp marker
					hasChanged = 1;					//set flag to 1
				}
				break;
			case 3:
				if (p->col3[i] == 0) {
					p->col3[i] = 1;
					hasChanged = 1;
				}
				break;
			case 4:
				if (p->col4[i] == 0) {
					p->col4[i] = 1;
					hasChanged = 1;
				}
				break;
			case 5:
				if (p->col5[i] == 0) {
					p->col5[i] = 1;
					hasChanged = 1;
				}
				break;
			case 6:
				if (p->col6[i] == 0) {
					p->col6[i] = 1;
					hasChanged = 1;
				}
				break;
			case 7:
				if (p->col7[i] == 0) {
					p->col7[i] = 1;
					hasChanged = 1;
				}
				break;
			}
			if (hasChanged == 1) break;						//if a value changed in this cycle, exits for loop
		}
	}
	else if (n > 7) {												//if n col > 7
		for (i = 0; i <= 2 * (n - (n - 7) * 2) - 2; i++) {			//same as above^^
			switch (n) {
			case 8:
				if (p->col8[i] == 0) {
					p->col8[i] = 1;
					hasChanged = 1;
				}
				break;
			case 9:
				if (p->col9[i] == 0) {
					p->col9[i] = 1;
					hasChanged = 1;
				}
				break;
			case 10:
				if (p->col10[i] == 0) {
					p->col10[i] = 1;
					hasChanged = 1;
				}
				break;
			case 11:
				if (p->col11[i] == 0) {
					p->col11[i] = 1;
					hasChanged = 1;
				}
				break;
			case 12:
				if (p->col12[i] == 0) {
					p->col12[i] = 1;
					hasChanged = 1;
				}
				break;
			}
			if (hasChanged == 1) break;
		}
	}
}

void setPerm(player* p) {
	int i, n;
	for (n = 2; n <= 12; n++) {
		if (n <= 7) {									//n col < or = 7
			for (i = 0; i <= 2 * n - 2; i++) {
				switch (n) {
				case 2:
					if (p->col2[i] == 1) {				//if there is a temp marker
						p->col2[i] = 2;					//place perm marker		
					}
					break;
				case 3:
					if (p->col3[i] == 1) {
						p->col3[i] = 2;
					}
					break;
				case 4:
					if (p->col4[i] == 1) {
						p->col4[i] = 2;
					}
					break;
				case 5:
					if (p->col5[i] == 1) {
						p->col5[i] = 2;
					}
					break;
				case 6:
					if (p->col6[i] == 1) {
						p->col6[i] = 2;
					}
					break;
				case 7:
					if (p->col7[i] == 1) {
						p->col7[i] = 2;
					}
					break;
				}
			}
		}
		else if (n > 7) {												//if n col > 7
			for (i = 0; i <= 2 * (n - (n - 7) * 2) - 2; i++) {			//same as above^^
				switch (n) {
				case 8:
					if (p->col8[i] == 1) {
						p->col8[i] = 2;
					}
					break;
				case 9:
					if (p->col9[i] == 1) {
						p->col9[i] = 2;
					}
					break;
				case 10:
					if (p->col10[i] == 1) {
						p->col10[i] = 2;
					}
					break;
				case 11:
					if (p->col11[i] == 1) {
						p->col11[i] = 2;
					}
					break;
				case 12:
					if (p->col12[i] == 1) {
						p->col12[i] = 2;
					}
					break;
				}
			}
		}
	}
}

void askContinue(board* cantStop, player* p) {
	char opt;
	int i;
	if ((cantStop->nTurns % 2 == 0 && p->playerN == 1) || (cantStop->nTurns % 2 != 0 && p->playerN == 2)) {
		if (p->nSubTurns == 0) {
			p->nSubTurns++;
			return;
		}
		do {
			sideMenuClear(0);
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2);
			printf("Do you want to continue playing?");
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 1);
			printf("Y or N: ");
			fseek(stdin, 0, SEEK_END);
			(void)scanf(" %c", &opt);
			opt = tolower(opt);
			if (opt == 'n') {
				cantStop->nTurns++;
				p->nSubTurns = 0;
				setPerm(p);
			}
		} while (opt != 'n' && opt != 'y');
	}
}