#include <stdio.h>
#include <stdbool.h>

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
	// TODO: each time a number is found starting at 2 going up that divides this number, divide it. Less iterations, more efficient.
	long long number = 600851475143;
	// long long number = 42;
	long long largest = largestPrime(number);
	printf("%lld\n", largest);
	return 0;
}