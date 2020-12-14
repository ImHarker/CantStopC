#include "harker.h"



void game(void) {
	int gameOver = false;
	board cantStop;
	player p;
	player AI;
	init(&cantStop, &p, &AI);
	draw(p, AI);
	while (!gameOver) {
		logic(gameOver, &cantStop, &p, &AI);
		draw(p,AI);
		askContinue(&cantStop, &p);
		draw(p, AI);
	}
}