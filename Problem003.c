#include <stdio.h>
#include <stdbool.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 3 on Project Euler
* Language: C
*
* Finds all prime factors of a given input and prints out the largest.
* Learned C had labels like in assembly code.
*/


bool prime(long long p) {
	long long i;
	for(i = 2; i <= (p / 2); i++) {
		if(p % i == 0) return false;
	}
	return true;
}

long long largestPrime(long long num) {
	long long i;
	loop:
	for(i = 2; i <= num;i++) {
		if(prime(i)) {
			if(i == num)
				return i;
			if(num % i == 0) {
				num /= i;
				goto loop;
			}

		}
	}
	return -1;

}

int main() {
	long long number = 600851475143;
	long long largest = largestPrime(number);
	printf("%lld\n", largest);
	return 0;
}