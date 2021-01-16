#include "harker.h"


void draw(player p, player AI) {
	int i;
	system("cls");
	drawBoard();			//board
	drawPlayerList(p, AI); // Player list and score
	for (i = 2; i <= 12; i++) {		//draws temp markers 
		drawTempMarkers(i, &p);
		drawTempMarkers(i, &AI);
		drawPermMarkers(i, &p);
		drawPermMarkers(i, &AI);
	}
}

void drawTempMarkers(int n, player* p) {
	int i;
	int index = -5;											//init position with an value to use as a flag aswell


	if (n <= 7) {											//n col < or = 7
		for (i = 0; i <= 2 * n - 2; i++) {
			switch (n) {									//changes to col number
			case 2:
				if (p->col2[i] == 0) {						//if there is no marker in this position
					index = i-1;							//set position to draw to i-1
				}else if (p->col2[2 * n - 2] == 1) {		//verify if the last position has a temporary marker
					index = 2 * n - 2;						//if so the position to draw is the last index
				}
				break;
			case 3:
				if (p->col3[i] == 0) {
					index = i-1;
				}else if (p->col3[2 * n - 2] == 1) {
					index = 2 * n - 2;
				}
				break;
			case 4:
				if (p->col4[i] == 0) {
					index = i-1;
				}else if (p->col4[2 * n - 2] == 1) {
					index = 2 * n - 2;
				}
				break;
			case 5:
				if (p->col5[i] == 0) {
					index = i-1;
				}else if (p->col5[2 * n - 2] == 1) {
					index = 2 * n - 2;
				}
				break;
			case 6:
				if (p->col6[i] == 0) {
					index = i-1;
				}else if (p->col6[2 * n - 2] == 1) {
					index = 2 * n - 2;
				}
				break;
			case 7:
				if (p->col7[i] == 0) {
					index = i-1;
				}else if (p->col7[2 * n - 2] == 1) {
					index = 2 * n - 2;
				}
				break;
			}
			if (index != -5) break;											//if the index changed then exit the for loop
		}
		if (p->playerN == 1 && index >= 0){									//if player n is 1 and the position is 0 or more change color and draw
			setForeColor(MY_COLOR_DARK_BLUE);
			showCharAt(COLS / 2 - 1 - ((7 - n) * 7)-1, 33 - ((7 - n) * 2) - (index * 2), 207);

		}else if (p->playerN == 2 && index >= 0){
			setForeColor(MY_COLOR_DARK_RED);
			showCharAt(COLS / 2 - 1 - ((7 - n) * 7) + 3, 33 - ((7 - n) * 2) - (index * 2), 207);
		}
		resetColor();														//back to default colors
	}else if (n > 7) {														//same as above but for n col > 7

		for (i = 0; i <= 2 * (n - (n - 7) * 2) - 2; i++) {
			switch (n) {
			case 8:
				if (p->col8[i] == 0) {
					index = i-1;
				}else if (p->col8[2 * (n - (n - 7) * 2) - 2] == 1) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			case 9:
				if (p->col9[i] == 0) {
					index = i-1;
				}else if (p->col9[2 * (n - (n - 7) * 2) - 2] == 1) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			case 10:
				if (p->col10[i] == 0) {
					index = i-1;
				}else if (p->col10[2 * (n - (n - 7) * 2) - 2] == 1) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			case 11:
				if (p->col11[i] == 0) {
					index = i-1;
				}else if (p->col11[2 * (n - (n - 7) * 2) - 2] == 1) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			case 12:
				if (p->col12[i] == 0) {
					index = i-1;
				}else if (p->col12[2 * (n - (n - 7) * 2) - 2] == 1) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			}
			if (index != -5) break;
		}
		if (p->playerN == 1 && index >= 0) {
			setForeColor(MY_COLOR_DARK_BLUE);
			showCharAt(COLS / 2 - 1 - ((7 - n) * 7) -1, (21 + ((n - (n - 7) * 2) - 1) * 2) - index * 2, 207);

		}
		else if (p->playerN == 2 && index >= 0){
			setForeColor(MY_COLOR_DARK_RED);
			showCharAt(COLS / 2 - 1 - ((7 - n) * 7) + 3, (21 + ((n - (n - 7) * 2) - 1) * 2) - index * 2, 207);
		}
		resetColor();
	}
}

void drawPlayerList(player p, player AI) {
	(strlen(p.name) > strlen(AI.name) ? showRectAt(COLS / 2 - COLS / 3 + 4, 3, strlen(p.name) + 10, 5) : showRectAt(COLS / 2 - COLS / 3 + 4, 3, strlen(AI.name) + 10, 5));
	gotoxy(COLS / 2 - COLS / 3 + 5, 4);
	printf("SCOREBOARD");
	if (p.playerN == 1) {						//Case: Human is the first playing
		gotoxy(COLS / 2 - COLS / 3 + 5, 6);
		printf("%s ", p.name);					//draw player name
		setForeColor(MY_COLOR_DARK_BLUE);
		setlocale(LC_ALL, "C");
		printf("%c %c", 254, 207);				//draw player marker (permanent and temp)
		resetColor();
		printf(" %c %d%c\n",26,p.score, 30);				//draw player current score (won cols)
		gotoxy(COLS / 2 - COLS / 3 + 5, 7);
		printf("%s ", AI.name);					//draw AI name
		setForeColor(MY_COLOR_DARK_RED);
		setlocale(LC_ALL, "C");
		printf("%c %c", 254, 207);				//draw AI marker (permanent and temp)
		resetColor();
		printf(" %c %d%c\n",26, AI.score, 30);				//draw AI current score (won cols)
	}
	else {										//Case: AI is the first playing
		gotoxy(COLS / 2 - COLS / 3 + 5, 6);
		printf("%s ", AI.name);					//draw AI name
		setForeColor(MY_COLOR_DARK_BLUE);
		setlocale(LC_ALL, "C");
		printf("%c %c", 254, 207);				//draw AI marker (permanent and temp)
		resetColor();
		printf(" %c %d%c\n",26,AI.score, 30);				//draw AI current score (won cols)
		gotoxy(COLS / 2 - COLS / 3 + 5, 7);
		printf("%s ", p.name);					//draw player name
		setForeColor(MY_COLOR_DARK_RED);
		setlocale(LC_ALL, "C");
		printf("%c %c", 254, 207);				//draw player marker (permanent and temp)
		resetColor();
		printf(" %c %d%c\n",26, p.score, 30);				//draw current score (won cols)
	}
}

void drawPermMarkers(int n, player* p) {
	int i;
	int index = -5;											//init position with an value to use as a flag aswell


	if (n <= 7) {											//n col < or = 7
		for (i = 1; i <= 2 * n - 2; i++) {
			switch (n) {									//changes to col number
			case 2:
				if ((p->col2[i] == 0 && p->col2[i-1] == 2) || (p->col2[i] == 1 && p->col2[i - 1] == 2)) {						//if there is no marker in this position or a temp marker in the current turn
					index = i - 1;							//set position to draw to i-1
				}
				else if (p->col2[2 * n - 2] == 2) {		//verify if the last position has a temporary marker
					index = 2 * n - 2;						//if so the position to draw is the last index
				}
				break;
			case 3:
				if ((p->col3[i] == 0 && p->col3[i - 1] == 2) || (p->col3[i] == 1 && p->col3[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col3[2 * n - 2] == 2) {
					index = 2 * n - 2;
				}
				break;
			case 4:
				if ((p->col4[i] == 0 && p->col4[i - 1] == 2) || (p->col4[i] == 1 && p->col4[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col4[2 * n - 2] == 2) {
					index = 2 * n - 2;
				}
				break;
			case 5:
				if ((p->col5[i] == 0 && p->col5[i - 1] == 2) || (p->col5[i] == 1 && p->col5[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col5[2 * n - 2] == 2) {
					index = 2 * n - 2;
				}
				break;
			case 6:
				if ((p->col6[i] == 0 && p->col6[i - 1] == 2) || (p->col6[i] == 1 && p->col6[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col6[2 * n - 2] == 2) {
					index = 2 * n - 2;
				}
				break;
			case 7:
				if ((p->col7[i] == 0 && p->col7[i - 1] == 2) || (p->col7[i] == 1 && p->col7[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col7[2 * n - 2] == 2) {
					index = 2 * n - 2;
				}
				break;
			}
			if (index != -5) break;											//if the index changed then exit the for loop
		}
		if (p->playerN == 1 && index >= 0) {									//if player n is 1 and the position is 0 or more change color and draw
			setForeColor(MY_COLOR_DARK_BLUE);
			showCharAt(COLS / 2 - 1 - ((7 - n) * 7) - 1, 33 - ((7 - n) * 2) - (index * 2), 254);

		}
		else if (p->playerN == 2 && index >= 0) {
			setForeColor(MY_COLOR_DARK_RED);
			showCharAt(COLS / 2 - 1 - ((7 - n) * 7) + 3, 33 - ((7 - n) * 2) - (index * 2), 254);
		}
		resetColor();														//back to default colors
	}
	else if (n > 7) {														//same as above but for n col > 7

		for (i = 1; i <= 2 * (n - (n - 7) * 2) - 2; i++) {
			switch (n) {
			case 8:
				if ((p->col8[i] == 0 && p->col8[i - 1] == 2) || (p->col8[i] == 1 && p->col8[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col8[2 * (n - (n - 7) * 2) - 2] == 2) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			case 9:
				if ((p->col9[i] == 0 && p->col9[i - 1] == 2) || (p->col9[i] == 1 && p->col9[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col9[2 * (n - (n - 7) * 2) - 2] == 2) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			case 10:
				if ((p->col10[i] == 0 && p->col10[i - 1] == 2) || (p->col10[i] == 1 && p->col10[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col10[2 * (n - (n - 7) * 2) - 2] == 2) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			case 11:
				if ((p->col11[i] == 0 && p->col11[i - 1] == 2) || (p->col11[i] == 1 && p->col11[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col11[2 * (n - (n - 7) * 2) - 2] == 2) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			case 12:
				if ((p->col12[i] == 0 && p->col12[i - 1] == 2) || (p->col12[i] == 1 && p->col12[i - 1] == 2)) {
					index = i - 1;
				}
				else if (p->col12[2 * (n - (n - 7) * 2) - 2] == 2) {
					index = 2 * (n - (n - 7) * 2) - 2;
				}
				break;
			}
			if (index != -5) break;
		}
		if (p->playerN == 1 && index >= 0) {
			setForeColor(MY_COLOR_DARK_BLUE);
			showCharAt(COLS / 2 - 1 - ((7 - n) * 7) - 1, (21 + ((n - (n - 7) * 2) - 1) * 2) - index * 2, 254);

		}
		else if (p->playerN == 2 && index >= 0) {
			setForeColor(MY_COLOR_DARK_RED);
			showCharAt(COLS / 2 - 1 - ((7 - n) * 7) + 3, (21 + ((n - (n - 7) * 2) - 1) * 2) - index * 2, 254);
		}
		resetColor();
	}
}




void drawBoard(void) {
	int i, j;
	showRectAt(COLS / 2 - COLS / 3, 0, 2 * COLS / 3, ROWS / 2 + ROWS / 3);
	for (j = 1; j < 7; j++) {
		for (i = 1; i < 16 - 2 * j; i++) {
			showRectAt(COLS / 2 - 6 - 7 * (j - 1) + 3, 2 * i + 2 * (j - 1) + 8, 6, 0); //draw horizontal lines 2 to 7
			showRectAt(COLS / 2 - 6 + 7 * (j - 1) + 3, 2 * i + 2 * (j - 1) + 8, 6, 0); //draw horizontal lines 7 to 11
		}
		gotoxy(COLS / 2 - 3 - 7 * (j - 1) + 3, 1 + 2 * (j - 1) + 8);
		printf("%d", 6 - j + 2);																//draw col number 2 to 7
		gotoxy(COLS / 2 - 3 + 7 * (j - 1) + 3, 1 + 2 * (j - 1)+8);
		printf("%d", 6 + j);																	//draw col number 7 to 11
		showRectAt(COLS / 2 - 6 * j - (j - 1) + 3, 2 * (j - 1) + 8, 6, 26 - 4 * (j-1));		//draw col 2 to 7
		showRectAt(COLS / 2 + 6 * (j - 2) + (j - 1) + 3, 2 * (j - 1) + 8, 6, 26 - 4 * (j-1));	//draw col 7 to 11
		printf("\n");

	}																	//draw credits
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS - 2);
	printf(" %c %s", COPY_CHAR, CREDITS);
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS - 1);
	printf(" %s", CREDITS1);
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS);
	printf(" %s", CREDITS2);
}

void drawCombo(int a1, int a2, int b1, int b2, int c1, int c2) {
	int i, j;
	int w = 4, h = 2;
	int dy = 0;
	int count = -1;
	int temp[6] = {a1, a2, b1, b2, c1, c2};

	showRectAt((COLS / 2 - COLS / 3 + 4) + (w + 1) * 2 - strlen("COMBINATIONS") / 2 -4, ROWS / 3 - 3 + 1, strlen("COMBINATIONS")+ 1, 6*h -1);
	gotoxy((COLS / 2 - COLS / 3 + 4) + (w+1)*2 -strlen("COMBINATIONS")/2 + 1 -4, ROWS / 3 - 1);
	printf("COMBINATIONS");

	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 2; j++) {
			showRectAt((COLS / 2 - COLS / 3 + 4) + (w + 1)*j + 2*j -2 -4, ROWS / 3 + dy, w, h);
			gotoxy((COLS / 2 - COLS / 3 + 4) + 2 + (w + 1)*j + 2*j -2 -4, ROWS / 3 + 1 + dy);
			count++;
			printf("%d", temp[count]);
		}
		dy += h + 1;
	}
}

void drawDice(int dice1, int dice2, int dice3, int dice4) {
	int i, j;
	int w = 4, h = 2;
	int dy = 0;
	int count = -1;
	int temp[4] = { dice1, dice2, dice3, dice4 };

	showRectAt((COLS / 2 - COLS / 3 + 4) + (w + 1) * 2 - strlen("DICES ROLLED") / 2 -4, ROWS / 5 - 3, strlen("DICES ROLLED") + 1, 4 * h);
	gotoxy((COLS / 2 - COLS / 3 + 4) + (w + 1) * 2 - strlen("DICES ROLLED") / 2 + 1 -4, ROWS / 5 - 2);
	printf("DICES ROLLED");

	for (i = 1; i <= 2; i++) {
		for (j = 1; j <= 2; j++) {
			showRectAt((COLS / 2 - COLS / 3 + 4) + (w + 1) * j + 2 * j - 2 -4, ROWS / 5 + dy - 1, w, h);
			gotoxy((COLS / 2 - COLS / 3 + 4) + 2 + (w + 1) * j + 2 * j - 2 -4, ROWS / 5 + dy);
			count++;
			printf("%d", temp[count]);
		}
		dy += h + 1;
	}
}
void drawWinner(player p, player p2) {
	system("cls");
	showRectAt(COLS / 2 - COLS / 3, 0, 2 * COLS / 3, ROWS / 2 + ROWS / 3);
	gotoxy(COLS / 2 - strlen("Player  won the game with an advantage of x column(s)")/2 - strlen(p.name)/2, ROWS / 2);
	printf("Player %s won the game with an advantage of %d column(s)", p.name, p.score - p2.score);
	gotoxy(COLS / 2 - strlen("Thanks for playing") / 2, ROWS / 2 + 2);
	printf("Thanks for playing");

	//credits
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS - 2);
	printf(" %c %s", COPY_CHAR, CREDITS);
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS - 1);
	printf(" %s", CREDITS1);
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS);
	printf(" %s", CREDITS2);

	gotoxy(COLS / 2 - strlen("Press any key to continue . . .") / 2, ROWS / 2 + 4);
	system("pause");
}
