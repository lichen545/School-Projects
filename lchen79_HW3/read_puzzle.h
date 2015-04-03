#include <stdio.h>

#define MAX_DIM 40
#define DEMO


void dump_board(char board[MAX_DIM][MAX_DIM], int nrows, int ncols);

int read_puzzle(char board[MAX_DIM][MAX_DIM], char *file, 
		  int *nrows_out, int *ncols_out);

