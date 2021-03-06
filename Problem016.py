"""
Author: Austin Derrow-Pinion
Purpose: Solve Problem 16 on Project Euler
Language: Python 2.x

Calculates the sum of all the digits in the
number 2 ^ 1000 which is a 302 digit number.
"""
import math

def sumOfDigits(n):
	output = 0
	while n > 9:
 		output += n % 10
 		n /= 10
	return output + n

def main():
	print "The sum of digits in the number 2 ** 1000:", sumOfDigits(2 ** 1000)

if __name__ == '__main__':
	main()