#include "harker.h"


int saveGame(FILE *fptr, player p) {
	savePlayer(fptr, p);
	//saveBoard();
	//saveVars();
	return 1;
}

int savePlayer(FILE *fptr, player p) {
	int i;
	if (fptr == NULL) return -1;

	fprintf(fptr, "%s\n", p.name);
	fprintf(fptr, "%d\n", p.nSubTurns);
	fprintf(fptr, "%d\n", p.playerN);
	fprintf(fptr, "%d\n", p.score);

	for (i = 0; i < 3; i++) {
		fprintf(fptr, "%d;", p.current[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 3; i++) {
		fprintf(fptr, "%d;", p.col2[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 5; i++) {
		fprintf(fptr, "%d;", p.col3[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 7; i++) {
		fprintf(fptr, "%d;", p.col4[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 9; i++) {
		fprintf(fptr, "%d;", p.col5[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 11; i++) {
		fprintf(fptr, "%d;", p.col6[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 13; i++) {
		fprintf(fptr, "%d;", p.col7[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 11; i++) {
		fprintf(fptr, "%d;", p.col8[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 9; i++) {
		fprintf(fptr, "%d;", p.col9[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 7; i++) {
		fprintf(fptr, "%d;", p.col10[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 5; i++) {
		fprintf(fptr, "%d;", p.col11[i]);
	}
	fprintf(fptr, "\n");

	for (i = 0; i < 3; i++) {
		fprintf(fptr, "%d;", p.col12[i]);
	}
	fprintf(fptr, "\n");
}