/* 
Name: Li Chen
NetID: lchen79
Assignment: Word Search
Version: 1.3
Description: Given a text file containing a word search board, intiates a program that will continually prompt
the user for a word, printing out a word search board with the word uppercased and highlighted in red if there is
a match.
*/


#include <stdio.h>
#include <ctype.h>
#include "simpleio.h"
#include "read_puzzle.h"


#define MAX_DIM 40


//Uppercases matched words from west to east
void find_w2e(char word[], char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
	int i, j, h;	

	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			//Tracks position of input string
			int k = 0;
			//Flag for character matching
			int match = 1;
			h=j;	
			while (word[k] != '\0' && h<ncols && match) {
				//Skips whitespace in input
				if (isspace(word[k])) {
					k++;
				} else if (word[k] == board[i][h]) {
					k++;
					h++;
				} else {
					match = 0;
				}
			}
			//If a match is found, uppercases the matched word in the word search
			if (word[k] == '\0') {
				k=0;
				h=j;
				while (word[k]!='\0') {
					if (isspace(word[k])) {
						k++;
					} else if (word[k] == board[i][h]) {
						board[i][h] = toupper(board[i][h]);
						k++;
						h++;
					}
				}
			}
		}
	}
} 

void find_e2w(char word[], char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
	int i, j, h;	

	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			//Tracks position of input string
			int k = 0;
			//Flag for character matching
			int match = 1;
			h=j;	
			while (word[k] != '\0' && h>=0 && match) {
				//Skips whitespace in input
				if (isspace(word[k])) {
					k++;
				} else if (word[k] == board[i][h]) {
					k++;
					h--;
				} else {
					match = 0;
				}
			}
			//If a match is found, uppercases the matched word in the word search
			if (word[k] == '\0') {
				k=0;
				h=j;
				while (word[k]!='\0') {
					if (isspace(word[k])) {
						k++;
					} else if (word[k] == board[i][h]) {
						board[i][h] = toupper(board[i][h]);
						k++;
						h--;
					}
				}
			}
		}
	}
}



//Uppercases matched words from north to south
void find_n2s(char word[], char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
	int i, j, h;	

	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			//Tracks position of input string
			int k = 0;
			//Flag for character matching
			int match = 1;
			h=i;	
			while (word[k] != '\0' && h<nrows && match) {
				//Skips whitespace in input
				if (isspace(word[k])) {
					k++;
				} else if (word[k] == board[h][j]) {
					k++;
					h++;
				} else {
					match = 0;
				}
			}
			//If a match is found, uppercases the matched word in the word search
			if (word[k] == '\0') {
				k=0;
				h=i;
				while (word[k]!='\0') {
					if (isspace(word[k])) {
						k++;
					} else if (word[k] == board[h][j]) {
						board[h][j] = toupper(board[h][j]);
						k++;
						h++;
					}
				}
			}
		}
	}
}


//Uppercases matched words from south to north
void find_s2n(char word[], char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
	int i, j, h;	

	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			//Tracks position of input string
			int k = 0;
			//Flag for character matching
			int match = 1;
			h=i;	
			while (word[k] != '\0' && h>=0 && match) {
				//Skips whitespace in input
				if (isspace(word[k])) {
					k++;
				} else if (word[k] == board[h][j]) {
					k++;
					h--;
				} else {
					match = 0;
				}
			}
			//If a match is found, uppercases the matched word in the word search
			if (word[k] == '\0') {
				k=0;
				h=i;
				while (word[k]!='\0') {
					if (isspace(word[k])) {
						k++;
					} else if (word[k] == board[h][j]) {
						board[h][j] = toupper(board[h][j]);
						k++;
						h--;
					}
				}
			}
		}
	}
}



//Uppercases matched words from northwest to southeast
void find_nw2se(char word[], char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
	int i, j;	

	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			//Tracks position of input string
			int k = 0;
			//Flag for exiting while loop
			int match = 1;
			//Used to iterate through board if a match is found
			int h = j, m = i;;	
			while (word[k] != '\0' && m<nrows && h<ncols && match) {
				//Skips whitespace in input
				if (isspace(word[k])) {
					k++;
				} else if (word[k] == board[m][h]) {
					k++;
					m++;
					h++;
				} else {
					match = 0;
				}
			}
			//If a match is found, uppercases the matched word in the word search
			if (word[k] == '\0') {
				k=0;
				h=j;
				m=i;
				while (word[k]!='\0') {
					if (isspace(word[k])) {
						k++;
					} else if (word[k] == board[m][h]) {
						board[m][h] = toupper(board[m][h]);
						k++;
						m++;
						h++;
					}
				}
			}
		}
	}
} 


//Uppercases matched words from southeast to northwest
void find_se2nw(char word[], char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
	int i, j;	

	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			//Tracks position of input string
			int k = 0;
			//Flag for exiting while loop
			int match = 1;
			//Used to iterate through board if a match is found
			int h = j, m = i;;	
			while (word[k] != '\0' && m>=0 && h>=0 && match) {
				//Skips whitespace in input
				if (isspace(word[k])) {
					k++;
				} else if (word[k] == board[m][h]) {
					k++;
					m--;
					h--;
				} else {
					match = 0;
				}
			}
			//If a match is found, uppercases the matched word in the word search
			if (word[k] == '\0') {
				k=0;
				h=j;
				m=i;
				while (word[k]!='\0') {
					if (isspace(word[k])) {
						k++;
					} else if (word[k] == board[m][h]) {
						board[m][h] = toupper(board[m][h]);
						k++;
						m--;
						h--;
					}
				}
			}
		}
	}
} 

//Uppercases matched words from southwest to northeast
void find_sw2ne(char word[], char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
	int i, j;	

	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			//Tracks position of input string
			int k = 0;
			//Flag for exiting while loop
			int match = 1;
			//Used to iterate through board if a match is found
			int h = j, m = i;;	
			while (word[k] != '\0' && m>=0 && h<ncols && match) {
				//Skips whitespace in input
				if (isspace(word[k])) {
					k++;
				} else if (word[k] == board[m][h]) {
					k++;
					m--;
					h++;
				} else {
					match = 0;
				}
			}
			//If a match is found, uppercases the matched word in the word search
			if (word[k] == '\0') {
				k=0;
				h=j;
				m=i;
				while (word[k]!='\0') {
					if (isspace(word[k])) {
						k++;
					} else if (word[k] == board[m][h]) {
						board[m][h] = toupper(board[m][h]);
						k++;
						m--;
						h++;
					}
				}
			}
		}
	}
} 

 
//Uppercases matched words from northeast to southwest
void find_ne2sw(char word[], char board[MAX_DIM][MAX_DIM], int nrows, int ncols) {
	int i, j;	

	for (i=0; i<nrows; i++) {
		for (j=0; j<ncols; j++) {
			//Tracks position of input string
			int k = 0;
			//Flag for exiting while loop
			int match = 1;
			//Used to iterate through board if a match is found
			int h = j, m = i;;	
			while (word[k] != '\0' && m<ncols && h>=0 && match) {
				//Skips whitespace in input
				if (isspace(word[k])) {
					k++;
				} else if (word[k] == board[m][h]) {
					k++;
					m++;
					h--;
				} else {
					match = 0;
				}
			}
			//If a match is found, uppercases the matched word in the word search
			if (word[k] == '\0') {
				k=0;
				h=j;
				m=i;
				while (word[k]!='\0') {
					if (isspace(word[k])) {
						k++;
					} else if (word[k] == board[m][h]) {
						board[m][h] = toupper(board[m][h]);
						k++;
						m++;
						h--;
					}
				}
			}
		}
	}
}


int main(int argc, char *argv[]) {
	char board[MAX_DIM][MAX_DIM], board_copy[MAX_DIM][MAX_DIM];
	int nrows, ncols, i, j;

	char *input;

	if(argc != 2) {
		fprintf(stderr, "expected single cmd-line arg (filename)\n");
		return 0;
	}

  	if(!read_puzzle(board, argv[1], &nrows, &ncols)) 
		fprintf(stderr, "ERROR in reading board %s\n", argv[1]);
 	else {
		printf("successfully read board\n");
		dump_board(board, nrows, ncols);

		while (*(input=get_string()) != '.') {

			//Creates a copy of the board
			for (i=0; i<nrows; i++) {
				for (j=0; j<ncols; j++) {
					board_copy[i][j] = board[i][j];
				}
			}

			find_w2e(input, board_copy, nrows, ncols);
			find_e2w(input, board_copy, nrows, ncols);
			find_n2s(input, board_copy, nrows, ncols);
			find_s2n(input, board_copy, nrows, ncols);
			find_nw2se(input, board_copy, nrows, ncols);
			find_se2nw(input, board_copy, nrows, ncols);
			find_sw2ne(input, board_copy, nrows, ncols);
			find_ne2sw(input, board_copy, nrows, ncols);
			dump_board(board_copy, nrows, ncols);
		}
 	}
}
