/* life.c */

#include <stdio.h>
#include <stdlib.h>
#include "board.h"


int main(int argc, char *argv[]) {
	unsigned int nr, nc, i, j, xoffset, yoffset, inputx, inputy;
	long gens, iteration;
	char *input;
	char *line = NULL;
	size_t len = 0;
	char **A;
	char **B;
	char **C;
	char **boards[3];
	char temp;
	int print = 0;
	int pause = 0;
	FILE *fp;

	// check number of arguments
	if (argc < 5) {
		printf("Too few arguments. Expected\n\t./life NR NC gens input [print] [pause]\n");
		exit(1);
	}
	
	nr = (unsigned int)atoi(argv[1]);
	nc = (unsigned int)atoi(argv[2]);
	gens = (long)atoi(argv[3]);
	input = argv[4];
	if (argc > 5 && argv[5][0] == 'y') print = 1;
	if (argc > 6 && argv[6][0] == 'y') pause = 1;

	// allocate arrays
	A = malloc(nc * sizeof(char *));
	B = malloc(nc * sizeof(char *));
	C = malloc(nc * sizeof(char *));
	for (i = 0; i < nc; i++) {
		A[i] = malloc(nr * sizeof(char));
		B[i] = malloc(nr * sizeof(char));
		C[i] = malloc(nr * sizeof(char));
	}

	// fill in array with blanks
	for (j = 0; j < nr; j++) {
		for (i = 0; i < nc; i++) {
			A[i][j] = 'o';
		}
	}

	// open file
	if ((fp = fopen(input, "r")) == NULL) {
		printf("file open error\n");
		exit(1);
	} // read from file
	inputy = 0;
	while ((xoffset = getline(&line, &len, fp)) != -1) {
		if (xoffset > inputx) inputx = xoffset;
		inputy++;
	}
	xoffset--; // getline includes the newline character
	xoffset = (nc - inputx) / 2.0f + 0.5f; // simulate rounding
	yoffset = (nr - inputy) / 2.0f + 0.5f;
		
	// always reqind your tapes before returning them
	rewind(fp);
	for (j = yoffset; j < nr; j++) {
		for (i = xoffset; i < nc; i++) {
			temp = fgetc(fp);
			if (temp == 'x') {
				A[i][j] = 'x';
			} else if (temp == '\n') {
				i = nc;
			} else if (temp == EOF) {
				i = nc;
				j = nr;
			}
		}
	}

	// prepare to play
	iteration = 0;
	boards[0] = A;
	boards[1] = B;
	boards[2] = C;

	while (iteration < gens) {
		if (print) {
			printf("\n==== ITERATION %4li ====\n", iteration);
			printBoard(nr, nc, boards[iteration % 3]);
		}

		if (pause) {
			printf("Press enter to continue...\n");
			getchar();
		}

		// play the game
		playOne(nr, nc, boards[iteration % 3], boards[(iteration + 1) % 3]);

		iteration++;
	}

	return 0;
}
