#include "harker.h"


int loadPlayer(FILE* fptr, player* p) {
	int i;
	if (fptr == NULL) return -1;
	char buff[21] = { '\0' };
	
	(void)fscanf(fptr, "%[^\n]20s", buff);
	strcpy(p->name, buff);

	(void)fscanf(fptr, "%d\n", &(p->nSubTurns));

	(void)fscanf(fptr, "%d\n", &(p->playerN));

	(void)fscanf(fptr, "%d\n", &(p->score));

	for (i = 0; i < 3; i++) {
		(void)fscanf(fptr, "%d", &(p->current[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 3; i++) {
		(void)fscanf(fptr, "%d", &(p->col2[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 5; i++) {
		(void)fscanf(fptr, "%d", &(p->col3[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 7; i++) {
		(void)fscanf(fptr, "%d", &(p->col4[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 9; i++) {
		(void)fscanf(fptr, "%d", &(p->col5[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 11; i++) {
		(void)fscanf(fptr, "%d", &(p->col6[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 13; i++) {
		(void)fscanf(fptr, "%d", &(p->col7[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 11; i++) {
		(void)fscanf(fptr, "%d", &(p->col8[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 9; i++) {
		(void)fscanf(fptr, "%d", &(p->col9[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 7; i++) {
		(void)fscanf(fptr, "%d", &(p->col10[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 5; i++) {
		(void)fscanf(fptr, "%d", &(p->col11[i]));
		fgetc(fptr);
	}
	fgetc(fptr);

	for (i = 0; i < 3; i++) {
		(void)fscanf(fptr, "%d", &(p->col12[i]));
		fgetc(fptr);
	}
	fgetc(fptr);
}