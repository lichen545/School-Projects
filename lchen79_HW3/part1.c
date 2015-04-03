#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

/**
* Homework 3, Part I:  warmup exercises.  Functions operating
*     on SQUARE NxN matrices of characters
*/

/**
* Function:  pop_mtx
* Description:  populates square matrix of characters
*		with random, lower-case letters a..z
*/
void pop_mtx(char m[N][N]) {
	srand(time(NULL));
	int i, j;

	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			m[i][j] = rand()%26 + 97;
		}
	}


}


/**
* Function:  display_mtx
* Description:  prints given square matrix row-by-row
*/
void display_mtx(char m[N][N]) {
	int i, j;

  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      printf("%4c", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/**
* Function:  swap_rows
* Description:  swaps the contents of rows r1 and r2 of
*               square matrix m.  Ordering of characters
*		within rows are preserved.
*
*               If r1 or r2 is out of range no modifications
*		are made.
*/
void swap_rows(char m[N][N], int r1, int r2) {
	int i;
	char tmp;
	//Checks to see if parameters are within bounds
	if (r1>=N || r2>=N || r1<0 || r2<0) {
		printf("Invalid row numbers entered\n");
		exit(1);
	}

	for (i=0; i<N; i++) {
		tmp = m[r1][i];
		m[r1][i] = m[r2][i];
		m[r2][i] = tmp;
	}
}

/**
* Function:  swap_cols
* Description:  swaps the contents of column c1 and c2 of
*               square matrix m.  Ordering of characters
*		within rows are preserved.
*
*               If c1 or c2 is out of range no modifications
*		are made.
*/
void swap_cols(char m[N][N], int c1, int c2) {
	int i;
	char tmp;
	//Checks to see if parameters are within bounds
	if (c1>=N || c2>=N || c1<0 || c2<0) {
		printf("Invalid column numbers entered\n");
		exit(1);
	}

	for (i=0; i<N; i++) {
		tmp = m[i][c1];
		m[i][c1] = m[i][c2];
		m[i][c2] = tmp;
	}
}



/**
* Function:  rotate_right
* Description:  "rotates" square matrix m 90 degrees right
*		(clockwise).
*
*		Example:  consider the 3x3 matrix below:
*
*			a b c
*			d e f
*			h i j
*
*		After one rotation, the matrix contents are:
*
*			h d a
*			i e b
*			j f c
*/


//helper function to reverse the contents of a char array
void reverse(char m[], int n) {
	int i, j;
	char tmp;

	for(i=0, j=n-1; i<j; i++, j--) {
		tmp = m[i];
		m[i] = m[j];
		m[j] = tmp;
	}
}

/*NOTE: I implemented the rotate_right function without creating a 2nd copy of the original array,
which according to Professor Lillis grants me extra credit points*/
void rotate_right(char m[N][N]) {
	int i, j, k;
	char tmp = 0;

	//Reflects the elements of the 2D array across the diagonal (e.g. m[1][0] <-> m[0][1], m[2][0] <-> m[0][2], ...)
	for (k=1; k<N; k++) {
		//Reflects upper left triangular half
		for(i=0, j=k; i<j; i++, j--) {
			tmp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = tmp;
		}
		//Reflects lower right triangular half
		for (i=k, j=N-1; i<j; i++, j--) {
			tmp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = tmp;
		}
	}
	
	//Reverses all the rows of the 2D array
	for (k=0; k<N; k++) {
		reverse(&m[k][0], N);
	}
}
