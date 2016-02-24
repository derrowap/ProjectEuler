#include <stdio.h>
#include <stdbool.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 5 on Project Euler
* Language: C
*
* Finds the smallest number that can be divided by numbers 1 to max without any remainders
* where max for this problem was 10 in the example and 20 for the solution.
*/

int smallestMultiple(int max) {
	int index = max, i;
	bool flag;
	while(true) {
		flag = true;
		for(i = 1; i < max; i++) {
			if(index % i != 0) {
				flag = false;
				index += 10;
			}
		}
		if(flag) {
			return index;
		}
	}
}

int main() {
	int result = smallestMultiple(10);
	printf("The smallest number that can be divided by numbers 1 to 10 without any remainder is %d\n", result);

	result = smallestMultiple(20);
	printf("The smallest number that can be divided by numbers 1 to 20 without any remainder is %d\n", result);

	return 0;
}