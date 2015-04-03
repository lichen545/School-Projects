/*
CS 141
Liyuan Chen
lchen79
HW1:log2
v1.0
Returns the largest value of log(2) < n for any given n.
*/

#include <stdio.h>
#include <stdlib.h>


int log_2(int n) {
	if (n<2)
		return 0;
	else
		return log_2(n/2) + 1;
}

int main() {
	int *input;
	input = (int *) malloc(sizeof(int));

	printf("Please input a non-negative integer.\n");
	scanf("%d", input);

	printf("The largest integer x such that 2^x <= %d is %d\n", *input, log_2(*input));
}