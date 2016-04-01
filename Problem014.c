#include <stdio.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 14 on Project Euler
* Language: C
*
* Finds the number under 1 million that has the largest
* number of terms in its Collatz Sequence.
*
* Collatz Sequence:
* n -> n / 2  (n is even)
* n -> 3n + 1 (n is odd)
*/

/** Returns the number of terms in the nth Collatz Sequence **/
long long termsInCollatzSequence(long long n) {
	long long count = 1;
	while (n != 1) {
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3*n + 1;
		count++;
	}
	return count;
}

/** Returns the number with the largest number of terms in Collatz Sequence
	between the lower and upper bound. **/
long long longestChain(long long lower, long long upper) {
	long long largest = 0;
	long long current = 0;
	long long i = 0;
	for(i = upper; i >= lower; i--) {
		current = termsInCollatzSequence(i);
		if(current > largest) {
			largest = current;
			printf("i = %lld \t largest = %lld\n", i, largest);
		}
	}
	return largest;
}

int main() {
	printf("largest chain under %d elements: %lld\n", 200000, longestChain(3, 1000000));
	return 0;
}