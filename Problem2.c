#include <stdio.h>

#define MAX 4000000
int main() {
	int i, previous = 1, sum = 0;
	for (i = 1; i < MAX; i += previous) {
		if (i != 1) previous = i - previous;
		if (i % 2 == 0) sum += i;
	}
	printf("The sum of even terms in the Fibonacci sequence under 4,000,000 is: %d\n", sum);
	return 0;
}