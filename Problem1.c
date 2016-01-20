#include <stdio.h>

int main() {
	int i;
	long sum = 0;
	for (i = 3; i < 1000; i += 3) {
		sum += i;
	}
	for (i = 5; i < 1000; i += 5) {
		if(i % 3 != 0) sum += i;
	}
	printf("The sum of all the multiples of 3 and 5 belowe 1000 are: %ld\n", sum);
	return 0;
}