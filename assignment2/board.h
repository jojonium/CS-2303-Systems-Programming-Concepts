/* board.h */

void playOne(unsigned int nr, unsigned int nc, char *old[], char *new[]);
void printBoard(unsigned int nr, unsigned int nc, char *board[]);
unsigned int getNeighbors(unsigned nr, unsigned nc, unsigned x, unsigned y, char *board[]);
