#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 7 on Project Euler
* Language: C
*
* Calculates the 10,001st prime number.
* Copied code over from my implementation of the
* Sieve of Eratosthenes algorithm.
* My compiler tells me it takes 0.2s to run.
*/

void sieveOfEratosthenes(int max) {
	bool *primes = malloc(max*sizeof(bool));
	int i, j;
	for(i = 2; i < sqrt(max); i++) {
		if(!primes[i]) {
			for(j = i*i; j <= max; j+=i) {
				primes[j] = true;
			}
		}
	}
	j = 0;
	for(i = 2; i < max; i++) {
		if(!primes[i]) {
			j++;
			if(j == 10001)
				printf("The 10,001st prime number is: %i\n", i);
		}
	}
}

int main() {
	/* this prints first one million prime numbers */
	int primesRange = 104745;
	sieveOfEratosthenes(primesRange);
	return 0;
}