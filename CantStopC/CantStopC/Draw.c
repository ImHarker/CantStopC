#include "harker.h"


void draw(player p, player AI) {
	system("cls");
	drawBoard();			//board
	drawPlayerList(p, AI); // Player list and score
}

void drawPlayerList(player p, player AI) {
	if (p.playerN == 1) {						//Case: Human is the first playing
		gotoxy(COLS / 2 - COLS / 3 + 3, 2);
		printf("%s ", p.name);					//draw player name
		setForeColor(MY_COLOR_DARK_BLUE);
		setlocale(LC_ALL, "C");
		printf("%c %c", 254, 207);				//draw player marker (permanent and temp)
		resetColor();
		printf(" %c 0%c\n",26, 30);				//draw player current score (won cols)
		gotoxy(COLS / 2 - COLS / 3 + 3, 3);
		printf("%s ", AI.name);					//draw AI name
		setForeColor(MY_COLOR_DARK_RED);
		setlocale(LC_ALL, "C");
		printf("%c %c", 254, 207);				//draw AI marker (permanent and temp)
		resetColor();
		printf(" %c 0%c\n",26, 30);				//draw AI current score (won cols)
	}
	else {										//Case: AI is the first playing
		gotoxy(COLS / 2 - COLS / 3 + 3, 2);
		printf("%s ", AI.name);					//draw AI name
		setForeColor(MY_COLOR_DARK_BLUE);
		setlocale(LC_ALL, "C");
		printf("%c %c", 254, 207);				//draw AI marker (permanent and temp)
		resetColor();
		printf(" %c 0%c\n",26, 30);				//draw AI current score (won cols)
		gotoxy(COLS / 2 - COLS / 3 + 3, 3);
		printf("%s ", p.name);					//draw player name
		setForeColor(MY_COLOR_DARK_RED);
		setlocale(LC_ALL, "C");
		printf("%c %c", 254, 207);				//draw player marker (permanent and temp)
		resetColor();
		printf(" %c 0%c\n",26, 30);				//draw current score (won cols)
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
		showRectAt(COLS / 2 - 6 * j - (j - 1) + 3, 2 * (j - 1) + 8, 6, 26 - 4 * (j-1));
		showRectAt(COLS / 2 + 6 * (j - 2) + (j - 1) + 3, 2 * (j - 1) + 8, 6, 26 - 4 * (j-1));
		printf("\n");

	}																	//draw credits
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS - 2);
	printf(" %c %s", COPY_CHAR, CREDITS);
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS - 1);
	printf(" %s", CREDITS1);
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS);
	printf(" %s", CREDITS2);
}