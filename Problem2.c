#include <stdio.h>

#define MAX 4000000

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 2 on Project Euler
* Language: C
*
* Simple formula for the Fibonacci sequence. 
* Iterates through all even terms in the sequence under 4 million.
* Prints the sum of all these terms.
*/


int main() {
	int i, previous = 1, sum = 0;
	for (i = 2; i < MAX; i += previous) {
		previous = i - previous;
		if (i % 2 == 0) sum += i;
	}
	printf("The sum of even terms in the Fibonacci sequence under 4,000,000 is: %d\n", sum);
	return 0;
}