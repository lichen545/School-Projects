/*
CS 141
Liyuan Chen
lchen79
HW1:Search
v1.0
Implements a simple search game on a cartesian grid.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void moveRight(int *x) {
	if (*x == 10)
		printf("Ouch! You bumped into the the wall!\n");
	else 
		*x = *x + 1;
}

void moveLeft(int *x) {
	if (*x == 0)
		printf("Ouch! You bumped into the the wall!\n");
	else 
		*x = *x - 1;
}

void moveUp(int *y) {
	if (*y == 10)
		printf("Ouch! You bumped into the the wall!\n");
	else 
		*y = *y + 1;
}

void moveDown(int *y) {
	if (*y == 0)
		printf("Ouch! You bumped into the the wall!\n");
	else 
		*y = *y - 1;
}

double calculateDistance(int *goldX, int *goldY, int *charX, int *charY) {
  return sqrt(pow(*goldY - *charY, 2) + pow(*goldX - *charX, 2));
}

void moveChar(char move, int *x, int *y) {
	
	switch (move) {
	case 'n': 
		moveUp(y);
		break;
	case 'e':
		moveRight(x);
		break;
	case 's':
		moveDown(y);
		break;
	case 'w':
		moveLeft(x);
		break;
	};
}


int main() {

	srand(time(NULL));

	int *charX, *charY;
	charX = (int *) malloc(sizeof(int));
	charY = (int *) malloc(sizeof(int));

	
	*charX = 5;
	*charY = 5;

	int *goldX, *goldY;
	goldX = (int *) malloc(sizeof(int));
	goldY = (int *) malloc(sizeof(int));


	*goldX = rand()%11;
	*goldY = rand()%11;


	char *dir;
	dir = (char *) malloc(sizeof(char));

	int n=0;
	double oldDist, newDist;

	printf("Welcome to the maze game! Your starting location is (5,5), try to find the pot of gold that is randomly placed within this 10 x 10 board!\n");
	
	while ((*charX != *goldX) || (*charY != *goldY)) {
		
		
		oldDist = calculateDistance(goldX, goldY, charX, charY);

		printf("Please enter a direction (n, s, w, e - case-sensitive): ");
		scanf(" %c", dir);
		printf("\n");

		moveChar(*dir, charX, charY);
		
		
		newDist = calculateDistance(goldX, goldY, charX, charY);

		if (oldDist>=newDist) {
			printf("Old dist: %g\n", oldDist);
			printf("new dist: %g\n", newDist);
			printf("CharX: %d\n", *charX);
			printf("CharY: %d\n", *charY);
			printf("goldX: %d\n", *goldX);
			printf("goldY: %d\n", *goldY);
			printf("Getting warmer!\n");
		}
		else {
			printf("Old dist: %g\n", oldDist);
			printf("new dist: %g\n", newDist);
			printf("CharX: %d\n", *charX);
			printf("CharY: %d\n", *charY);
			printf("goldX: %d\n", *goldX);
			printf("goldY: %d\n", *goldY);
			printf("Getting colder!\n");
		}
		
		printf("\n");
		n++;
 
	}

	printf("Hooray! you found the pot of gold!\n");
	printf("moves used: %d\n", n);
}