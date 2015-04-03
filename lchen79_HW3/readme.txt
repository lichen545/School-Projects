Hi, welcome to Li's wsearch program!

Instructions:
Type "make wsearch" to create the wsearch program. Run it using "./wsearch [name of board]" (e.g. "./wsearch board1.txt")


Notes:
1) In lines 24-30 of "read_puzzle.c", I added code so that uppercase letters would be printed in red.
2) (FIXED) My search functions (e.g. e2w, s2n, etc) are currently not uppercasing matched characters like they should, but everything else is working fine.

Side note: I implemented the rotate_right function in "part1.c" without creating a 2nd copy of the original array,
which according to Professor Lillis grants me extra credit points.


Changelog:
	v1.3
		-Changed the end condition of the for loop that uppercased matched words [e.g. "(h=0; h!='\0'; h++)" to "(k=0, h=j; word[k]!='\0'; k++, h++)"]
		-Changed "word[h] = toupper(word[h])" to "board[i][j] = toupper(board[i][j])" in every search function
		-Vastly revamped logic of search algorithm to be able to skip whitespace in input
		-Declared a "board_copy" that copies the values from the original board, allowing each word entered to start fresh with a new board
		-Changed "pstring_red" function in color_demo.c to accept "char s" intead of "char *s" and made necessary compatibility updates
		
