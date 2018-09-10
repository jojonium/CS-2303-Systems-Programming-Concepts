/* life.c */

#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main(int argc, char *argv[]) {
	unsigned int nr, nc, i, j, xoffset, yoffset, inputx, inputy;
	long gens;
	char *input;
	char *line = NULL;
	size_t len = 0;
	char **board;
	char **buffer;
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
	board = malloc(nc * sizeof(char *));
	buffer = malloc(nc * sizeof(char *));
	for (i = 0; i < nc; i++) {
		board[i] = malloc(nr * sizeof(char));
		buffer[i] = malloc(nr * sizeof(char));
	}

	// fill in array with blanks
	for (j = 0; j < nr; j++) {
		for (i = 0; i < nc; i++) {
			board[i][j] = 'o';
			buffer[i][j] = 'o';
		}
	}

	// open file
	if ((fp = fopen(input, "r")) == NULL) {
		printf("file open error\n");
		exit(1);
	}

	// read from file
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
				board[i][j] = 'x';
				buffer[i][j] = 'x';
			} else if (temp == '\n') {
				i = nc;
			} else if (temp == EOF) {
				i = nc;
				j = nr;
			}
		}
	}

	printf("=== STARTING BOARD ===\n\n");
	printBoard(nr, nc, board);

	printf("=== NEIGHBORS ===\n\n");
	for (j = 0; j < nr; j++) {
		for (i = 0; i < nc; i++) {
			printf("%u", getNeighbors(nr, nc, i, j, board));
		}
		printf("\n");
	}

	return 0;
}
