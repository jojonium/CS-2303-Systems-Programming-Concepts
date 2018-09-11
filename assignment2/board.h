/* board.h */

void playOne(unsigned int nr, unsigned int nc, char *old[], char *new[]);
void printBoard(unsigned int nr, unsigned int nc, char *board[], long iteration);
unsigned int getNeighbors(unsigned nr, unsigned nc, unsigned x, unsigned y, char *board[]);
int checkDone(unsigned nr, unsigned nc, char *A[], char *B[], char *C[]);
