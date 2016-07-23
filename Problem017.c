#include <stdio.h>

/**
* Author: Austin Derrow-Pinion
* Purpose: Solve Problem 16 on Project Euler
* Language: C
*
* 
*/

int ones[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
int teens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int tens[] = {6, 6, 5, 5, 5, 7, 6, 6};
int hundred = 7;
int thousand = 8;

int sumOneToThousand() {
	int output = 0;
	int i = 0, j = 0;
	for(i = 0; i < 9; i++)
		output += ones[i];
	int underTen = output;
	for(i = 0; i < 10; i++)
		output += teens[i];
	
	int tenSum = 0;
	for(i = 0; i < 8; i++)
		tenSum += tens[i];
	output += 10 * tenSum + 8 * underTen;

	int underHundred = output;

	output += underTen * 100;
	output += underHundred * 9;
	output += hundred * 9;
	output += (hundred + 3) * 9 * 99;

	output += ones[0] + thousand;

	return output;
}

int main() {
	printf("%d\n", sumOneToThousand());
	return 0;
}