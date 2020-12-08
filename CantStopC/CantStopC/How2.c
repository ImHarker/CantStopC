#include "harker.h"

void how2(void) {
	
    FILE* fptr;
    char c;

    // Open file 
    fptr = fopen("Rules.txt", "r");
    if (fptr == NULL){
        printf("Cannot open file \n");
        return;
    }

    // Read contents from file 
    c = fgetc(fptr);
    while (c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);

    system("pause");
    menu();

}