#include "harker.h"


void logic(int gameOver, board *cantStop, player *p, player *AI) {
	int dice1, dice2, dice3, dice4;
	genDice(&dice1, &dice2, &dice3, &dice4);
	//NJOGADAS CHECKER HERE!!!!!!!!!!!!!!!!! if (njogadas % 2== 0) if(p->nplayer == 1)
	input(dice1, dice2, dice3, dice4, cantStop, p);
	

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
	printf("\nDice1: %d, Dice2: %d, Dice3: %d, Dice4: %d", dice1, dice2, dice3, dice4);//debug
	printf("\n %i e %i OU %i e %i OU %i e %i \n", a1, a2, b1, b2, c1, c2); //debug
	printf("%i\n", canPlay(p, cantStop, a1, a2, b1, b2, c1, c2)); // debug
	play(p, cantStop, a1, a2, b1, b2, c1, c2);

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
void play(player* p, board* cantStop, int a1, int a2, int b1, int b2, int c1, int c2) {
	int i;
	char combination = NULL;
	if (canPlay(p, cantStop, a1, a2, b1, b2, c1, c2)) {
		if (   (p->current[0] == 0 
			&& cantStop->isFull[a1 - 2] == false 
			&& cantStop->isFull[a2 - 2] == false 
			&& cantStop->isFull[b1 - 2] == false
			&& cantStop->isFull[b2 - 2] == false
			&& cantStop->isFull[c1 - 2] == false
			&& cantStop->isFull[c2 - 2] == false)
			|| (p->current[1] == 0
				&& cantStop->isFull[a1 - 2] == false
				&& cantStop->isFull[a2 - 2] == false
				&& cantStop->isFull[b1 - 2] == false
				&& cantStop->isFull[b2 - 2] == false
				&& cantStop->isFull[c1 - 2] == false
				&& cantStop->isFull[c2 - 2] == false)) {										//No temp markers or 1 marker and no cols full
			printf("\nA: %i and %i\nB: %i and %i\nC: %i and %i", a1, a2, b1, b2, c1, c2);
			printf("\nChoose one combination A, B or C to play\n");
			(void)scanf(" %c", &combination);
			combination = tolower(combination);
			switch (combination)
			{
			case 'a':
				movePlayer(a1, p);
				movePlayer(a2, p);
				break;
			case 'b':
				movePlayer(b1, p);
				movePlayer(b2, p);
				break;
			case 'c':
				movePlayer(c1, p);
				movePlayer(c2, p);
				break;
			default:
				play(p, cantStop, a1, a2, b1, b2, c1, c2);
				break;
			}
		}else if((p->current[0] == 0
			   || cantStop->isFull[a1 - 2] == true
		   	   || cantStop->isFull[a2 - 2] == true
			   || cantStop->isFull[b1 - 2] == true
			   || cantStop->isFull[b2 - 2] == true
			   || cantStop->isFull[c1 - 2] == true
			   || cantStop->isFull[c2 - 2] == true)
			   || (p->current[1] == 0
			   || cantStop->isFull[a1 - 2] == true
			   || cantStop->isFull[a2 - 2] == true
		       || cantStop->isFull[b1 - 2] == true
			   || cantStop->isFull[b2 - 2] == true
			   || cantStop->isFull[c1 - 2] == true
			   || cantStop->isFull[c2 - 2] == true)){		//No  temp markers or 1 marker any cols full


			if (cantStop->isFull[a1 - 2] == true && cantStop->isFull[a2 - 2] == true) {							//A IMPOSSIBLE
				printf("\nA: %i and %i (NOT POSSIBLE)\nB: %i and %i\nC: %i and %i", a1, a2, b1, b2, c1, c2);
			}
			else if (cantStop->isFull[b1 - 2] == true && cantStop->isFull[b2 - 2] == true) {					//B IMPOSSIBLE
				printf("\nA: %i and %i\nB: %i and %i (NOT POSSIBLE)\nC: %i and %i", a1, a2, b1, b2, c1, c2);
			}
			else if (cantStop->isFull[c1 - 2] == true && cantStop->isFull[c2 - 2] == true) {					//C IMPOSSIBLE
				printf("\nA: %i and %i\nB: %i and %i\nC: %i and %i (NOT POSSIBLE)", a1, a2, b1, b2, c1, c2);
			}
			else if (cantStop->isFull[a1 - 2] == true && cantStop->isFull[a2 - 2] == true &&
					 cantStop->isFull[b1 - 2] == true && cantStop->isFull[b2 - 2] == true) {					// A & B IMPOSSIBLE
				printf("\nA: %i and %i (NOT POSSIBLE)\nB: %i and %i (NOT POSSIBLE)\nC: %i and %i", a1, a2, b1, b2, c1, c2);
			}
			else if (cantStop->isFull[a1 - 2] == true && cantStop->isFull[a2 - 2] == true &&
					 cantStop->isFull[c1 - 2] == true && cantStop->isFull[c2 - 2] == true) {					//A & C IMPOSSIBLE
				printf("\nA: %i and %i (NOT POSSIBLE)\nB: %i and %i\nC: %i and %i (NOT POSSIBLE)", a1, a2, b1, b2, c1, c2);
			}
			else if (cantStop->isFull[b1 - 2] == true && cantStop->isFull[b2 - 2] == true &&
					 cantStop->isFull[c1 - 2] == true && cantStop->isFull[c2 - 2] == true) {					//B & C IMPOSSIBLE
				printf("\nA: %i and %i\nB: %i and %i (NOT POSSIBLE)\nC: %i and %i (NOT POSSIBLE)", a1, a2, b1, b2, c1, c2);
			}
		
		
		}
	}else {
		printf("\nNo possible moves! You lost all the progress made in this round!\n");							//A & B & C IMPOSSIBLE	
	}
}
void movePlayer(int n, player *p) {
	int i;
	int hasChanged = 0;								//flag
	if (n <= 7) {									//n col < or = 7
		for (i = 0; i <= 2 * n - 2; i++) {
			switch (n) {
			case 2:
				if (p->col2[i] == 0) {				//if there is no marker
					p->col2[i] = 1;					//place temp marker
					hasChanged = 1;					//set flag to 1
				}
				break;
			case 3:
				if (p->col3[i] == 0) {
					p->col3[i] = 1;
					hasChanged = 1;
				}
				break;
			case 4:
				if (p->col4[i] == 0) {
					p->col4[i] = 1;
					hasChanged = 1;
				}
				break;
			case 5:
				if (p->col5[i] == 0) {
					p->col5[i] = 1;
					hasChanged = 1;
				}
				break;
			case 6:
				if (p->col6[i] == 0) {
					p->col6[i] = 1;
					hasChanged = 1;
				}
				break;
			case 7:
				if (p->col7[i] == 0) {
					p->col7[i] = 1;
					hasChanged = 1;
				}
				break;
			}
			if (hasChanged == 1) break;						//if a value changed in this cycle, exits for loop
		}
	}
	else if (n > 7) {												//if n col > 7
		for (i = 0; i <= 2 * (n - (n - 7) * 2) - 2; i++) {			//same as above^^
			switch (n) {
			case 8:
				if (p->col8[i] == 0) {
					p->col8[i] = 1;
					hasChanged = 1;
				}
				break;
			case 9:
				if (p->col9[i] == 0) {
					p->col9[i] = 1;
					hasChanged = 1;
				}
				break;
			case 10:
				if (p->col10[i] == 0) {
					p->col10[i] = 1;
					hasChanged = 1;
				}
				break;
			case 11:
				if (p->col11[i] == 0) {
					p->col11[i] = 1;
					hasChanged = 1;
				}
				break;
			case 12:
				if (p->col12[i] == 0) {
					p->col12[i] = 1;
					hasChanged = 1;
				}
				break;
			}
			if (hasChanged == 1) break;
		}
	}
}