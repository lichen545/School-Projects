

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
void pop_mtx(char m[N][N]);


/**
* Function:  display_mtx
* Description:  prints given square matrix row-by-row
*/
void display_mtx(char m[N][N]);

/**
* Function:  swap_rows
* Description:  swaps the contents of rows r1 and r2 of
*               square matrix m.  Ordering of characters
*		within rows are preserved.
*
*               If r1 or r2 is out of range no modifications
*		are made.
*/
void swap_rows(char m[N][N], int r1, int r2);

/**
* Function:  swap_cols
* Description:  swaps the contents of column c1 and c2 of
*               square matrix m.  Ordering of characters
*		within rows are preserved.
*
*               If c1 or c2 is out of range no modifications
*		are made.
*/
void swap_cols(char m[N][N], int c1, int c2);



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
void rotate_right(char m[N][N]);




