#include <stdio.h>
#include <stdbool.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 526 on Project Euler
* Language: C
*
*
* Function f(n) is the largest prime factor of n.
* Function g(n) is the sum of largest prime factors of 
* 	each nine consecutive numbers starting with n.
* Function h(n) is maximum value of g(k) for 2 <= k <= n.
* 
* This problem is set up to find h(10^(16)).
*/

bool prime(long long p);
long long largestPrime(long long num);
long long sumOfLargestPrimes(long long num);

bool prime(long long p) {
	long long i;
	for (i = 2; i <= (p / 2); i++) {
		if (p % i == 0) return false;
	}
	return true;
}

/**
* 	Returns the largest prime factor of num.
*
**/
long long largestPrime(long long num) {
	long long i;
loop:
	for (i = 2; i <= num; i++) {
		if (prime(i)) {
			if (i == num)
				return i;
			if (num % i == 0) {
				num /= i;
				goto loop;
			}

		}
	}
	return -1;
}

/**
*	f(n) if the largest prime factor of n.
*	This returns g(n) = f(n) + f(n+1) + f(n+2) + f(n+3) +
*		f(n+4) + f(n+5) + f(n+6) + f(n+7) + f(n+8)
**/
long long sumOfLargestPrimes(long long num) {
	int i;
	long long sum = 0;
	for (i = 0; i < 9; i++) {
		sum += largestPrime(num + (long long) i);
	}
	return sum;
}

long long maxSumLargestPrime(long long num) {
	long long i, temp, max = 0;
	for (i = 2; i <= num; i++) {
		temp = sumOfLargestPrimes(i);
		if (temp > max)
			max = temp;
	}
	return max;
}

int main() {
	long long number = 1000000000;
	long long largest = maxSumLargestPrime(number);
	printf("%lld\n", largest);
	return 0;
}