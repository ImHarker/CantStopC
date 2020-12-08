#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include "lab.h"


//changes both foreground and background colors
void setColor(int foreGround, int backGround) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround * 16 + foreGround);
}
//changes foreground color while keeping background color
void setForeColor(int foreGround) {
	int backGround = MY_COLOR_BLACK;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	backGround = csbiInfo.wAttributes / 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround * 16 + foreGround);
}
//changes background color while keeping foreground color
void setBackColor(int backGround) {
	int foreGround = MY_COLOR_BLACK;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	foreGround = csbiInfo.wAttributes % 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround * 16 + foreGround);
}
//Colors reset: foreground white, background black
void resetColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MY_COLOR_BLACK * 16 + MY_COLOR_WHITE);
}

//allows to place the cursor at any given position
void gotoxy(int x, int y) {
	COORD c = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//allows to draw a rectangle (double lines) at any given position
void showRectAt(int x, int y, int width, int height) {

	setlocale(LC_ALL, "C");
	int i;
	gotoxy(x, y);
	printf("%c", 201);
	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 187);
	gotoxy(x, height + y);
	printf("%c", 200);

	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 188);

	for (i = y + 1; i < height + y; i++) {
		gotoxy(x, i);
		printf("%c", 186);

		gotoxy(x + width, i);
		printf("%c", 186);

	}
	setlocale(LC_ALL, "");
}
//allows to draw a rectangle (double lines) at any given position, rotated by 90º 
void show90RectAt(int x, int y, int width, int height) {
	showRectAt(x, y, height * 2, width / 2);
}
//show a char at a designated position
void showCharAt(int x, int y, char c) {
	setlocale(LC_ALL, "C");
	gotoxy(x, y);
	printf("%c", c);
	setlocale(LC_ALL, "");
}
//write a 'string' verticaly at a designated position
void showVerticalWordAt(int x, int y, char c[], int charNumber) {
	setlocale(LC_ALL, "C");
	int i = 0;
	for (i = 0; i < charNumber; i++) {
		gotoxy(x, y + i);
		printf("%c", c[i]);
	}

	setlocale(LC_ALL, "");
}
//write an horizontal 'string' at a designated position
void printfAt(int x, int y, char c[]) {
	setlocale(LC_ALL, "C");
	gotoxy(x, y);
	printf("%s", c);
	setlocale(LC_ALL, "");
}


// print the ascii table in two locale Modes 
// usage sample: printAscii(174, 223, 4);
void printAscii(int N0, int N, int col) {

	int i = 0, j = 0;
	int aux = 0, linhas = 0;

	if (N0 >= N || N <= 32 || col < 1)
		return;				// nothing to do here!
	if (N > 256) N = 256;	// upper limite of the set to print
	if (N0 < 32) N0 = 32;	// lower limite of the set to print...
							// ...first ascii numbers are indeed actions
	if (col > (N - N0)) col = N - N0; 	// number of columns to split the print

	printf("locale: ");
	setForeColor(MY_COLOR_DARK_RED);
	printf("\t setlocale(LC_ALL, \"C\");");
	setForeColor(MY_COLOR_SOFT_GREEN);
	printf("\t  setlocale(LC_ALL, \"Portuguese\");");
	resetColor();

	printf("\n\n");
	N++;
	linhas = (N - N0) / col;
	if ((N - N0) % col) linhas++;
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < col; j++) {
			aux = i + j * linhas + N0;
			if (aux > N - 1) break;
			setlocale(LC_ALL, "C");
			printf("\t%3d - ", aux);
			setForeColor(MY_COLOR_DARK_RED);
			printf("%c", aux);
			resetColor();
			setlocale(LC_ALL, "");
			printf(" - ");
			setForeColor(MY_COLOR_SOFT_GREEN);
			printf("%c ", aux);
			resetColor();
		}
		printf("\n");
	}
	resetColor();
}