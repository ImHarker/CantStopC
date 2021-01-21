#include "harker.h"


void logic(board *cantStop, player *p, player *AI) {
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
	drawDice(dice1, dice2, dice3, dice4);
	drawCombo(a1, a2, b1, b2, c1, c2);
	//printf("Dice1: %d, Dice2: %d, Dice3: %d, Dice4: %d", dice1, dice2, dice3, dice4);//debug
	play(p, cantStop, a1, a2, b1, b2, c1, c2);

}
int canPlay(int *matrix, int a1, int a2, int b1, int b2, int c1, int c2) {
	int i;
	int diceCombo[6] = { a1,a2,b1,b2,c1,c2 };
	for (i = 0; i < 6; i++) {
		if (matrix[diceCombo[i]-2] == 1){
			return true;
	}
}
	return false;
}
void play(player* p, board* cantStop, int a1, int a2, int b1, int b2, int c1, int c2) {
	char move = '0';
	int comboMatrix[11];

	genComboMatrix(comboMatrix, p, cantStop, a1, a2, b1, b2, c1, c2);

	/* //DEBUG
	gotoxy(20, ROWS / 2 + 1);
	printf("DEBUG:");
	gotoxy(20, ROWS / 2 + 2);
	printf("Can play: %i", canPlay(comboMatrix, a1, a2, b1, b2, c1, c2));
	*/


	if (canPlay(comboMatrix, a1, a2, b1, b2, c1, c2)) {

			sideMenuClear(4);
			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 2);
			printf("Possible Moves:");

			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 4);
			printf("A:");
			if (comboMatrix[a1 - 2] == 0 && comboMatrix[a2 - 2] == 0) printf(" No possible moves");
			if (comboMatrix[a1 - 2]) printf(" %d", a1);
			if (comboMatrix[a1 - 2] && comboMatrix[a2 - 2]) {
				printf(" and %d", a2);
			}else if (comboMatrix[a2 - 2]) printf(" %d", a2);

			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 5);
			printf("B:");
			if (comboMatrix[b1 - 2] == 0 && comboMatrix[b2 - 2] == 0) printf(" No possible moves");
			if (comboMatrix[b1 - 2]) printf(" %d", b1);
			if (comboMatrix[b1 - 2] && comboMatrix[b2 - 2]) {
				printf(" and %d", b2);
			}
			else if (comboMatrix[b2 - 2]) printf(" %d", b2);

			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 6);
			printf("C:");
			if (comboMatrix[c1 - 2] == 0 && comboMatrix[c2 - 2] == 0) printf(" No possible moves");
			if (comboMatrix[c1 - 2]) printf(" %d", c1);
			if (comboMatrix[c1 - 2] && comboMatrix[c2 - 2]) {
				printf(" and %d", c2);
			}
			else if (comboMatrix[c2 - 2]) printf(" %d", c2);

			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 8);
			printf("Choose a move A, B or C to play");

			gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 9);
			fseek(stdin, 0, SEEK_END);
			(void)scanf(" %c", &move);
			fseek(stdin, 0, SEEK_END);
			move = tolower(move);

			switch (move)
			{
			case 'a':
				if (comboMatrix[a1 - 2] == 0 && comboMatrix[a2 - 2] == 0) {
					play(p, cantStop, a1, a2, b1, b2, c1, c2);
					break;
				}
				if (comboMatrix[a1 - 2] && comboMatrix[a2 - 2] && p->current[0] != a1 && p->current[1] != a1 && p->current[2] != a1 && p->current[0] != a2 && p->current[1] != a2 && p->current[2] != a2 && p->current[0] != 0 && p->current[1] != 0 && a1 != a2) {
					extremeMove(p, a1, a2);
					return;
				}
				if (comboMatrix[a1 - 2]) {
					movePlayer(a1, p);
					addToCurrent(p, a1);
				}
				if (comboMatrix[a2 - 2]) {
					movePlayer(a2, p);
					addToCurrent(p, a2);
				}
				p->nSubTurns++;
				break;
			case 'b':
				if (comboMatrix[b1 - 2] == 0 && comboMatrix[b2 - 2] == 0) {
					play(p, cantStop, a1, a2, b1, b2, c1, c2);
					break;
				}
				if (comboMatrix[b1 - 2] && comboMatrix[b2 - 2] && p->current[0] != b1 && p->current[1] != b1 && p->current[2] != b1 && p->current[0] != b2 && p->current[1] != b2 && p->current[2] != b2 && p->current[0] != 0 && p->current[1] != 0 && b1 != b2) {
					extremeMove(p, b1, b2);
					return;
				}
				if (comboMatrix[b1 - 2]) {
					movePlayer(b1, p);
					addToCurrent(p, b1);
				}
				if (comboMatrix[b2 - 2]) {
					movePlayer(b2, p);
					addToCurrent(p, b2);
				}
				p->nSubTurns++;
				break;
			case 'c':
				if (comboMatrix[c1 - 2] == 0 && comboMatrix[c2 - 2] == 0) {
					play(p, cantStop, a1, a2, b1, b2, c1, c2);
					break;
				}
				if (comboMatrix[c1 - 2] && comboMatrix[c2 - 2] && p->current[0] != c1 && p->current[1] != c1 && p->current[2] != c1 && p->current[0] != c2 && p->current[1] != c2 && p->current[2] != c2 && p->current[0] != 0 && p->current[1] != 0 && c1!= c2) {
					extremeMove(p, c1, c2);
					return;
				}
				if (comboMatrix[c1 - 2]) {
					movePlayer(c1, p);
					addToCurrent(p, c1);
				}
				if (comboMatrix[c2 - 2]) {
					movePlayer(c2, p);
					addToCurrent(p, c2);
				}
				p->nSubTurns++;
				break;
			default:
				play(p, cantStop, a1, a2, b1, b2, c1, c2);
				break;
			}
		}else {
		printf("\nNo possible moves! You lost all the progress made in this round!\n");							//A & B & C IMPOSSIBLE	
		system("pause");
		resetProgress(p);
		cantStop->nTurns++;
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
				//reset current
				for (i = 0; i < 3; i++) {
					p->current[i] = 0;
				}
			}
		} while (opt != 'n' && opt != 'y');
	}
}

void genComboMatrix(int* matrix, player* p, board* cantStop, int a1, int a2, int b1, int b2, int c1, int c2) {
	int i,j;
	int diceCombo[6] = {a1,a2,b1,b2,c1,c2};
	for (i = 0; i < 11; i++) { // initialize matrix
		matrix[i] = 0;
	}
	
	for (i = 0; i < 6; i++) {
		switch (diceCombo[i]) {
		case 2:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col2[2] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 3:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col3[4] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 4:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col4[6] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 5:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col5[8] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 6:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col6[10] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 7:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col7[12] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 8:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col8[10] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 9:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col9[8] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 10:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col10[6] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 11:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col11[4] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		case 12:
			for (j = 0; j < 3; j++) {
				if ((p->current[j] == 0 || p->current[j] == diceCombo[i]) && (cantStop->isFull[diceCombo[i] - 2] == 0 && p->col12[2] == 0)) {
					matrix[diceCombo[i] - 2] = 1;
				}
			}
			break;
		}
	}
}

void addToCurrent(player *p, int move) {
	int i;
	for (i = 0; i < 3; i++) {
		if (p->current[i] == move) {
			return;
		}
		else {
			if (p->current[i] == 0) {
				p->current[i] = move;
				return;
			}
		}
	}
}
void resetProgress(player *p) {
	int i;
			//col2
			for (i = 0; i < 3; i++) {
				if (p->col2[i] == 1) {
					p->col2[i] = 0;
				}
			}
			//col3
			for (i = 0; i < 5; i++) {
				if (p->col3[i] == 1) {
					p->col3[i] = 0;
				}
			}
			//col4
			for (i = 0; i < 7; i++) {
				if (p->col4[i] == 1) {
					p->col4[i] = 0;
				}
			}
			//col5
			for (i = 0; i < 9; i++) {
				if (p->col5[i] == 1) {
					p->col5[i] = 0;
				}
			}
			//col6
			for (i = 0; i < 11; i++) {
				if (p->col6[i] == 1) {
					p->col6[i] = 0;
				}
			}
			//col7
			for (i = 0; i < 13; i++) {
				if (p->col7[i] == 1) {
					p->col7[i] = 0;
				}
			}
			//col8
			for (i = 0; i < 11; i++) {
				if (p->col8[i] == 1) {
					p->col8[i] = 0;
				}
			}
			//col9
			for (i = 0; i < 9; i++) {
				if (p->col9[i] == 1) {
					p->col9[i] = 0;
				}
			}
			//col10
			for (i = 0; i < 7; i++) {
				if (p->col10[i] == 1) {
					p->col10[i] = 0;
				}
			}
			//col11
			for (i = 0; i < 5; i++) {
				if (p->col11[i] == 1) {
					p->col11[i] = 0;
				}
			}
			//col12
			for (i = 0; i < 3; i++) {
				if (p->col12[i] == 1) {
					p->col12[i] = 0;
				}
			}

			//current
			for (i = 0; i < 3; i++) {
					p->current[i] = 0;
			}

			p->nSubTurns = 0;
}

void extremeMove(player* p, int a, int b) {
	char move = '0';
	sideMenuClear(4);
	gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 2);
	printf("Possible Moves:");
	gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 4);
	printf("A: %d", a);
	gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 5);
	printf("B: %d", b);

	gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 8);
	printf("Choose a move A or B to play");

	gotoxy(COLS / 2 - COLS / 3 + 4, ROWS / 2 + 9);
	fseek(stdin, 0, SEEK_END);
	(void)scanf(" %c", &move);
	fseek(stdin, 0, SEEK_END);
	move = tolower(move);

	switch (move)
	{
	case 'a':
		movePlayer(a, p);
		addToCurrent(p, a);
		break;
	case 'b':
		movePlayer(b, p);
		addToCurrent(p, b);
		break;
	default:
		extremeMove(p, a, b);
		break;
	}
	
}

void gameOverChecker(int* gameOver, player p, player AI) {
	if (p.score >= 3) {
		*gameOver = 1;
		drawWinner(p, AI);
	}
	else if (AI.score >= 3) {
		*gameOver = 1;
		drawWinner(AI, p);
	}
}
