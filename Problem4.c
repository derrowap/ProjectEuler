#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 4 on Project Euler
* Language: C
*
* Brute force method would take way too long for a computer to find 
* the largest palindrome of any multiple of numbers with at least 2 digits.
* Once the algorithm worked for two digit palindromes, the algorithm for
* any number of digits only changes two lines. The i=__ statement and the
* while(second < ___) statement.
*/



bool isPalindrome(int i) {
	char s[11];
	int j, size;
	sprintf(s, "%ld", i);
	size = strlen(s);
	for (j = 0; j < size / 2; j++) {
		if (s[j] != s[size - j - 1]) {
			return false;
		}
	}
	return true;
}

int twoDigitPalindrome() {
	int i, first, second, output = -1;
	for (i = 198; i > 1; i--) {
		first = i / 2;
		if (first + first == i) second = first;
		else second = first + 1;
		while (second < 100) {
			if (first * second > output) {
				if (isPalindrome(first * second))
					output = first * second;
			}
			second++;
			first--;
		}
		if (output > 0) return output;
	}
	return output;
}

int threeDigitPalindrome() {
	int i, first, second, output = -1;
	for (i = 998001; i > 1; i--) {
		first = i / 2;
		if (first + first == i) second = first;
		else second = first + 1;
		while (second < 1000) {
			if (first * second > output) {
				if (isPalindrome(first * second))
					output = first * second;
			}
			second++;
			first--;
		}
		if (output > 0) return output;
	}
	return output;
}

int fourDigitPalindrome() {
	int i, first, second, output = -1;
	for (i = 99980001; i > 1; i--) {
		first = i / 2;
		if (first + first == i) second = first;
		else second = first + 1;
		while (second < 10000) {
			if (first * second > output) {
				if (isPalindrome(first * second))
					output = first * second;
			}
			second++;
			first--;
		}
		if (output > 0) return output;
	}
	return output;
}

int main() {
	// if(isPalindrome(9210129)) printf("yes");
	int largestTwoDigitPalindrome = twoDigitPalindrome();
	printf("The largest palindrome made from the product of two 2-digit numbers is: %i\n", largestTwoDigitPalindrome);
	int largestThreeDigitPalindrome = threeDigitPalindrome();
	printf("The largest palindrome made from the product of two 3-digit numbers is: %i\n", largestThreeDigitPalindrome);
	int largestFourDigitPalindrome = fourDigitPalindrome();
	printf("The largest palindrome made from the product of two 4-digit numbers is: %i\n", largestFourDigitPalindrome);
	return 0;
}