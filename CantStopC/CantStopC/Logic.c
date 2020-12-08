#include "harker.h"


void logic(int gameOver, board *cantStop, player *p) {
	int dice1, dice2, dice3, dice4;
	int current[3] = { 0, 0, 0 };
	genDice(&dice1, &dice2, &dice3, &dice4);
	input(dice1, dice2, dice3, dice4, cantStop, p);
	//movePlayer();
	

}

/*void checkCol() {
 //n is the number of the col
	if (col[2*n - 2] && n <= 7) {
		//col won
	}
	else if (col[2 * (n - (n - 7) * 2) - 2] && n > 7) {
		//col won
	}
}*/	

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
	printf("\nDado1: %d, Dado2: %d, Dado3: %d, Dado4: %d", dice1, dice2, dice3, dice4);//debug
	printf("\n %i e %i OU %i e %i OU %i e %i \n", a1, a2, b1, b2, c1, c2); //debug
	printf("%i\n", canPlay(p, cantStop, a1, a2, b1, b2, c1, c2)); // debug
	system("pause");
}
int canPlay(player *p,board *cantStop, int a1, int a2, int b1, int b2, int c1, int c2){
	int i;

	for (i = 0; i < 3; i++) {
		if  (p->current[i] == 0										 ||
			(p->current[i] == a1 && cantStop->isFull[a1-2] == false) ||
			(p->current[i] == a2 && cantStop->isFull[a2-2] == false) ||
			(p->current[i] == b1 && cantStop->isFull[b1-2] == false) ||
			(p->current[i] == b2 && cantStop->isFull[b2-2] == false) ||
			(p->current[i] == c1 && cantStop->isFull[c1-2] == false) ||
			(p->current[i] == c2 && cantStop->isFull[c2-2] == false))
			return true;
	}
	return false;
}