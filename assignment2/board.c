/* board.c */

#include <stdlib.h>
#include <stdio.h>

#define ALIVE 'x'
#define DEAD 'o'

unsigned int getNeighbors(unsigned nr, unsigned nc, unsigned x, unsigned y, char *b[]) {
	return  ((y > 0 && x > 0) ? (b[x - 1][y - 1] == ALIVE) : 0) +           // top left
		((y > 0) ? (b[x][y - 1] == ALIVE) : 0) +                        // top
		((y > 0 && x < nc - 1) ? (b[x + 1][y - 1] == ALIVE) : 0) +      // top right
		((x < nc - 1) ? (b[x + 1][y] == ALIVE) : 0) +                   // right
		((y < nr - 1 && x < nc - 1) ? (b[x + 1][y + 1] == ALIVE) : 0) + // bot right
		((y < nr - 1) ? (b[x][y + 1] == ALIVE) : 0) +                   // bottom
		((y < nr - 1 && x > 0) ? (b[x - 1][y + 1] == ALIVE) : 0) +      // bot left
		((x > 0) ? (b[x - 1][y] == ALIVE) : 0);                         // left
}

void playOne(unsigned int nr, unsigned int nc, char *old[], char *new[]) {
	unsigned int i, j, neighbors;
	for (j = 0; j < nr; j++) {
		for (i = 0; i < nc; i++) {
			if (((neighbors = getNeighbors(nr, nc, i, j, old)) == 3) ||
			    (neighbors == 2 && old[i][j] == ALIVE)) {
				new[i][j] = ALIVE;
			} else {
				new[i][j] = DEAD;
			}
		}
	}
}


void printBoard(unsigned int nr, unsigned int nc, char *board[], long iteration) {
	unsigned int i, j;

	// clear the screen
	printf("\e[1;1H\e[2J");

	printf("==== ITERATION %li ====\n", iteration);
	for (j = 0; j < nr; j++) {
		for (i = 0; i < nc; i++) {
			if (board[i][j] == ALIVE)
				printf("\x1B[32mX\x1B[0m");
			else
				printf(" ");
		}
		printf("\n");
	}
}

// returns 1 if equal, 0 otherwise
int arrayEquals(unsigned nr, unsigned nc, char *A[], char *B[]) {
	unsigned int i, j;
	for (j = 0; j < nr; j++) {
		for (i = 0; i < nc; i++) {
			if (A[i][j] != B[i][j])
				return 0;
		}
	}
	return 1;
}

// returns 0 for not done, 1 for loop, 2 for oscillate
int checkDone(unsigned nr, unsigned nc, char *A[], char *B[], char *C[]) {
	if (arrayEquals(nr, nc, A, B))
		return 1;
	else if (arrayEquals(nr, nc, C, B))
		return 2;
	else
		return 0;
}
