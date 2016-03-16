#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 10 on Project Euler
* Language: C
*
* Sums up all prime numbers below a given number.
* Project Euler problem was to sum up all primes under
* 2 million. This was very simple using my Sieve of
* Eratosthenes code. Just a small addition to the end
* in order to get the overall sum.
* Can be used to find the sum of primes below any given
* number in range of a long long. To prove this I added in
* commented code at the bottom that sums all primes below
* 1 billion. The answer is 24739512092254535.
*/

long long sieveOfEratosthenes(long long max) {
	bool *primes = calloc(max, sizeof(bool));
	long long i, j, output = 0;
	for(i = 2; i < sqrt(max); i++) {
		if(!primes[i]) {
			for(j = i*i; j <= max; j+=i) {
				primes[j] = true;
			}
		}
	}
	for(i = 2; i <= max; i++) {
		if(!primes[i]) {
			output += i;
		}
	}
	return output;
}

int main() {
	long long maxPrime = 2000000;
	long long result = sieveOfEratosthenes(maxPrime);
	printf("The sum of all primes below %lld is: %lld\n", maxPrime, result);

	// maxPrime = 1000000000;
	// result = sieveOfEratosthenes(maxPrime);
	// printf("The sum of all primes below %lld is: %lld\n", maxPrime, result);
	return 0;
}