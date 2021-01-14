#include "harker.h"



void game(void) {
	int gameOver = false;
	board cantStop;
	player p;
	player AI;
	FILE* fptr;
	init(&cantStop, &p, &AI);
	//fptr = fopen("player.txt", "r");
	//saveGame(fptr, p);
	//loadPlayer(fptr, &p);
	//fclose(fptr);
	draw(p, AI);
	while (!gameOver) {
		logic(gameOver, &cantStop, &p, &AI);
		draw(p,AI);
		askContinue(&cantStop, &p);
		checkCols(&cantStop, &AI); //updates score and isfull array
		checkCols(&cantStop, &p);
		draw(p, AI);

	}
}