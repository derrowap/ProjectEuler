#include <stdio.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 5 on Project Euler
* Language: C
*
* Finds the difference between the sum of the squares of
* the first n natural numbers and the square of the sum.
*/

long sumOfSquare(long n) {
	long output = 1, i;
	for (i = 2; i <= n; i++) {
		output += i * i;
	}
	return output;
}

long squareOfSum(long n) {
	long output = 1, i;
	for (i = 2; i <= n; i++) {
		output += i;
	}
	return output * output;
}

int main() {
	long result = squareOfSum(10) - sumOfSquare(10);
	printf("The difference between the sum of the squares of the first ten natural numbers and square of the sum is %d\n", result);

	result = squareOfSum(100) - sumOfSquare(100);
	printf("The difference between the sum of the squares of the first one hundred natural numbers and square of the sum is %d\n", result);

	return 0;
}