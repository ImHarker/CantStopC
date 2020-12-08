#include "harker.h"

//Menu
#define Welcome			"Welcome to Can't Stop!"
#define MainMenu		"Main Menu"
//Menu Rect
#define rectWIDTH		2*strlen(Welcome)
#define rectHEIGHT		strlen(Welcome)
#define rectX			(COLS /2)-strlen(Welcome)
#define rectY			4
#define rectCenterX		rectWIDTH / 2 + rectX
#define rectCenterY		rectHEIGHT / 2 + rectY


void menu(void) {
	system("cls");
	char selector;

	//Title
	gotoxy((COLS - strlen(Welcome)) / 2, 3); //center text
	printf(Welcome); //Welcome text

	//MENU
	gotoxy((rectWIDTH / 2 + rectX) - strlen(MainMenu) / 2, rectY + 1);
	printf(MainMenu);
	gotoxy(rectX + 2, rectY + 9);
	printf("1 - Play");
	gotoxy(rectX + 2, rectY + 10);
	printf("2 - Load Game");

	gotoxy(rectX + 2, rectY + 16);
	printf("3 - How to Play");

	gotoxy(rectX + 2,rectY + rectHEIGHT - 1);
	printf("0 - Exit");


	//Draw Menu rect
	showRectAt(rectX, rectY, rectWIDTH, rectHEIGHT);		
	showRectAt(COLS / 2 - COLS / 3, 0,2* COLS/3, ROWS /2 + ROWS / 3);

	//credits
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS - 2);
	printf(" %c %s", COPY_CHAR, CREDITS);
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS - 1);
	printf(" %s", CREDITS1);
	gotoxy(COLS - strlen(CREDITS2) - 1, ROWS);
	printf(" %s", CREDITS2);

	//menu logic
	gotoxy(rectX + 2, rectY + rectHEIGHT + 2);
		printf("Choose an option: ");
		(void)scanf(" %c", &selector);

	switch (selector){

		case '1':
			system("cls");
			game();
			break;

		case '2':
			system("cls");
			//loadGame();
			break;

		case '3':
			system("cls");
			how2();
			break;

		case '0':
			system("cls");
			break;

		default:
			menu();
			selector = NULL;
			break;
	}
}

