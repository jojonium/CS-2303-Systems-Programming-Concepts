/* board.c */

#include <stdlib.h>
#include <stdio.h>

#define ALIVE 'x'
#define DEAD 'o'

unsigned int getNeighbors(unsigned nr, unsigned nc, unsigned x, unsigned y, char *board[]) {
	return  ((y > 0 && x > 0) ? (board[x -1][y - 1] == ALIVE) : 0) +            // top left
		((y > 0) ? (board[x][y - 1] == ALIVE) : 0) +                        // top
		((y > 0 && x < nc - 1) ? (board[x - 1][y + 1] == ALIVE) : 0) +      // top right
		((x < nc - 1) ? (board[x + 1][y] == ALIVE) : 0) +                   // right
		((y < nr - 1 && x < nc - 1) ? (board[x + 1][y + 1] == ALIVE) : 0) + // bot right
		((y < nr - 1) ? (board[x][y + 1] == ALIVE) : 0) +                   // bottom
		((y < nr - 1 && x > 0) ? (board[x - 1][y + 1] == ALIVE) : 0) +      // bot left
		((x > 0) ? (board[x - 1][y] == ALIVE) : 0);                         // left
}

void playOne(unsigned int nr, unsigned int nc, char *old[], char *new[]) {
	unsigned int i, j, neighbors;
	for (j = 0; j < nr; j++) {
		for (i = 0; i < nc; i++) {
			printf(" ");
		}
	}
}


void printBoard(unsigned int nr, unsigned int nc, char *board[]) {
	unsigned int i, j;
	for (j = 0; j < nr; j++) {
		for (i = 0; i < nc; i++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

