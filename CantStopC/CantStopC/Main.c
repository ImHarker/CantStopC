#define _CRT_SECURE_NO_WARNINGS
#include "harker.h"


int main(void) {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //fullscreen
    setlocale(LC_ALL, "C");

    srand((int)time(NULL));

    //terminal size
    /*CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    printf("columns: %d\n", columns);
    printf("rows: %d\n", rows);
    */
    
	menu();

	return 0;
}