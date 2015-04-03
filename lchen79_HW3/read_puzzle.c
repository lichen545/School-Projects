#include <stdio.h>
#include "color_demo.h"


#define MAX_DIM 40
//#define DEMO


int next_symbol(FILE *fptr) {
int ch;

  while(( (ch = fgetc(fptr)) != EOF) && isspace(ch));

  return ch;
}
  
void dump_board(char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
int i, j;

  printf("\n");
  for(i=0; i<nrows; i++) {
    printf("    ");
    for(j=0; j<ncols; j++) {
		//Prints in red if the letter is uppercase
		if (board[i][j]>='A' && board[i][j]<='Z') {
			printf(" ");
			pstring_red(board[i][j]);
			printf(" ");
		}
		else {
			printf(" %c ", board[i][j]);
		}
    }
    printf("\n");
  }
  printf("\n");
}

int read_puzzle(char board[MAX_DIM][MAX_DIM], char *file, 
		  int *nrows_out, int *ncols_out) {

FILE *fptr = fopen(file, "r");
int nrows, ncols;
int i, j;
int ch;

  if(fptr == NULL) {
	fprintf(stderr, "ERR:  failed to open file %s\n", file);
	return 0;
  }
  if(fscanf(fptr, "%i %i\n", &nrows, &ncols) != 2 ||
	  nrows <= 0 || ncols <= 0 || nrows > MAX_DIM || ncols > MAX_DIM){
	fprintf(stderr, "ERR:  bad board dimensions\n");
	fclose(fptr);
	return 0;
  }
  for(i=0; i<nrows; i++) {
	for(j=0; j<ncols; j++) {
	  if( (ch = next_symbol(fptr)) == EOF) {
		fprintf(stderr, "ERR:  file too short\n");
		fclose(fptr);
		return 0;
	  }
	  else if(!isalpha(ch)) {
		fprintf(stderr, "ERR:  bad char in input (%c)\n", ch);
		fclose(fptr);
		return 0;
	  }
	  
	  board[i][j] = tolower(ch);
	}
  }
  if(next_symbol(fptr) != EOF) {
	fprintf(stderr, "ERR:  file too long\n");
	fclose(fptr);
	return 0;
  }
  // if we get here we succeeded!
  fclose(fptr);
  *nrows_out = nrows;
  *ncols_out = ncols;
  return 1;
}
	
#ifdef DEMO
	    
	
int main(int argc, char *argv[]){
char board[MAX_DIM][MAX_DIM];
int nrows, ncols;

  if(argc != 2) {
	fprintf(stderr, "expected single cmd-line arg (filename)\n");
	return 0;
  }

  if(!read_puzzle(board, argv[1], &nrows, &ncols)) 
	fprintf(stderr, "ERROR in reading board %s\n", argv[1]);
  else {
	printf("successfully read board\n");
	dump_board(board, nrows, ncols);
  }
}

#endif
  
