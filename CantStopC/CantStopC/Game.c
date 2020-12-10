#include "harker.h"



void game(void) {
	int gameOver = false;
	board cantStop = {.isFull = false};
	player p = { .col2 = false, .col3 = false, .col4 = false, .col5 = false, .col6 = false, .col7 = false, .col8 = false, .col9 = false, .col10 = false, .col11 = false, .col12 = false, .current = 0, .name = "", .playerN = 1};
	player AI = { .current = 0, .name = "AI", .playerN = 2 };
	init(&cantStop, &p, &AI);
	while (!gameOver) {
		draw(p,AI);
		logic(gameOver, &cantStop, &p, &AI);
	}
}