#ifndef _LABH_		//protectes from multiple including...
#define _LABH_		//... needs an #endif at bottom
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

#define false	0
#define true	1

#define MY_COLOR_BLACK			0
#define MY_COLOR_DARK_BLUE		1
#define MY_COLOR_SOFT_GREEN		2
#define MY_COLOR_SOFT_BLUE		3
#define MY_COLOR_DARK_RED		4
#define MY_COLOR_PURPLE			5
#define MY_COLOR_DARK_YELLOW	6
#define MY_COLOR_GRAY			7
#define MY_COLOR_DARK_GRAY		8
#define MY_COLOR_CYAN			9
#define MY_COLOR_LIGTH_GREEN	10
#define MY_COLOR_LIGTH_BLUE		11
#define MY_COLOR_LIGTH_RED		12
#define MY_COLOR_PINK			13
#define MY_COLOR_LIGTH_YELLOW	14
#define MY_COLOR_WHITE			15

//changes both foreground and background colors
void setColor(int foreGround, int backGround);

//changes foreground color while keeping background color
void setForeColor(int foreGround);

//changes background color while keeping foreground color
void setBackColor(int backGround);

//Colors reset: foreground white, background black
void resetColor();

//allows to place the cursor at any given position
void gotoxy(int x, int y);

//allows to draw a rectangle (double lines) at any given position
void showRectAt(int x, int y, int width, int height);

//allows to draw a rectangle (double lines) at any given position, rotated by 90º 
void show90RectAt(int x, int y, int width, int height);

//show a char at a designated position
void showCharAt(int x, int y, char c);

//write a 'string' verticaly at a designated position
void showVerticalWordAt(int x, int y, char c[], int charNumber);

//write an horizontal 'string' at a designated position
void printfAt(int x, int y, char c[]);

// print the ascii table in two locale Modes 
// usage sample: printAscii(174, 223, 4);
void printAscii(int N0, int N, int col);


#endif
