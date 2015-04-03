/*
CS 141
Liyuan Chen
lchen79
HW1:Zig Zag
v1.0
Prints a zig zag pattern according to parameters input from user.
*/

#include <stdio.h>
#include <stdlib.h>


void printZigZag(int width, int roundTrips);


int main() {

	int *input1, *input2;
	input1 = (int *) malloc(sizeof(int));
	input2 = (int *) malloc(sizeof(int));

	printf("Please enter the width of the zig zag: ");
	do {
		(scanf("%d", input1));
	} while (*input1 < 1);
	printf("\n");

	printf("Please enter the number of round trips: ");
	do {
		(scanf("%d", input2));
	} while (*input2 < 1);
	printf("\n");

	printZigZag(*input1, *input2);
}


void printZigZag(int width, int roundTrips) {
	int i,j,t;

	printf("x\n");

	for(t=0; t<roundTrips; t++) {
		
		for (i=1; i<width; i++) {
			for (j=0; j<i; j++)
				printf(" ");
			printf("x\n");
		}

		for (i=(width-1); i>0; i--) {
			for (j=1; j<i; j++)
				printf(" ");
			printf("x\n");
		}
	}
}