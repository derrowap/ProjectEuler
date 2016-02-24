#include <stdio.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 5 on Project Euler
* Language: C
* 
* TODO: UNFINISHED
*
* Finds the difference between the sum of the squares of 
* the first n natural numbers and the square of the sum.
*/

int sumOfSquare(int n) {

	return -1;
}

int squareOfSum(int n) {

	return -1;
}

int main() {
	int result = squareOfSum(10) - sumOfSquare(10);
	printf("The difference between the sum of the squares of the first ten natural numbers and square of the sum is %d\n", result);

	result = sumOfSquare(100) - sumOfSquare(100);
	printf("The difference between the sum of the squares of the first one hundred natural numbers and square of the sum is %d\n", result);

	return 0;
}